/**************************************************************
* Title: Hospital Room Escape
* Author:
* Created :
* Email:
* Course: CIS 164- Advanced C++
* OS:
* IDE: 
* Description :
* Copyright : This is my own original work  based on specifications issued by the course instructor
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access
* to my program.
***************************************************************/

// need to figure out the formatting for displaying the time/ score a little better still

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include<unistd.h> // for unix sleep
//#include<windows.h> // for windows sleep delay time function
#include <chrono> // used for clock and timing of game
#include <ctime>
#include <fstream>
#include "elevatorroom.h"
#include "emergencyroom.h"
#include "lobbyroom.hpp"
#include "OperatingRoom.h"
#include "psychwardroom.h"
using namespace std;

//protoypes
void helpMenu();
void displayStats();
void recordStats(string,string);
void startGame();

int main() {
    
    string userInput = "";

    while (userInput != "4") {
        cout << "Welcome to our Hospital Escape Game!" << endl;
        cout << "************************************" << endl;
        cout << "Would you like to: " << endl;
        cout << "1) View rules and instructions" << endl;
        cout << "2) View scoreboard" << endl;
        cout << "3) Start new game" << endl;
        cout << "4) End program" << endl;
        cin >> userInput;

        if (userInput == "1") {
            helpMenu();
            userInput = "0";
        }
        else if (userInput == "2") {
            displayStats();
            userInput = "0";
        }
        else if (userInput == "3") {
            startGame();
            userInput = "0";
        }
        else if (userInput != "4"){
            cout << "Invalid input. Please make a valid selection." << endl;
            cin >> userInput;
        }
    }

    return 0;
}

void helpMenu() {
    // prints basic rules and directions
    cout << "The goal of the game is to make it out of the hospital." << endl;
    cout << "Follow the prompts and solve puzzles to make it room to room." << endl;
    cout << "If you get stuck, restart and try again." << endl;
    
    sleep(4);
}

void displayStats() {
    // shows records stored in a file for times of past players
    
    string line = " "; // each line's text
    int lineCount = 0; // number of lines of text in file
    
    //open file to READ from
    ifstream csvRead("PlayerHistory.csv", ios::in);
        
    // gets the number of lines of text in the file
    while(getline(csvRead,line)){
        lineCount++;
    }
        
    //close file
    csvRead.close();
    
    //open file to READ from
    ifstream csvRead2("PlayerHistory.csv" , ios::in);

    vector<string> userNames; // reads every other line into an vector
    vector<double> times; // reads every other line into an vector

    // reads all lines and stores the values for the lines with price and qty to the respective vector
    for(int i = 2, j = 1; i < lineCount + 2; i++, j++){
        getline(csvRead2,line);
        
        if (i % 2 == 0){
            userNames.push_back(line); // adds to end of qtys vector
        }
        
        if (j % 2 == 0){
            double doubleLine = stod(line); // cast to double from string
            times.push_back(doubleLine); // adds to end of prices vector
        }
    }
    
    cout << "\n" << " Player" << right << setw(15) << "Game Time (sec)" << endl;
    cout << "_______________________" << endl;
    for ( int i = 0; i < userNames.size(); i++){
        cout << right << setw(10) << userNames[i] << right << setw(10) << times[i] << "\n" << endl;
    }
    sleep(4);
}

void recordStats(string userName, string time){
    // open or create file to WRITE to
    ofstream csvWrite("PlayerHistory.csv",ios_base::app);
   
    // Write to file
    csvWrite << userName << "\n " << time << "\n" ;
    
    // Close file
    csvWrite.close();
}


void startGame () {
    //Get user name
    string userName = "";
    cout << "Enter your name: " << endl;
    cin >> userName;

    // start time
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // declare a room object for each of the room classes
    OperatingRoom room1(userName);
    room2 room2;
    PsychWardRoom room3(userName);
    ElevatorRoom room4;
    LobbyRoom room5;

    // run each rooms game play
     room1.execute();
     room2.execute();
     room3.execute();
     room4.execute();
     room5.execute();
    
    // end time
    auto finishTime = chrono::high_resolution_clock::now();
    
    //elapsed time
    chrono::duration<double> elapsedTime = finishTime - startTime;
    string gameTime = to_string(elapsedTime.count());

    // prints out at the end of the game
     cout << "Congratulations, " << userName << "! You have completed the game in "
         << setprecision(2) << gameTime  << " seconds! \n" << endl;
    
    // call method to record the player name and their time to the stats csv file
    recordStats(userName, gameTime);
    sleep(3);
}

