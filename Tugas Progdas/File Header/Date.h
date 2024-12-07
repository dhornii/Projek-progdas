#include <string>

struct Date{
    std:: string hari;

    enum class jam_datang{
        Pagi,
        Siang,
        Sore,
        Malam
    };

    jam_datang jadwal;
    int tanggal;
    int bulan;
    int tahun;
};