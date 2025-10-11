#include <iostream> // Giriş/Çıkış işlemleri için
#include <string> // string sınıfı için
#include <chrono> // Zaman işlemleri için
#include <thread> // Uyku işlemi için
#include <vector> // vector container için
#include <algorithm> // transform için
#include <cctype> // tolower için
#include <cmath> // pow fonksiyonu için
#include <conio.h> // _getch() için
#include <windows.h>
#include <io.h>
#include <fcntl.h>

#define YUKARI 72
#define ASAGI 80
#define ENTER 13
#define ESC 27
#define BILINMEYEN 0


using namespace std;

void turkce()  {

        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
        
} // Türkçe karakter desteği fonksiyonu

void ekrantemizle()  {
    for(int i= 0; i<50; i++) {

        cout << "\n";
    }
} // Ekranı temizleme fonksiyonu

void YavasYaz(const string& text, int delay_ms = 20)  {        
        for (char karakter: text) {

            // Bekleyen karakterleri kontrol et ve temizle
            if (_kbhit()) {
                _getch(); // Bekleyen karakteri oku ve at
            }
            
            cout << karakter << flush;
            this_thread::sleep_for(chrono::milliseconds(delay_ms)); // Gecikme
        }
    } // Yavaş yazma efekti fonksiyonu

void enterBekle()  {

    // Önce bekleyen tüm karakterleri temizle
    while (_kbhit()) {
        _getch();
    }
    
    cin.clear();

    while(true) {

        int tus = _getch();
        if (tus == 13) break;
        while (_kbhit()) _getch(); // Bekleyen karakterleri temizle
    }

} // Enter tuşuna basılmasını bekleyen fonksiyon

void bekle(int milisaniye = 1000) {
    this_thread::sleep_for(chrono::milliseconds(milisaniye));
    
}

// Arrow key navigation için tuş okuma fonksiyonu
int tusOku() {
    int karakter = _getch();
    
    if (karakter == 224) {
        int ikinci = _getch();
        if (ikinci == 72) return YUKARI;    
        if (ikinci == 80) return ASAGI;
    }
    if (karakter == 13) return ENTER;
    if (karakter == 27) return ESC;
    
    return BILINMEYEN;
}

// Arrow key menü çizim fonksiyonu
void menu(int secili) {
    ekrantemizle();
    cout << "\n\n\n\nAna Menüye Hoşgeldiniz!\n\n\n";
    
   
    if (secili == 0) {
        cout << "► 1. 4 Bantlı Direnç Hesaplama\n";
        cout << "   [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4\n\n";
    } else {
        cout << "  1. 4 Bantlı Direnç Hesaplama\n";
        cout << "   [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4\n\n";
    }
    
      
    if (secili == 1) {
        cout << "► 2. 5 Bantlı Direnç Hesaplama\n";
        cout << "   [████] [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4  Renk5\n\n";
    } else {
        cout << "  2. 5 Bantlı Direnç Hesaplama\n";
        cout << "   [████] [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4  Renk5\n\n";
    }

    

    if (secili == 2)  {
        cout << "► 3. 6 Bantlı Direnç Hesaplama\n";
        cout << "   [████] [████] [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4  Renk5  Renk6\n\n";
    } else {
        cout << "  3. 6 Bantlı Direnç Hesaplama\n";
        cout << "   [████] [████] [████] [████] [████] [████]\n";
        cout << "    Renk1  Renk2  Renk3  Renk4  Renk5  Renk6\n\n";
    }
    

    if (secili == 3) {
        cout << "► 4. Çıkış\n\n"; 
    } else {
        cout << "  4. Çıkış\n\n"; 
    }
    
    cout << "Yukarı/Aşağı ok tuşları: Seçim | Enter: Onayla | Esc: Çıkış\n";
}

// Arrow key navigation ana fonksiyonu
int arrowKeyMenu() {

    int secili = 0;   
    int toplam = 4; 
    
    while (true) {
        menu(secili); 
        
        int tus = tusOku();
        
        if (tus == YUKARI) {
            secili = (secili - 1 + toplam) % toplam; // Yukarı git
        }
        else if (tus == ASAGI) {
            secili = (secili + 1) % toplam;          // Aşağı git
        }
        else if (tus == ENTER) {
            return secili + 1;
        }
        else if (tus == ESC) {
            return 4;
        }
    }
}

void bilgilendirme4() {
    
    cout << "4 Bantlı Direnç Hesaplayıcısı" << endl;
    cout << "------------------------------" << endl << endl;
    cout << "Direncinize ait 4 bandın renk kodlarını girerek direncinizin değerini, toleransını öğrenebilirsiniz." << endl << endl;
    cout << "1. ve 2. bantlar direncin ilk iki basamağını temsil etmektedir." << endl;
    cout << "3. Bant çarpan değerini temsil etmektedir." << endl;
    cout << "4. Bant ise tolerans değerini yani değer aralığını temsil etmektedir." << endl;
    cout << "\nDirenç renklerini sırayla girdikten sonra direncinizin değeri ve değer aralığı hesaplanacaktır." << endl;
    cout << "Çıkış yapmak isterseniz herhangi bir bant rengini sorarken 'q' tuşuna basabilirsiniz." << endl;
    
    YavasYaz("\nLütfen devam etmek için Enter'a basın...");
    enterBekle();
}

void bilgilendirme5() {
    
    cout << "5 Bantlı Direnç Hesaplayıcısı" << endl;
    cout << "------------------------------" << endl << endl;
    cout << "Direncinize ait 5 bandın renk kodlarını girerek direncinizin değerini, toleransını öğrenebilirsiniz." << endl << endl;
    cout << "1., 2. ve 3. bantlar direncin ilk üç basamağını temsil etmektedir." << endl;
    cout << "4. Bant çarpan değerini temsil etmektedir." << endl;
    cout << "5. Bant ise tolerans değerini yani değer aralığını temsil etmektedir." << endl;
    cout << "\nDirenç renklerini sırayla girdikten sonra direncinizin değeri ve değer aralığı hesaplanacaktır." << endl;
    cout << "Çıkış yapmak isterseniz herhangi bir bant rengini sorarken 'q' tuşuna basabilirsiniz." << endl;

    YavasYaz("\nLütfen devam etmek için Enter'a basın...");
    enterBekle();
}

void bilgilendirme6() {
    
    cout << "6 Bantlı Direnç Hesaplayıcısı" << endl;
    cout << "------------------------------" << endl << endl;
    cout << "Direncinize ait 6 bandın renk kodlarını girerek direncinizin değerini, toleransını ve sıcaklık katsayısını öğrenebilirsiniz." << endl << endl;
    cout << "1., 2. ve 3. bantlar direncin ilk üç basamağını temsil etmektedir." << endl;
    cout << "4. Bant çarpan değerini temsil etmektedir." << endl;
    cout << "5. Bant ise tolerans değerini yani değer aralığını temsil etmektedir." << endl;
    cout << "6. Bant ise sıcaklık katsayısını yani direncin sıcaklık değişimine olan duyarlılığını temsil etmektedir." << endl;
    cout << "\nDirenç renklerini sırayla girdikten sonra direncinizin değeri, toleransı ve sıcaklık katsayısı hesaplanacaktır." << endl;
    cout << "Çıkış yapmak isterseniz herhangi bir bant rengini sorarken 'q' tuşuna basabilirsiniz." << endl;

    YavasYaz("\nLütfen devam etmek için Enter'a basın...");
    enterBekle();
}

void sonbilgilendirme() {
    YavasYaz("\nProgramı kullandığınız için teşekkürler!\n");
    YavasYaz("Direncinizin değeri hesaplanan değer aralığının dışındaysa lütfen direncinizin sağlamlığını kontrol ediniz.\n\n");
    bekle(2000);

    for (int i = 10; i >= 0; --i) {
        cout << "Program " << i << " saniye içinde kapanacaktır...  \r";
        cout << flush;
        bekle(1000);
    }
    ekrantemizle();
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

int altibandsicaklik (string b6) {
    if (b6 == "siyah") return 250;
    else if(b6 == "kahverengi") return 100;
    else if(b6 == "kirmizi" ||b6 == "kırmızı") return 50;
    else if(b6 == "turuncu") return 15;
    else if(b6 == "sari" || b6 == "sarı") return 25;
    else if(b6 == "yesil" || b6 == "yeşil") return 20;
    else if(b6 == "mavi") return 10;
    else if(b6 == "mor") return 5;
    else if(b6 == "gri") return 1;
    else if(b6 == "beyaz") return 0;
    else return -1;
}


int main() {


    string b1, b2, b3, b4, b5, b6; // Bant renkleri değişkenleri


    turkce();
    ekrantemizle();

   
    YavasYaz("Resistor Calculator'a Hoşgeldiniz!\n");
    bekle();

    YavasYaz("Giriş yapmak için enter tuşuna basınız...");
    enterBekle();
    
    ekrantemizle();

        YavasYaz("Sisteme giriş yapılıyor...");
        bekle(2000);
        ekrantemizle();

        YavasYaz("Sisteme giriş başarılı! Ana menüye yönlendiriliyorsunuz...");
        bekle();
        ekrantemizle();

        int secim;

        secim = arrowKeyMenu();
        
        while(true) {

            if(secim == 1)  {
                ekrantemizle();
                YavasYaz("4 Bantlı Direnç Hesaplayıcısı seçildi!\n");
                YavasYaz("Devam etmek için Enter'a basınız...");
                enterBekle();
                bekle();

                ekrantemizle();

                bilgilendirme4();
                ekrantemizle();

                YavasYaz("Lütfen direncinizin 1. Bandının rengini giriniz: ");
                getline(cin, b1);
                transform(b1.begin(), b1.end(), b1.begin(), ::tolower); // Küçük harfe çevir
                
                if(b1 == "q") {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }
                
                YavasYaz("2. Bandın rengini giriniz: ");
                getline(cin, b2);
                transform(b2.begin(), b2.end(), b2.begin(), ::tolower);

                if(b2 == "q") {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("3. Bandın rengini giriniz: ");
                getline(cin, b3);
                transform(b3.begin(), b3.end(), b3.begin(), ::tolower); 


                if(b3 == "q") {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("4. Bandın rengini giriniz: ");
                getline(cin, b5);
                transform(b5.begin(), b5.end(), b5.begin(), ::tolower); 

                if(b5 == "q") {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                if (b1.empty() || b2.empty() || b3.empty() || b5.empty()) {
                    YavasYaz("\nHatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue; // Döngünün başına dön
                }


                if (renkkodu1(b1) == -1 || renkkodu2(b2) == -1 || renkkodu3(b3) == -1 || renkkodutolerans(b5) == -1) {
                    YavasYaz("\nHatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("\nDirencinizin değerleri hesaplanıyor...");
                bekle(3000);
                ekrantemizle();
                YavasYaz("\nDirencinizin değerleri hesaplandı!\n");
                bekle();
                ekrantemizle();

                long long formul = (renkkodu1(b1)*10 + renkkodu2(b2)) * static_cast <long long> (pow(10, renkkodu3(b3)));
                YavasYaz("Direncinizin değeri: " + to_string(formul) + " Ω ±%" + to_string(renkkodutolerans(b5)) + "\n");
                YavasYaz("Direncinizin değer aralığı: " + to_string(formul -(formul * renkkodutolerans(b5) /100)) + " Ω - " + to_string(formul + (formul * renkkodutolerans(b5) /100)) + " Ω\n");
                sonbilgilendirme();
                break;

            }
            else if(secim == 2)  {

                ekrantemizle();
                YavasYaz("5 Bantlı Direnç Hesaplayıcısı seçildi!\n");
                YavasYaz("Devam etmek için Enter'a basın...");
                enterBekle();
                bekle();

                ekrantemizle();
                bilgilendirme5();
                ekrantemizle();

                YavasYaz("Lütfen 5 Bantlı direncinizin 1. Bandının rengini giriniz: ");
                getline(cin,b1);
                transform(b1.begin(), b1.end(), b1.begin(), ::tolower); 

                if(b1 == "q")  {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("2. Bandın rengini giriniz: ");
                getline(cin,b2);
                transform(b2.begin(), b2.end(), b2.begin(), ::tolower);

                if(b2 == "q")  {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("3. Bandın rengini giriniz: ");
                getline(cin,b3);
                transform(b3.begin(), b3.end(), b3.begin(), ::tolower);

                if(b3 == "q")   {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("4. Bandın rengini giriniz: ");
                getline(cin,b4);
                transform(b4.begin(), b4.end(), b4.begin(), ::tolower);

                if(b4 == "q")   {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("5. Bandın rengini giriniz: ");
                getline(cin,b5);
                transform(b5.begin(), b5.end(), b5.begin(), ::tolower);

                if(b5 == "q")   {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }


                if (b1.empty() ||b2.empty() || b3.empty() || b4.empty() || b5.empty()) {
                    YavasYaz("\nHatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                if( renkkodu1(b1) == -1 || renkkodu2(b2) == -1 || renkkodu3(b3) == -1 || besbandrenkkodu4(b4) == -1 || renkkodutolerans(b5) == -1) {
                    YavasYaz("\nHatalı giriş yaptınız. Ana menüye yönlendiriliyorsunuz.\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("\nDirencinizin değerleri hesaplanıyor...");
                bekle(3000);
                ekrantemizle();

                YavasYaz("\nDirencinizin değerleri hesaplandı! \n");
                bekle();

                long long formul2 = (renkkodu1(b1)*100+ renkkodu2(b2)*10 + renkkodu3(b3)) * static_cast <long long> (pow(10, besbandrenkkodu4(b4)));
                YavasYaz("Direncinizin değeri: " + string(to_string(formul2)) + " Ω ±%" + to_string(renkkodutolerans(b5)) + "\n");
                YavasYaz("Direncinizin değer aralığı: " + to_string(formul2 - (formul2 * renkkodutolerans(b5) / 100)) + " Ω - " + to_string(formul2 + (formul2 * renkkodutolerans(b5) / 100)) + " Ω\n");
                sonbilgilendirme();
                break;

            }

            else if(secim == 3)  {

                ekrantemizle();
                YavasYaz("6 Bantlı Direnç Hesaplayıcısı seçildi! \n");
                YavasYaz("Devam etmek için Enter'a basın...");
                enterBekle();
                bekle();
                ekrantemizle();

                bilgilendirme6();
                ekrantemizle();

                YavasYaz("Lütfen 6 Bantlı direncinizin 1. Bandının rengini giriniz: ");
                getline(cin,b1);
                transform(b1.begin(), b1.end(), b1.begin(), ::tolower);

                if(b1 == "q")  {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("2. Bandın rengini giriniz: ");
                getline(cin,b2);
                transform(b2.begin(), b2.end(), b2.begin(), ::tolower);

                if(b2 == "q")  {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("3. Bandın rengini giriniz: ");
                getline(cin,b3);
                transform(b3.begin(), b3.end(), b3.begin(), ::tolower);
                
                if(b3 == "q")  {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("4. Bandın rengini giriniz: ");
                getline(cin,b4);
                transform(b4.begin(), b4.end(), b4.begin(), ::tolower);

                if(b4 == "q")  {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("5. Bandın rengini giriniz: ");
                getline(cin,b5);
                transform(b5.begin(), b5.end(), b5.begin(), ::tolower);

                if(b5 == "q")  {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("6. Bandın rengini giriniz: ");
                getline(cin,b6);
                transform(b6.begin(), b6.end(), b6.begin(), ::tolower);
                if(b6 == "q")  {
                    YavasYaz("\nÇıkış yapmayı seçtiniz. Ana menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                if (b1.empty() || b2.empty() || b3.empty() || b4.empty() || b5.empty() || b6.empty()) {
                    YavasYaz("\nHatalı girdi yaptınız. Ana menüye yönlendiriliyorsunuz\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                if( renkkodu1(b1) == -1 || renkkodu2(b2) == -1 || renkkodu3(b3) == -1 || besbandrenkkodu4(b4) == -1 || renkkodutolerans(b5) == -1 || altibandsicaklik(b6) == -1) {
                    YavasYaz("\nHatalı giriş yaptınız. Ana menüye yönlendiriliyorsunuz.\n\n");
                    bekle(2000);
                    ekrantemizle();
                    secim = arrowKeyMenu();
                    continue;
                }

                YavasYaz("\nDirencinizin değerleri hesaplanıyor...");
                bekle(3000);
                ekrantemizle();
                YavasYaz("\nDirencinizin değerleri hesaplandı! \n");
                bekle();
                long long formul3 = (renkkodu1(b1)*100 + renkkodu2(b2)*10 + renkkodu3(b3)) * static_cast <long long> (pow(10, besbandrenkkodu4(b4)));
                YavasYaz("Direncinizin değeri:" + string(to_string(formul3)) + " Ω ±%" + to_string(renkkodutolerans(b5)) + " || Sıcaklık Katsayısı: " + string(to_string(altibandsicaklik(b6))) + " ppm/°C \n");
                YavasYaz("Direncinizin değer aralığı: " + to_string(formul3 - (formul3 * renkkodutolerans(b5) / 100)) + " Ω - " + to_string(formul3 + (formul3 * renkkodutolerans(b5) / 100)) + " Ω\n");
                sonbilgilendirme();
                break;

            }

            else if(secim == 4)  {
                YavasYaz("Çıkış yapmayı seçtiniz. Program durduruluyor...");
                bekle(2000);
                ekrantemizle();
                break;
            }
            
        }
       
    return 0;
    
}