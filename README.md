# Projeto - V2P - NS-3 - Semana 1

## Revisão Bibliográfica
Realizar uma revisão rápida da literatura para compreender os conceitos básicos do V2P, redes veiculares, NS-3 e acesso Non-3GPP.

#### V2X (Vehicle-to-Everything):
V2X, ou comunicação veículo-a-tudo (Vehicle-to-Everything), é uma tecnologia que permite que os veículos se comuniquem uns com os outros, com a infraestrutura de estradas e com outros dispositivos. Isso pode ser feito usando uma variedade de métodos, incluindo Wi-Fi, Bluetooth e ondas de rádio.
O V2X tem o potencial de melhorar a segurança nas estradas, permitindo que os veículos se comuniquem uns com os outros e com a infraestrutura da estrada sobre potenciais riscos. Isso pode ajudar a prevenir acidentes, melhorar a eficiência do tráfego e criar novas aplicações para carros autônomos.
Alguns dos benefícios potenciais do V2X incluem:
#### Redução de acidentes:
o V2X pode ajudar a reduzir acidentes permitindo que os veículos se comuniquem uns com os outros e com a infraestrutura da estrada sobre potenciais riscos. Por exemplo, um carro pode usar V2V para enviar um aviso a outro carro que está prestes a mudar de faixa na frente dele.
#### Melhoria da eficiência do tráfego:
o V2X pode ajudar a melhorar a eficiência do tráfego permitindo que os veículos se comuniquem uns com os outros e com a infraestrutura da estrada sobre as condições do tráfego. Isso pode ajudar a evitar congestionamentos e melhorar o fluxo do tráfego.
#### Criação de novas aplicações para carros autônomos:
o V2X é um componente essencial para carros autônomos. Os carros autônomos precisam ser capazes de se comunicar uns com os outros e com a infraestrutura da estrada para navegar com segurança nas estradas.

#### V2P (Vehicle-to-Pedestrian):
é uma tecnologia que permite que veículos se comuniquem com pedestres. Isso pode ser feito usando uma variedade de métodos, incluindo Wi-Fi, Bluetooth e ondas de rádio. O V2P tem o potencial de melhorar a segurança nas estradas, permitindo que os veículos se comuniquem uns com os outros e com pedestres sobre potenciais riscos. Por exemplo, um carro pode usar V2P para enviar um aviso a um pedestre que está prestes a atravessar a rua na frente dele.
#### Redes veiculares:
são redes de comunicação projetadas especificamente para veículos. Essas redes podem ser usadas para uma variedade de propósitos, incluindo comunicação V2V (Vehicle-to-Vehicle), comunicação V2I (Vehicle-to-Infrastructure) e comunicação V2P (Vehicle-to-Pedestrian). As redes veiculares podem ser baseadas em uma variedade de tecnologias, incluindo 3GPP (3rd Generation Partnership Project), LTE (Long Term Evolution) e 5G (5th Generation). As redes veiculares são necessárias para permitir que os veículos se comuniquem uns com os outros e com a infraestrutura da estrada em tempo real. Isso pode ajudar a prevenir acidentes, melhorar a eficiência do tráfego e criar novas aplicações para carros autônomos.
#### NS-3 (Network Simulator 3):
é um simulador de rede de código aberto. O NS-3 pode ser usado para simular uma variedade de redes, incluindo redes veiculares. O NS-3 é uma ferramenta valiosa para pesquisadores e desenvolvedores que desejam estudar e desenvolver novas tecnologias para redes veiculares. O NS-3 pode ser usado para simular uma variedade de cenários, incluindo tráfego de veículos, comunicação V2V e V2I, e segurança em redes veiculares.
#### Acesso Non-3GPP:
é um termo usado para descrever as formas de acesso à rede que não são baseadas na especificação 3GPP. O acesso Non-3GPP pode ser usado para uma variedade de propósitos, incluindo V2P, V2V e V2I. O acesso Non-3GPP pode ser baseado em uma variedade de tecnologias, incluindo Wi-Fi, Bluetooth e ondas de rádio. O acesso Non-3GPP tem o potencial de fornecer uma série de vantagens sobre o acesso 3GPP, incluindo maior largura de banda, menor latência e maior eficiência energética.

Desenvolvimento de Modelos V2P Simplificados
Implementar modelos básicos para representar veículos e pedestres no ambiente de simulação do NS-3. Os modelos serão simplificados para focar na comunicação essencial do V2P.
Objetivos da simulação.
#### Estudar o impacto da comunicação V2P na segurança viária;
Avaliar o desempenho de diferentes tecnologias de comunicação V2P;
Fornecer insights preliminares sobre o desempenho dessa comunicação em redes veiculares.
#### O que estamos tentando alcançar com a simulação?
Estamos tentando estudar o impacto da comunicação V2P na segurança viária. Acreditamos que a comunicação V2P pode ajudar a melhorar a segurança viária de várias maneiras. Por exemplo, os veículos podem trocar informações sobre sua localização e velocidade com os pedestres, o que pode ajudar a prevenir acidentes.

#### Estamos tentando estudar o impacto da comunicação V2P na segurança viária?
Estamos tentando avaliar o desempenho de diferentes tecnologias de comunicação V2P. Existem muitas tecnologias diferentes de comunicação V2P disponíveis, e é importante avaliar o desempenho de cada uma para determinar qual é a melhor para uma determinada aplicação.
#### Estamos tentando avaliar o desempenho de diferentes tecnologias de comunicação V2P?
Estamos tentando fornecer insights preliminares sobre o desempenho da comunicação V2P em redes veiculares. A comunicação V2P é uma tecnologia relativamente nova, e ainda há muito que não sabemos sobre seu desempenho em redes veiculares. Acreditamos que nossa simulação pode ajudar a fornecer insights preliminares sobre o desempenho da comunicação V2P em redes veiculares, o que pode ser usado para melhorar o design e o desenvolvimento de sistemas V2P.
O ambiente de simulação.
NS-3, um simulador de rede de código aberto, que pode ser usado para simular uma variedade de redes, em uma variedade de cenários.

## Implementação dos modelos V2P.
Desenvolver os módulos que representam os veículos e pedestres na simulação.
Criando classes específicas para cada entidade e definindo suas características de comunicação, mobilidade e comportamentos.

Criando classes específicas para cada entidade.
Cada entidade (veículo ou pedestre) deve ter sua própria classe.
Essa classe deve conter as características de comunicação, mobilidade e comportamento da entidade.

cd scratch/v2p-simulation
./ns3 build
./ns3 run scratch/v2p-simulation/main -- --log=pedestrian:debug --log=vehicle:debug
ou
./ns3 run scratch/v2p-simulation/main




A pasta scratch é uma pasta padrão do ns-3 onde você pode colocar seus códigos de simulação. É uma boa ideia usar essa pasta para que você possa manter seus códigos de simulação separados dos códigos do ns-3.

Implementado:
Vehicle.cpp
Pedestrian.cpp



Definindo as características de comunicação das entidades.
Isso inclui o tipo de tecnologia de comunicação que a entidade usa, a frequência de comunicação e o alcance de comunicação.


Definindo as características de mobilidade das entidades.
Isso inclui a velocidade, a aceleração e o rumo da entidade.

Definindo os comportamentos das entidades.
Isso inclui como a entidade reage a diferentes eventos, como colisões, obstáculos e mudanças de tráfego.

Os comportamentos das entidades podem ser personalizados para atender às suas necessidades específicas. Por exemplo, você pode definir um comportamento que faça um pedestre evitar obstáculos ou um comportamento que faça um veículo reduzir a velocidade em uma interseção.

Depois de implementar os modelos V2P, eles podem ser usados para simular a comunicação entre veículos e pedestres em um cenário. A simulação pode ser usada para estudar o impacto da comunicação V2P na segurança viária e para avaliar o desempenho de diferentes tecnologias de comunicação V2P.



Configurando os parâmetros dos modelos.
Com os modelos V2P implementados, é necessário configurar os parâmetros relevantes para a simulação. Isso pode incluir o número de veículos e pedestres no cenário, velocidades iniciais, posições iniciais, padrões de mobilidade, potência de transmissão, alcance de comunicação, entre outros.
Executando a simulação e analisando os resultados.
Agora, você pode executar a simulação com os modelos V2P e os cenários de teste definidos. Após a conclusão da simulação, é importante analisar os resultados para verificar se os requisitos de comunicação essenciais estão sendo atendidos e se o desempenho é satisfatório.
