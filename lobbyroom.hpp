#ifndef LOBBYROOM_H
#define LOBBYROOM_H

#include <string>
using namespace std;

class LobbyRoom{
    private:
        string ui = "0"; // user input
        bool hasCleaningSupplies = false; // used to determine if user has found the cleaning supplied from the closet
        bool hasCard = false; // used to determine if user has key card or not
        bool hasKey = false; // used to determine if user has key to the outside or not
        
        string correctCode = "5674";
        string userTryCode = "0";
        
        bool isClean = false; // used to determine if chair is sticky/dirty or clean
        
    public:
        LobbyRoom(); // default constructor
        void execute();
        
        void setUi(string);
        void setHasCleaningSupplies(bool);
        void setHasCard(bool);
        void setHasKey(bool);
        void setUserTryCode(string);
        void setIsClean(bool);
    
        string getUi();
        bool getHasCleaningSupplies();
        bool getHasCard();
        bool getHasKey();
        string getUserTryCode();
        string getCorrectCode();
        bool getIsClean();
        
        void desk();
        void waitingArea();
        void closet();
        void exitDoor();
};

#endif // LOBBYROOM_H
