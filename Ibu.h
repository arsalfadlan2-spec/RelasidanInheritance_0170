#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward Declaration agar class ibu tahu bahwa class anak akan ada
class anak;

class ibu {
public:
    string nama;
    vector<anak*> daftar_anak;

    // Konstruktor
    ibu(string pNama) : nama(pNama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    }

    // Destruktor
    ~ibu() {
        cout << "Ibu \"" << nama << "\" tidak ada\n";
    }

    void tambahAnak(anak*);
    void cetakAnak();
};

class anak {
public:
    string nama;
    anak(string pNama) : nama(pNama) {
        cout << "Anak \"" << nama << "\" ada\n";
    }
    ~anak() {
        cout << "Anak \"" << nama << "\" tidak ada\n";
    }
};

// Implementasi method class ibu
void ibu::tambahAnak(anak* pAnak) {
    daftar_anak.push_back(pAnak);
}

void ibu::cetakAnak() {
    cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
    for (int i = 0; i < daftar_anak.size(); i++) {
        cout << i + 1 << ". " << daftar_anak[i]->nama << endl;
    }
    cout << endl;
}

int main() {
    // Membuat objek Ibu
    ibu* ibuCantik = new ibu("Siti");

    // Membuat objek Anak
    anak* anak1 = new anak("Budi");
    anak* anak2 = new anak("Andi");

    // Menambahkan hubungan (Agregasi)
    ibuCantik->tambahAnak(anak1);
    ibuCantik->tambahAnak(anak2);

    // Menampilkan data
    ibuCantik->cetakAnak();

    // Menghapus ibu (Anak tetap ada di memori karena ini Agregasi)
    delete ibuCantik;

    cout << "Setelah Ibu dihapus, Anak masih ada: " << anak1->nama << endl;

    // Bersihkan memori anak
    delete anak1;
    delete anak2;

    return 0;
}