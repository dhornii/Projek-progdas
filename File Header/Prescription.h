/**
 * Project Aplikasi Klinik
 */


#ifndef _PRESCRIPTION_H
#define _PRESCRIPTION_H

#include <global.h>

class Prescription {
public: 
    
bool checkValidity();
    
/**
 * @param pharmacist
 */
void sendToPharmacist(Pharmacist pharmacist);

private: 
    string prescriptionID;
    list <string> medications;
};

#endif //_PRESCRIPTION_H