// mobility.h
#ifndef MOBILITY_H
#define MOBILITY_H

class Mobility {
public:
    Mobility();
    Mobility(double speed, double acceleration, double direction);
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
