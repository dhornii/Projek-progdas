/**
 * Project Aplikasi Klinik
 */


#ifndef _BILL_H
#define _BILL_H

#include <global.h>

class Bill {
    public: 

        Bill(string bid, string pid, int doctorcost, int treatmentcost)
            : billID(bid), patientID(pid), jasa_dokter(doctorcost), biaya_tindakan(treatmentcost){}

        void generateBill(){
            total_amount = jasa_dokter + jasa_rs + biaya_tindakan + uang_administrasi;

            cout << "Biaya jasa dokter: Rp " << jasa_dokter << endl;
            cout << "Biaya jasa rumah sakit: Rp " << jasa_rs << endl;
            cout << "Biaya jasa dokter: Rp " << biaya_tindakan << endl;
            cout << "Biaya jasa dokter: Rp " << uang_administrasi << endl;
            cout << '\n' << "Biaya total yang dibayarkan: Rp " << total_amount << endl;
        }
    
/**
 * @param percentage adalah persentase keringanan biaya yang didapat melalui asuransi
 */
        void applyDiscount(double percentage){
            total_amount -= (total_amount*percentage)/100;
        }

    private:
        string billID;
        string patientID;
        
        int jasa_dokter;
        int biaya_tindakan;

        double total_amount;
        double discount;
        
        static int jasa_rs;
        static int uang_administrasi;
};

#endif //_BILL_H