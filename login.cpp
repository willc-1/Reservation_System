#include "login.h"

string user, pass, emails;


bool checkUserValid(string user, string pass) {
    ifstream file;
    string username, password;
    int n=0;
    file.open("users.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> username >> password;
            n++;
            if (user==username && pass==password)
                return n;
        }
    }
    else
    {
        cout << "Error: the user data file missing" << endl;
    }
    return 0;
}



void Login() {
    int loginattempts=0;
    ifstream userfile;
    userfile.open("users.txt");
    string userset, passset;
    while (checkUserValid(user, pass)==false)
    {
        loginattempts++;
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;
        if (checkUserValid(user, pass)!=0)
            cout << "Welcome user: " << user << "!" << endl;
        else if (loginattempts==5)
        {
            cout << "Maximum login attempts exceeded." << endl;
            break;
        }
        else
        {
            cout << "Invalid username/password combination" << endl;
        }
    }
    userfile.close();
}


void Register() {
    ifstream file;
    ofstream newuser;
    string username, password, passwordconfirm, email;
    file.open("users.txt", ios::app);
    newuser.open("users.txt", ios::app);
    bool uservalid = false;
    while (!uservalid)
    {
        cout << "Please enter Username: ";
        cin >> username;
        cout << "Please enter Password: ";
        cin >> password;
        cout << "Please Confirm password: ";
        cin >> passwordconfirm;
        cout<< "Please enter email: ";
        cin >> email;
        int m = 0;
        int k = 0;
        int e = 0;
        while (file >> user >> pass >> emails) {
            m++;
            if (username!=user) {
                k++;
            }
            if (email!=emails) {
                e++;
            }
        }
        if (m==k && password==passwordconfirm && m==e) {
            uservalid=true;
        }
        else if (m!=k) {
            cout << "There is already a user with this username." << endl;
        }
        else if(m!=e){
            cout << "This email has already been used" << endl;
        }
        else {
            cout << "The passwords given do not match." << endl;
        }
    }
    newuser << username << " " << password <<" "<< email << endl;
    user = "";
    pass = "";
    printf("Register successfully!\n");
    file.close();
    newuser.close();
}
