/**
 * Project Aplikasi Klinik
 */


#ifndef _APPOINTMENT_H
#define _APPOINTMENT_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Date.h"


class Appointment {
public: 

    static std::string data_jadwal;
    static std::string data_akun;

    void open_allAppointment(){
        //membuka file csv
        std::ifstream file (data_jadwal);

        //tempat menyimpan baris untuk sementara
        std:: string line;
        //skip baris pertama yang hanya heading
        std:: getline (file, line);

        //header atas sebagai kolom tabel
        std:: cout  << "\nBerikut jadwal dokter yang tersedia periode ini (1-15 Desember 2024) : \n"
                        << "=====================================================================================================\n"
                        << "ID"
                        << std::setw(15) << "Nama Dokter" 
                        << std::setw(14) << "Spesialis" 
                        << std::setw(15) << "Ruang Temu"
                        << std::setw(30) << "Tanggal dan Waktu Praktik"
                        << std::setw(26) <<"Biaya Reservasi (Rp)\n"
                        << "-----------------------------------------------------------------------------------------------------\n";

        //tampilkan semua data
        while(getline(file,line)){
                std::istringstream ss(line);
                std::string no, nama, spesialis, ruang, waktu, uang;
                
                /*meng-copy nilai yang terdapat pada baris yang diambil berdasarkan koma, 
                lalu memberikan nilai tersebut pada variabel yang sesuai untuk dioutputkan*/
                std:: getline(ss, no, ',');
                std:: getline(ss, nama, ',');
                std:: getline(ss, spesialis, ',');
                std:: getline(ss, ruang, ',');
                std:: getline(ss, waktu, ',');
                std:: getline(ss, uang, ',');

                //menampilkan output pada terminal 
                std:: cout  << std::right
                            << no
                            << std::setw(13) << nama 
                            << std::setw(17) << spesialis 
                            << std::setw(13) << ruang 
                            << std::setw(26) << waktu 
                            << std::setw(21) << uang << '\n';                            
        }
            
        std::cout   << "=====================================================================================================\n"
                    << "\nInformasi waktu praktik: \n"
                    << "- Pagi: 08.00 - 11.45 WIB\n"
                    << "- Siang: 13.00 - 15.30 WIB\n"
                    << "- Sore: 16.00 - 17.45 WIB\n"
                    << "- Malam: 17.15 - 20.30 WIB\n";

        //membersihkan nilai line setelah output selesai
        line.clear();
        //menutup file csv
        file.close();    
    }

    void bayar_reservasi(int& sekarang, const std::string& pemilik, const std::string& id){
        std:: ifstream baca (data_jadwal);

        bool terbayar = false;
        bool id_ketemu = false;
        std::string line;

        while(getline(baca, line)){
            std:: istringstream ss (line);
            std:: string ID, nama, spesialis, ruang, waktu, biaya;
            int biayaint;

            std:: getline (ss, ID, ',');
            std:: getline (ss, nama, ',');
            std:: getline (ss, spesialis, ',');
            std:: getline (ss, ruang, ',');
            std:: getline (ss, waktu, ',');
            std:: getline (ss, biaya, ',');

            if(ID == id){
                biayaint = std:: stoi(biaya);
                id_ketemu = true;
                if(sekarang >= biayaint){
                    sekarang -= biayaint;
                    terbayar = true;
                }
                else{
                    std::cout << "Saldo akun anda tidak cukup, kembali ke menu utama";
                    break;
                }
            }
        
        }

        if(terbayar == true){
            std:: ifstream file (data_akun);
            std:: string line;
            std:: vector <std::string> memori;

            while(getline(file, line)){
                    std:: istringstream ss (line);
                    std:: string nama, pass, duitstr;

                    std:: getline (ss, nama, ',');
                    std:: getline (ss, pass, ',');
                    std:: getline (ss, duitstr, ',');

                    if(nama == pemilik){
                    duitstr = std::to_string(sekarang);
                    }

                    memori.push_back(nama + "," + pass + "," + duitstr);
            }

            file.close();

            std:: ofstream tulis_ulang (data_akun);

            //menuliskan ulang data yang masuk ke memori
            for(int i = 0; i < memori.size(); i++){
                    tulis_ulang << memori[i] << '\n';
            }

            //membersihkan nilai yang masih terdapat di variabel line
            line.clear();
            tulis_ulang.close();
        }

        if(id_ketemu == false){
            std::string anything;
            std::cout   << "\nID reservasi tidak ditemukan, kembali ke menu utama\n"
                        << "input apapun untuk melanjutkan ";
            std::cin    >> anything;
        }else{
            std::string anything1;
            std::cout   << "\nReservasi berhasil, kami tunggu kedatangannya!\n"
                        << "input apapun untuk melanjutkan ";
            std::cin    >> anything1;
        }
    
    }

private: 
    std:: string appointmentID;
    Date time;
    bool status;
};

std::string Appointment::data_jadwal = "jadwal.csv";
std::string Appointment::data_akun = "data_akun_pasien.csv";

#endif //_APPOINTMENT_H