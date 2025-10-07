#include <iostream> // Giriş/Çıkış işlemleri için
#include <string> // string sınıfı için
#include <chrono> // Zaman işlemleri için
#include <thread> // Uyku işlemi için
#include <vector> // vector container için
#include <algorithm> // transform için
#include <cctype> // tolower için
#include <cmath> // pow fonksiyonu için
#include <conio.h> // _getch() için

// Arrow key navigation sabitleri
#define YUKARI 72
#define ASAGI 80
#define ENTER 13
#define ESC 27
#define BILINMEYEN 0

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

// Arrow key navigation için tuş okuma fonksiyonu
int tusOku() {
    int karakter = _getch(); // İlk karakter
    
    if (karakter == 224) {   // Arrow key başlangıcı (Windows)
        int ikinci = _getch(); // İkinci karakter
        if (ikinci == 72) return YUKARI;    // ↑ tuşu
        if (ikinci == 80) return ASAGI;     // ↓ tuşu
    }
    if (karakter == 13) return ENTER;       // Enter tuşu
    if (karakter == 27) return ESC;         // Esc tuşu
    
    return BILINMEYEN; // Tanımlanmamış tuş
}

// Arrow key menü çizim fonksiyonu
void menu(int secili) {
    ekrantemizle();
    cout << "\n\n\n\nAna Menüye Hoşgeldiniz!\n\n\n";
    
    // Seçenek 1 - 4 Bantlı
    if (secili == 0) {
        cout << "► 1. 4 Bantlı Direnç Hesaplama\n";  // Seçili
        cout << "   [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4\n\n";
    } else {
        cout << "  1. 4 Bantlı Direnç Hesaplama\n";  // Normal
        cout << "   [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4\n\n";
    }
    
    // Seçenek 2 - 5 Bantlı  
    if (secili == 1) {
        cout << "► 2. 5 Bantlı Direnç Hesaplama\n";  // Seçili
        cout << "   [████] [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4  Renk5\n\n";
    } else {
        cout << "  2. 5 Bantlı Direnç Hesaplama\n";  // Normal
        cout << "   [████] [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4  Renk5\n\n";
    }
    
    // Seçenek 3 - Çıkış
    if (secili == 2) {
        cout << "► 3. Çıkış\n\n";  // Seçili
    } else {
        cout << "  3. Çıkış\n\n";  // Normal
    }
    
    cout << "Yukarı/Aşağı ok tuşları: Seçim | Enter: Onayla | Esc: Çıkış\n";
}

// Arrow key navigation ana fonksiyonu
int arrowKeyMenu() {
    int secili = 0;        // Hangi seçenek seçili (0, 1, 2)
    int toplam = 3;        // Toplam seçenek sayısı
    
    while (true) {
        menu(secili);   // Menüyü çiz
        
        int tus = tusOku(); // Tuş bekle
        
        if (tus == YUKARI) {
            secili = (secili - 1 + toplam) % toplam; // Yukarı git (döngüsel)
        }
        else if (tus == ASAGI) {
            secili = (secili + 1) % toplam;          // Aşağı git (döngüsel)
        }
        else if (tus == ENTER) {
            return secili + 1; // 1, 2, veya 3 döndür
        }
        else if (tus == ESC) {
            return 3; // Çıkış seçeneği
        }
    }
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


    string b1, b2, b3, b4, b5, b6; // Bant renkleri değişkenleri


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

        // Arrow key navigation ile menü
        secim = arrowKeyMenu();
        
        while(true) {

            if(secim == 1)  {
                ekrantemizle();
                YavasYaz("4 Bantlı Direnç Hesaplayıcısı seçildi!\n");
                YavasYaz("Devam etmek için Enter'a basın...");
                enterBekle();
                bekle();

                ekrantemizle();

                YavasYaz("4 Bantlı Direncinizin 1. Bandının rengini string olarak giriniz: (Çıkış için 'q' yazabilirsiniz.)\n");
                getline(cin, b1);
                transform(b1.begin(), b1.end(), b1.begin(), ::tolower); // Küçük harfe çevir
                
                if(b1 == "q") {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }
                
                YavasYaz("2. Bandın rengini giriniz:");
                getline(cin, b2);
                transform(b2.begin(), b2.end(), b2.begin(), ::tolower);

                if(b2 == "q") {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("3. Bandın rengini giriniz:");
                getline(cin, b3);
                transform(b3.begin(), b3.end(), b3.begin(), ::tolower); 


                if(b3 == "q") {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("4. Bandın rengini giriniz:");
                getline(cin, b5);
                transform(b5.begin(), b5.end(), b5.begin(), ::tolower); 

                if(b5 == "q") {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                if (b1.empty() || b2.empty() || b3.empty() || b5.empty()) {
                    YavasYaz(" Hatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue; // Döngünün başına dön
                }

                int band1 = renkkodu1(b1);
                int band2 = renkkodu2(b2);
                int band3 = renkkodu3(b3);
                int band4 = besbandrenkkodu4(b4);
                int tolerans = renkkodutolerans(b5);

                if (band1 == -1 || band2 == -1 || band3 == -1 || tolerans == -1) {
                    YavasYaz(" Hatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
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
                bekle();

                ekrantemizle();

                YavasYaz("5 Bantlı Direncinizin 1. Bandının rengini string olarak giriniz: (Çıkış için 'q' yazabilirsiniz.)\n");
                getline(cin,b1);
                transform(b1.begin(), b1.end(), b1.begin(), ::tolower); 

                if(b1 == "q")  {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("2. Bandın rengini giriniz:");
                getline(cin,b2);
                transform(b2.begin(), b2.end(), b2.begin(), ::tolower);

                if(b2 == "q")  {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("3. Bandın rengini giriniz:");
                getline(cin,b3);
                transform(b3.begin(), b3.end(), b3.begin(), ::tolower);

                if(b3 == "q")   {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("4. Bandın rengini giriniz:");
                getline(cin,b4);
                transform(b4.begin(), b4.end(), b4.begin(), ::tolower);

                if(b4 == "q")   {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("5. Bandın rengini giriniz:");
                getline(cin,b5);
                transform(b5.begin(), b5.end(), b5.begin(), ::tolower);

                if(b5 == "q")   {
                    YavasYaz(" Çıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }


                if (b1.empty() ||b2.empty() || b3.empty() || b4.empty() || b5.empty()) {
                    YavasYaz("Hatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                int band1 = renkkodu1(b1);
                int band2 = renkkodu2(b2);
                int band3 = renkkodu3(b3);
                int band4 = besbandrenkkodu4(b4);
                int tolerans = renkkodutolerans(b5);

                if( band1 == -1 || band2 == -1 || band3 == -1 || band4 == -1 || tolerans == -1) {
                    YavasYaz(" Hatalı giriş yaptınız. Ana menüye yönlendiriliyorsunuz.\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("Direncinizin değerleri hesaplanıyor...");
                bekle(3000);
                ekrantemizle();

                YavasYaz("Direncinizin değerleri hesaplandı! \n");
                bekle();

                long long formul2 = (band1*100+ band2*10 + band3) * static_cast <long long> (pow(10, band4));
                YavasYaz("Direncinizin değeri: " + string(to_string(formul2)) + " Ω ±%" + to_string(tolerans) + "\n");
                bekle(1000);
                break;

            }
            else if(secim == 3)  {
                YavasYaz("Çıkış yapmayı seçtiniz. Program durduruluyor...");
                bekle(2000);
                ekrantemizle();
                break;
            }
            
        }
       
    return 0;
    
}