// communication.h
#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string>

/*
    V2P-Simulation 0.0.1 25/07/2023
*/
class Communication {
public:
    Communication();
    Communication(
        const std::string& type,
        double frequency,
        double range
    );
    ~Communication();

    std::string GetType() const;
    void SetType(const std::string& type);

    double GetFrequency() const;
    void SetFrequency(double frequency);

    double GetRange() const;
    void SetRange(double range);

private:
    std::string type;
    double frequency;
    double range;
};

#endif // COMMUNICATION_H
