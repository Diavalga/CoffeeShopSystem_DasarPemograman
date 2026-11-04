#include <iostream>
#include "adminSystem/stockSystem.cpp"
#include "buyerSystem/order.cpp"
#include "buyerSystem/receipt.cpp"

using namespace std;

bool passwordCheck() {
    int percobaan = 0;
    while (percobaan < 3) {
        string password;
        cout << "Password : ";
        cin >> password;
        if (password == "admin123") {
            return true;
        } else {
            cout << "Password salah. Silakan coba lagi." << endl;
            percobaan++;
        }
    }
    return false;
}

void adminMenu() {
        cout << "[ Menu Admin ]" << endl;
    cout << "==================" << endl;
    cout << "1. Lihat Stok" << endl;
    cout << "2. Tambah Stok" << endl;
    cout << "3. Hapus Stok" << endl;
    cout << "0. Kembali" << endl;
    cout << "Anda : ";
    int pilihan;
    do {
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                viewStock();
                break;
            case 2:
                inputStock();
                break;
            case 3:
                deleteStock();
                break;
            case 0:
                cout << "Kembali ke menu utama." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 0);
}

void buyerMenu() {
    int pilihan;
    do {
        cout << "[ Menu Pembeli ]" << endl;
        cout << "==================" << endl;
        cout << "1. Lihat Menu" << endl;
        cout << "2. Buat Pesanan" << endl;
        cout << "3. Lihat Riwayat Pesanan" << endl;
        cout << "0. Kembali" << endl;
        cout << "Anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // lihatMenu();         // <- Tolong tambahin ini kalo udah ada fungsi buat liat menu
                break;
            case 2:
                // buatPesanan();       // <- Tolong tambahin ini kalo udah ada fungsi buat bikin pesanan
                break;
            case 3:
                // lihatRiwayat();      // <- Tolong tambahin ini kalo udah ada fungsi buat liat riwayat pesanan
                break;
            case 0:
                cout << "Kembali ke menu utama." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 0);
}

int main(){
    int pilihan;
    do {
        cout << "[ Menu Utama ]" << endl;
        cout << "==================" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Pembeli" << endl;
        cout << "0. Keluar" << endl;
        cout << "Anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (passwordCheck()) {
                    adminMenu();
                } else {
                    cout << "Password salah. Akses ditolak." << endl;
                }
                break;
            case 2:
                buyerMenu();
                break;
            case 0:
                cout << "Anda telah keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}