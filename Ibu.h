#ifndef IBU_H
#define IBU_H
#include <iostream>
#include <vector>
#include <string>
#include "anak.h" // Harus include ini karena menggunakan tipe data anak*

using namespace std;

class ibu {
public:
    string nama;
    vector<anak*> daftar_anak;

    ibu(string pNama) : nama(pNama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    }
    
    ~ibu() {
        cout << "Ibu \"" << nama << "\" tidak ada\n";
    }

    void tambahAnak(anak* pAnak) {
        daftar_anak.push_back(pAnak);
    }

    void cetakAnak() {
        cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
        for (int i = 0; i < daftar_anak.size(); i++) {
            cout << i + 1 << ". " << daftar_anak[i]->nama << endl;
        }
        cout << endl;
    }
};
#endif