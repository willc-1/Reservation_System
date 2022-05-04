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
void time_with_status::change_status() {
    if(status_ == true) {
        status_ = false;
    } else {
        status_ = true;
    }
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


timelink* create_time_link(int length, timelink ** timelink) {
    timelink_node * first_node = new timelink_node(0);
    (*timelink)->head_ = first_node;
    timelink_node* current = (*timelink)->head_;
    for(int i = 1; i < length; i++) {
        timelink_node * new_node = new timelink_node(i);
        current->next  = new_node;
        current = current->next;
    }
    return *timelink;
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

void ListAppointment(string * userName, vector<string>* appointment) {
    ifstream file;
    file.open("appointment.txt", ios::app);
    if(!file) {
        cout<<"can not find file"<<endl;
    }
    string name, line;
    string space = " ";
    int date, time;
    string USER;
    size_t position = 0;
    int counter = 0;
    while(!file.eof()) {
        getline(file, line);
        position = line.find(space);
        USER = line.substr(0, position);
        if(USER == *userName) {
            cout<< counter <<". "<<line <<endl;
            appointment->push_back(line);
            counter++;
        }
    }
    return;
}

bool checkAvai_type1(int day, int timeslot, timelink* timelink) {
    timelink_node* current = timelink->head_;
    while(current != nullptr) {
        if(current->get_weekday() == day) {
            for(int i = 0; i < 24; i++) {
                if(current->node_[i].get_timeSlot() == timeslot) {
                    if(current->node_[i].get_status_() == true) {
                        return true;
                    } 
                }
            }
        }
        current = current->next;
    }
    return false;
}
bool checkAvai_type2(int day, int timeslot) {
    ifstream file;
    file.open("appointment.txt", ios::app);
    if(!file) {
        cout<<"can not find file"<<endl;
    }
    string name;
    bool avai_date = true;
    bool toReturn = true;
    //string user;
    int date, time;
    while(file >>name >>date >> time) {
        if(date == day) {
            avai_date = false;
        }
        if(avai_date == false && time == timeslot) {
            toReturn = false;
        }
    }
    return toReturn;
}

void changeAvai(int day, int timeslot, timelink* timelink) {
    timelink_node* current = timelink->head_;
    while(current != nullptr) {
        if(current->get_weekday() == day) {
            for(int i = 0; i < 24; i++) {
                if(current->node_[i].get_timeSlot() == timeslot) {
                    current->node_[i].change_status();
                    return;
                }
            }
        }
        current = current->next;
    }
}


void MakeAppointment(string * user, int weekday, int timeslot, timelink* timelink) {
    ofstream appointment;
    appointment.open("appointment.txt", ios::app);
    timelink_node* current = timelink->head_;
    if(checkAvai_type2(weekday, timeslot) == false) {
        cout<<"This time has already been reserved"<<endl;
    } else {
        appointment<<*user<<" "<< weekday << " "<<timeslot<<endl;
        changeAvai(weekday, timeslot, timelink);
    }
    appointment.close();
}

void changeAppointment(string day1, string time1, string day2, string time2);

void cancelAppointment_type2(string toCancel) {
    ifstream filein;
    ofstream fileout;
    //ofstream {"temp.txt"};
    filein.open("appointment.txt", ios::app);
    fileout.open("temp.txt", ios::app);
    if(!filein || !fileout) {
        cout<<"can not find file"<<endl;
    }
    int counter = 0;
    string line_1;
    bool found = false;
    while(!filein.eof()) {
        getline(filein, line_1);
        if(line_1!= toCancel) {
            //line.replace(line.find(toCancel),toCancel.length(),"");
            fileout<<line_1<<endl;
        }
        //if(found) break;
    }
    filein.close();
    fileout.close();
    //delete the appointment.txt
    ofstream ofs;
    ofs.open("appointment.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    //copy the temp.txt to appointment.txt and remove the temp.txt file
    ofstream copy;
    ifstream tocp;
    copy.open("appointment.txt", ios::app);
    tocp.open("temp.txt", ios::app);
    string line_2;
    while(!tocp.eof()) {
        getline(tocp, line_2);
        copy<<line_2<<endl;
    }
    copy.close();
    tocp.close();
    remove("temp.txt");
    return;

}

