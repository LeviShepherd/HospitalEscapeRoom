#include "psychwardroom.h"
#include <iostream>

// Author: Levi Shepherd

PsychWardRoom::PsychWardRoom()
{
    playerName = "Player";
    keycard = false;
}

PsychWardRoom::PsychWardRoom(string player)
{
    playerName = player;
    keycard = false;
}

string PsychWardRoom::getPlayerName() const{
    return playerName;
}

void PsychWardRoom::setPlayerName(string player){
    this->playerName = player;
}

void PsychWardRoom::getPlayerChoice(){
    string playerChoice = "";
    bool exit = false;

    cout << playerName << " you're faced with a decision, left, right, or forward." << endl;

    while(exit != true){
        cout << "What is your decision? ";
        cin >> playerChoice;
        if((playerChoice == "left") || (playerChoice == "Left")){
            exit = true;
            this->goLeft();
        }
        else if((playerChoice == "right") || (playerChoice == "Right")){
            exit = true;
            this->goRight();
        }
        else if((playerChoice == "forward") || (playerChoice == "Forward")){
            exit = true;
            this->goForward();
        }
        else {
            cout << "Invalid selection, please choose left, right or forward." << endl;
        }
    }
}

void PsychWardRoom::getOfficeChoice(){
    string officeChoice = "";
    bool exit = false;

    cout << playerName << " you're met with another decision. Do you wish to check the cabinet, drawer, or bin?" << endl;
    while(exit != true){
        cout << "What is your dicision? ";
        cin >> officeChoice;
        if((officeChoice == "cabinet") || (officeChoice == "Cabinet")){
            cout << "Digging through the cabinet you find a small card under some medical records.." << endl;
            cout << "Reading the card you see the name 'Dr. Strange' but the picture on the card seems blurred out." << endl;
            cout << "Flipping the card over you see there is a sort of barcode strip, a keycard ID maybe?" << endl;
            this->keycard = true;
            exit = true;
        }
        else if((officeChoice == "drawer") || (officeChoice == "Drawer")){
            cout << "You find a note scribbled on a scrap of paper.." << endl;
            cout << "The note reads: Employees should only use the hallway entry and avoid using the ER doorway!" << endl;
            cout << "This could be a clue.." << endl;
        }
        else if((officeChoice == "bin") || (officeChoice == "Bin")){
            cout << "You find nothing of value.. unless you value trash?" << endl;
        }
        else {
            cout << "Invalid selection, please choose cabinet, drawer or bin." << endl;
        }
    }

    cout << "Feeling you've found all you could find, you head back to the check-in area." << endl;
    this->getPlayerChoice();
}

void PsychWardRoom::showRoomStory(){
    cout << "Exiting the dark ER through the double doors you begin to gather your surroundings." << endl;
    cout << "The air around you is cool and damp, there is total silence throughout the area." << endl;
    cout << endl;
    cout << "Slowly you make your way towards what seems to be a check-in area and notice a map of the area." << endl;
    cout << "From the map you take note of the ER where you came from, to the left is a holding area." << endl;
    cout << "To your front lies an opening with various smaller rooms and to the right is a hallway." << endl;
    cout << endl;
    cout << "After peering at the map you hear a bone-chilling scream from what seems to be the holding area." << endl;
    cout << "There's a sound like pans hitting the floor coming from the area ahead of you." << endl;
    cout << endl;
    this->getPlayerChoice();
}

void PsychWardRoom::goLeft(){
    cout << "You make your way towards the sound of screams (Are you CRAZY??) and stop short of a door" << endl;
    cout << "Above the door hangs a sign reading: Holding Cell 1 DO NOT OPEN" << endl;
    cout << "You begin to wonder to yourself.. What is inside?" << endl;
    cout << "While trying to look into the small window something grabs you from behind!" << endl;
    cout << "You feel a stinging pain from behind your neck, slowly the area grows dark and you collapse.." << endl;
    cout << "You awaken back to the check-in area, forgetting what happened before.." << endl;
    this->getPlayerChoice();

}

void PsychWardRoom::goRight(){
    cout << "You approach the hallway, dimly lit with few lights flickering in the distance." << endl;
    cout << "As you creep forward there's a door at the end of the hallway." << endl;
    cout << "'Employees Only' the sign on the door reads.  There is a terminal next to the door." << endl;
    cout << "Looking at the terminal it seems to still be working.  The terminal asks for you to insert a keycard." << endl;
    if(keycard){
        cout << "Digging into your pocket you retrieve the keycard and insert it into the terminal." << endl;
        cout << "The terminal glows green and you hear a faint chime.  The terminal now reads: OPEN" << endl;
        cout << "You grab the door handle, pulling the door open and step inside." << endl;
        this->exitRoom();
    } else {
        cout << "You reach into your pockets- empty.  Looks like it's time to find another way." << endl;
        cout << "Perhaps you can find a keycard in here somewhere.." << endl;
        this->getPlayerChoice();
    }
}

void PsychWardRoom::goForward(){
    cout << "Remembering the sounds of pans hitting the floor, you move into the area ahead." << endl;
    cout << "The room ahead of you looks to be a small lounge area or breakroom with a small kitchen." << endl;
    cout << "There are pots and pans strung out around the cabinets and blood in the sink, gross!" << endl;
    cout << "It looks as though there are offices to the left of the kitchen, there seems to be nothing else around." << endl;
    cout << "You make your way into the first office you find. 'Dr. Strange' the nameplate reads on the large oak desk." << endl;
    cout << "There appears to be many things which could hold a clue for a way out of here." << endl;
    cout << endl;
    cout << "In the office you notice a filing cabinet, the desk drawer, and a small metal trash bin." << endl;
    this->getOfficeChoice();
}

void PsychWardRoom::exitRoom(){
    // To-Do
}

void PsychWardRoom::execute(){
    showRoomStory();
    exitRoom();
}
