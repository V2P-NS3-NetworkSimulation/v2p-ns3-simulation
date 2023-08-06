// pedestrian.cpp
#include "pedestrian.h"
#include "vector2d.h"
#include "vehicle.h"

/*
    V2P-Simulation 0.0.1 25/07/2023
*/
Pedestrian::Pedestrian() : id(0) {}

Pedestrian::Pedestrian(
    int id,
    double x,
    double y,
    double speed,
    double acceleration,
    double direction
) : id(id), position(x, y), mobilityModel(
    speed,
    acceleration,
    direction
) {}

int Pedestrian::GetId() const {
    return id;
}

void Pedestrian::SetId(int id) {
    this->id = id;
}

Vector2D Pedestrian::GetPosition() const {
    return position;
}

void Pedestrian::SetPosition(const Vector2D& position) {
    this->position = position;
}

Communication Pedestrian::GetCommunicationModel() const {
    return communicationModel;
}

void Pedestrian::SetCommunicationModel(
    const Communication& communicationModel
) {
    this->communicationModel = communicationModel;
}

Mobility Pedestrian::GetMobilityModel() const {
    return mobilityModel;
}

void Pedestrian::SetMobilityModel(const Mobility& mobilityModel) {
    this->mobilityModel = mobilityModel;
}

Behavior Pedestrian::GetBehavior() const {
    return behavior;
}

void Pedestrian::SetBehavior(const Behavior& behavior) {
    this->behavior = behavior;
}

void Pedestrian::Communicate(Vehicle& vehicle) {
    printf("O Pedestre de id %d está comunicando com o Pedestre de id %d.\n",
    this->id,
    vehicle.GetId()
);
}