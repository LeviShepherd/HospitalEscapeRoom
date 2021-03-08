#include "emergencyroom.h"
#include <iostream>
using namespace std;

/*
 * Todo list:
 * Implement scoring
*/

// lines with issues: 137, the part with the code is a little confusing with number 5 and number 6, but a really cool room!
// github test

room2::room2() {
    int menuIndex;
    code = 2187;
    idCard = false;
    vendingMachineDestroyed = false;
    roomDone = false;
    codeNum1 = -1;
    codeNum2 = -1;
    codeNum3 = -1;
    codeNum4 = -1;

    cout << "----------" << endl;
    cout << "You enter the Emergency Department. Suddenly, the door slams shut behind you! You desperately try to open it again but it's no use the door won't budge. ";
    cout << "How could this happen, you think to yourself, I'm smarter than this!" << endl;

    while (roomDone == false) {
        cout << "\nWhere would you like to go?" << endl;
        cout << "1. Desk in the center of the room." << endl;
        cout << "2. Employee only room behind the desk." << endl;
        cout << "3. One of the rooms for patients behind a curtain." << endl;
        cout << "4. One of the other patient rooms behind a curtain." << endl;
        cout << "5. The door at the end of the room." << endl;
        cout << "6. Code guess." << endl;
        cin >> menuIndex;
        if (menuIndex == 1) {
            room2::desk();
        }
        else if (menuIndex == 2) {
            room2::employeeOnlyRoom();
        }
        else if (menuIndex == 3) {
            room2::patientRoom();
        }
        else if (menuIndex == 4) {
            room2::patientRoom2();
        }
        else if (menuIndex == 5) {
            room2::exit();
        }
        else if (menuIndex == 6) {
            room2::codeGuesses();
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}





void room2::desk() { // called by option 1, code number 2
    int menuIndex = 0;
    cout << "You approach the desk. The floor around it is filled with overturned objects and paperwork for patients. You notice a computer giving off a dim light." << endl;

    while (menuIndex != 3) {
        cout << "1. Investigate the computer." << endl;
        cout << "2. Investigate paperwork." << endl;
        cout << "3. Return to the beginning." << endl;
        cin >> menuIndex;

        if (menuIndex == 1) {
            cout << "You try moving the mouse around but the computer is frozen! It seems whoever was last using the computer was already logged in. You can make out a message:" << endl;
            cout << "\"Happy birthday Luke! I know you're fond of puzzles so I decided to set one up for you. The door at the end of the room requires an access code to open. ";
            cout << "I've made some puzzles throughout the room to give you the code. Once you find all the pieces you can enter the code and move on. ";
            cout << "Don't worry if you can't figure it out or don't want to do it just text me and I'll send you the code. ";
            cout << "Here's a hint, the first digit is hidden in the names of the patients. Your friend, Wedge.\"" << endl;
            cout << "I've got a bad feeling about this, you think to yourself as you step away from the computer." << endl;
        }
        else if (menuIndex == 2) {
            cout << "You pick the papers up off the floor and begin to read them. The paperwork goes over basic medical details for three patients such as their medical history, medications, and allergies." << endl;
            cout << "The names of the patients are: " << endl; // first letter of each name == 2/the first digit
            cout << "Thrawn" << endl;
            cout << "Winter" << endl;
            cout << "Onasi" << endl;
        }
        else if (menuIndex == 3) {
            cout << "You return to where you started." << endl;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}





void room2::employeeOnlyRoom() { // called by option 2, code number 1
    int menuIndex = 1;
    int guess;
    cout << "You go behind the desk and enter the employee only room. The door seems to have been left open to by whoever was here before. ";
    cout << "It's a small room but it seems to be a room for employee's to go on their lunch break or after their shift. ";
    cout << "There is a table with chairs around it and papers on top, a small vending machine with a few items, and a coat hangar that still has a doctor's lab coat on it in the corner." << endl;

    while (menuIndex != 4) {
        cout << "1. Investigate table." << endl;
        cout << "2. Investigate vending machine." << endl;
        cout << "3. Investigate doctor's coat." << endl;
        cout << "4. Return to the beginning." << endl;
        cin >> menuIndex;
        if (menuIndex == 1) {
            cout << "You go to the table and begin to look through all the papers lying around. You find a note: ";
            cout << "\"You're close to the second digit Luke nice job. If I were you I'd get a soda to help you think on it.\"" << endl;
        }
        else if (menuIndex == 2) {
            if (vendingMachineDestroyed == false) {
                cout << "You make your way over to the vending machine. As you look at its contents you can see most of its items are sold out. ";
                cout << "Behind one of the rows you see an item that doens't match the others." << endl;
                while (menuIndex != 3) {
                    cout << "1. Look for wallet." << endl;
                    cout << "2. Destroy vending machine." << endl;
                    cout << "3. Leave vending machine alone." << endl;
                    cin >> menuIndex;
                    if (menuIndex == 1) {
                        cout << "You check for your wallet but cannot find it. It must have been taken sometime during your stay at the hospital." << endl;
                    }
                    else if (menuIndex == 2) {
                        cout << "You grab a chair from around the table and begin to smash the vending machine open. ";
                        cout << "After its destroyed you reach in and grab a hold of what appears to be a can of Coke with another note wrapped around it." << endl;
                        cout << "The note shows an equation: " << endl;
                        cout << "(7 + X/7) * (7 + 7) = 100" << endl; // answer is 1
                        cout << "X = ?: " << endl;
                        cin >> guess; // causes endless loop if you guess wrong and/ or wont let you try again
                        vendingMachineDestroyed = true;
                        break;
                    }
                    else if (menuIndex == 3) {
                        cout << "You step away from the vending machine." << endl;
                        break;
                    }
                    else {
                        cout << "Invalid input" << endl;
                    }
                }
            }
            else {
                cout << "The vending machine is destroyed. You step away from the vending machine." << endl;
                cout << "The note you found says: " << endl;
                cout << "(7 + X/7) * (7 + 7) = 100" << endl; // answer is 1
                cout << "X = ?: " << endl;
            }
        }
        else if (menuIndex == 3) {
            cout << "You look through the pockets of the doctor's coat. You find another note saying: \"Hint for digit 4, think of the ways to write numbers.\"" << endl; //FINISH AND COME UP WITH LAST PUZZLE!!!
        }
        else if(menuIndex == 4) {
            cout << "You return to where you started." << endl;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}





void room2::patientRoom() { // called by option 3, code number 8
    int guess;
    int menuIndex = 0;

    cout << "You approach the room opening the curtain. Inside the room you see a bed and a counter with cabinets, a sink, and paperwork on it." << endl;

    while (menuIndex != 5) { //CHANGE
        cout << "1. Rest on the bed." << endl;
        cout << "2. Wash hands." << endl;
        cout << "3. Paperwork on the counter." << endl;
        cout << "4. Check the cabinets." << endl;
        cout << "5. Return to the beginning." << endl;
        cin >> menuIndex;
        if (menuIndex == 1) {
            cout << "You lay down on the bed for a short rest." << endl;
            cout << "...\n...\n...\nIt's comfortable." << endl;
        }
        else if (menuIndex == 2) {
            cout << "You go over to the sink and wash your hands. The soap kills 99.9% of germs." << endl;
        }
        else if (menuIndex == 3) {
            cout << "You rummage through the paperwork and stumble upon a note: " << endl;
            cout << "\"You've found the third puzzle/digit you're almost there Luke! This puzzle is all about logarithms.\"" << endl;
            cout << "Sequence pairs: 4  2 - 16  4 - 64  6 - 256  X" << endl; // answer is 8
            cout << "X = ?" << endl;
            cin >> guess;
        }
        else if (menuIndex == 4) {
            cout << "You open all the cabinets and look inside. There are standard tools you'd expect to find in a hospital, notihng that seems too useful." << endl;
        }
        else if (menuIndex == 5) {
            cout << "You return to where you started." << endl;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}





void room2::patientRoom2() { // called by option 4, code number 7
    int menuIndex = 0;
    cout << "You approach the room opening the curtain. Inside you see a patient room with a bed and a counter with cabinets and a sink. ";
    cout << "You also see a positionable light above the bed." << endl;

    while (menuIndex != 5) { //CHANGE
        cout << "1. Rest on the bed." << endl;
        cout << "2. Wash hands." << endl;
        cout << "3. Investigate the light." << endl;
        cout << "4. Check the cabinets." << endl;
        cout << "5. Return to the beginning." << endl;
        cin >> menuIndex;
        if (menuIndex == 1) {
            cout << "You lay down on the bed for a short rest." << endl;
            cout << "...\n...\n...\nIt's not very comfortable." << endl;
        }
        else if (menuIndex == 2) {
            cout << "You go over to the sink and wash your hands but the soap seems to have run out." << endl;
        }
        else if (menuIndex == 3) {
            cout << "You go up to the positionable light above the bed as look around it you find a note wrapped around part of it:" << endl;
            cout << "\"This is it Luke the final digit to the passcode out of here. Lets see if you can find the number.\"" << endl;
            cout << "ASHFIWNAIVNWANVA" << endl;
            cout << "IQWNIAVSIGNADSBA" << endl;
            cout << "QIUVIANVZJJEHAFR" << endl;
            cout << "HFASEVENFAINWINF" << endl;
            //          ^^^^^ 7
            cout << "ANFIAWNANBVANWAN" << endl;
            cout << "EIOVABWJAMSEVENT" << endl;
            //                 ^^^^^ 7
            // put two in because I wasn't sure how difficult this would be
        }
        else if (menuIndex == 4) {
            cout << "You open all the cabinets and look inside. There are standard tools you'd expect to find in a hospital, notihng that seems too useful." << endl;
        }
        else if (menuIndex == 5) {
            cout << "You return to where you started." << endl;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}





void room2::exit() { // called by option 5
    int menuIndex = 0;
    cout << "You approach the door. There is a keypad on the side of the door near the handle." << endl;

    while (menuIndex != 3) {
        cout << "1. Try to open the door." << endl;
        cout << "2. Investigate keypad." << endl;
        cout << "3. Return to the beginning." << endl;
        cin >> menuIndex;

        if (menuIndex == 1) {
            cout << "You grab the handle of the door and pull. The door doesn't move. You grab with both hands and pull as hard as you can but even still nothing happens." << endl;
            cout << endl; // seperates the output
        }
        else if (menuIndex == 2) {
            menuIndex = 1;
            cout << "You go up to the keypad. It's a standard design that accepts four numbers as input." << endl;
            while (menuIndex != 2) {
                cout << "1. Try the keypad" << endl;
                cout << "2. Don't try the keypad" << endl;
                cin >> menuIndex;
                if (menuIndex == 1) {
                    int codeAttempt;
                    cout << "Enter code: ";
                    cin >> codeAttempt;
                    if (codeAttempt == code) {
                        cout << "Correct. Access granted!" << endl;
                        cout << "It seems you entered the correct code. You the hear a clicking sound as the door unlocks. The door opens easily as you pull on the door handle and delve deeper into the hospital." << endl;
                        roomDone = true;
                        return;
                    }
                    else if (codeAttempt != code) {
                        cout << "Incorrect. Access denied." << endl;
                    }
                } else if (menuIndex == 2) {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                }
            }
        }
        else if (menuIndex == 3) {
            cout << "You return to where you started." << endl;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
}

void room2::codeGuesses() { // called by option 6
    int guess;
    int menuIndex = 0;
    cout << "I've got to keep track of what I've found, you think to yourself." << endl;

    cout << "Enter what you think the code is: ";
    if (codeNum1 < 0) {
        cout << "*";
    }
    else {
        cout << codeNum1;
    }
    if (codeNum2 < 0) {
        cout << "*";
    }
    else {
        cout << codeNum2;
    }
    if (codeNum3 < 0) {
        cout << "*";
    }
    else {
        cout << codeNum3;
    }
    if (codeNum4 < 0) {
        cout << "*" << endl;
    }
    else {
        cout << codeNum4 << endl;
    }

    while (menuIndex != 6) {
        cout << "1. Enter first digit." << endl;
        cout << "2. Enter second digit." << endl;
        cout << "3. Enter third digit." << endl;
        cout << "4. Enter fourth digit." << endl;
        cout << "5. Reset code to default." << endl;
        cout << "6. Return to the beginning." << endl;
        cin >> menuIndex;
        if (menuIndex == 1) {
            cout << "First digit: ";
            cin >> guess;
            while (guess > 9 || guess < 0) {
                cout << "Digit cannot be negative or greater than 9. Enter again: ";
                cin >> guess;
            }
            codeNum1 = guess;
        }
        if (menuIndex == 2) {
            cout << "Second digit: ";
            cin >> guess;
            while (guess > 9 || guess < 0) {
                cout << "Digit cannot be negative or greater than 9. Enter again: ";
                cin >> guess;
            }
            codeNum2 = guess;
        }
        else if (menuIndex == 3) {
            cout << "Third digit: ";
            cin >> guess;
            while (guess > 9 || guess < 0) {
                cout << "Digit cannot be negative or greater than 9. Enter again: ";
                cin >> guess;
            }
            codeNum3 = guess;
        }
        else if (menuIndex == 4) {
            cout << "Fourth digit: ";
            cin >> guess;
            while (guess > 9 || guess < 0) {
                cout << "Digit cannot be negative or greater than 9. Enter again: ";
                cin >> guess;
            }
            codeNum4 = guess;
        }
        else if (menuIndex == 5) {
            codeNum1 = -1;
            codeNum2 = -1;
            codeNum3 = -1;
            codeNum4 = -1;
        }
        else if (menuIndex == 6) {
            cout << "You return to where you started." << endl;
        }
    }

    cout << "Code guess: ";
    if (codeNum1 < 0) {
        cout << "*";
    }
    else {
        cout << codeNum1;
    }
    if (codeNum2 < 0) {
        cout << "*";
    }
    else {
        cout << codeNum2;
    }
    if (codeNum3 < 0) {
        cout << "*";
    }
    else {
        cout << codeNum3;
    }
    if (codeNum4 < 0) {
        cout << "*" << endl;
    }
    else {
        cout << codeNum4 << endl;
    }
}
