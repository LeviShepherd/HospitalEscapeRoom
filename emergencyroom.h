#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H


class room2 {
public:
    room2(); // constructor called upon creation of object
    void desk(); //index 1 on menu
    void employeeOnlyRoom(); // index 2 on menu
    void patientRoom(); // index 3 on menu
    void patientRoom2(); // might change if I come up with a better idea... index 4 on the menu
    void exit(); // index 5 on menu
    void codeGuesses(); // index 6 on menu
private:
    bool roomDone;
    bool vendingMachineDestroyed;
    bool idCard;
    int code;
    int codeNum1;
    int codeNum2;
    int codeNum3;
    int codeNum4;
};

#endif // EMERGENCYROOM_H
