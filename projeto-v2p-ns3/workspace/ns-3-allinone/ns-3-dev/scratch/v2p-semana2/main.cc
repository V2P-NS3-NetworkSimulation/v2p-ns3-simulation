#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/wifi-module.h"
#include "ns3/wifi-helper.h"
#include "ns3/wifi-standards.h"
#include "ns3/internet-module.h"
#include "ns3/net-device.h"
#include "ns3/node-container.h"
#include "vehicle.h"
#include "pedestrian.h"
#include "vector2d.h"
#include "communication.h"
#include "behavior.h"
#include "mobility.h"

using namespace ns3;

int main()
{
  // Criação do ambiente de simulação
  NodeContainer vehicles;
  vehicles.Create(1); // Número de veículos

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
  wifi.SetStandard(ns3::WIFI_STANDARD_80211n); // Set Wi-Fi standard to 802.11be


// Criação do objeto YansWifiChannelHelper
YansWifiChannelHelper ch;
ch.SetPropagationDelay ("ns3::ConstantSpeedPropagationDelayModel"); // Configura o atraso de propagação como constante
ch.AddPropagationLoss ("ns3::FriisPropagationLossModel"); // Configura o modelo de perda de propagação como Friis

// Criação do objeto channel
Ptr<YansWifiChannel> channel = ch.Create ();

// Criação do objeto YansWifiPhyHelper
YansWifiPhyHelper phy; // Construtor padrão
phy.SetErrorRateModel ("ns3::NistErrorRateModel"); // Configura o modelo de taxa de erro
phy.SetChannel (channel); // Configura o canal Yans

WifiMacHelper wifiMac;
wifiMac.SetType("ns3::AdhocWifiMac");

// Instalação dos dispositivos Wi-Fi nos veículos e nos pedestres
NetDeviceContainer devices, vehicleDevices, pedestrianDevices; // Declaração das variáveis
vehicleDevices = wifi.Install(phy, wifiMac, vehicles); // Atribuição dos dispositivos dos veículos
pedestrianDevices = wifi.Install(phy, wifiMac, pedestrians); // Atribuição dos dispositivos dos pedestres

devices.Add (vehicleDevices); // Adição dos dispositivos dos veículos ao container geral
devices.Add (pedestrianDevices); // Adição dos dispositivos dos pedestres ao container geral


  // Configuração da pilha de protocolos da internet
  InternetStackHelper internet;
  internet.Install(vehicles);
  internet.Install(pedestrians);

  // Atribuição de endereços IP
  Ipv4AddressHelper ipv4;
  ipv4.SetBase("10.0.0.0", "255.255.255.0");
  Ipv4InterfaceContainer vehicleInterfaces = ipv4.Assign(vehicleDevices);
  Ipv4InterfaceContainer pedestrianInterfaces = ipv4.Assign(pedestrianDevices);

  // Create vehicle and pedestrian objects
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

  // Simulação
  Simulator::Run();
  Simulator::Destroy();

  return 0;
}