#include "login.h"



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



void Login(string *user_name) {
    int loginattempts=0;
    ifstream userfile;
    userfile.open("users.txt");
    string userset, passset;
    bool is_valid;
    do
    {
        loginattempts++;
        cout << "Username: ";
        cin >> userset;
        cout << "Password: ";
        cin >> passset;
        is_valid = checkUserValid(userset, passset);
        *user_name = userset;
        if (is_valid) {
            cout << "Welcome user: " << userset << "!" << endl;
            cout<<"------------------------------------------"<<endl;
        }
        else if (loginattempts==5)
        {
            cout << "Maximum login attempts exceeded." << endl;
            break;
        }
        else
        {
            cout << "Invalid username/password combination" << endl;
        }
    } while ( is_valid ==false);
    userfile.close();
}


void Register() {
    ifstream file;
    ofstream newuser;
    string username, password, passwordconfirm, email, fileuser, filepass, fileemails;
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
        while (file >> fileuser >> filepass >> fileemails) {
            m++;
            if (username!=fileuser) {
                k++;
            }
            if (email!=fileemails) {
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
    cout<<"Register successfully!"<<endl;
    cout<<"------------------------------------------"<<endl;
    file.close();
    newuser.close();
}
