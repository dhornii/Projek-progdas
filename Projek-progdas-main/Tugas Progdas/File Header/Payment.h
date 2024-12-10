/**
 * Project Aplikasi Klinik
 */


#ifndef _PAYMENT_H
#define _PAYMENT_H

#include "Appointment.h"

class Payment {
public: 

    static std::string data_akunUser;
/** 
 * @param nama: nama akun yang akan diberikan detailnya 
 * @param uang: jumlah saldo saat ini
 **/
    void walletdetail(std:: string nama, int uang){
        std::cout   << "\nUsername atas nama: " << nama << '\n'
                    << "Saat ini memiliki saldo sebanyak: Rp "
                    << uang << '\n';
    }
/** 
 * @param sekarang: jumlah uang yang ada sekarang
 */
    void top_up(int& sekarang, const std::string& pemilik){
        int tambahan;
        std:: cout  << "Input jumlah to-up (minimal Rp 15000): ";
        std:: cin   >> tambahan;

        bool uangmasuk = false;

        if(tambahan >= 15000){
            uangmasuk = true;
            sekarang += tambahan; 
        }
        else{
            std:: cout << "\nInput tidak valid atau jumlah to-up tidak sesuai\n";
        }

        if(uangmasuk == true){
            std:: ifstream file (data_akunUser);
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

                //vektor akan berisi baris-baris yang tidak dihapus
                memori.push_back(nama + "," + pass + "," + duitstr);
            }

            file.close();

            std:: ofstream tulis_ulang (data_akunUser);

            //menuliskan ulang data yang masuk ke memori
            for(int i = 0; i < memori.size(); i++){
                tulis_ulang << memori[i] << '\n';
            }

            std::cout   << "\nSaldo berhasil ditambahkan pada akun: "
                        << pemilik << '\n';

            //membersihkan nilai yang masih terdapat di variabel line
            line.clear();
            tulis_ulang.close();
        }
    }

private: 
    std:: string paymentID;
    double amount;
    Date date;
};

std::string Payment::data_akunUser = "data_akun_pasien.csv";

#endif //_PAYMENT_H