#ifndef PSYCHWARDROOM_H
#define PSYCHWARDROOM_H

// Author: Levi Shepherd

#include <string>
using namespace std;

class PsychWardRoom
{
private:
    string playerName;
    bool keycard;
public:
    PsychWardRoom();
    PsychWardRoom(string player);

    void setPlayerName(string player);
        string getPlayerName() const;
    void getPlayerChoice();
    void getOfficeChoice();
    void showRoomStory();
    void goLeft();
    void goRight();
    void goForward();
    void exitRoom();
    void execute();
};

#endif // PSYCHWARDROOM_H
