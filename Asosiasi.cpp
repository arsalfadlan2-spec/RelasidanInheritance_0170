#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Ditambahkan untuk fungsi find

using namespace std;

class dokter; // Forward Declaration

class pasien {
public:
    string nama;
    vector<dokter*> daftar_dokter;

    pasien(string pNama) : nama(pNama) {
        cout << "Pasien \"" << nama << "\" terdaftar.\n";
    }
    ~pasien() {
        cout << "Pasien \"" << nama << "\" keluar dari sistem.\n";
    }

    void tambahDokter(dokter*);
    void cetakDokter();
};

class dokter {
public:
    string nama;
    vector<pasien*> daftar_pasien;

    dokter(string pNama) : nama(pNama) {
        cout << "Dokter \"" << nama << "\" aktif.\n";
    }
    ~dokter() {
        cout << "Dokter \"" << nama << "\" nonaktif.\n";
    }

    void tambahPasien(pasien*);
    void cetakPasien();
};

// Implementasi Method Pasien
void pasien::tambahDokter(dokter* pDokter) {
    // Cek apakah dokter sudah ada di daftar agar tidak duplikat
    for (auto& dr : daftar_dokter) {
        if (dr == pDokter) return; 
    }
    daftar_dokter.push_back(pDokter);
}

void pasien::cetakDokter() {
    cout << "=== Daftar Dokter yang menangani Pasien " << this->nama << " ===" << endl;
    if (daftar_dokter.empty()) {
        cout << "(Belum ada dokter)" << endl;
    } else {
        for (auto& dr : daftar_dokter) {
            cout << "- " << dr->nama << endl;
        }
    }
    cout << endl;
}

// Implementasi Method Dokter
void dokter::tambahPasien(pasien* pPasien) {
    // Cek apakah pasien sudah ada di daftar
    for (auto& psn : daftar_pasien) {
        if (psn == pPasien) return;
    }
    daftar_pasien.push_back(pPasien);
    
    // Otomatis tambahkan dokter ini ke daftar pasien (Asosiasi Dua Arah)
    pPasien->tambahDokter(this);
}

void dokter::cetakPasien() {
    cout << "=== Daftar Pasien dari Dokter " << this->nama << " ===" << endl;
    if (daftar_pasien.empty()) {
        cout << "(Belum ada pasien)" << endl;
    } else {
        for (auto& psn : daftar_pasien) {
            cout << "- " << psn->nama << endl;
        }
    }
    cout << endl;
}

int main() {
    // Inisialisasi Objek di Heap
    dokter* dr1 = new dokter("dr. Budi");
    dokter* dr2 = new dokter("dr. Tono");
    
    pasien* psn1 = new pasien("Andi");
    pasien* psn2 = new pasien("Lia");

    cout << "\n--- Proses Asosiasi ---\n";
    dr1->tambahPasien(psn1);
    dr1->tambahPasien(psn2);
    dr2->tambahPasien(psn1);
    
    // Mencoba menambah pasien yang sama ke dokter yang sama (tidak akan duplikat)
    dr1->tambahPasien(psn1); 

    // Menampilkan Output
    dr1->cetakPasien();
    dr2->cetakPasien();
    psn1->cetakDokter();
    psn2->cetakDokter();

    // Cleanup Memori
    delete psn1;
    delete psn2;
    delete dr1;
    delete dr2;

    return 0;
}