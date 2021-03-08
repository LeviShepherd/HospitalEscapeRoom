//
// Created by Ty Hobbs on 2/14/21.
//

#ifndef ORESCAPE_ORROOM_H
#define ORESCAPE_ORROOM_H

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class OperatingRoom {
private:
    string playerName;

public:
    OperatingRoom();
    OperatingRoom(string pName){
        playerName = pName;
    };


    void setPlayerName(string playerName);
    string getPlayerName() const;

    void showRoomStory();

    void unlockFromTable();

    void freeFromIVPump();

    void exitRoom();
    
    void execute();
};


#endif //ORESCAPE_ORROOM_H
