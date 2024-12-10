/**
 * Project Aplikasi Klinik
 */


#ifndef _DOCTOR_H
#define _DOCTOR_H

#include "Appointment.h"
#include "Prescription.h"
#include "MedicalRecord.h"

class Doctor {
public: 
    
/**
 * @param appointment
 */
void conductConsultation(Appointment appointment){

}
    
Prescription generatePrescription();
    
/**
 * @param record
 */
void updateMedicalRecord(MedicalRecord record){

}
private: 
    std:: string doctorID;
    std:: string specialization;
    std:: string name;
};

#endif //_DOCTOR_H