/**
 * Project Aplikasi Klinik
 */


#ifndef _STAFF_H
#define _STAFF_H

#include "Patient.h"
#include "Bill.h"

class Staff {
public: 
    
void addAppointment(){
  
}
    
/**
 * @param patient pasien tujuan 
 * @param message pesan yang dikirimkan pada pasien
 */
void notifyPatient(Patient patient, std:: string message);
    
/**
 * @param bill
 */
void manageBill(Bill bill);
    
/**
 * @param bill
 */
void applyDiscount(Bill bill);
private: 
    std:: string staffID;
    std:: string name;
};

#endif //_STAFF_H