#include "finalproject.h"


// güncelleme için test

int main(int argc, char* argv[]){

    int size=getNextId()-101;
    int latestId=getNextId();
    

    product p[L]={
    {101,"iPhone", 50000 ,3},
    {102, "Mouse", 250 ,15},
    {103, "Monitor", 4500 ,4}};


    //argc argv kontorlü
    if (argc<2)
    {
        printf("HATA: Komut girmediniz!\n");
        printf("Kullanim Ornekleri:\n");
        printf("  Listeleme: .\\depo.exe -l\n");
        printf("  Ekleme:    .\\depo.exe -a [Isim] [Fiyat] [Stok]\n");
        printf("  Raporlama:    .\\depo.exe -r [Isim] [Fiyat] [Stok]\n");
        printf("  Update:    .\\depo.exe -u [ID] [Fiyat] \n");
        return 1; // Hata koduyla çık
    }
    if (strcmp(argv[1],"-l")==0)
    {
        printf("Listeleme modunu sectiniz.\n");
        printList(p,size);

    } else if (strcmp(argv[1],"-a")==0)
    {
        if (argc!=5)
        {
            printf("Eksik komut girdiniz.\n");
            return 1;
        }
        
        printf("Ekleme modunu sectiniz.\n");
        char* newName=argv[2];
        float newPrice=atof(argv[3]);
        int newStock=atoi(argv[4]);
        addToList(newName,newPrice,newStock);

    }else if (strcmp(argv[1],"-r")==0)
    {
        printf("Report modunu sectiniz.\n");
        reportCriticalStock(p,size);

    }else if (strcmp(argv[1],"-u")==0)
    {
        printf("Update modunu seçtiniz.\n");
        int arananId=atoi(argv[2]);
        float yeniFiyat=atof(argv[3]);
        updatePrice(p,arananId,yeniFiyat);
    }
    
    
    
    


    return 0;
}