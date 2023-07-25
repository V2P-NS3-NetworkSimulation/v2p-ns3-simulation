// main.cpp
#include "ns3/core-module.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
#include "vehicle.h"
#include "pedestrian.h"

using namespace ns3;

/*
    V2P-Simulation 0.0.1 25/07/2023
*/
int main (int argc, char *argv[]) {
    printf("Aqui 1\n");

    // LogComponentEnable("pedestrian", LOG_LEVEL_INFO);
    // LogComponentEnable("vehicle", LOG_LEVEL_INFO);

    // Criar nós
    NodeContainer vehicles;
    vehicles.Create(1);
    NodeContainer pedestrians;
    pedestrians.Create(1);

    // Definir modelos de mobilidade
    MobilityHelper mobility;
    Ptr<ListPositionAllocator> positionAlloc
        = CreateObject<ListPositionAllocator>();
    positionAlloc->Add(Vector(0.0, 0.0, 0.0));
    positionAlloc->Add(Vector(100.0, 0.0, 0.0)); // Veículos e pedestres estão a 100 metros de distância
    mobility.SetPositionAllocator(positionAlloc);
    mobility.SetMobilityModel(
        "ns3::ConstantPositionMobilityModel"
    );
    mobility.Install(vehicles);
    mobility.Install(pedestrians);

    // Configure a comunicação V2P entre o veículo e o pedestre
    Vehicle vehicle(1, 0, 0.0, 0.0, 0.0, 0.0, 0.0);
    Pedestrian pedestrian(1, 0.0, 10.0, 0.0, 0.0, 0.0);
    vehicle.Communicate(pedestrian);

    // Criar objeto de animação
    AnimationInterface anim("v2p-simulation.xml");

    Simulator::Run();
    Simulator::Destroy();

    printf("Aqui 2\n");

    return 0;
}
