#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int tarihFarkHesapla(int gun, int ay, int yil){
    int sonuc = 0;

    /// 1/1/1922 pazar gunu
    int yilFark = (yil-1922);
    int ayFark = (ay - 1);
    int gunFark = (gun-1);
    int artikYilSayisi = 0;
    /// yil farki icin
    for(int i = 0; i < yilFark; i++){
        if(((yil +i) % 4 == 0 && (yil +i) % 100 != 0) || ((yil +i) % 400 == 0)){
            // artik yil
            sonuc += 366;
            artikYilSayisi++;
        }
        else{
            sonuc += 365;
        }
    }
    /// ay farki icin
    for(int i = 1; i <= ayFark; i++){
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12 ){
            /// 31 ceken aylar
            sonuc += 31;
        }
        else if (i == 2){
            sonuc += 28;
        }
        else
        {
            /// 30 ceken aylar
            sonuc += 30;
        }
    }

    /// gun farki icin
    for(int i = 1; i <= gunFark; i++){
        sonuc += 1;
    }

    sonuc += artikYilSayisi;

    // hafta 7 gun mod 7 bize hangi gun oldugunu vericek
    /// 0   1   2   3   4   5   6
    /// pz  pzt sl  cr  pr  cu  cum
    return sonuc % 7;
}

int tarihKontrol(int gun, int ay, int yil){
    /// girilen tarihin dogrulugunu kontrol eder
    /// hatali tarih ise -1 doner
    /// hatali degilse o gunun hangi gun oldugunu soyler.

    if(yil < 1922 || yil > 2999)
        return -1;
    if(ay < 1 || ay > 12)
        return -1;
    if(gun < 1 || gun > 31)
        return -1;
    else if(ay == 2 && (((yil) % 4 == 0 && (yil) % 100 != 0) || ((yil) % 400 == 0)) && (gun < 1 || gun > 29))
        return -1;
    else if( ay == 2 && (gun < 1 || gun > 28))
        return -1;

    /// tum sartlar saglaniyorsa gunu hesapla
    return tarihFarkHesapla(gun,ay,yil);


}


int main()
{
    char devam = 'h';
    int g = 0,a = 0,y = 0;
    do{

        printf("\nGun girin: "); scanf("%d",&g);
        printf("\nAy girin: "); scanf("%d",&a);
        printf("\nYil girin: "); scanf("%d",&y);
        int gun = tarihKontrol(g,a,y);
        if(gun){
            printf("Girilen tarih %d/%d/%d ",g,a,y);
            switch(gun){
                case 0: printf("Pazar"); break;
                case 1: printf("Pazartesi"); break;
                case 2: printf("Sali"); break;
                case 3: printf("Carsamba"); break;
                case 4: printf("Persembe"); break;
                case 5: printf("Cuma"); break;
                case 6: printf("Cumartesi"); break;
            }
        }
        else{
            printf("\n Girilen tarih hatali");
        }
        printf("\n Tekrar oynamak istiyorsaniz 'h', devam etmek icin herhangi bir tusa basin: ");
        devam = getche();
    }while(devam != 'h');


    return 0;
}
