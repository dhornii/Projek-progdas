/**
 * Project Aplikasi Klinik
 */


#ifndef _PHARMACIST_H
#define _PHARMACIST_H

#include <global.h>

class Pharmacist {
public: 
    
/**
 * @param prescription
 */
void processMedicationOrder(Prescription prescription);

private: 
    string pharmacistID;
    string name;
};

#endif //_PHARMACIST_H