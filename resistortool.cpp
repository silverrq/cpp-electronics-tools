#include <iostream> // Giriş/Çıkış işlemleri için
#include <string> // string sınıfı için
#include <chrono> // Zaman işlemleri için
#include <thread> // Uyku işlemi için

// Windows için konsol kodlama ayarları. Linux/MacOS'ta gerek yok. Türkçe karakterler için.
#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#endif

using namespace std; // std ad alanını kullan


// Konsolun Türkçe karakterleri doğru görüntülemesi için ayar yapan fonksiyon

void turkce() {
    #ifdef _WIN32
        SetConsoleOutputCP(65001); // UTF-8 output
        SetConsoleCP(65001);       // UTF-8 input
    #endif
}

void ekrantemizle()  {
    for(int i= 0; i<50; i++) {

        cout << "\n";
    }
} // Ekranı temizleme fonksiyonu

void YavasYaz(const string& text, int delay_ms = 25)  {  // Varsayılan gecikme 25 ms
        for (char karakter: text) {
            cout << karakter << flush; // Karakteri yazdır
            this_thread::sleep_for(chrono::milliseconds(delay_ms)); // Gecikme
        }
    } // Yavaş yazma efekti fonksiyonu

void enterBekle()  {
    char input;
    bool validinput = false;

    do {
        input = cin.get();

        if (input == '\n') {
            validinput = true;
        }else {
            YavasYaz("\nLütfen sadece Enter tuşuna basınız.\n");
            cin.ignore(1000, '\n'); // Geçersiz girişleri temizle
        }
    } while (!validinput);
} // Enter tuşuna basılmasını bekleyen fonksiyon

void bekle(int milisaniye = 1000) {
    this_thread::sleep_for(chrono::milliseconds(milisaniye));
}


int main() {

    turkce(); // Türkçe karakter desteği için fonksiyonu çağır
    ekrantemizle(); //başlangıçta ekranı temizle

    //Başlangıç mesajı
    YavasYaz("Resistor Calculator'a Hoşgeldiniz!\n");
    bekle();

    YavasYaz("Giriş yapmak için enter tuşuna basınız..\n");
    enterBekle();
    
    ekrantemizle();

        YavasYaz("Sisteme giriş yapılıyor...");
        bekle(2);
        ekrantemizle();

        YavasYaz("Sisteme giriş başarılı! Ana menüye yönlendiriliyorsunuz...");
        bekle();
        ekrantemizle();


    return 0;
    
}