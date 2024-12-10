/**
 * Project Aplikasi Klinik
 */


#ifndef _PRESCRIPTION_H
#define _PRESCRIPTION_H

#include <string>
#include <list>
#include "Pharmacist.h"

class Pharmacist;

class Prescription {
    
public: 
    
bool checkValidity();
    
/**
 * @param pharmacist
 */
void sendToPharmacist(const Pharmacist& pharmacist);

private: 
    std:: string prescriptionID;
    std:: list <std::string> medications;
};

#endif //_PRESCRIPTION_H