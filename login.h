#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string username;
string password;

bool checkUserValid(string username);
bool checkUserExist(string username);
void Login();
void Register();