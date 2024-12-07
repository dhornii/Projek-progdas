/**
 * Project Aplikasi Klinik
 */


#ifndef _APPOINTMENT_H
#define _APPOINTMENT_H

#include <iostream>
#include "Date.h"

using namespace std;

class Appointment {
public: 

void chooseTime();
    
void confirmAvailability();

private: 
    string appointmentID;
    Date time;
    bool status;
    };

#endif //_APPOINTMENT_H