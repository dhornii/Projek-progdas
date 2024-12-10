/**
 * Project Aplikasi Klinik
 */


#ifndef _PHARMACIST_H
#define _PHARMACIST_H

#include <string>
#include "Prescription.h"

class Prescription;

class Pharmacist {
public: 
    
/**
 * @param prescription
 */
void processMedicationOrder(const Prescription* prescription);

private: 
    std:: string pharmacistID;
    std:: string name;
};

    #endif //_PHARMACIST_H