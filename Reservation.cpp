#include "Reservation.h"


int timelink::getlength_() {
    return length_;
}
bool time_with_status::get_status_() {
    return status_;
}

int time_with_status::get_timeSlot() {
    return time_slot_;
}

int timelink_node::get_weekday() {
    return weekday_;
}

timelink::timelink(int length) {
    head_ = nullptr;
    length_ = length;
}

timelink_node::timelink_node(int weekday) {
    weekday_ = weekday;
    for(int i = 0; i < 24; i++) {
        time_with_status * status = new time_with_status(i);
        node_.push_back(*status);
    }
    next = nullptr;

}
time_with_status::~time_with_status() {

}
timelink_node::~timelink_node() {

}
timelink::~timelink() {

}
time_with_status::time_with_status(int timeslot) {
    time_slot_ = timeslot;
    status_ = true;
}


timelink* create_time_link(int length) {
    timelink* a_week = new timelink(length);
    timelink_node * first_node = new timelink_node(0);
    a_week->head_ = first_node;
    timelink_node* current = a_week->head_;
    for(int i = 1; i < length; i++) {
        timelink_node * new_node = new timelink_node(i);
        current->next  = new_node;
        current = current->next;
    }
    return a_week;
}

void print_time_link(timelink* timelink) {
    
    timelink_node* current = timelink->head_;
    int a = 0;
    while(current!=nullptr) {
        cout<<"on workday: "<< a <<endl;
        for(int j = 0; j < 24; j++) {
            cout<<"The status of time slot: "<<current->node_[j].get_timeSlot()<<" is "<<current->node_[j].get_status_() <<endl;
        }
        current = current->next;
        a++;

    }
}

void ListAppointment(string day, string time, bool wheTHerSuper);

bool checkAvai(string day, string time);

void MakeAppointment(string * user, string weekday, string timeslot);

void changeAppointment(string day1, string time1, string day2, string time2);

void cancleAppointment(string day, string time);
