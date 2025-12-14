#include "header.h"

int main(){
    DataKata dataBase[maxPanjang];
    int totalKata = 0;
    char namaFile[100];

    printf("Masukkan nama file input (txt): ");
    scanf("%[^\n]", namaFile);
    
    FILE *fp = fopen(namaFile, "r");

    if(fp == NULL){
        printf("Error, Gagal membuka file!!!\n");
        return 1;
    }

    return 0;
}