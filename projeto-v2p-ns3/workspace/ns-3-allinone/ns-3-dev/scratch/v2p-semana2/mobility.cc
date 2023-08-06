// mobility.cpp
#include "mobility.h"

Mobility::Mobility() : speed(0.0), acceleration(0.0), direction(0.0) {}

Mobility::Mobility(double speed, double acceleration, double direction)
    : speed(speed), acceleration(acceleration), direction(direction) {}

Mobility::~Mobility() {}

double Mobility::GetSpeed() const {
    return speed;
}

void Mobility::SetSpeed(double speed) {
    this->speed = speed;
}

double Mobility::GetAcceleration() const {
    return acceleration;
}

void Mobility::SetAcceleration(double acceleration) {
    this->acceleration = acceleration;
}

double Mobility::GetDirection() const {
    return direction;
}

void Mobility::SetDirection(double direction) {
    this->direction = direction;
}