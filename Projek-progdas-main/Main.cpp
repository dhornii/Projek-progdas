#include "./Tugas Progdas/File Header/global.h"
#include <map>

void login_pasien();
void menu_awal();
void Register_pasien();
void menu_utama_ps();
bool login_DokterdanStaff();
void displaydataakun();
void opsidisplay();
void menu_saldops();
void menu_utama_RS();
void menu_RM();
void menu_jadwal();

std:: string apapun;

std::string tempusername;
std::string temppassword;
int tempuang;

int main(){
    menu_awal();


    return 0;
}

void opsireservasi(){
    Appointment jadwal;
    jadwal.open_allAppointment();

    int opsi1;
    std:: cout  << "Input ID reservasi yang diinginkan: \n"
                << "(Ketik 0 untuk kembali)\n\n";
    std:: cin   >> opsi1;

    if(opsi1 > 0){
        std:: string opsi1str = std::to_string(opsi1);
        jadwal.bayar_reservasi(tempuang, tempusername, opsi1str);
    }else{
        return;
    }
}

void opsidisplay(){
    Patient pasien;
    int opsi;
    std:: cout  << "\n1. Cari melalui nama lengkap pasien\n"
                << "2. Hubungi Staff Administrasi\n"
                << "Pilihan: ";

                std:: cin >> opsi;
                if(opsi==1){
                    pasien.viewMedicalRecord();
                }else{
                    std::cout   << "\nBerikut kontak klinik yang tersedia: \n\n"
                                << "Telephone: (0841) 2723\n"
                                << "WhatsApp: 085707083831"
                                << "\n\nInput apapun untuk kembali pada menu utama";

                    std::cin    >> apapun;
                }
}

void displaydataakun(){
    std::cout   << "\nData akun anda saat ini adalah: \n"
                << "username: " << tempusername << '\n'
                << "password: " << temppassword << '\n'
                << "\n\nInput apapun untuk kembali pada menu utama";
    std::cin    >> apapun;;
}

void menu_saldops(){
    Payment pembayaran;
    int opsi;

    pembayaran.walletdetail(tempusername, tempuang);
    std:: cout  << "\n1. Tambah saldo\n"
                << "0. Kembali ke menu utama\n"
                << "Pilihan: ";
    std:: cin   >> opsi;

    if(opsi == 1){
        pembayaran.top_up(tempuang, tempusername);
    }
    else{
        return;
    }
}

void menu_utama_ps(){
    Patient pasien;
    Payment pembayaran;
    while(true){
        int choice1;
        std:: cout  << "\n=========================================\n"
                    << "\tMenu Utama Klinik\n"
                    << "=========================================\n"
                    << "Silahkan pilih opsi yang diinginkan: \n"
                    << "1. Detail data akun\n"
                    << "2. Cek data rekam medis\n"
                    << "3. Reservasi pemeriksaan\n"
                    << "4. Cek saldo saat ini\n"
                    << "0. Logout akun\n"
                    << "Pilihan: ";

        std:: cin >> choice1;

        switch (choice1){
            case 1:
                displaydataakun();
                break;
            
            case 2:
                opsidisplay();
                break;

            case 3:
                opsireservasi();
                break;
            
            case 4:
                menu_saldops();
                break;

            case 0:
                return;

            default:
                std::cout << "Input tidak valid, mohon beri input kembali\n";
        }
    }
}   

void menu_awal(){
    while (true){
        int choice;
            std:: cout  << "\n==============================\n" 
                        << "\tAplikasi Klinik\n"
                        << "==============================\n"
                        << "Silahkan pilih menu login atau register:\n"
                        << "1. Login Akun Pasien\n"
                        << "2. Login Akun Staff atau Dokter\n"
                        << "3. Register (untuk Pasien baru)\n"
                        << "0. Exit\n"
                        << "Pilihan: ";
            std:: cin   >> choice;

        switch (choice){
            case 1:
                login_pasien();
                break;

            case 2:
                login_DokterdanStaff();
                break;

            case 3:
                Register_pasien();
                break;

            case 0:
                std::cout << "Terima kasih telah menggunakan jasa kami! :D";
                return;

            default:
                std::cout << "Input tidak valid, mohon beri input kembali\n";

        }

    }
}

void Register_pasien(){
    std::string username;
    std::string password;

    std:: cout  << "\n=========================================\n"
                << "\tHalaman Registrasi Akun Pasien\n"
                << "=========================================\n"
                << "Username (tanpa spasi): ";
    std:: cin   >> username;

    std:: cin.ignore();

    std:: cout  << "Password: ";
    std:: getline(std::cin, password);

    std::fstream file ("data_akun_pasien.csv", std::ios::app);
    file << username << "," << password << '\n';
    file.close();

    std::cout   << "\nRegisterasi berhasil, kembali ke menu awal"
                << "\n\nInput apapun untuk kembali pada menu utama";

    std::cin    >> apapun;

    menu_awal();
}

void login_pasien(){
    std::string username;
    std::string password;

    std:: cout  << "\n=========================================\n"
                << "\tHalaman Login Akun Pasien\n"
                << "=========================================\n"
                << "Username: ";
    std:: cin   >> username;

    std:: cin.ignore();

    std:: cout  << "Password: ";
    std:: getline(std::cin, password);

    std::ifstream file ("data_akun_pasien.csv");
    std::string line;

    bool status = false;

    std:: getline(file, line);

    while(getline(file, line)){
        std:: istringstream ss(line);
        std:: string nama, pass, uangstr;

        std:: getline(ss, nama, ',');

        if(nama == username){
            std:: getline (ss, pass, ',');

            if(pass == password){
                status = true;
                
                std:: getline(ss, uangstr, ',');

                tempuang = std::stoi(uangstr);
                tempusername = nama;
                temppassword = pass;
            }
            break;
        }
    }

    if (status){
        std::cout   << "\nLogin berhasil!, menuju menu utama\n"
                    << "\n\nInput apapun untuk melanjutkan";
        std::cin    >> apapun;
        menu_utama_ps();
    }
    else {
        std::cout   << "\nusername atau password salah\n"
                    << "Kembali ke menu awal\n"
                    << "\n\nInput apapun untuk melanjutkan";
        std::cin    >> apapun;
        menu_awal();
    }
}

bool login_DokterdanStaff(){
    std:: map <std::string, std::string> data_akun_DokterdanStaff = {
        {"Administrator1", "Meja1"},
        {"Administrator2", "Meja2"},
        {"Dokter1", "Ruang1"},
        {"Dokter2", "Ruang2"},
        {"Dokter3", "Ruang3"},
        {"Apoteker1", "Apotek1"},
        {"Apoteker2", "Apotek2"},
        {"Staffbawah", "Staffbottom"},
        {"Staffatas", "Staffupper"}
    };

    std:: string username, password;

    std:: cout  << "\n================================================\n"
                << "\tHalaman Login Akun Staff dan Dokter\n"
                << "================================================\n"
                << "Username: ";
    std:: cin   >> username;

    std:: cin.ignore();

    std:: cout  << "Password: ";
    std:: getline(std::cin, password);

    if (data_akun_DokterdanStaff.find(username) != data_akun_DokterdanStaff.end() &&
        data_akun_DokterdanStaff[username] == password) {
        std::cout << "\nLogin berhasil!\n";
        menu_utama_RS();
        return true;
    }

    std::cout   << "\nusername atau password salah\n"
                << "Kembali ke menu awal\n"
                << "\n\nInput apapun untuk melanjutkan";
    std::cin    >> apapun;
    return false;
}

void menu_utama_RS(){
    Appointment periksa;
    while(true){
        int choice2;
        std:: cout  << "\n============================================\n"
                    << "\tMenu Utama Klinik (Mode Karyawan)\n"
                    << "============================================\n"
                    << "Silahkan pilih opsi yang diinginkan: \n"
                    << "1. Menu data rekam medis\n"
                    << "2. Jadwal pemeriksaan periode saat ini\n"
                    << "0. Logout akun\n"
                    << "Pilihan: ";

        std:: cin >> choice2;

        switch(choice2){
            case 1:
                menu_RM();
                break;

            case 2:
                periksa.open_allAppointment();
                break;

            case 0:
                return;
            default:
                std::cout << "Input tidak valid, mohon beri input kembali\n";
        }

    }
}

void menu_RM(){
    MedicalRecord MR_data;
    while(true){
        int choice2;
        std:: cout  << "\n=========================================\n"
                    << "\tMenu Data Rekam Medis\n"
                    << "=========================================\n"
                    << "Silahkan pilih opsi yang diinginkan: \n"
                    << "1. Tampilkan semua data\n"
                    << "2. Tampilkan salah satu data\n"
                    << "3. Tambahkan data\n"
                    << "4. Hapus salah satu data\n"
                    << "0. Kembali\n"
                    << "Pilihan: ";

        std:: cin >> choice2;

        switch(choice2){
            case 1: 
                MR_data.open_entireRecords();
                break;

            case 2:
                MR_data.displayrecord();
                break;

            case 3:
                MR_data.addrecord();
                break;
            
            case 4:
                MR_data.deleterecord();

            case 0:
                return;

            default:
                std::cout << "Input tidak valid, mohon beri input kembali\n";
        }

    }
}