/**
 * Project Aplikasi Klinik
 */


#ifndef _BILL_H
#define _BILL_H

#include <iostream>
#include <string>


class Bill {
        
        std:: string billID;
        std:: string patientID;
        
        int jasa_dokter;
        int biaya_tindakan;

        double total_amount;
        double discount = 0;
        
        static int jasa_rs;
        static int uang_administrasi;

    public: 

        Bill(std:: string bid, std:: string pid, int doctorcost, int treatmentcost)
            : billID(bid), patientID(pid), jasa_dokter(doctorcost), biaya_tindakan(treatmentcost){}

        void applydiscount(double persen){
            discount = persen;
        }

        void generateBill(){
            total_amount = jasa_dokter + jasa_rs + biaya_tindakan + uang_administrasi;

            std:: cout << "Biaya jasa dokter: Rp " << jasa_dokter << '\n'
                       << "Biaya jasa rumah sakit: Rp " << jasa_rs << '\n'
                       << "Biaya tindakan: Rp " << biaya_tindakan << '\n'
                       << "Biaya administrasi: Rp " << uang_administrasi << '\n'
                       << "Keringanan biaya asuransi sebanyak: " << discount <<"%";
                        if(discount > 0){
                            total_amount -= total_amount*discount/100;
                        }
            std:: cout << '\n' << "Biaya total yang dibayarkan: Rp " << total_amount << std:: endl;
        }
};

int Bill::jasa_rs = 20000;
int Bill::uang_administrasi = 15000;

#endif //_BILL_H