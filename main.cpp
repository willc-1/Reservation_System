#include <stdio.h>
#include <iostream>
#include "login.h"
#include "Reservation.h"
#include <string.h>
using namespace std;
int main() {
    int choice;
    int weekdayChoice;
    int timeSlotChoice;
    string user_name;
    bool outerNext_1 = true;
    bool outerNext_2 = true;
    while(outerNext_1) {
        
        cout<<"Welcome to the Library reservation system!"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"First please select:"<<endl;
        cout<<"1.Login\n2.Register New Account\n3.Quit"<<endl;
        cin>>choice;
        switch (choice) {
        case 1:
            cout<<"------------------------------------------"<<endl;
            Login(&user_name);
            outerNext_1 = false;
            break;
        case 2:
            cout<<"------------------------------------------"<<endl;
            Register();
            break;
        case 3:
            cout<<"------------------------------------------"<<endl;
            cout<<"Thanks for using this system"<<endl;
            outerNext_1 = false;
            break;
        default:
            cout<<"------------------------------------------"<<endl;
            cout<<"This is an invalid option"<<endl;
            outerNext_1 = false;
            
            break;
            
        }
    }
    while(outerNext_2) {
        cout<< "Please select the service: "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"1.Make Appointment\n2.Cancel Appointment\n3.Change Appointment\n4.Quit"<<endl;
        string weekday_string;
        string toCancel;
        int weekday_int;
        string time_slot;
        vector<string> current_appointment;
        timelink * new_timelink_1 = new timelink(7);
        create_time_link(7, &new_timelink_1);
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"------------------------------------------"<<endl;
                cout<<"Please enter the weekdays you want to make the reservation: "<<endl;
                cout<<"1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n5.Friday\n6.Saturday\n7.Sunday"<<endl;
                cin>>weekdayChoice;
                weekday_int = weekdayChoice;
                switch (weekdayChoice)
                {
                case 1:
                    weekday_string = "Monday";
                    break;
                case 2:
                    weekday_string ="Tuesday"; 
                    break;
                case 3:
                    weekday_string = "Webnesday";
                    break;
                case 4:
                    weekday_string = "Thursday";
                    break;
                case 5:
                    weekday_string = "Friday";
                    break;
                case 6:
                    weekday_string = "Saturday";
                    break;
                case 7:
                    weekday_string = "Sunday";
                    break;
                default:
                    cout<<"This is a invalid option"<<endl;
                    break;
                }
                cout<<"------------------------------------------"<<endl;
                cout<<"Please enter the timeslot you want to make the reservation: "<<endl;
                cout<<"1.0-1AM\n2.1-2AM\n3.2-3AM\n4.3-4AM\n5.4-5AM\n6.5-6AM\n7.6-7AM\n8.7-8AM\n9.8-9AM\n10.9-10AM\n11.10-11AM\n12.11-12AM\n13.12-1PM\n14.1-2PM\n15.2-3PM\n16.3-4PM\n17.4-5PM\n18.5-6PM\n19.6-7PM\n20.7-8PM\n21.8-9PM\n22.9-10PM\n23.10-11PM\n24.11-12PM"<<endl;
                int timeslot_choice_1;
                cin>>timeslot_choice_1;
                switch (timeslot_choice_1)
                {
                case 1:
                    time_slot = "0-1AM";
                    break;
                case 2:
                    time_slot ="1-2AM"; 
                    break;
                case 3:
                    time_slot = "2-3AM";
                    break;
                case 4:
                    time_slot = "3-4AM";
                    break;
                case 5:
                    time_slot = "4-5AM";
                    break;
                case 6:
                    time_slot = "5-6AM";
                    break;
                case 7:
                    time_slot = "6-7AM";
                    break;
                case 8:
                    time_slot = "7-8AM";
                    break;
                case 9:
                    time_slot = "8-9AM";
                    break;
                case 10:
                    time_slot = "9-10AM";
                    break;
                case 11:
                    time_slot = "10-11AM";
                    break;
                case 12:
                    time_slot = "11-12AM";
                    break;
                case 13:
                    time_slot = "12-1PM";
                    break;
                case 14:
                    time_slot = "1-2PM";
                    break;
                case 15:
                    time_slot = "2-3PM";
                    break;
                case 16:
                    time_slot = "3-4PM";
                    break;
                case 17:
                    time_slot = "4-5PM";
                    break;
                case 18:
                    time_slot = "5-6PM";
                    break;
                case 19:
                    time_slot = "6-7PM";
                    break;
                case 20:
                    time_slot = "7-8PM";
                    break;
                case 21:
                    time_slot = "8-9PM";
                    break;
                case 22:
                    time_slot = "9-10PM";
                    break;
                case 23:
                    time_slot = "10-11PM";
                    break;
                case 24:
                    time_slot = "11-12PM";
                    break;
                default:
                    cout<<"This is a invalid option"<<endl;
                    break;
                }
                cout<<"------------------------------------------"<<endl;
                MakeAppointment(&user_name, weekday_int, timeslot_choice_1, new_timelink_1);
                cout<<"Do you want to continue reservation service?"<<endl;
                cout<<"1. Yes \n2. NO"<<endl;
                int conti_num_1;
                cin>>conti_num_1;
                if(conti_num_1 == 1) {
                    outerNext_2 = true;
                } else {
                    outerNext_2 = false;
                }
                break;
            case 2:
                cout<<"------------------------------------------"<<endl;
                //print_time_link(new_timelink_1);
                cout<<"Here is the appointment you currently reserved"<<endl;
                cout<<"Please select the time slot you want to cancel"<<endl;
                ListAppointment(&user_name, &current_appointment);
                int cancelChoice_1;
                cin>>cancelChoice_1;
                toCancel = current_appointment[cancelChoice_1];
                cancelAppointment_type2(toCancel);
                //cancelAppointment();
                //changeAppointment();
                cout<<"Do you want to continue reservation service?"<<endl;
                cout<<"1. Yes \n2. NO"<<endl;
                int conti_num_2;
                cin>>conti_num_2;
                if(conti_num_2 == 1) {
                    outerNext_2 = true;
                } else {
                    outerNext_2 = false;
                }
                break;
            case 3:
                cout<<"------------------------------------------"<<endl;
                cout<<"Here is the appointment you currently reserved"<<endl;
                cout<<"Please select the time slot you want to change"<<endl;
                ListAppointment(&user_name, &current_appointment);
                int cancelChoice_2;
                cin>>cancelChoice_2;
                toCancel = current_appointment[cancelChoice_2];
                cancelAppointment_type2(toCancel);
                cout<<"Your appointment has been canceled successfully"<<endl;
                cout<<"------------------------------------------"<<endl;
                cout<<"Please enter the weekdays you want to make the reservation: "<<endl;
                cout<<"1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n5.Friday\n6.Saturday\n7.Sunday"<<endl;
                cin>>weekdayChoice;
                weekday_int = weekdayChoice;
                switch (weekdayChoice)
                {
                case 1:
                    weekday_string = "Monday";
                    break;
                case 2:
                    weekday_string ="Tuesday"; 
                    break;
                case 3:
                    weekday_string = "Webnesday";
                    break;
                case 4:
                    weekday_string = "Thursday";
                    break;
                case 5:
                    weekday_string = "Friday";
                    break;
                case 6:
                    weekday_string = "Saturday";
                    break;
                case 7:
                    weekday_string = "Sunday";
                    break;
                default:
                    cout<<"This is a invalid option"<<endl;
                    break;
                }
                cout<<"------------------------------------------"<<endl;
                cout<<"Please enter the timeslot you want to make the reservation: "<<endl;
                cout<<"1.0-1AM\n2.1-2AM\n3.2-3AM\n4.3-4AM\n5.4-5AM\n6.5-6AM\n7.6-7AM\n8.7-8AM\n9.8-9AM\n10.9-10AM\n11.10-11AM\n12.11-12AM\n13.12-1PM\n14.1-2PM\n15.2-3PM\n16.3-4PM\n17.4-5PM\n18.5-6PM\n19.6-7PM\n20.7-8PM\n21.8-9PM\n22.9-10PM\n23.10-11PM\n24.11-12PM"<<endl;
                int timeslot_choice_2;
                cin>>timeslot_choice_2;
                switch (timeslot_choice_2)
                {
                case 1:
                    time_slot = "0-1AM";
                    break;
                case 2:
                    time_slot ="1-2AM"; 
                    break;
                case 3:
                    time_slot = "2-3AM";
                    break;
                case 4:
                    time_slot = "3-4AM";
                    break;
                case 5:
                    time_slot = "4-5AM";
                    break;
                case 6:
                    time_slot = "5-6AM";
                    break;
                case 7:
                    time_slot = "6-7AM";
                    break;
                case 8:
                    time_slot = "7-8AM";
                    break;
                case 9:
                    time_slot = "8-9AM";
                    break;
                case 10:
                    time_slot = "9-10AM";
                    break;
                case 11:
                    time_slot = "10-11AM";
                    break;
                case 12:
                    time_slot = "11-12AM";
                    break;
                case 13:
                    time_slot = "12-1PM";
                    break;
                case 14:
                    time_slot = "1-2PM";
                    break;
                case 15:
                    time_slot = "2-3PM";
                    break;
                case 16:
                    time_slot = "3-4PM";
                    break;
                case 17:
                    time_slot = "4-5PM";
                    break;
                case 18:
                    time_slot = "5-6PM";
                    break;
                case 19:
                    time_slot = "6-7PM";
                    break;
                case 20:
                    time_slot = "7-8PM";
                    break;
                case 21:
                    time_slot = "8-9PM";
                    break;
                case 22:
                    time_slot = "9-10PM";
                    break;
                case 23:
                    time_slot = "10-11PM";
                    break;
                case 24:
                    time_slot = "11-12PM";
                    break;
                default:
                    cout<<"This is a invalid option"<<endl;
                    break;
                }
                cout<<"------------------------------------------"<<endl;
                MakeAppointment(&user_name, weekday_int, timeslot_choice_2, new_timelink_1);
                cout<<"Do you want to continue reservation service?"<<endl;
                cout<<"1. Yes \n2. NO"<<endl;
                int conti_num_3;
                cin>>conti_num_3;
                if(conti_num_3 == 1) {
                    outerNext_2 = true;
                } else {
                    outerNext_2 = false;
                }
                break;
            case 4:
                cout<<"------------------------------------------"<<endl;
                outerNext_2 = false;
                break;
            default:
                cout<<"------------------------------------------"<<endl;
                cout<<"This is an invalid option"<<endl;
                cout<<"------------------------------------------"<<endl;
                cout<<"Do you want to continue reservation service?"<<endl;
                cout<<"1. Yes \n2. NO"<<endl;
                int conti_num_4;
                cin>>conti_num_4;
                if(conti_num_4 == 1) {
                    outerNext_2 = true;
                } else {
                    outerNext_2 = false;
                }
                break;
                
        }
    }
    cout<<"Thanks for using this system"<<endl;
    return 0;
}