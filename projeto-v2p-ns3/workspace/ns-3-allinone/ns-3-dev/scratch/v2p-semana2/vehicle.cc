// vehicle.cpp
#include "vehicle.h"
#include "vector2d.h"
#include "pedestrian.h"

Vehicle::Vehicle() : id(0), lane(0) {}

Vehicle::Vehicle(int id, int lane, double x, double y, double speed, double acceleration, double direction)
    : id(id), lane(lane), position(x, y), mobilityModel(speed, acceleration, direction) {}

int Vehicle::GetId() const {
    return id;
}

void Vehicle::SetId(int id) {
    this->id = id;
}

int Vehicle::GetLane() const {
    return lane;
}

void Vehicle::SetLane(int lane) {
    this->lane = lane;
}

Vector2d Vehicle::GetPosition() const {
    return position;
}

void Vehicle::SetPosition(const Vector2d& position) {
    this->position = position;
}

Communication Vehicle::GetCommunicationModel() const {
    return communicationModel;
}

void Vehicle::SetCommunicationModel(const Communication& communicationModel) {
    this->communicationModel = communicationModel;
}

Mobility Vehicle::GetMobilityModel() const {
    return mobilityModel;
}

void Vehicle::SetMobilityModel(const Mobility& mobilityModel) {
    this->mobilityModel = mobilityModel;
}

Behavior Vehicle::GetBehavior() const {
    return behavior;
}

void Vehicle::SetBehavior(const Behavior& behavior) {
    this->behavior = behavior;
}

void Vehicle::Communicate(Pedestrian& pedestrian) {
    printf("O Veículo de id %d está comunicando com o Pedestre de id %d.\n", this->id, pedestrian.GetId());
    printf("__________________\n");

    printf("O Veículo de id %d:\nlane: %d; x: %.2lf, y: %.2lf, speed: %.2lf, acceleration: %.2lf, direction: %.2lf\n",
        this->id,
        this->GetLane(),
        this->GetPosition().x,
        this->GetPosition().y,
        this->GetMobilityModel().GetSpeed(),
        this->GetMobilityModel().GetAcceleration(),
        this->GetMobilityModel().GetDirection()
    );
    printf("__________________\n");

    printf("O Pedestre de id %d:\nx: %.2lf, y: %.2lf, speed: %.2lf, acceleration: %.2lf, direction: %.2lf\n",
        pedestrian.GetId(),
        pedestrian.GetPosition().x,
        pedestrian.GetPosition().y,
        pedestrian.GetMobilityModel().GetSpeed(),
        pedestrian.GetMobilityModel().GetAcceleration(),
        pedestrian.GetMobilityModel().GetDirection()
    );
    printf("__________________\n");
}
