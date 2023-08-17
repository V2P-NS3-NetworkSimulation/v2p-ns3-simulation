# Projeto - V2P - NS-3 - Semana 1

## Revisão Bibliográfica
Realizar uma revisão rápida da literatura para compreender os conceitos básicos do V2P, redes veiculares, NS-3 e acesso Non-3GPP.

### V2X (Vehicle-to-Everything):
V2X, ou comunicação veículo-a-tudo (Vehicle-to-Everything), é uma tecnologia que permite que os veículos se comuniquem uns com os outros, com a infraestrutura de estradas e com outros dispositivos. Isso pode ser feito usando uma variedade de métodos, incluindo Wi-Fi, Bluetooth e ondas de rádio.

O V2X tem o potencial de melhorar a segurança nas estradas, permitindo que os veículos se comuniquem uns com os outros e com a infraestrutura da estrada sobre potenciais riscos. Isso pode ajudar a prevenir acidentes, melhorar a eficiência do tráfego e criar novas aplicações para carros autônomos.

Alguns dos benefícios potenciais do V2X incluem:
- Redução de acidentes: o V2X pode ajudar a reduzir acidentes permitindo que os veículos se comuniquem uns com os outros e com a infraestrutura da estrada sobre potenciais riscos. Por exemplo, um carro pode usar V2V para enviar um aviso a outro carro que está prestes a mudar de faixa na frente dele.
- Melhoria da eficiência do tráfego: o V2X pode ajudar a melhorar a eficiência do tráfego permitindo que os veículos se comuniquem uns com os outros e com a infraestrutura da estrada sobre as condições do tráfego. Isso pode ajudar a evitar congestionamentos e melhorar o fluxo do tráfego.
- Criação de novas aplicações para carros autônomos: o V2X é um componente essencial para carros autônomos. Os carros autônomos precisam ser capazes de se comunicar uns com os outros e com a infraestrutura da estrada para navegar com segurança nas estradas.

### V2P (Vehicle-to-Pedestrian):
V2P é uma tecnologia que permite que veículos se comuniquem com pedestres. Isso pode ser feito usando uma variedade de métodos, incluindo Wi-Fi, Bluetooth e ondas de rádio.

O V2P tem o potencial de melhorar a segurança nas estradas, permitindo que os veículos se comuniquem uns com os outros e com pedestres sobre potenciais riscos. Por exemplo, um carro pode usar V2P para enviar um aviso a um pedestre que está prestes a atravessar a rua na frente dele.

### Redes veiculares:
Redes veiculares são redes de comunicação projetadas especificamente para veículos. Essas redes podem ser usadas para uma variedade de propósitos, incluindo comunicação V2V (Vehicle-to-Vehicle), comunicação V2I (Vehicle-to-Infrastructure) e comunicação V2P (Vehicle-to-Pedestrian). As redes veiculares podem ser baseadas em uma variedade de tecnologias, incluindo 3GPP (3rd Generation Partnership Project), LTE (Long Term Evolution) e 5G (5th Generation). As redes veiculares são necessárias para permitir que os veículos se comuniquem uns com os outros e com a infraestrutura da estrada em tempo real. Isso pode ajudar a prevenir acidentes, melhorar a eficiência do tráfego e criar novas aplicações para carros autônomos.

### NS-3 (Network Simulator 3):
NS-3 é um simulador de rede de código aberto. O NS-3 pode ser usado para simular uma variedade de redes, incluindo redes veiculares. O NS-3 é uma ferramenta valiosa para pesquisadores e desenvolvedores que desejam estudar e desenvolver novas tecnologias para redes veiculares. O NS-3 pode ser usado para simular uma variedade de cenários, incluindo tráfego de veículos, comunicação V2V e V2I, e segurança em redes veiculares.

### Acesso Non-3GPP:
Acesso Non-3GPP é um termo usado para descrever as formas de acesso à rede que não são baseadas na especificação 3GPP. O acesso Non-3GPP pode ser usado para uma variedade de propósitos, incluindo V2P, V2V e V2I. O acesso Non-3GPP pode ser baseado em uma variedade de tecnologias, incluindo Wi-Fi, Bluetooth e ondas de rádio. O acesso Non-3GPP tem o potencial de fornecer uma série de vantagens sobre o acesso 3GPP, incluindo maior largura de banda, menor latência e maior eficiência energética.

## Desenvolvimento de Modelos V2P Simplificados
Implementação dos modelos básicos para representar veículos e pedestres no ambiente de simulação do NS-3. Modelos simplificados para focar na comunicação essencial do V2P.

### Modelos básicos implementados:

#### Behavior
A classe Behavior representa o comportamento dos veículos e pedestres na simulação. Cada veículo e pedestre possui um comportamento que pode ser definido por um tipo e parâmetros específicos.

Membros:
- type: Uma string que descreve o tipo de comportamento (por exemplo, "normal", "agressivo", "cauteloso", etc.).
  - Definindo diferentes tipos de comportamentos e parâmetros específicos para cada um, é possível simular cenários realistas com veículos e pedestres que se comportam de maneiras distintas. Isso é essencial para analisar como a comunicação V2P pode impactar e ser afetada pelo comportamento dos atores envolvidos na simulação.
- parameters: Um vetor de valores numéricos que contém os parâmetros específicos do comportamento.

#### Communication
A classe Communication representa o modelo de comunicação entre veículos e pedestres. Cada veículo e pedestre pode ter diferentes modelos de comunicação para trocar informações entre si.

Membros:
- type: Uma string que descreve o tipo de comunicação (por exemplo, "Wi-Fi", "802.11p", etc.).
  - IEEE 802.11p é uma emenda aprovada ao padrão IEEE 802.11 para adicionar acesso sem fio em ambientes veiculares, um sistema de comunicação veicular. Ele define aprimoramentos para 802.11 necessários para oferecer suporte a aplicativos de sistemas de transporte inteligentes.
- frequency: A frequência de comunicação do modelo (em Hz).
- range: O alcance de comunicação do modelo (em metros).

#### Mobility
A classe Mobility representa o modelo de mobilidade dos veículos e pedestres. Cada veículo e pedestre pode ter diferentes modelos de mobilidade que definem sua velocidade, aceleração e direção.

Membros:
- speed: A velocidade do veículo ou pedestre (em m/s).
- acceleration: A aceleração do veículo ou pedestre (em m/s²).
- direction: A direção do veículo ou pedestre (em graus).

#### Vector2D
A classe Vector2D representa um vetor bidimensional com componentes x e y. Ela é utilizada para representar posições no plano cartesiano.

Membros:
- x: A componente x do vetor.
- y: A componente y do vetor.

#### Vehicle
A classe Vehicle representa um veículo na simulação. Cada veículo possui uma identificação única, uma faixa de tráfego, uma posição no plano cartesiano, um modelo de comunicação e um modelo de mobilidade.

Membros:
- id: A identificação única do veículo.
- lane: A faixa de tráfego em que o veículo está localizado.
- position: Um objeto Vector2D que representa a posição do veículo no plano cartesiano.
- communicationModel: Um objeto Communication que representa o modelo de comunicação do veículo.
- mobilityModel: Um objeto Mobility que representa o modelo de mobilidade do veículo.
- behavior: Um objeto Behavior que representa o comportamento do veículo.

#### Pedestrian
A classe Pedestrian representa um pedestre na simulação. Cada pedestre possui uma identificação única, uma posição no plano cartesiano, um modelo de comunicação e um modelo de mobilidade.

Membros:
- id: A identificação única do pedestre.
- position: Um objeto Vector2D que representa a posição do pedestre no plano cartesiano.
- communicationModel: Um objeto Communication que representa o modelo de comunicação do pedestre.
- mobilityModel: Um objeto Mobility que representa o modelo de mobilidade do pedestre.
- behavior: Um objeto Behavior que representa o comportamento do pedestre.

### Main
A Main contém a implementação do cenário de simulação e a comunicação V2P entre um veículo e um pedestre. Ele utiliza as classes Vehicle e Pedestrian para criar os objetos do cenário, define a mobilidade e comunicação dos veículos e pedestres, e simula a comunicação V2P entre eles.
</hr>
# Simulação de Comunicação Vehicle-to-Pedestrian (V2P) no NS-3

## Semana 2: Definição do Cenário e Protocolo

Nesta etapa do projeto, houve um foco na definição de um cenário de simulação e na seleção/configuração de um protocolo de comunicação básico para permitir a troca de informações entre veículos e pedestres. O código desenvolvido (especialmente a main.cc) é a parte principal da implementação que configura o ambiente de simulação, define a mobilidade dos veículos e pedestres, configura os dispositivos Wi-Fi, atribui endereços IP, cria aplicativos para enviar e receber pacotes de ping, finalmente executando a simulação.

```cpp
// Criação do Ambiente de Simulação
NodeContainer vehicles;
NodeContainer pedestrians;
vehicles.Create(2);
pedestrians.Create(1);

// Configuração da Mobilidade
MobilityHelper vehicleMobility;
MobilityHelper pedestrianMobility;
vehicleMobility.SetPositionAllocator("ns3::GridPositionAllocator", ...);
pedestrianMobility.SetPositionAllocator("ns3::GridPositionAllocator", ...);
vehicleMobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
pedestrianMobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");
vehicleMobility.Install(vehicles);
pedestrianMobility.Install(pedestrians);

// Configuração do Canal de Comunicação Wi-Fi
WifiHelper wifi;
YansWifiChannelHelper ch;
wifi.SetStandard(ns3::WIFI_STANDARD_80211n);
NetDeviceContainer devices, vehicleDevices, pedestrianDevices;
vehicleDevices = wifi.Install(phy, wifiMac, vehicles);
pedestrianDevices = wifi.Install(phy, wifiMac, pedestrians);

// Configuração da Pilha de Protocolos da Internet
InternetStackHelper internet;
internet.Install(vehicles);
internet.Install(pedestrians);

// Atribuição de Endereços IP
Ipv4AddressHelper ipv4;
ipv4.SetBase("10.0.0.0", "255.255.255.0");
Ipv4InterfaceContainer vehicleInterfaces = ipv4.Assign(vehicleDevices);
Ipv4InterfaceContainer pedestrianInterfaces = ipv4.Assign(pedestrianDevices);

// Criação de Aplicativos para Envio e Recebimento de Pacotes
UdpEchoClientHelper echoClientHelper(serverIp, serverPort);
ApplicationContainer clientApps = echoClientHelper.Install(vehicles.Get(i));
Config::ConnectWithoutContext("/NodeList/*/ApplicationList/*/$ns3::PacketSink/Rx", MakeCallback(&ReceivePacket));

