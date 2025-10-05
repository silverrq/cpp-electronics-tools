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


// Metin karakter karakter yazdıran ve her karakter arasında gecikme ekleyen fonksiyon
void YavasYaz(const string& text, int delay_ms = 25)  {
        for (char karakter: text) {
            cout << karakter << flush; // Karakteri yazdır
            this_thread::sleep_for(chrono::milliseconds(delay_ms)); // Gecikme
        }
    }

int main() {

    turkce();
    
    //Başlangıç mesajı
    YavasYaz("Resistor Calculator'a Hoşgeldiniz!");
    Sleep(1000);
    YavasYaz("Giriş yapmak için enter tuşuna basınız.");

    return 0;
    
}