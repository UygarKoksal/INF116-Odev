#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 100

typedef struct 
{
    int id;
    char* name;
    float price;
    int stock;
}product;


void printList(product* p,int size);
void addToList(char* newName,float price, int stock);
void reportCriticalStock(product*p,int size);
int getNextId();
void updatePrice(product* p,int arananId,int yeniFiyat);
