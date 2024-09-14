#include <iostream>
#include <iomanip>
using namespace std;

double kecepatanjalan(double beratbadan, double tinggibadan){
    //berat badan dalam satuan kg
    //tinggi badan dalam satuan cm
    const double average_kecepatan = 4.68;

    double faktortinggi = 0.001; 
    //tambahan kecepatan sesuai tinggi badan
    double faktorberat  = 0.01;
    //pengurangan kecepatan sesuai berat badan

    double kecepatan_km_per_jam = average_kecepatan + (tinggibadan*faktortinggi) - (beratbadan*faktorberat);
    if (kecepatan_km_per_jam < 4.4){
        kecepatan_km_per_jam = 4.4;
        //tetapan kecepatan paling kecil yang mungkin didapat
    }
    double kecepatan_m_per_sekon = (kecepatan_km_per_jam*1000/3600);
    return kecepatan_m_per_sekon;
    //hasil kecepatan dalam satuan m/s
}

double waktuperjalanan(double jarak, double kecepatan){
    jarak = jarak*1000;
    
    return jarak/kecepatan;
    //hasil waktu yang kemungkinan ditempuh selama perjalanan
}

double waktuistirahat(double waktu_menit){
    int interval_istirahat = 30;
    int waktu_istirahat    = 15;

    int jumlah_istirahat = static_cast<int>(waktu_menit/interval_istirahat);

    return waktu_istirahat*jumlah_istirahat; 
    ///waktu istirahat yang disarankan setiap 30 menitnya selama perjalanan
}

double kaloriterbakar(double beratbadan, double waktu_menit){
    const double MET = 3.5;
    return (beratbadan*MET*3.5)/200*waktu_menit;
    //tambahan jumlah kalori yang terbakar setelah melakukan perjalanan
}

int main(){
    double berat, tinggi, jarak_tempuh;

    cout    <<"Masukkan berat badan anda dalam satuan kg: ";
    cin     >> berat;
    cout    << "Input tinggi badan anda dalam satuan cm: ";
    cin     >> tinggi;
    cout    << "Input jarak yang ditempuh (km): ";
    cin     >> jarak_tempuh;

    double kecepatan = kecepatanjalan(berat,tinggi);

    double waktu_perjalanan = waktuperjalanan(jarak_tempuh, kecepatan);
    double waktu_menit      = waktu_perjalanan/60;
    double waktu_jam        = waktu_menit/60;

    double waktu_istirahat = waktuistirahat(waktu_menit);

    double total_waktu_menit = waktu_istirahat + waktu_menit;
    double total_waktu_jam   = (waktu_istirahat/60) + waktu_jam;

    double kalori_terbakar = kaloriterbakar(berat, waktu_menit);

    cout<< fixed << setprecision(2);
    //tetapan nilai pada output yang memaksimalkan jumlah angka di belakang koma sebanyak 2
    cout<< "Kecepatan berjalan anda: " << kecepatan << " m/s"<<'\n';
    cout<<"Kemungkinan waktu tempuh perjalanan anda: " << waktu_menit << " menit"<<'\n';
    cout<<"Waktu istirahat yang disarankan: " << waktu_istirahat << " menit" << '\n';
    cout<<"Total waktu perjalanan anda dalam menit: " << total_waktu_menit << " menit"<<'\n';
    cout<<"Total waktu perjalanan anda dalam jam: " << total_waktu_jam << " jam"<<'\n';
    cout<<"Kalori yang terbakar: " << kalori_terbakar << " kalori"<<'\n';

    return 0;
}
