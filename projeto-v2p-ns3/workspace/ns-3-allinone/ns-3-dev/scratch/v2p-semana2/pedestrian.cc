// pedestrian.cpp
#include "pedestrian.h"
#include "vector2d.h"
#include "vehicle.h"

Pedestrian::Pedestrian() : id(0) {}

Pedestrian::Pedestrian(int id, double x, double y, double speed, double acceleration, double direction)
    : id(id), position(x, y), mobilityModel(speed, acceleration, direction) {}

int Pedestrian::GetId() const {
    return id;
}

void Pedestrian::SetId(int id) {
    this->id = id;
}

Vector2d Pedestrian::GetPosition() const {
    return position;
}

void Pedestrian::SetPosition(const Vector2d& position) {
    this->position = position;
}

Communication Pedestrian::GetCommunicationModel() const {
    return communicationModel;
}

void Pedestrian::SetCommunicationModel(const Communication& communicationModel) {
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
    printf("O Pedestre de id %d está comunicando com o Veículo de id %d.\n", this->id, vehicle.GetId());
    printf("__________________\n");

    printf("O Veículo de id %d:\nlane: %d; x: %.2lf, y: %.2lf, speed: %.2lf, acceleration: %.2lf, direction: %.2lf\n",
        vehicle.GetId(),
        vehicle.GetLane(),
        vehicle.GetPosition().x,
        vehicle.GetPosition().y,
        vehicle.GetMobilityModel().GetSpeed(),
        vehicle.GetMobilityModel().GetAcceleration(),
        vehicle.GetMobilityModel().GetDirection()
    );
    printf("__________________\n");

    printf("O Pedestre de id %d:\nx: %.2lf, y: %.2lf, speed: %.2lf, acceleration: %.2lf, direction: %.2lf\n",
        this->id,
        this->GetPosition().x,
        this->GetPosition().y,
        this->GetMobilityModel().GetSpeed(),
        this->GetMobilityModel().GetAcceleration(),
        this->GetMobilityModel().GetDirection()
    );
    printf("__________________\n");
}