#include "communication.h"

Communication::Communication() : frequency(0.0), range(0.0) {}

Communication::Communication(const std::string& type, double frequency, double range)
    : type(type), frequency(frequency), range(range) {}

Communication::~Communication() {}

std::string Communication::GetType() const {
    return type;
}

void Communication::SetType(const std::string& type) {
    this->type = type;
}

double Communication::GetFrequency() const {
    return frequency;
}

void Communication::SetFrequency(double frequency) {
    this->frequency = frequency;
}

double Communication::GetRange() const {
    return range;
}

void Communication::SetRange(double range) {
    this->range = range;
}
