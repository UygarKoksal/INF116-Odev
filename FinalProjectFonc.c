#include "finalproject.h"



void printList(product* p,int size){
    printf("-------DEPO Listesi-------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",p[i].id);
        printf("%s ",p[i].name);
        printf("%.2f ",p[i].price);
        printf("%d\n",p[i].stock);
    }
    

}


void addToList(char* newName,float price, int stock){
    int newid;
    newid=getNextId();
    FILE* fptr;
    fptr=fopen("inventory.txt","a");
    if (fptr==NULL)
    {
        printf("Dosya acilamadi.\n");
        return ;
    }
    
    
    fprintf(fptr,"%d ",newid);
    fprintf(fptr,"%s ",newName);
    fprintf(fptr,"%.2f ",price);
    fprintf(fptr,"%d\n",stock);
    printf("Dosyaya basariyla eklendi.\n");
    
    fclose(fptr);
    
    


}
void reportCriticalStock(product*p,int size){
    FILE* fptr;
    fptr=fopen("kritik.txt","w");
    for (int i = 0; i < size; i++)
    {
        if (p[i].stock<5)
        {
            printf("%s is low on stock.\n",p[i].name);
            fprintf(fptr,"%d %s %f %d",&p[i].id,p[i].name,&p[i].price,&p[i].stock);
        }
        
    }
    printf("Kritik stok olan urunler listeye yazildi.\n");
    fclose(fptr);
    
}
int getNextId() {
    FILE *fp = fopen("inventory.txt", "r");
    if (fp == NULL) return 100;

    int id, stok;
    float fiyat;
    char isim[50];
    int sonId = 99;

    // DEĞİŞİKLİK BURADA: != EOF yerine == 4 kullanıyoruz.
    // Anlamı: "Eğer başarıyla 4 tane veri (id, isim, fiyat, stok) okuduysan devam et"
    // Boş satıra gelirse 4 veri okuyamaz ve döngüden ÇIKAR.
    while (fscanf(fp, "%d %s %f %d", &id, isim, &fiyat, &stok) == 4) {
        sonId = id;
    }

    fclose(fp);
    return sonId + 1;

}
void updatePrice(product* p, int arananId, int yeniFiyat){
    int i = 0;
    FILE* fptr;

    // 1. ADIM: Dosyayı OKU ve Diziye Yükle
    fptr = fopen("inventory.txt", "r");
    if (fptr == NULL) return; // Dosya yoksa patlamasın

    // Not: String okurken (name) başına & konulmaz, p[i].name yeterlidir.
    while (fscanf(fptr, "%d %s %f %d", &p[i].id, p[i].name, &p[i].price, &p[i].stock) != EOF)
    {
        i++;
    }
    fclose(fptr); // Okuma bitti, kapat.

    // 2. ADIM: Hafızada Güncelleme Yap
    int bulundu = 0;
    for (int j = 0; j < i; j++)
    {
        if (arananId == p[j].id)
        {
            p[j].price = (float)yeniFiyat; // Fiyatı güncelle
            bulundu = 1;
        }
    }

    // 3. VE EN ÖNEMLİ ADIM: Dosyayı SIFIRDAN YAZ (Kaydet)
    if (bulundu) {
        fptr = fopen("inventory.txt", "w"); // "w" modu dosyanın içini temizler, sıfırdan yazar.

        for (int j = 0; j < i; j++) {
            // Dizideki her şeyi dosyaya geri döküyoruz
            fprintf(fptr, "%d %s %.2f %d\n", p[j].id, p[j].name, p[j].price, p[j].stock);
        }

        fclose(fptr); // Yazma bitti, kapat.
        printf("Fiyat basariyla guncellendi ve kaydedildi.\n");
    } else {
        printf("Urun bulunamadi, hicbir degisiklik yapilmadi.\n");
    }
}