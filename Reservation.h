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
        time_with_status(int timeslot);
        ~time_with_status();
};

class timelink_node {
    private:
        int weekday_;
        //vector<time_with_status> node_;
        //timelink_node* next;
    public:
        vector<time_with_status> node_;
        timelink_node* next;
        int get_weekday();
        timelink_node(int weekday);
        ~timelink_node();

};      
class timelink {
    private:
        //timelink_node* head_;
        int length_;
        
    public:
        timelink_node* head_;
        int getlength_();
        timelink(int length);
        ~timelink();
};

    timelink *create_time_link(int length);
    void print_time_link(timelink* timelink);

    void ListAppointment(string day, string time, bool wheTHerSuper);


    bool checkAvai(string day, string time);



    void MakeAppointment(string * user, string weekday, string timeslot);



    void changeAppointment(string day1, string time1, string day2, string time2);




    void cancleAppointment(string day, string time);
