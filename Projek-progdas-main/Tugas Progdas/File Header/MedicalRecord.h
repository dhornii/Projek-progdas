/**
 * Project Aplikasi Klinik
 */


#ifndef _MEDICALRECORD_H
#define _MEDICALRECORD_H

#include <global.h>

class MedicalRecord {
    public: 
    
    ifstream in;
    ifstream out;
    string fileName;

    MedicalRecord(const char* fileName){
        MedicalRecord:: fileName = fileName;
    }

void open_medrecords(){

}
    
/**
 * @param notes
 */
void update(string notes);
    
/**
 * @param notes
 */
void addNoteToRecord(string notes);

private: 
    string recordID;
    string patientname;
    string diagnoses;
    list<string> notes;
    list<Prescription> prescriptions;
};

#endif //_MEDICALRECORD_H