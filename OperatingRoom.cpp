//
// Created by Ty Hobbs on 2/14/21.
//

// lines with issues: 91

#include "OperatingRoom.h"


OperatingRoom::OperatingRoom() {
    playerName = "player";
}

string OperatingRoom::getPlayerName() const{
    return playerName;
}

void OperatingRoom::setPlayerName(string playerName) {
    this->playerName = playerName;
}

void OperatingRoom::showRoomStory(){
    //Opening story line for the game.
    cout << "Welcome " << playerName << "You awake laying on a cold OR table.  The room is dark and no one is around.  You attempt to call for"
            "help but no on comes.  You notice that your arm is padlocked to the OR table." << endl;
}

void OperatingRoom::unlockFromTable(){
    //Class function that is used for the player to unlock themself from the OR table.
    cout << "You look at the lock and notice it is a pattern game that is a sequence for the combination.  The"
            "game is partially started."<< endl;

    int missingNum; //variable for the missing number of the puzzle.
    //Needle = 2
    //Vial = 3
    // Scalpel = 5
    // Answer = 10
    cout <<  "Needle   +  Needle  +   Needle  =  6" << endl;
    cout <<  "Needle   +  Vial    +   Vial    =  8"  << endl;
    cout << "Vial     +  Scalpel  +  Scalpel  =  13 " <<endl;
    cout<<  "Needle   +  Vial     +  Scalpel  =  ?"  << endl;

    while(missingNum != 10){
        cout << "What is the final total? " << endl;
        cin >> missingNum;
    }

    //If successful
    cout <<  "The padlock falls off and the chain clanks on the ground.  You are freed from the table."
             "It is time to get out of here but as you move towards the door you are halted to a stop by a tube connected to your "
             "body.  It has a sign attached that says do not yank out or you will pay a price." << endl;

} //End of unlockFromTable

void OperatingRoom::freeFromIVPump(){
    //Function that allows for the user to unlock from the IV pump in the game

    cout << "You follow the tube back and realize you are hooked up to a IV pump that needs a code to be unlocked.  "
            "There is a note attached that says look around for clues." << endl;
    int secretCode; //3059
    int selection; //Variable to hold user selection.
    int medBoxLockSelection;  //Variable to hold med box selection.

    while(secretCode != 3059){
        //Output user options
        cout << "1.  Look at nearby phone" << endl;
        cout << "2.  Look at beside table" << endl;
        cout << "3.  Look at locked medicine cabinet" << endl;
        cout << "4. Enter Code into IV Pump" << endl;
        cout << "Enter your selection : " << endl;
        cin >> selection;

        if (selection == 1){
            //Phone Choice
            cout << "Wow a phone, maybe I can call for help. But when you put the headset to your ear it is dead."
                    "So you decide to examine the phone a little closer. "
                    "It is a hospital phone that with speed dial labels to different units. There is a also a orange"
                    "label on it that says In Case of a Emergency dial 911" << endl;
        }else if(selection == 2){
            //Bedside table choice.
            cout << "On the bedside table you notice a chart.  It is full of medical orders on it.  2mg of Versed IV,"
                    "4 mg of Morphine IV, NPO till 12 tomorrow."  << endl;
        }else if (selection == 3){
            //Med Cabinet Choice.
            cout << "You notice a locked medicine cabinet that requires a 3 digit code to unlock it." << endl;
            cout << "1.  Attempt Code" << endl ;
            cout << "2.  Look around some more" << endl;
            cin >> medBoxLockSelection;
            if(medBoxLockSelection == 1){
                cout << "To Unlock Enter a 3 Digit Code" << endl;
                int code;
                cout << "Enter code: " << endl;
                cin >> code; // needs a print message for in wrong code is entered
                if (code == 911){
                    cout << "Door Opens to reveal a piece of paper hanging on the back" << endl;
                    cout << "3059" << endl;
                }

            }else if(medBoxLockSelection == 2){
                cout << "" << endl;
            }

        }else if(selection == 4){
            //Enter Code into IV Pump.
            cout << "Enter the Code: " << endl;
            cin >> secretCode;
            if (secretCode == 3059){
                cout << "Correct, the IV pump door opens up and you are released." << endl;
            }else{
                cout << "Wrong Code" << endl;
            }
        }

    }

}  //end freeFromIVPump.

void OperatingRoom::exitRoom(){
    //Add a game to exit from the room.
    int doorCode;
    int attempts = 0;
    cout << "You walk towards the door, so you can get out of this nightmare. It is also locked" <<endl;
    cout << "It is keypad locked with a sign that says enter a 4 digit code to exit. With a note hanging below it that says COVID!!" <<endl;
    cout << "After seeing the COVID sign, you think to yourself yeah this is just what I need after the YEAR COVID caused to you."<<endl;

    while (doorCode != 2020){
        cout << "Enter the door code to escape: " << endl;
        cin >> doorCode;
        attempts ++;
        if (doorCode != 2020){
            cout << "Wrong Code" << endl;
        }
        if (attempts > 2){
            cout << "Darn wrong code again.  You wonder if you can blame this on COVID, since it was the excuse of 2020." << endl;
        }
    }

    cout << "The door opens and you think to yourself the only thing that 2020 has been good for." <<endl;

}

void OperatingRoom:: execute(){
    showRoomStory();
    unlockFromTable();
    freeFromIVPump();
    exitRoom();
}

