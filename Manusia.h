#ifndef MANUSIA_H
#define MANUSIA_H

#include <iostream>
#include <string>
#include "jantung.h" // Sangat penting untuk menghubungkan ke class jantung

using namespace std;

class manusia {
public:
    string name;
    jantung varJantung; // Inilah letak hubungan Komposisi

    manusia(string pName)
        : name(pName) {
        cout << name << " hidup\n";
    }
    ~manusia() {
        cout << name << " mati\n";
    }
};

#endif