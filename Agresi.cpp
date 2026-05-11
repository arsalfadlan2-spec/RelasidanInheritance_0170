#include <iostream>
#include "anak.h"
#include "ibu.h"

using namespace std;

int main() {
    // Membuat objek Ibu
    ibu* varIbu = new ibu("dini");
    ibu* varIbu2 = new ibu("novi");

    // Membuat objek Anak
    anak* varAnak1 = new anak("tono");
    anak* varAnak2 = new anak("rini");
    anak* varAnak3 = new anak("Dewi");

    // Menambahkan hubungan (Agregasi)
    varIbu->tambahAnak(varAnak1);
    varIbu->tambahAnak(varAnak2);
    varIbu2->tambahAnak(varAnak3);
    varIbu2->tambahAnak(varAnak1); // Satu anak bisa punya banyak ibu dalam kode ini

    // Cetak hasil
    varIbu->cetakAnak();
    varIbu2->cetakAnak();

    // Hapus objek dari memori
    delete varIbu;
    delete varIbu2;
    delete varAnak1;
    delete varAnak2;
    delete varAnak3;

    return 0;
}