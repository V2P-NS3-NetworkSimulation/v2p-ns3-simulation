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
# Semana 2: Definição do Cenário e Protocolo para Comunicação Vehicle-to-Pedestrian (V2P) no NS-3

Nesta etapa do projeto, houve um foco na definição de um cenário de simulação e na seleção/configuração de um protocolo de comunicação básico para permitir a troca de informações entre veículos e pedestres. O código desenvolvido (especialmente a `main.cc`) é a parte principal da implementação que configura o ambiente de simulação, define a mobilidade dos veículos e pedestres, configura os dispositivos Wi-Fi, atribui endereços IP, cria aplicativos para enviar e receber pacotes de ping, finalmente executando a simulação.

### Criação do Ambiente de Simulação:

Nesta etapa, é estabelecido o contexto virtual em que a simulação ocorrerá. Trata-se da instanciação dos elementos fundamentais para a representação de veículos e pedestres, criando um ambiente virtual no qual essas entidades interagem e se comunicam.

- `NodeContainer vehicles;` e `NodeContainer pedestrians;`: Criação de contêineres para representar os veículos e pedestres na simulação.
- `vehicles.Create(2);` e `pedestrians.Create(1);`: Criação do número especificado de nós para veículos e pedestres.

### Configuração da Mobilidade:

A configuração da mobilidade envolve a definição dos padrões de movimentação para os veículos e pedestres dentro do cenário simulado. Através do uso de um posicionamento, os nós (veículos e pedestres) são dispostos com espaçamento uniforme, permitindo assim a simulação de seus deslocamentos.

- `MobilityHelper vehicleMobility;` e `MobilityHelper pedestrianMobility;`: Criação de objetos MobilityHelper para configurar a mobilidade dos veículos e pedestres.
- `vehicleMobility.SetPositionAllocator("ns3::GridPositionAllocator", ...);` e `pedestrianMobility.SetPositionAllocator("ns3::GridPositionAllocator", ...);`: Definição de um alocador de posição em grade para posicionar os veículos e pedestres em uma grade.
- `vehicleMobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");` e `pedestrianMobility.SetMobilityModel("ns3::ConstantVelocityMobilityModel");`: Escolha de um modelo de mobilidade constante para os veículos e pedestres.
- `vehicleMobility.Install(vehicles);` e `pedestrianMobility.Install(pedestrians);`: Aplicação da configuração de mobilidade aos veículos e pedestres.

### Configuração do Canal de Comunicação Wi-Fi:

Nesse ponto, são definidas as propriedades do canal de comunicação que permite a troca de dados entre os nós da simulação. Esse canal virtual é modelado de acordo com parâmetros como atraso de propagação constante e perda de propagação.

- `WifiHelper wifi;` e `YansWifiChannelHelper ch;`: Criação de objetos para configurar os parâmetros Wi-Fi e o canal de comunicação.
- `wifi.SetStandard(ns3::WIFI_STANDARD_80211n);`: Definição do padrão Wi-Fi como 802.11n.

### Instalação dos Dispositivos Wi-Fi:

A etapa de instalação de dispositivos Wi-Fi implica na associação dos módulos de comunicação Wi-Fi aos nós representativos de veículos e pedestres. Isso possibilita a constituição de uma infraestrutura de rede sem fio, na qual os nós podem transmitir e receber informações por meio de interfaces Wi-Fi.

- `NetDeviceContainer devices, vehicleDevices, pedestrianDevices;`: Criação de contêineres para armazenar os dispositivos Wi-Fi dos veículos, pedestres e geral.
- `vehicleDevices = wifi.Install(phy, wifiMac, vehicles);` e `pedestrianDevices = wifi.Install(phy, wifiMac, pedestrians);`: Instalação dos dispositivos Wi-Fi nos veículos e pedestres, usando o modelo de camada física (phy) e o protocolo de camada de controle de acesso ao meio (MAC) específicos.

### Configuração da Pilha de Protocolos da Internet:

A configuração da pilha de protocolos da Internet engloba a adição das camadas de protocolos necessárias para habilitar a conectividade e comunicação entre os nós da simulação. Esse processo estabelece um contexto no qual os nós podem utilizar protocolos de roteamento, encaminhamento e troca de dados.

- `InternetStackHelper internet;`: Criação de um objeto InternetStackHelper para configurar a pilha de protocolos da internet nos nós.
- `internet.Install(vehicles);` e `internet.Install(pedestrians);`: Instalação da pilha de protocolos da internet nos veículos e pedestres.

### Atribuição de Endereços IP:

Nessa fase, os endereços IP são atribuídos às interfaces dos dispositivos Wi-Fi dos veículos e pedestres. Esses endereços IP servem para identificar cada nó na rede simulada, permitindo o encaminhamento correto de pacotes de dados através da infraestrutura de rede criada.

- `Ipv4AddressHelper ipv4;`: Criação de um objeto para auxiliar na atribuição de endereços IP.
- `ipv4.SetBase("10.0.0.0", "255.255.255.0");`: Definição da base do endereço IP e máscara de sub-rede.
- `Ipv4InterfaceContainer vehicleInterfaces = ipv4.Assign(vehicleDevices);` e `Ipv4InterfaceContainer pedestrianInterfaces = ipv4.Assign(pedestrianDevices);`: Atribuição de endereços IP às interfaces dos dispositivos dos veículos e pedestres.

### Configuração de Veículos e Pedestres:

A configuração dos modelos de veículos (Vehicle) e pedestres (Pedestrian) envolve a definição de características individuais, como identificação, posição inicial, comportamento de mobilidade, tecnologia de comunicação empregada (Wi-Fi) e padrões de comportamento.

### Criação de Aplicativos para Envio e Recebimento de Pacotes:

São implementados aplicativos específicos para possibilitar a troca de mensagens entre veículos e pedestres. Esses aplicativos, baseados no protocolo de eco UDP, estabelecem a comunicação de pacotes de ping para avaliar a conectividade e latência entre os nós.

- `UdpEchoClientHelper echoClientHelper(serverIp, serverPort);`: Criação de um cliente de eco UDP para enviar pacotes de ping para um servidor (pedestre).
- `ApplicationContainer clientApps = echoClientHelper.Install(vehicles.Get(i));`: Instalação do cliente de eco UDP em cada veículo.
- Criação de um servidor de eco UDP no pedestre usando `PacketSinkHelper`.

### Registro da Função de Retorno de Chamada:

A função de retorno de chamada é registrada para monitorar e processar os pacotes recebidos. Essa função captura os pacotes de ping recebidos pelos nós alvo da simulação e realiza a análise necessária para entender o comportamento da comunicação.

- `Config::ConnectWithoutContext("/NodeList/*/ApplicationList/*/$ns3::PacketSink/Rx", MakeCallback(&ReceivePacket));`: Registro da função de retorno de chamada `ReceivePacket` para lidar com pacotes recebidos.

## Semana 3: Análise dos Resultados e Conclusão

Durante as duas semanas de trabalho com o NS-3 para simular a comunicação V2P (Vehicle-to-Pedestrian), foram estudados vários conceitos e técnicas relacionados à simulação de redes veiculares e à implementação de modelos básicos no NS-3. Conclusão sobre o que foi aprendido:

### Conceitos básicos do V2P e redes veiculares

Foi realizada uma revisão bibliográfica para compreender os conceitos básicos do V2P e das redes veiculares. O V2P é uma tecnologia que permite a comunicação entre veículos e pedestres, melhorando a segurança nas estradas e criando novas aplicações para carros autônomos.

### Uso do NS-3 como simulador de rede

O NS-3 foi utilizado como simulador de rede de código aberto para simular a comunicação V2P. O NS-3 é uma ferramenta valiosa para pesquisadores e desenvolvedores que desejam estudar e desenvolver novas tecnologias para redes veiculares.

### Implementação de modelos básicos no NS-3

Foram implementados modelos básicos para representar veículos e pedestres no ambiente de simulação do NS-3. Esses modelos simplificados focaram na comunicação essencial do V2P e permitiram analisar como a comunicação V2P pode impactar e ser afetada pelo comportamento dos atores envolvidos na simulação.

### Configuração da mobilidade dos veículos e pedestres

Foi configurada a mobilidade dos veículos e pedestres no ambiente de simulação. Foi utilizado um modelo de mobilidade constante (`ConstantVelocityMobilityModel`) para os veículos e pedestres se moverem.

### Configuração dos parâmetros Wi-Fi e do canal de comunicação

Foram configurados os parâmetros Wi-Fi, especificamente o protocolo 802.11n, e o canal de comunicação. Isso permitiu simular a comunicação sem fio entre os veículos e pedestres.

### Simulação da comunicação V2P

Foi simulada a comunicação V2P entre um veículo e um pedestre. Foram registradas funções de retorno de chamada para lidar com os pacotes recebidos. Essa simulação inicial permitiu entender como a comunicação básica V2P pode ser realizada no NS-3.

Em resumo, durante as duas primeiras semanas de trabalho com o NS-3 para simular o cenário de comunicação V2P, foram aprendidos os conceitos básicos do V2P e redes veiculares, a utilização do NS-3 como simulador de rede, a implementação de modelos básicos no NS-3, a configuração da mobilidade e dos parâmetros de comunicação, e a simulação da comunicação V2P. Esses conhecimentos são fundamentais para o desenvolvimento e estudo de tecnologias de comunicação veicular.

## Simulação

O processo de simulação é executado, levando em consideração as configurações e elementos previamente estabelecidos. Durante a simulação, os veículos e pedestres interagem de acordo com os modelos de mobilidade e comunicação definidos, permitindo observar e analisar os resultados obtidos. Ao final, a simulação é encerrada e os resultados são consolidados para avaliação e conclusão do experimento.

- `Simulator::Run();` e `Simulator::Destroy();`: execução e término da simulação.

## Conclusão

Essa implementação demonstra um cenário simples onde dois veículos e um pedestre estão se comunicando usando pacotes de ping através de uma rede Wi-Fi. Os veículos enviam pacotes de ping para o pedestre, que responde aos pacotes. A função de retorno de chamada `ReceivePacket` imprime informações sobre os pacotes recebidos. Isso representa uma simulação inicial da comunicação básica V2P no NS-3, conforme planejado na metodologia do projeto.

