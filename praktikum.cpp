#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. Class Induk (Base Class)
// ==========================================
class User {
protected:
    // Deklarasi static variable
    static int globalId; 
    
    int id;
    string nama;
    string email;

    // Method untuk meng-generate ID otomatis
    int generateId() {
        globalId++;
        return globalId;
    }

public:
    // Constructor User
    User(string nama, string email) {
        this->id = generateId();
        this->nama = nama;
        this->email = email;
    }

    // Getter ditambahkan di C++ agar class Admin bisa membaca data ini
    int getId() const { return id; }
    string getNama() const { return nama; }
    string getEmail() const { return email; }
};

// Inisialisasi static variable C++ harus dilakukan di luar class
int User::globalId = 0; 


// ==========================================
// 2. Class Turunan Pertama (Member)
// Dideklarasikan lebih dulu agar dikenali oleh class Admin
// ==========================================
class Member : public User {
private:
    bool status;

public:
    // Memanggil constructor dari class induk (User) menggunakan Initialization List
    Member(string nama, string email) : User(nama, email) {
        this->status = true; // Secara default aktif
    }

    // Getter untuk status
    bool getStatus() const {
        return this->status;
    }

    // Setter untuk status
    void setStatus(bool status) {
        this->status = status;
    }

    // Method untuk menampilkan profil
    void showProfile() const {
        cout << "=== Profil Member ===" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Non-Aktif") << endl;
        cout << "=====================\n" << endl;
    }
};


// ==========================================
// 3. Class Turunan Kedua (Admin)
// ==========================================
class Admin : public User {
public:
    // Memanggil constructor class induk (User)
    Admin(string nama, string email) : User(nama, email) {}

    // Method menggunakan vector of pointers (Member*) untuk menghindari duplikasi memori
    void showAllMember(const vector<Member*>& memberList) const {
        cout << "=== Daftar Semua Member ===" << endl;
        for (Member* m : memberList) {
            cout << "ID: " << m->getId() 
                 << " | Nama: " << m->getNama() 
                 << " | Status Aktif: " << (m->getStatus() ? "Ya" : "Tidak") << endl;
        }
        cout << "===========================\n" << endl;
    }

    // Menggunakan pointer (Member*) agar status pada objek aslinya yang berubah
    void toggleActivationMember(Member* member) {
        member->setStatus(!member->getStatus()); // Membalik nilai boolean
        string statusSekarang = member->getStatus() ? "Aktif" : "Non-Aktif";
        cout << "Status member " << member->getNama() << " berhasil diubah menjadi: " << statusSekarang << "\n" << endl;
    }
};


// ==========================================
// Fungsi Utama (Main) untuk Testing
// ==========================================
int main() {
    // 1. Membuat Admin
    Admin admin1("Budi Supriadi", "adminbudi@web.com");

    // 2. Membuat beberapa Member
    Member member1("Andi Saputra", "andi@web.com");
    Member member2("Siti Aminah", "siti@web.com");

    // Menyimpan member dalam vector menggunakan alamat memori (&)
    vector<Member*> listMember;
    listMember.push_back(&member1);
    listMember.push_back(&member2);

    // 3. Admin melihat semua member
    admin1.showAllMember(listMember);

    // 4. Cek profil member 1
    member1.showProfile();

    // 5. Admin menonaktifkan member 1
    admin1.toggleActivationMember(&member1);

    // 6. Cek kembali profil member 1 setelah dinonaktifkan
    member1.showProfile();

    return 0;
}