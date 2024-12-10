/**
 * Project Aplikasi Klinik
 */


#ifndef _MEDICALRECORD_H
#define _MEDICALRECORD_H

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Prescription.h"

class Doctor;
class Staff;

class MedicalRecord {
    public: 

        //menentukan data yang akan dibuka oleh fungsi
        static std::string datamedis;

        friend class Doctor;
        friend class Staff;

        /*contructor class MedicalRecord, data pengobatan dan resep obat yang diterima 
        pasien akan ditambahkan oleh dokter ataupun staff melalui fungsi yang berbeda*/
        MedicalRecord(const std::string& id = "", const std::string& nama = "", const std::string& diagnosis = "")
            :patientID(id), patientname(nama), diagnoses(diagnosis){}

        //fungsi untuk menampilkan seluruh data rekam medis
        void open_entireRecords(){
            //membuka file csv
            std::ifstream file (datamedis);

            //tempat menyimpan baris sementara
            std:: string line;
            //skip baris pertama yang hanya heading
            std:: getline (file, line);

            //header atas sebagai kolom tabel
            std:: cout  << "\nBerikut data medis yang tersimpan saat ini:\n"
                        << "============================================================================================\n"
                        << std::setw(2)  << "ID Pasien" 
                        << std::setw(20) << "Nama Pasien" 
                        << std::setw(26) << "Diagnosa Terakhir"
                        << std::setw(18) << "Resep Obat\n"
                        << "--------------------------------------------------------------------------------------------\n";

            //tampilkan semua data yang tersimpan di medical record saat ini
            while(getline(file,line)){
                std::istringstream ss(line);
                std::string id, nama, diagnosa, resep;
                
                /*meng-copy nilai yang terdapat pada baris yang diambil berdasarkan koma, 
                lalu memberikan nilai tersebut pada variabel yang sesuai untuk dioutputkan*/
                std:: getline(ss, id, ',');
                std:: getline(ss, nama, ',');
                std:: getline(ss, diagnosa, ',');
                std:: getline(ss, resep, ',');

                //menampilkan output pada terminal 
                std:: cout  << std::left
                            << std::setw(15) << id 
                            << std::setw(22) << nama 
                            << std::setw(21) << diagnosa 
                            << resep << '\n';                            
            }
            
            std::cout   << "============================================================================================\n";

            //membersihkan nilai line setelah output selesai
            line.clear();
            //menutup file csv
            file.close();    
        }

        //fungsi untuk menambahkan data rekam medis
        void addrecord(){

            //membuka file dalam mode menulis untuk dapat menambahkan data
            std::fstream file (datamedis, std::ios::app);

            //deklarasi variabel rekam sebagai default dari MedicalRecord
            MedicalRecord rekam;

            std::string prescription;

            //Mendapatkan input dari dokter atau staff yang mengurus
            std:: cout  << "Input ID pasien: ";
            std:: cin   >> rekam.patientID;

            std:: cin.ignore();

            std:: cout  << "Input nama pasien (maks. 3 kata): ";
            std:: getline(std::cin, rekam.patientname);

            std:: cout  << "Hasil diagnosis pasien: ";
            std:: getline(std::cin, rekam.diagnoses);

            std:: cout  << "resep yang diberikan (ketik 'fin' untuk mengakhiri): ";
            
            /*proses loop untuk mendapatkan beberapa input sebagai anggota vektor 
            prescription yang dapat berisi lebih dari satu obat*/
            bool selesai = true;
            while (selesai){
                std:: getline (std::cin, prescription);

                //input obat selesai saat kata "fin" diinputkan
                if (prescription == "fin"){
                    selesai = false;
                }
                else

                //data terbaru yang diterima akan diletakkan pada posisi terbelakang vektor
                {rekam.prescription.push_back(prescription);}
            }

            //penulisan data dimulai dengan identitas pasien serta diagnosa
            file    << rekam.patientID << "," 
                    << rekam.patientname << "," 
                    << rekam.diagnoses << ",";
                
                //loop untuk menuliskan setiap data resep obat yang diberikan dokter
                //rekam.prescription.size() akan return jumlah vektor dari prescription
                for (int i = 0; i < rekam.prescription.size(); ++i) {
                    file << rekam.prescription[i];

                    /*setiap obat akan dipisahkan dengan tanda "|" untuk 
                    membedakan dari kolom file csv lainnya*/
                    if (i < rekam.prescription.size() - 1) {
                        file << "|";
                        }
                }
                file << '\n';

            file.close();
        }
    
        //fungsi untuk menampilkan salah satu rekam medis
        void displayrecord(){
            
            //meminta id yang akan ditampilkan
            std::string id_dicari;
            std::cout << "\nSilahkan input id pasien untuk melihat rekam medisnya: ";
            std::cin >> id_dicari;
            
            std::ifstream file (datamedis);
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

            //message tambahan jika data tidak ditemukan karena belum terdaftar
            if(ketemu == false){
                std:: cout << "\nData dengan ID tersebut belum terdaftar.";
            }
            
            file.close();
        }
        
        //fungsi untuk menghapus salah satu data rekam medis
        void deleterecord(){
            
            std:: string id_dicari;
            std:: cout   << "Silahkan input id data yang akan dihapus: ";
            std:: cin    >> id_dicari;

            std:: ifstream file (datamedis);
            std:: string line;
            std:: vector <std::string> memori;

            std:: getline(file, line);

            //membandingkan id input dengan yang ada di file
            while(getline(file, line)){
                std:: istringstream ss (line);
                std:: string id;

                //mengambil nilai id yang terdapat di file
                std:: getline (ss, id, ',');

                //kondisi jika id sama, satu baris akan diskip
                if(id == id_dicari){
                    continue;
                }

                //vektor akan berisi baris-baris yang tidak dihapus
                memori.push_back(line);
            }

            file.close();

            std:: ofstream tulis_ulang (datamedis);

            //menuliskan ulang data yang masuk ke memori
            for(int i = 0; i < memori.size(); i++){
                tulis_ulang << memori[i] << '\n';
            }

            std::cout << "\ndata yang dipilih telah dihapus\n";

            //membersihkan nilai yang masih terdapat di variabel line
            line.clear();
            tulis_ulang.close();
        }

    private: 
        std:: string patientID;
        std:: string patientname;
        std:: string diagnoses;
        std:: vector < std::string > prescription;
};

//data csv yang akan dibuka oleh fungsi manapun dari class ini
std::string MedicalRecord::datamedis = "data_MedRecord.csv";

#endif //_MEDICALRECORD_H