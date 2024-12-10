#include "./File Header/Patient.h"
#include <map>

void login_pasien();
void menu_awal();
void Register_pasien();
void menu_utama_ps();
void login_pahlawan();

int main(){
    menu_awal();

    return 0;
}

void menu_utama_ps(){
    std::cout << "tes";
;}

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
                        << "Ketik pilihanmu: ";
            std:: cin   >> choice;

        switch (choice){
            case 1:
                login_pasien();
                break;

            case 2:
                login_pahlawan();
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

    std:: cout  << "\tHalaman Registrasi Akun Pasien\n"
                << "=========================================\n"
                << "Username (tanpa spasi): ";
    std:: cin   >> username;

    std:: cin.ignore();

    std:: cout  << "Password: ";
    std:: getline(std::cin, password);

    std::fstream file ("datadummyakunps.csv", std::ios::app);
    file << username << "," << password << '\n';
    file.close();

    std::cout << "\nRegisterasi berhasil, kembali ke menu awal\n";

    menu_awal();
}

void login_pasien(){
    std::string username;
    std::string password;

    std:: cout  << "\tHalaman Login Akun Pasien\n"
                << "=========================================\n"
                << "Username: ";
    std:: cin   >> username;

    std:: cin.ignore();

    std:: cout  << "Password: ";
    std:: getline(std::cin, password);

    std::ifstream file ("datadummyakunps.csv");
    std::string line;

    bool status = false;

    while(getline(file, line)){
        std:: istringstream ss(line);
        std:: string nama, pass;

        std:: getline(ss, nama, ',');

        if(nama == username){
            std:: getline (ss, pass, ',');

            if(pass == password){
                status = true;
            }
            break;
        }
    }

    if(status){
        menu_utama_ps();
    }
    else{
        std::cout   << "\nusername atau password salah\n"
                    << "Kembali ke menu awal\n";

        menu_awal();

    }



}

void login_pahlawan(){

}