/**
 * Project Aplikasi Klinik
 */


#ifndef _MEDICALRECORD_H
#define _MEDICALRECORD_H

#include <global.h>

class MedicalRecord {
public: 
    
void access();
    
/**
 * @param notes
 */
void update(string notes);
    
/**
 * @param note
 */
void addNoteToRecord(string note);

private: 
    string recordID;
    string patientname;
    string diagnoses;
    list<string> notes;
    list<Prescription> prescriptions;
};

#endif //_MEDICALRECORD_H