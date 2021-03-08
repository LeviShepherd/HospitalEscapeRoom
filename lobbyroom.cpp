#include "lobbyroom.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include<unistd.h> // for unix sleep
//#include<windows.h> // for windows sleep delay time function
#include <chrono> // used for clock and timing of game
#include <ctime>
#include <fstream>

// constructor
LobbyRoom::LobbyRoom(){}

// ==== setters ====
void LobbyRoom::setUi(string ui){
    this->ui = ui;
}

void LobbyRoom::setHasCleaningSupplies(bool hasCleaningSupplies){
    this->hasCleaningSupplies = hasCleaningSupplies;
}

void LobbyRoom::setHasCard(bool hasCard){
    this->hasCard = hasCard;
}

void LobbyRoom::setHasKey(bool hasKey){
    this->hasKey = hasKey;
}

void LobbyRoom::setUserTryCode(string userTryCode){
    this->userTryCode = userTryCode;
}

void LobbyRoom::setIsClean(bool isClean){
    this->isClean = isClean;
}

// ==== getters ====
string LobbyRoom::getUi(){
    return ui;
}
bool LobbyRoom::getHasCleaningSupplies(){
    return hasCleaningSupplies;
}
bool LobbyRoom::getHasCard(){
    return hasCard;
}
bool LobbyRoom::getHasKey(){
    return hasKey;
}
string LobbyRoom::getUserTryCode(){
    return userTryCode;
}
string LobbyRoom::getCorrectCode(){
    return correctCode;
}

bool LobbyRoom::getIsClean(){
    return isClean;
}


// ==== execute method to run room ====
void LobbyRoom::execute(){
    string ui = "0"; // local ui var
    cout << "\n Finally, you have made it to the lobby. Freedom is so close, but you are not out yet. As you adjust your eyes to the bright lights shining through the many small, square windows that line the top of each wall in the large lobby, you are able to make out a receptionist desk to your right and a utility closet to your left. Across the large waiting area filled with chairs, you see it. The door to the outside." << endl;
    
    //sleep(3);
    cout << "\n In this room, all yes or no questions can be answered by entering 1 or 2. OR by entering the number associated with a menu selection when one is presented.........\n" << endl;
    //sleep(1);
    while (true){ // loops like a mini main menu till user exits room
        cout << "\n What would you like to do? \n 1) Go to receptionist's desk  \n 2) Go to waiting area \n 3) Go to the utility closet door \n 4) Go to the door to the outside" << endl;

        if(cin.fail()){ // prevents an endless loop caused by bad past input
            cin.clear();
            cin.ignore();
        }
    
        cin >> ui;
        this->setUi(ui);
        
        if (this->getUi() == "1"){
            desk();
            this->setUi("0");
        }
        else if (this->getUi() == "2"){
            waitingArea();
            this->setUi("0");
        }
       else if (this->getUi() == "3"){
           closet();
           this->setUi("0");
        }
       else if (this->getUi() == "4"){
          exitDoor();
           if (hasKey == true){
               return; // returns to main
           }
        }
        else{
            cout << "\n Invalid selection else " << endl;
            this->setUi("0");
        }
    }
}

void LobbyRoom::desk(){
    string ui = "0"; // local ui var
    string tryCode = "1234"; // local var
    
    cout << "\n It looks like the computer at the desk is on... " << endl;

    sleep(1);

    while (true){
        cout << "\n Do you want to use the computer? (1 or 2)  "  << endl;

        if(cin.fail()){ // prevents an endless loop caused by bad past input
            cin.clear();
            cin.ignore();
        }
        cin >> ui;
        this->setUi(ui);

        if (this->getUi() == "1"){ // yes, user wants to look at computer
            cout << "\n ****** Computer Screen ******\n Enter employee passcode to log on: \n" << endl;
            
            if(cin.fail()){ // prevents an endless loop caused by bad past input
                cin.clear();
                cin.ignore();
            }
            
            cin >> tryCode; // the code that the user enters to try
            this->setUserTryCode(tryCode);

            if (this->getUserTryCode() == this->getCorrectCode()){ // prints 3D key if the code is correct
                cout << "\n Access Granted \n" << endl;
                sleep(1);
                
                if (this->getHasKey() == false){ // if the user has NOT already obtained the 3D key
                    this->setHasKey(true);
                    cout << "\n Look, the 3D printer attached to the computer has printed out a 3D key! \n" << endl;
                }
                else{ // if the user has already obtained the 3D key
                    cout << " \n You already have the 3D key!" << endl;
                }
            }
            else{
                cout << "\n Incorrect Code \n" << endl;
                sleep(1);
            }
        }
        else if (this->getUi() == "2"){ // no, the user does not want to use the computer
            while (true){
                this->setUi("0");
                cout << "\n There is nothing new here, would you like to try searching another area of the lobby? (1 or 2)" << endl;

                if(cin.fail()){ // prevents an endless loop caused by bad past input
                    cin.clear();
                    cin.ignore();
                }
                cin >> ui;
                this->setUi(ui);

                if (this->getUi() == "1"){
                    return; // return to start of loop in execute()
                }
                else if (this->getUi() == "2"){
                    break; // return to outer while loop
                }
                else{
                    cout << "\n Invalid selection " << endl;
                    this->setUi("0");
                }
            }
        }
        else{
            cout << "\n Invalid selection " << endl;
            this->setUi("0");
        }
    }
}

void LobbyRoom::waitingArea(){
    cout << "\n Most of the chairs in the room are covered in thick dust and look like they have not been used in some time. However, you see two chairs that look like the dust upon them has been recently disturbed." << endl;

    sleep(2);

    while (true){
        this->setUi("0");
        
        cout << "\n Would you like to take a closer look at the chairs? (1 or 2) "  << endl;

        if(cin.fail()){ // prevents an endless loop caused by bad past input
            cin.clear();
            cin.ignore();
        }
        cin >> ui;
        this->setUi(ui);

        if (this->getUi() == "1"){ // yes, look at chairs
            while (true){
                this->setUi("0");
                
                cout << "\n Which chair would you like to look at? (1 or 2...enter 0 to when you want to stop inspecting them) " << endl;

                if(cin.fail()){ // prevents an endless loop caused by bad past input
                    cin.clear();
                    cin.ignore();
                }
                cin >> ui;
                this->setUi(ui);

                if(this->getUi() == "0"){ // done looking at chairs
                    break;
                }

                else if (this->getUi() == "1"){ // look at chair 1
                    if (getHasCard() == false){ // if user NOT already found card
                        cout << "\n You see something sticking out from in between the chair seat and back cushions. You pick it up and see that it is a key card. I wonder if it opens anything....\n" << endl;
                        sleep(2);
                        setHasCard(true); // take card
                    }
                    else{  // if user already found card
                        cout << "\n You have already found the item that was here." << endl;
                    }
                }
                else if (this->getUi() == "2"){ // look at chair 2
                    if (getIsClean() == false){ // if user has NOT already used cleaning supplies to clean chair
                    cout << "\n Yuck, this chair is covered in something sticky and gross. You are about to turn away when you notice something. You can make out part of something written under the sticky substance. Maybe you can find something to clean the chair with..." << endl;
                        sleep(2);

                        if (getHasCleaningSupplies() == true){ // if the user has the cleaning supplies
                            cout << "\n Great, you found something to clean the chair! " << endl;
                            setIsClean(true); // cleans the chair
                            sleep(1);
                        }
                    }
                    if (getIsClean() == true) { // if the chair has already been cleaned
                        cout << "\n Cleaning the sticky grime reveled an employee badge with a number: 5674. Hmm… I wonder if this could be a code to something..." << endl;
                        sleep(2);
                    }
                }
                else{
                    cout << "\n Invalid selection " << endl;
                    this->setUi("0");
                }
            }
        }
        else if (this->getUi() == "2"){ // if the user does not want to look at chairs
            while (true){
                this->setUi("0");
                
                cout << "\n There is nothing new here, would you like to try searching another area of the lobby? (1 or 2) " << endl;

                if(cin.fail()){ // prevents an endless loop caused by bad past input
                    cin.clear();
                    cin.ignore();
                }
                cin >> ui;
                this->setUi(ui);

                if (this->getUi() == "1"){
                    return; // return to start of loop in execute()
                }
                if (this->getUi() == "2"){
                    break; // return to outer while loop
                }
            }
        }
        else{
            cout << "\n Invalid selection " << endl;
            this->setUi("0");
        }

    }
}

void LobbyRoom::closet(){
    string ui = "0"; // local var

    cout << "\n This looks like a janitor's closet. Maybe there is something useful inside. " << endl;

    sleep(1);

    while (true){
        cout << "\n Would you like to check out the closet? (1 or 2) "  << endl;

        if(cin.fail()){ // prevents an endless loop caused by bad past input
            cin.clear();
            cin.ignore();
        }
        cin >> ui;
        this->setUi(ui);

        if (this->getUi() == "1"){ // yes, user wants to try to open door to closet
            if (getHasCard() == false){ // if the user does NOT have the key card to unlock closet
                cout <<  "This room is locked. It looks like it needs a key card to open." << endl;
            }
            else{ // if the user does have the key card to unlock closet
                if (getHasCleaningSupplies() == false){ // if the user has NOT already obtained cleaning supplies
                    setHasCleaningSupplies(true); // takes the cleaning supplies
                    cout << "It looks like you found some cleaning supplies in here. Good find!! " << endl;
                    sleep(1);
                }
                else{ // if the cleaning supplies have already been found
                    cout << "You already found the item here." << endl;
                    sleep(1);
                }
            }
        }
        else if (this->getUi() == "2"){ // no, the user does not want to try to open the closet door
            while (true){
                this->setUi("0");
                
                cout << "\n There is nothing new here, would you like to try searching another area of the lobby? (1 or 2)" << endl;

                if(cin.fail()){ // prevents an endless loop caused by bad past input
                    cin.clear();
                    cin.ignore();
                }
                cin >> ui;
                this->setUi(ui);

                if (this->getUi() == "1"){
                    return; // return to start of loop in execute()
                }
                if (this->getUi() == "2"){
                    break; // returns to outer loop
                }
            }
        }
        else{
            cout << "\n Invalid selection " << endl;
            this->setUi("0");
        }
    }
}

void LobbyRoom::exitDoor(){
    string ui = "0"; // local var

    cout << "\n This is the door to the outside. " << endl;

    sleep(1);

    while (true){
        cout << "\n Try to open door? (1 or 2)  "  << endl;

        if(cin.fail()){ // prevents an endless loop caused by bad past input
            cin.clear();
            cin.ignore();
        }
        cin >> ui;
        this->setUi(ui);

        if (this->getUi() == "1"){ // yes, the user wants to try to open the door
            if (getHasKey() == true){ // if they have the key
                return; // returns to execute(), then execute() will return to the startGame() in the main file to finish game story
            }
            else{ // if the user does NOT have the key
                cout << "\n Not surprisingly, the door is locked and you need to find the key." << endl;
            }
        }
        else if (this->getUi() == "2"){ // no, the user does not want to try to open the door
            while (true){
                this->setUi("0");
                
                cout << "\n There is nothing new here, would you like to try searching another area of the lobby? (1 or 2) " << endl;

                if(cin.fail()){ // prevents an endless loop caused by bad past input
                    cin.clear();
                    cin.ignore();
                }
                cin >> ui;
                this->setUi(ui);

                if (this->getUi() == "1"){
                    return; // return to start of loop in execute()
                }
                if (this->getUi() == "2"){
                    break; // returns to outer loop
                }
            }
        }
        else{
            cout << "\n Invalid selection " << endl;
            this->setUi("0");
        }
    }
}

