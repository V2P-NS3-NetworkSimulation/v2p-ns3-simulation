#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <string>
#include <vector>

class Behavior {
public:
    Behavior();
    Behavior(const std::string& type, const std::vector<double>& parameters);
    ~Behavior();

    std::string GetType() const;
    void SetType(const std::string& type);

    std::vector<double> GetParameters() const;
    void SetParameters(const std::vector<double>& parameters);

private:
    std::string type;
    std::vector<double> parameters;
};

#endif // BEHAVIOR_H
