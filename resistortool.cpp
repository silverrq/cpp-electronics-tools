#include <iostream> // Giriş/Çıkış işlemleri için
#include <string> // string sınıfı için
#include <chrono> // Zaman işlemleri için
#include <thread> // Uyku işlemi için
#include <vector> // vector container için

// Windows için konsol kodlama ayarları. Linux/MacOS'ta gerek yok. Türkçe karakterler için.
#ifdef _WIN32
    #include <windows.h>
    #include <io.h>
    #include <fcntl.h>
#endif

using namespace std; // std ad alanını kullan

void turkce()  {
    #ifdef _WIN32
        SetConsoleOutputCP(65001); // UTF-8 output
        SetConsoleCP(65001);       // UTF-8 input
    #endif
} // Türkçe karakter desteği fonksiyonu

void ekrantemizle()  {
    for(int i= 0; i<50; i++) {

        cout << "\n";
    }
} // Ekranı temizleme fonksiyonu

void YavasYaz(const string& text, int delay_ms = 20)  {  // Varsayılan gecikme 20 ms
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

void anamenu()  {

    YavasYaz("\n\n\n\nAna Menüye Hoşgeldiniz!\n\n\n");
            
    bekle();
    
            YavasYaz(" Lütfen yapmak istediğiniz işlemi seçiniz:\n");
            YavasYaz(" 1. 4 Bantlı Direnç Hesaplama için 1 yazınız.\n");
            YavasYaz(" [████] [████] [████] [████]\n");
            YavasYaz("  Renk1  Renk2  Renk3  Renk4\n\n");
            bekle();
            YavasYaz(" 2. 5 Bantlı Direnç Hesaplama için 2 yazınız.\n");
            YavasYaz(" [████] [████] [████] [████] [████]\n");
            YavasYaz("  Renk1  Renk2  Renk3  Renk4  Renk5\n\n");
            YavasYaz(" 3. Çıkış yapmak için 3 yazınız.\n\n");

            YavasYaz(" Seçiminiz: ");

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
        bekle(2000);
        ekrantemizle();

        YavasYaz("Sisteme giriş başarılı! Ana menüye yönlendiriliyorsunuz...");
        bekle();
        ekrantemizle();

        int secim;

        anamenu();
        
        while(true) {

            cout << endl;
            cin >> secim;

            if(secim == 1)  {
                ekrantemizle();
                YavasYaz("4 Bantlı Direnç Hesaplayıcısı seçildi!\n");
                YavasYaz("Devam etmek için Enter'a basın...");
                enterBekle();
                ekrantemizle();
            }
            else if(secim == 2)  {
                ekrantemizle();
                YavasYaz("5 Bantlı Direnç Hesaplayıcısı seçildi!\n");
                YavasYaz("Devam etmek için Enter'a basın...");
                enterBekle();
                ekrantemizle();
            }
            else if(secim == 3)  {
                YavasYaz("Çıkış yapmayı seçtiniz. Program durduruluyor...");
                bekle(2000);
                ekrantemizle();
                break;
            }
            else {
                YavasYaz(" Hatalı girdi yaptınız. Lütfen geçerli bir girdi giriniz.\n\n");
                YavasYaz(" Seçiminiz: ");
            }
        }
       


    return 0;
    
}