#include <stdio.h>
#include <iostream>
#include "login.h"
#include "Reservation.h"
using namespace std;

int main() {
    int choice;
    bool outerNext = true;
    bool innerNext = true;
    while(outerNext) {
        
        cout<<"Welcome to the Library reservation system!"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"First please select:"<<endl;
        cout<<"1.Login   \n2.Register New Account\n3.Quit"<<endl;
        cin>>choice;
        switch (choice) {
        case 1:
            cout<<"------------------------------------------"<<endl;
            Login();
            outerNext = false;
            break;
        case 2:
            cout<<"------------------------------------------"<<endl;
            Register();
            break;
        case 3:
            cout<<"------------------------------------------"<<endl;
            cout<<"Thanks for using this system"<<endl;
            outerNext = false;
            break;
        default:
            cout<<"------------------------------------------"<<endl;
            cout<<"This is an invalid option"<<endl;
            outerNext = false;
            
            break;
            
        }
    }        
    return 0;
}