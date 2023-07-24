#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <string>
#include "behavior.h"
#include "mobility.h"
#include "communication.h"
#include "Vector2D.h"

class Vehicle; // Forward declaration of Vehicle

class Pedestrian {
public:
    Pedestrian();
    Pedestrian(int id, double x, double y, double speed, double acceleration, double direction);

    int GetId() const;
    void SetId(int id);

    Vector2D GetPosition() const;
    void SetPosition(const Vector2D& position);

    Communication GetCommunicationModel() const;
    void SetCommunicationModel(const Communication& communicationModel);

    Mobility GetMobilityModel() const;
    void SetMobilityModel(const Mobility& mobilityModel);

    Behavior GetBehavior() const;
    void SetBehavior(const Behavior& behavior);

    void Communicate(Vehicle& vehicle);

private:
    int id;
    Vector2D position;
    Communication communicationModel;
    Mobility mobilityModel;
    Behavior behavior;
};

#endif // PEDESTRIAN_H
