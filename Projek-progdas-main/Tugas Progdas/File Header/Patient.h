/**
 * Project Aplikasi Klinik
 */


#ifndef _PATIENT_H
#define _PATIENT_H

#include "MedicalRecord.h"
#include "Payment.h"

class Patient {
    public: 

        static std::string datamedis_pasien;
        static std::string data_akunPasien;

        Patient(const std::string& id = "", const std::string& nama = "")
            : patientID(id), name(nama){}

        void Register_pasien(){
            std::string username;
            std::string password;

            std:: cout  << "\tHalaman Registrasi Akun Pasien\n"
                        << "================================"
                        << "Username (tanpa spasi): ";
            std:: cin   >> username;

            std:: cin.ignore();

            std:: cout  << "Password: ";
            std:: getline(std::cin, password);

            std::fstream file (data_akunPasien, std::ios::app);
            file << username << ", " << password << '\n';
            file.close();
        }
    
        void viewMedicalRecord(){
            
            //menetapkan id yang akan ditampilkan sebagai id milik pasien tersebut
            std::string id_dicari = patientID;

            std::ifstream file (datamedis_pasien);
            std::string line;

            //kondisi yang menentukan apakah data rekam medis yang dicari ada atau tidak
            bool ketemu = false;

            //program membandingkan input dengan id yang terdapat di file
            while(getline(file, line)){
                std::istringstream ss(line);
                std::string id, nama, diagnosa, resep_full;

                std:: getline(ss, id, ',');

                //id yang sesuai akan ditampilkan seluruh informasinya
                if(id == id_dicari){
                    std:: getline (ss, nama, ',');
                    std:: getline (ss, diagnosa, ',');
                    std:: getline (ss, resep_full, ',');

                    std:: cout  << "ID pasien: " << id << '\n'
                                << "Nama pasien: " << nama << '\n'
                                << "Diagnosa terakhir: " << diagnosa << '\n'
                                << "Resep terakhir yang diberikan: \n";

                    std:: istringstream batas(resep_full);
                    std:: string resep_detail;

                    //memberikan list obat dari rekam medis
                    while(getline(batas, resep_detail, '|')){
                        std::cout << "- " << resep_detail << '\n';
                    }
                    ketemu = true;
                    break;
                }   
            }

            if(ketemu == false){
                std:: cout << "\nData dengan ID tersebut belum terdaftar, silahkan hubungi administrasi";
            }
            
            file.close();
        }
    
/**
 * @param time
 */
        Appointment bookAppointment(Date time);
    
/**
 * @param amount
 */
        Payment makePayment(double amount);

    private: 
        std:: string patientID;
        std:: string name;
        Date date_of_birth;
};

std::string Patient::datamedis_pasien   = "data_MedRecord.csv";
std::string Patient::data_akunPasien    = "data_akun_pasien.csv";

#endif //_PATIENT_H