/**
 * Project Aplikasi Klinik
 */


#ifndef _PATIENT_H
#define _PATIENT_H

#include "MedicalRecord.h"
#include "Payment.h"

class Patient {
public: 
    
void Register();
    
void viewMedicalRecord();
    
/**
 * @param time
 */
Appointment bookAppointment(Date time);
    
/**
 * @param amount
 */
Payment makePayment(double amount);
private: 
    string patientID;
    string name;
    Date dob;
    MedicalRecord medicalRecord;
};

#endif //_PATIENT_H