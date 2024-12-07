/**
 * Project Aplikasi Klinik
 */


#ifndef _PAYMENT_H
#define _PAYMENT_H

#include <global.h>

class Payment {
public: 
    
void processPayment();

private: 
    string paymentID;
    double amount;
    Date date;
};

#endif //_PAYMENT_H