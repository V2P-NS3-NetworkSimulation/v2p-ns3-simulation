#include "ns3/core-module.h"
#include "ns3/mobility-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
#include "vehicle.h"
#include "pedestrian.h"

using namespace ns3;

int main (int argc, char *argv[]) {
    printf("Aqui 1\n");

    // LogComponentEnable("pedestrian", LOG_LEVEL_INFO);
    // LogComponentEnable("vehicle", LOG_LEVEL_INFO);

    // Create nodes
    NodeContainer vehicles;
    vehicles.Create(1);
    NodeContainer pedestrians;
    pedestrians.Create(1);

    // Set mobility models
    MobilityHelper mobility;
    Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator>();
    positionAlloc->Add(Vector(0.0, 0.0, 0.0));
    positionAlloc->Add(Vector(100.0, 0.0, 0.0)); // Vehicles and pedestrians are 100 meters apart
    mobility.SetPositionAllocator(positionAlloc);
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(vehicles);
    mobility.Install(pedestrians);

    // Set up V2P communication between vehicle and pedestrian
    Vehicle vehicle(1, 0, 0.0, 0.0, 0.0, 0.0, 0.0);
    Pedestrian pedestrian(1, 0.0, 10.0, 0.0, 0.0, 0.0);
    vehicle.Communicate(pedestrian);

    // Create animation object
    AnimationInterface anim("v2p-simulation.xml");

    Simulator::Run();
    Simulator::Destroy();

    printf("Aqui 2\n");

    return 0;
}
