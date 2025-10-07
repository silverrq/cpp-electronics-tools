#include <iostream> // Giriş/Çıkış işlemleri için
#include <string> // string sınıfı için
#include <chrono> // Zaman işlemleri için
#include <thread> // Uyku işlemi için
#include <vector> // vector container için
#include <algorithm> // transform için
#include <cctype> // tolower için
#include <cmath> // pow fonksiyonu için

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

int renkkodu1 (string b1)  {

    if(b1 == "siyah") return 0;
    else if(b1 == "kahverengi") return 1;
    else if(b1 == "kirmizi" || b1 == "kırmızı") return 2;
    else if(b1 == "turuncu") return 3;
    else if(b1 == "sari" || b1 == "sarı") return 4;
    else if(b1 == "yesil" || b1 == "yeşil") return 5;
    else if(b1 == "mavi") return 6;
    else if(b1 == "mor") return 7;
    else if(b1 == "gri") return 8;
    else if(b1 == "beyaz") return 9;
    else return -1; // Geçersiz renk
}

int renkkodu2 (string b2)  {

    if(b2 == "siyah") return 0;
    else if(b2 == "kahverengi") return 1;
    else if(b2 == "kirmizi" || b2 == "kırmızı") return 2;
    else if(b2 == "turuncu") return 3;
    else if(b2 == "sari" || b2 == "sarı") return 4;
    else if(b2 == "yesil" || b2 == "yeşil") return 5;
    else if(b2 == "mavi") return 6;
    else if(b2 == "mor") return 7;
    else if(b2 == "gri") return 8;
    else if(b2 == "beyaz") return 9;
    else return -1;
}

int renkkodu3 (string b3)  {
    if(b3 == "siyah") return 0;
    else if(b3 == "kahverengi") return 1;
    else if(b3 == "kirmizi" || b3 == "kırmızı") return 2;
    else if(b3 == "turuncu") return 3;
    else if(b3 == "sari" || b3 == "sarı") return 4;
    else if(b3 == "yesil" || b3 == "yeşil") return 5;
    else if(b3 == "mavi") return 6;
    else if(b3 == "mor") return 7;
    else if(b3 == "gri") return 8;
    else if(b3 == "beyaz") return 9;
    else return -1;
}

int besbandrenkkodu4 (string b4)  {
    if(b4 == "siyah") return 0;
    else if(b4 == "kahverengi") return 1;
    else if(b4 == "kirmizi" || b4 == "kırmızı") return 2;
    else if(b4 == "turuncu") return 3;
    else if(b4 == "sari" || b4 == "sarı") return 4;
    else if(b4 == "yesil" || b4 == "yeşil") return 5;
    else if(b4 == "mavi") return 6;
    else if(b4 == "mor") return 7;
    else if(b4 == "gri") return 8;
    else if(b4 == "beyaz") return 9;
    else return -1;
}

int renkkodutolerans (string b5)  {
    if(b5 == "altin" || b5 == "altın") return 5;
    else if(b5 == "gumus" || b5 == "gümüş") return 10;
    else return -1;
}


int main() {

    string b1, b2, b3, b4, b5; // Bant renkleri değişkenleri


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
            cin.ignore(); // Buffer'daki Enter karakterini temizle!

            if(secim == 1)  {
                ekrantemizle();
                YavasYaz("4 Bantlı Direnç Hesaplayıcısı seçildi!\n");
                YavasYaz("Devam etmek için Enter'a basın...");
                enterBekle();
                bekle();

                ekrantemizle();

                YavasYaz("4 Bantlı Direncinizin 1. Bandının rengini string olarak giriniz: (Çıkış için q veya Q yazabilirsiniz)\n");
                getline(cin, b1);
                transform(b1.begin(), b1.end(), b1.begin(), ::tolower); // Küçük harfe çevir
                
                YavasYaz("2. Bandın rengini giriniz:");
                getline(cin, b2);
                transform(b2.begin(), b2.end(), b2.begin(), ::tolower);

                YavasYaz("3. Bandın rengini giriniz:");
                getline(cin, b3);
                transform(b3.begin(), b3.end(), b3.begin(), ::tolower); 

                YavasYaz("4. Bandın rengini giriniz:");
                getline(cin, b5);
                transform(b5.begin(), b5.end(), b5.begin(), ::tolower); 

                if(b1 == "q" || b1 == "Q" || b2 == "q" || b2 == "Q" || b3 == "q" || b3 == "Q" || b5 == "q" || b5 == "Q")  {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Program durduruluyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }

                if (b1.empty() || b2.empty() || b3.empty() || b5.empty()) {
                    YavasYaz(" Hatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    anamenu();
                    continue; // Döngünün başına dön
                }

                int band1 = renkkodu1(b1);
                int band2 = renkkodu2(b2);
                int band3 = renkkodu3(b3);
                int tolerans = renkkodutolerans(b5);

                if (band1 == -1 || band2 == -1 || band3 == -1 || tolerans == -1) {
                    YavasYaz(" Hatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    anamenu();
                    continue;
                }

                YavasYaz("Direncinizin değerleri hesaplanıyor...");
                bekle(3000);
                ekrantemizle();
                YavasYaz("Direncinizin değerleri hesaplandı!\n");
                bekle();
                long long formul = (band1*10 + band2) * static_cast <long long> (pow(10, band3));
                YavasYaz("Direncinizin değeri: " + to_string(formul) + " Ω ±%" + to_string(tolerans) + "\n");
                bekle(1000);
                break;

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
            if(secim != 1 && secim != 2 && secim != 3) {
                YavasYaz(" Hatalı girdi yaptınız. Lütfen geçerli bir girdi giriniz.\n\n");
                YavasYaz(" Seçiminiz: ");
                continue; // Döngünün başına dön
            }
        }
       
    return 0;
    
}