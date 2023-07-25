// mobility.h
#ifndef MOBILITY_H
#define MOBILITY_H

/*
    V2P-Simulation 0.0.1 25/07/2023
*/
class Mobility {
public:
    Mobility();
    Mobility(
        double speed,
        double acceleration,
        double direction
    );
    
    ~Mobility();

    double GetSpeed() const;
    void SetSpeed(double speed);

    double GetAcceleration() const;
    void SetAcceleration(double acceleration);

    double GetDirection() const;
    void SetDirection(double direction);

private:
    double speed;
    double acceleration;
    double direction;
};

#endif // MOBILITY_H
