/**
 * Project Aplikasi Klinik
 */


#ifndef _PAYMENT_H
#define _PAYMENT_H

#include "Appointment.h"

class Payment {
public: 
    
void processPayment();

private: 
    std:: string paymentID;
    double amount;
    Date date;
};

#endif //_PAYMENT_H