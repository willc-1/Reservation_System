#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class time_with_status {
    private:
        int time_slot_;
        bool status_;
    public:
        int get_timeSlot();
        bool get_status_();
        void change_status();
        time_with_status(int timeslot);
        ~time_with_status();
};

class timelink_node {
    private:
        int weekday_;
    public:
        vector<time_with_status> node_;
        timelink_node* next;
        int get_weekday();
        timelink_node(int weekday);
        ~timelink_node();

};      
class timelink {
    private:
        int length_;
        
    public:
        timelink_node* head_;
        int getlength_();
        timelink(int length);
        ~timelink();
};

    timelink *create_time_link(int length, timelink** timelink);

    void print_time_link(timelink* timelink);

    void ListAppointment(string * userName, vector<string>* appointment);

    /*
        Function to check whether the time has already been reserved
        This is used for timelink version
    */
    bool checkAvai_type1(int day, int timeslot, timelink* timelink);

    /*
        Function to check whether the time has already been reserved\
        This is the file check version
    */
    bool checkAvai_type2(int day, int timeslot);

    void changeAvai(int day, int timeslot, timelink* timelink);


    void MakeAppointment(string * user, int weekday, int timeslot, timelink* timelink);



    void changeAppointment(string day1, string time1, string day2, string time2);




    void cancelAppointment_type2(string time);
