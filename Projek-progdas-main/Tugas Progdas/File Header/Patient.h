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

        //constructor default untuk class ini
        Patient(const std::string& id = "", const std::string& nama = "")
            : patientID(id), name(nama){}

        //fungsi untuk melihat rekam medis nama yang diajukan
        void viewMedicalRecord(){
            
            std::string nama_dicari;

            std::cin.ignore();
            std::cout << "Silahkan input nama lengkap pasien: ";
            std::getline(std::cin, nama_dicari);

            std::ifstream file (datamedis_pasien);
            std::string line;

            //kondisi yang menentukan apakah data rekam medis yang dicari ada atau tidak
            bool ketemu = false;

            //program membandingkan input dengan id yang terdapat di file
            while(getline(file, line)){
                std::istringstream ss(line);
                std::string id, nama, diagnosa, resep_full;

                std:: getline(ss, id, ',');
                std:: getline(ss, nama, ',');

                //id yang sesuai akan ditampilkan seluruh informasinya
                if(nama == nama_dicari){
                    std:: getline (ss, diagnosa, ',');
                    std:: getline (ss, resep_full, ',');

                    std:: cout  << "\nBerikut data pasien yang ditemukan: \n"
                                << "======================================\n"
                                << "ID pasien: " << id << '\n'
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

            if(!ketemu){
                std:: cout << "\nData dengan nama tersebut belum terdaftar, silahkan hubungi administrasi";
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