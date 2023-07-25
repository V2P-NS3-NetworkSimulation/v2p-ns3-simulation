// behavior.cpp
#include "behavior.h"

/*
    V2P-Simulation 0.0.1 25/07/2023
*/
Behavior::Behavior() {}

Behavior::Behavior(
    const std::string& type,
    const std::vector<double>& parameters
)
    : type(type), parameters(parameters) {}

Behavior::~Behavior() {}

std::string Behavior::GetType() const {
    return type;
}

void Behavior::SetType(const std::string& type) {
    this->type = type;
}

std::vector<double> Behavior::GetParameters() const {
    return parameters;
}

void Behavior::SetParameters(
    const std::vector<double>& parameters
) {
    this->parameters = parameters;
}
