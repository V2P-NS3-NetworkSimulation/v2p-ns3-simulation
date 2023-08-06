#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/wifi-module.h"
#include "ns3/wifi-helper.h"
#include "ns3/wifi-standards.h"
#include "ns3/internet-module.h"
#include "ns3/net-device.h"
#include "ns3/node-container.h"
#include "ns3/udp-echo-helper.h"
#include "ns3/packet-sink-helper.h"

#include "vehicle.h"
#include "pedestrian.h"
#include "vector2d.h"
#include "communication.h"
#include "behavior.h"
#include "mobility.h"

using namespace ns3;

// Função callback para imprimir pacotes recebidos
static void ReceivePacket(Ptr<const Packet> packet, const Address &from)
{
    std::cout << "Recebeu uma resposta de ping de: " << from << std::endl;
    std::cout << "Tamanho do pacote: " << packet->GetSize() << " bytes" 
    << std::endl;
}

int main()
{
  // Criação do ambiente de simulação
  NodeContainer vehicles;
  vehicles.Create(2); // Número de veículos

  NodeContainer pedestrians;
  pedestrians.Create(1); // Número de pedestres

  // Configuração da mobilidade dos veículos
  MobilityHelper vehicleMobility;
  vehicleMobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                       "MinX", DoubleValue(0.0),
                                       "MinY", DoubleValue(0.0),
                                       "DeltaX", DoubleValue(10.0),
                                       "DeltaY", DoubleValue(10.0),
                                       "GridWidth", UintegerValue(3),
                                       "LayoutType", StringValue("RowFirst"));
  vehicleMobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
  vehicleMobility.Install(vehicles);

  // Configuração da mobilidade dos pedestres
  MobilityHelper pedestrianMobility;
  pedestrianMobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                          "MinX", DoubleValue(0.0),
                                          "MinY", DoubleValue(0.0),
                                          "DeltaX", DoubleValue(10.0),
                                          "DeltaY", DoubleValue(10.0),
                                          "GridWidth", UintegerValue(3),
                                          "LayoutType", StringValue("RowFirst"));
  pedestrianMobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
  pedestrianMobility.Install(pedestrians);

  // Configuração do canal de comunicação
  WifiHelper wifi;
  wifi.SetStandard(ns3::WIFI_STANDARD_80211n); //Defina o padrão Wi-Fi para 802.11n

  // Criação do objeto YansWifiChannelHelper
  YansWifiChannelHelper ch;
  // Configura o atraso de propagação como constante
  ch.SetPropagationDelay("ns3::ConstantSpeedPropagationDelayModel"); 

  // Configura o modelo de perda de propagação como Friis
  ch.AddPropagationLoss("ns3::FriisPropagationLossModel"); 

  // Criação do objeto channel
  Ptr<YansWifiChannel> channel = ch.Create();

  // Criação do objeto YansWifiPhyHelper
  YansWifiPhyHelper phy; // Construtor padrão

  // Configura o modelo de taxa de erro
  phy.SetErrorRateModel("ns3::NistErrorRateModel"); 
  phy.SetChannel(channel); // Configura o canal Yans

  WifiMacHelper wifiMac;
  wifiMac.SetType("ns3::AdhocWifiMac");

  // Instalação dos dispositivos Wi-Fi nos veículos e nos pedestres

  // Declaração das variáveis
  NetDeviceContainer devices, vehicleDevices, pedestrianDevices; 
  // Atribuição dos dispositivos dos veículos
  vehicleDevices = wifi.Install(phy, wifiMac, vehicles); 
  // Atribuição dos dispositivos dos pedestres
  pedestrianDevices = wifi.Install(phy, wifiMac, pedestrians); 

  // Adição dos dispositivos dos veículos ao container geral
  devices.Add(vehicleDevices); 
  // Adição dos dispositivos dos pedestres ao container geral
  devices.Add(pedestrianDevices); 

  // Configuração da pilha de protocolos da internet
  InternetStackHelper internet;
  internet.Install(vehicles);
  internet.Install(pedestrians);

  // Atribuição de endereços IP
  Ipv4AddressHelper ipv4;
  ipv4.SetBase("10.0.0.0", "255.255.255.0");
  Ipv4InterfaceContainer vehicleInterfaces = ipv4.Assign(vehicleDevices);
  Ipv4InterfaceContainer pedestrianInterfaces = ipv4.Assign(pedestrianDevices);

  // Cria os objetos para veiculo e pedestre
  std::vector<Vehicle> vehicleObjects;
  for (uint32_t i = 0; i < vehicles.GetN(); ++i) {
    Vehicle vehicle;
    vehicle.SetId(i + 1);
    vehicle.SetLane(1);
    vehicle.SetPosition(Vector2d(0.0, 0.0));
    vehicle.SetMobilityModel(Mobility(10.0, 2.0, 0.0));
    vehicle.SetCommunicationModel(Communication("Wi-Fi", 2.4, 100.0));
    vehicle.SetBehavior(Behavior("Normal", {1.0, 2.0, 3.0}));
    vehicleObjects.push_back(vehicle);
  }

  std::vector<Pedestrian> pedestrianObjects;
  for (uint32_t i = 0; i < pedestrians.GetN(); ++i) {
    Pedestrian pedestrian;
    pedestrian.SetId(i + 1);
    pedestrian.SetPosition(Vector2d(10.0, 0.0));
    pedestrian.SetMobilityModel(Mobility(1.0, 0.0, 0.0));
    pedestrian.SetCommunicationModel(Communication("Wi-Fi", 2.4, 100.0));
    pedestrian.SetBehavior(Behavior("Normal", {1.0, 2.0, 3.0}));
    pedestrianObjects.push_back(pedestrian);
  }
// Criar aplicativos para enviar e receber pacotes de ping
  Ipv4Address serverIp = pedestrianInterfaces.GetAddress(0);
  uint16_t serverPort = 9; // Echo port (ICMP)

  for (uint32_t i = 0; i < vehicles.GetN(); ++i) {
    // Veículo envia um pacote de ping para o pedestre
    UdpEchoClientHelper echoClientHelper(serverIp, serverPort);
    echoClientHelper.SetAttribute("MaxPackets", UintegerValue(1));
    echoClientHelper.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClientHelper.SetAttribute("PacketSize", UintegerValue(1024));

    ApplicationContainer clientApps = echoClientHelper.Install(vehicles.Get(i));
    clientApps.Start(Seconds(1.0));
    clientApps.Stop(Seconds(10.0));
  }

  /* Cria um aplicativo para receber pacotes de ping no pedestre usando o 
  PacketSinkHelper.*/
  PacketSinkHelper packetSinkHelper ("ns3::UdpSocketFactory", 
  InetSocketAddress (Ipv4Address::GetAny (), serverPort));
  
  ApplicationContainer serverApp = packetSinkHelper.Install(pedestrians.Get(0));
  serverApp.Start(Seconds(1.0));
  serverApp.Stop(Seconds(10.0));

  /* Registra a função de retorno de chamada ReceivePacket para lidar com os 
  pacotes recebidos.*/
  Config::ConnectWithoutContext("/NodeList/*/ApplicationList/*/$ns3::PacketSink/Rx", 
  MakeCallback(&ReceivePacket));

  // Simulação
  Simulator::Run();
  Simulator::Destroy();

  return 0;
}