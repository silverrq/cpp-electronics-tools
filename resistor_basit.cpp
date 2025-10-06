#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Türkçe karakter desteği
void turkceAyar() {
    SetConsoleOutputCP(65001);
}

// Basit ekran temizleme
void temizle() {
    system("cls");
}

// Basit menü gösterme
void menuGoster() {
    cout << "=== RESISTOR CALCULATOR ===" << endl;
    cout << endl;
    cout << "1. 4 Bantli Direnc Hesapla" << endl;
    cout << "2. 5 Bantli Direnc Hesapla" << endl;
    cout << "3. Cikis" << endl;
    cout << endl;
    cout << "Seciminiz (1-3): ";
}

int main() {
    turkceAyar();
    
    cout << "Resistor Calculator'a Hosgeldiniz!" << endl;
    cout << "Devam etmek icin Enter'a basin...";
    cin.get();
    
    int secim;
    
    while(true) {
        temizle();
        menuGoster();
        cin >> secim;
        
        if(secim == 1) {
            cout << "4 bantli direnc hesaplayici secildi!" << endl;
            cout << "Enter'a basin...";
            cin.ignore();
            cin.get();
        }
        else if(secim == 2) {
            cout << "5 bantli direnc hesaplayici secildi!" << endl;
            cout << "Enter'a basin...";
            cin.ignore();
            cin.get();
        }
        else if(secim == 3) {
            cout << "Gule gule!" << endl;
            break;
        }
        else {
            cout << "Hatali secim! Tekrar deneyin." << endl;
            cout << "Enter'a basin...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}