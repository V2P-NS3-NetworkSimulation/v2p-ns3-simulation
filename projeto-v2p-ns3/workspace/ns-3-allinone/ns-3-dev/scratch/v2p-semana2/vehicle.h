// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "behavior.h"
#include "mobility.h"
#include "communication.h"
#include "vector2d.h"

class Pedestrian; // Forward declaration of Pedestrian

class Vehicle {
public:
    Vehicle();
    Vehicle(int id, int lane, double x, double y, double speed, double acceleration, double direction);

    int GetId() const;
    void SetId(int id);

    int GetLane() const;
    void SetLane(int lane);

    Vector2d GetPosition() const;
    void SetPosition(const Vector2d& position);

    Communication GetCommunicationModel() const;
    void SetCommunicationModel(const Communication& communicationModel);

    Mobility GetMobilityModel() const;
    void SetMobilityModel(const Mobility& mobilityModel);

    Behavior GetBehavior() const;
    void SetBehavior(const Behavior& behavior);

    void Communicate(Pedestrian& pedestrian);

private:
    int id;
    int lane;
    Vector2d position;
    Communication communicationModel;
    Mobility mobilityModel;
    Behavior behavior;
};

#endif // VEHICLE_H