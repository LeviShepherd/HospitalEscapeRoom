#ifndef ELEVATORROOM_H
#define ELEVATORROOM_H

#include <string>
using namespace std;

class ElevatorRoom
{
private:
    void describeRoom(); // print out room description
    void investigateItems();
    void exitRoom();

public:
    void execute();
    ElevatorRoom();
};

#endif // ELEVATORROOM_H
