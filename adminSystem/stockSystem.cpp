#pragma once
#include <iostream>
#include <fstream>
using namespace std;

//bismillah

string nama[100];  //Ini buat nyimpen nama item 
int jumlah[100];   //Ini buat nyimpen jumlah item
int banyak = 0;    //Ini buat nyimpen banyak item yang ada di stock

//Ini buat mengubah string menjadi huruf kecil semua (casesensitive)
string kecil(string teks) {
    for (int i = 0; i < teks.length(); i++) {
        if (teks[i] >= 'A' && teks[i] <= 'Z') {
            teks[i] = teks[i] + 32;
        }
    }
    return teks;
}

//ini buat cari item di stock, kalo ketemu return indexnya, kalo ga ketemu return -1
int cariItem(string cari) {
    for (int i = 0; i < banyak; i++) {
        if (kecil(nama[i]) == kecil(cari)) {
            return i;
        }
    }
    return -1;
}

//ini buat baca data dari file stock.txt
void bacaData() {
    banyak = 0;
    ifstream file("data/stock.txt");
    string baris;
    while (getline(file, baris)) {
        int koma = baris.find(',');
        if (koma == -1) continue;  
        nama[banyak] = baris.substr(0, koma);
        jumlah[banyak] = stoi(baris.substr(koma + 1));
        banyak++;
    }
    file.close();
}

//ini buat simpan data ke file stock.txt
void simpanData() {
    ofstream file("data/stock.txt");
    for (int i = 0; i < banyak; i++) {
        file << nama[i] << "," << jumlah[i] << endl;
    }
    file.close();
}

//ini buat nampilin stock ke layar
void tampilStok() {
    cout << "[ Stok Barang ]" << endl;
    cout << "==================" << endl;

    if (banyak == 0) {
        cout << "Stok masih kosong." << endl;
        return;
    }
    for (int i = 0; i < banyak; i++) {
        cout << i + 1 << ". " << nama[i] << ", Jumlah: " << jumlah[i] << endl;
    }
    cout << "\n";
}

//ini buat liat stock
void viewStock() {
    bacaData();
    tampilStok();

    string keluar;
    do {
        cout << "[0.Keluar] : ";
        cin >> keluar;
        cout << endl;
    } while (keluar != "0");
}


//ini buat input stock baru
void inputStock() {
    bacaData();
    tampilStok();
    string namaBaru;
    int tambah;
    cout << "Masukkan nama item : ";
    cin.ignore();
    getline(cin, namaBaru);
    cout << "Masukkan jumlah item : ";
    cin >> tambah;

    int posisi = cariItem(namaBaru);
    if (posisi != -1) {
        jumlah[posisi] += tambah;
        cout << "Item sudah ada, stok ditambah." << endl;
    } else {
        nama[banyak] = namaBaru;
        jumlah[banyak] = tambah;
        banyak++;
        cout << "Item baru ditambahkan!\n" << endl;
    }
    simpanData();
}

//ini buat hapus stock
void deleteStock() {
    bacaData();
    tampilStok();
    string hapus;
    cout << "Masukkan nama item yang ingin dihapus : ";
    cin.ignore();
    getline(cin, hapus);

    int posisi = cariItem(hapus);
    if (posisi == -1) {
        cout << "Item tidak ditemukan.\n" << endl;
        return;
    }


    for (int i = posisi; i < banyak - 1; i++) {
        nama[i] = nama[i + 1];
        jumlah[i] = jumlah[i + 1];
    }
    banyak--;
    simpanData();
    cout << "Item berhasil dihapus!\n" << endl;
}