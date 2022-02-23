#include <stdio.h>
#include <iostream>
#include "login.h"
#include "Reservation.h"
using namespace std;

int main() {
    cout<<"Welcome to the Library reservation system!"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"First please select:"<<endl;
    cout<<"1.Login   \n2.Register New Account\n3.Quit"<<endl;
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"------------------------------------------"<<endl;
        cout<<"This is for old user"<<endl;
        Login();
        break;
    case 2:
        cout<<"------------------------------------------"<<endl;
        Register();

        break;
    case 3:
        cout<<"------------------------------------------"<<endl;
        cout<<"Thanks for using this system"<<endl;
        break;


    default:
        cout<<"------------------------------------------"<<endl;
        cout<<"This is an invalid option"<<endl;
        break;
    }










    return 0;
}