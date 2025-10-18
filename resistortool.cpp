#include <iostream>
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

void YavasYaz(const string& text, int delay_ms = 10)  {        
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

string turkceKucukHarfeCevir(string text) {

    for (size_t i = 0; i < text.length(); ++i) {
        text[i] = tolower(text[i]);
    }

    size_t pos = 0;
    while ((pos = text.find("I", pos)) != string::npos) {
        text.replace(pos, 1, "ı");
        pos += 2;
    }
    pos = 0;
    while ((pos = text.find("İ", pos)) != string::npos) {
        text.replace(pos, 2, "i");
        pos += 1;
    }
    pos = 0;
    while ((pos = text.find("Ş", pos)) != string::npos) {
        text.replace(pos, 2, "ş");
        pos += 2;
    }
    pos = 0;
    while ((pos = text.find("Ğ", pos)) != string::npos) {
        text.replace(pos, 2, "ğ");
        pos += 2;
    }
    pos = 0;
    while ((pos = text.find("Ü", pos)) != string::npos) {
        text.replace(pos, 2, "ü");
        pos += 2;
    }
    pos = 0;
    while ((pos = text.find("Ö", pos)) != string::npos) {
        text.replace(pos, 2, "ö");
        pos += 2;
    }
    pos = 0;
    while ((pos = text.find("Ç", pos)) != string::npos) {
        text.replace(pos, 2, "ç");
        pos += 2;
    }
    return text;
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
    bekle(1000);

    YavasYaz("Giriş yapmak için enter tuşuna basınız...");
    enterBekle();
    
    ekrantemizle();

        YavasYaz("Sisteme giriş yapılıyor...");
        bekle(2000);
        ekrantemizle();

        int secim;
        
        while(true) {
            
            bool anamenuyedonus = false; // bayrak
            secim = arrowKeyMenu();

            if(secim == 1)  {
                ekrantemizle();
                YavasYaz("4 Bantlı Direnç Hesaplayıcısı seçildi!\n");
                YavasYaz("Devam etmek için Enter'a basınız...");
                enterBekle();

                ekrantemizle();

                bilgilendirme4();
                ekrantemizle();

                YavasYaz("\nLütfen direncinizin 1. Bandının rengini giriniz: ");

                while(true)  {
                getline(cin, b1);
                b1 = turkceKucukHarfeCevir(b1);
                if(b1 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }

                if(renkkodu1(b1) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;

                  }else break;

            }if (anamenuyedonus) {continue;} // Ana menüye dön
                
                
                YavasYaz("\n\n2. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin, b2);
                b2 = turkceKucukHarfeCevir(b2);
                if(b2 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
    
                if(renkkodu2(b2) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
             }if (anamenuyedonus) {continue;}
                
                YavasYaz("\n\n3. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin, b3);
                b3 = turkceKucukHarfeCevir(b3);
                if(b3 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }

                if(renkkodu3(b3) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
             }if (anamenuyedonus) {continue;}
                
                YavasYaz("\n\n4. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin, b5);
                b5 = turkceKucukHarfeCevir(b5);

                if(b5 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }

                if(renkkodutolerans(b5) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
                
            }if (anamenuyedonus) {continue;}

                ekrantemizle();
                YavasYaz("\nDirencinizin değerleri hesaplanıyor...");
                bekle(1500);
                ekrantemizle();
                YavasYaz("\nDirencinizin değerleri hesaplandı!\n");
                bekle(1000);
                ekrantemizle();

                long long formul = (renkkodu1(b1)*10 + renkkodu2(b2)) * static_cast <long long> (pow(10, renkkodu3(b3)));
                double ana_deger = static_cast<double>(formul);
                double tolerans_degeri = static_cast<double>(renkkodutolerans(b5));
                double min_deger = ana_deger - (ana_deger * tolerans_degeri / 100);
                double max_deger = ana_deger + (ana_deger * tolerans_degeri / 100);

                YavasYaz("Direncinizin değeri: " + to_string(formul) + " Ω ±%" + to_string(renkkodutolerans(b5)) + "\n");
                YavasYaz("Direncinizin değer aralığı: " + to_string(min_deger) + " Ω - " + to_string(max_deger) + " Ω\n");

                YavasYaz("\nProgramı kullandığınız için teşekkürler!\n");
                YavasYaz("Ana menüye dönmek için Enter'a, çıkış yapmak için Esc tuşuna basınız...");
                while(true) {
                    int tus = _getch();
                    if (tus == 13) {
                        anamenuyedonus = true;
                        ekrantemizle();
                        YavasYaz("\nAna menüye dönülüyor...");
                        bekle(2000);
                        ekrantemizle();
                        break;
                    }
                    else if(tus == 27) {
                        ekrantemizle();
                        YavasYaz("\nProgramdan çıkış yapılıyor...");
                        bekle(2000);
                        ekrantemizle();
                        return 0;
                    }

                }if (anamenuyedonus) {continue;}

                break;

            }
            else if(secim == 2)  {

                ekrantemizle();
                YavasYaz("5 Bantlı Direnç Hesaplayıcısı seçildi!\n");
                YavasYaz("Devam etmek için Enter'a basın...");
                enterBekle();

                ekrantemizle();
                bilgilendirme5();
                ekrantemizle();

                YavasYaz("\nLütfen 5 Bantlı direncinizin 1. Bandının rengini giriniz: ");
                
                while(true)  {
                getline(cin,b1);
                b1 = turkceKucukHarfeCevir(b1);
                if(b1 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }

                if(renkkodu1(b1) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                }else break;
            }if (anamenuyedonus) {continue;}

                YavasYaz("\n\n2. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b2);
                b2 = turkceKucukHarfeCevir(b2);
                if(b2 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                
                if(renkkodu2(b2) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                }else break;
            }if (anamenuyedonus) {continue;}

                YavasYaz("\n\n3. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b3);
                b3 = turkceKucukHarfeCevir(b3);
                if(b3 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(renkkodu3(b3) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                }else break;
                
            }if (anamenuyedonus) {continue;}

                YavasYaz("\n\n4. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b4);
                b4 = turkceKucukHarfeCevir(b4);
                if(b4 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(besbandrenkkodu4(b4) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                }else break;
                
            
            }if (anamenuyedonus) {continue;}

                YavasYaz("\n\n5. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b5);
                b5 = turkceKucukHarfeCevir(b5);
                if(b5 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(renkkodutolerans(b5) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                }else break;
                
            }if (anamenuyedonus) {continue;}

                ekrantemizle();
                YavasYaz("\nDirencinizin değerleri hesaplanıyor...");
                bekle(1500);
                ekrantemizle();

                YavasYaz("\nDirencinizin değerleri hesaplandı! \n");
                bekle(1000);

                long long formul = (renkkodu1(b1)*100+ renkkodu2(b2)*10 + renkkodu3(b3)) * static_cast <long long> (pow(10, besbandrenkkodu4(b4)));
                double ana_deger = static_cast<double>(formul);
                double tolerans_degeri = static_cast<double>(renkkodutolerans(b5));
                double min_deger = ana_deger - (ana_deger * tolerans_degeri / 100);
                double max_deger = ana_deger + (ana_deger * tolerans_degeri / 100);

                YavasYaz("Direncinizin değeri: " + string(to_string(formul)) + " Ω ±%" + to_string(renkkodutolerans(b5)) + "\n");
                YavasYaz("Direncinizin değer aralığı: " + to_string(min_deger) + " Ω - " + to_string(max_deger) + " Ω\n");
                
                YavasYaz("\nProgramı kullandığınız için teşekkürler!\n");
                YavasYaz("Ana menüye dönmek için Enter'a, çıkış yapmak için Esc tuşuna basınız...");
                while(true) {
                    int tus = _getch();
                    if (tus == 13) {
                        anamenuyedonus = true;
                        ekrantemizle();
                        YavasYaz("\nAna menüye dönülüyor...");
                        bekle(2000);
                        ekrantemizle();
                        break;
                    }
                    else if(tus == 27) {
                        ekrantemizle();
                        YavasYaz("\nProgramdan çıkış yapılıyor...");
                        bekle(2000);
                        ekrantemizle();
                        return 0;
                    }

                }if (anamenuyedonus) {continue;}

                break;
                break;

            }

            else if(secim == 3)  {

                ekrantemizle();
                YavasYaz("6 Bantlı Direnç Hesaplayıcısı seçildi! \n");
                YavasYaz("Devam etmek için Enter'a basın...");
                enterBekle();
                ekrantemizle();
                
                bilgilendirme6();
                ekrantemizle();

                YavasYaz("\nLütfen 6 Bantlı direncinizin 1. Bandının rengini giriniz: ");
                while(true)  {
                getline(cin,b1);
                b1 = turkceKucukHarfeCevir(b1);
                if(b1 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(renkkodu1(b1) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
             } if (anamenuyedonus) {continue;}

                YavasYaz("\n\n2. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b2);
                b2 = turkceKucukHarfeCevir(b2);
                if(b2 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(renkkodu2(b2) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
                
            }if (anamenuyedonus) {continue;}

                YavasYaz("\n\n3. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b3);
                b3 = turkceKucukHarfeCevir(b3);
                if(b3 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(renkkodu3(b3) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
                
            }if (anamenuyedonus) {continue;}

                YavasYaz("\n\n4. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b4);
                b4 = turkceKucukHarfeCevir(b4);
                if(b4 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(besbandrenkkodu4(b4) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
                
                }if (anamenuyedonus) {continue;}

                YavasYaz("\n\n5. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b5);
                b5 = turkceKucukHarfeCevir(b5);
                if(b5 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(renkkodutolerans(b5) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
                
            }if (anamenuyedonus) {continue;}

                YavasYaz("\n\n6. Bandın rengini giriniz: ");
                while(true)  {
                getline(cin,b6);
                b6 = turkceKucukHarfeCevir(b6);
                if(b6 == "q")  {
                    anamenuyedonus = true;
                    YavasYaz("\nAna menüye dönülüyor...");
                    bekle(2000);
                    ekrantemizle();
                    break;
                }
                if(altibandsicaklik(b6) == -1)  {
                    YavasYaz("\nHatalı girdi yaptınız. Lütfen geçerli bir değer giriniz: ");
                    continue;
                  }else break;
                
            }if (anamenuyedonus) {continue;}
                
                ekrantemizle();
                YavasYaz("\nDirencinizin değerleri hesaplanıyor...");
                bekle(1500);
                ekrantemizle();
                YavasYaz("\nDirencinizin değerleri hesaplandı! \n");
                bekle(1000);
                long long formul = (renkkodu1(b1)*100 + renkkodu2(b2)*10 + renkkodu3(b3)) * static_cast <long long> (pow(10, besbandrenkkodu4(b4)));
                double ana_deger = static_cast<double>(formul);
                double tolerans_degeri = static_cast<double>(renkkodutolerans(b5));
                double min_deger = ana_deger - (ana_deger * tolerans_degeri / 100);
                double max_deger = ana_deger + (ana_deger * tolerans_degeri / 100);

                YavasYaz("Direncinizin değeri:" + string(to_string(formul)) + " Ω ±%" + to_string(renkkodutolerans(b5)) + " || Sıcaklık Katsayısı: " + string(to_string(altibandsicaklik(b6))) + " ppm/°C \n");
                YavasYaz("Direncinizin değer aralığı: " + to_string(min_deger) + " Ω - " + to_string(max_deger) + " Ω\n");
                
                YavasYaz("\nProgramı kullandığınız için teşekkürler!\n");
                YavasYaz("Ana menüye dönmek için Enter'a, çıkış yapmak için Esc tuşuna basınız...");
                while(true) {
                    int tus = _getch();
                    if (tus == 13) {
                        anamenuyedonus = true;
                        ekrantemizle();
                        YavasYaz("\nAna menüye dönülüyor...");
                        bekle(2000);
                        ekrantemizle();
                        break;
                    }
                    else if(tus == 27) {
                        ekrantemizle();
                        YavasYaz("\nProgramdan çıkış yapılıyor...");
                        bekle(2000);
                        ekrantemizle();
                        return 0;
                    }

                }if (anamenuyedonus) {continue;}

                break;
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