#include "vehicle.h"
#include "Vector2D.h"
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

Vector2D Vehicle::GetPosition() const {
    return position;
}

void Vehicle::SetPosition(const Vector2D& position) {
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
    printf(
        "Vehicle with id %d is communicating with Pedestrian with id %d.\n",
        this->id,
        pedestrian.GetId()
    );
}
