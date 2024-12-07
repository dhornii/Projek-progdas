/**
 * Project Aplikasi Klinik
 */


#ifndef _DOCTOR_H
#define _DOCTOR_H

#include <global.h>

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
    string doctorID;
    string name;
    string specialization;
};

#endif //_DOCTOR_H