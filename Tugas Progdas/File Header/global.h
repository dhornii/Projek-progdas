#include <string>
#include <chrono>
#include <list>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

using namespace std;

#include <Appointment.h>
#include <staff.h>
#include <Bill.h>
#include <MedicalRecord.h>
#include <Doctor.h>
#include <Patient.h>
#include <Payment.h>
#include <Prescription.h>
#include <Pharmacist.h>

struct Date{
    string hari;

    enum class jam_datang{
        Pagi,
        Siang,
        Sore,
        Malam
    };

    jam_datang jadwal;
    int tanggal;
    int bulan;
    int tahun;
};