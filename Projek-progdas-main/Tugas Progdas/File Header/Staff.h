/**
 * Project Aplikasi Klinik
 */


#ifndef _STAFF_H
#define _STAFF_H

#include "Patient.h"
#include "Bill.h"

class Staff {
public: 
    
/*
  @param appointment
 */
void manageAppointment(Appointment appointment);
    
/**
 * @param patient pasien tujuan 
 * @param message pesan yang dikirimkan pada pasien
 */
void notifyPatient(Patient patient, string message);
    
/**
 * @param bill
 */
void manageBill(Bill bill);
    
/**
 * @param bill
 */
void applyDiscount(Bill bill);
private: 
    string staffID;
    string name;
};

#endif //_STAFF_H