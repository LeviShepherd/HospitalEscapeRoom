#include "elevatorroom.h"
#include <iostream>

ElevatorRoom::ElevatorRoom()
{

}

void ElevatorRoom::describeRoom(){ // print out room description
    cout << "You spot an open elevator and make your way to it."
            "You try to hit the lobby button but the doors won't close."
            "You see a keypad under the elevator buttons and realize this is an employee elevator."
            "Looks like you will need to enter an access code to use this elevator."
            "On the floor of the elevator you see files scattered and a lab coat." << endl;
};
void ElevatorRoom::investigateItems(){
    string input = "";
    bool codeEntered = false;
    while (!codeEntered) {
        cout << "What would you like to do?" << endl;
        cout << "1) Investigate the scattered files" << endl;
        cout << "2) Search through lab coat" << endl;
        cout << "3) Enter access code" << endl;

        cout << "Enter number selection: " << endl;
        getline(cin, input);

        if (input == "1"){
            cout << "You riffle through the papers scattered on the ground and they are all files on patients."
            "Nothing seems to pertain to the elevator." << endl;
        }
        else if (input == "2"){
            cout << "You search through the lab-coat and find an employee badge and a sticky note with the"
                 " numbers 7384 written on it." << endl;
        }
        else if (input == "3"){
            cout << "Enter code: " << endl;
            getline(cin, input);
            if (input == "7384") {
                codeEntered = true;
            }
            else {
                cout << "You enter the code and the keypad screen flashes red. "
                        "Looks like you need to look around some more." << endl;
            }
        }
        else {
           cout << "Invalid selection, try again." << endl;
        }
    }

};
void ElevatorRoom::exitRoom(){
    cout << "You enter in the code and the keypad screen flashes green. "
            "You hit the button for the main lobby and sigh with relief as the elevator doors close. " << endl;
};
void ElevatorRoom::execute(){
    describeRoom();
    investigateItems();
    exitRoom();
};
