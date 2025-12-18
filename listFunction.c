#include "header.h"  

void cleanSafe(char *kata, DataKata *dataBase, int *ptrTotal){
    char chrBersih[maxPanjang];
    int id = 0;

    for(int i = 0; kata[i] != '\0'; i++){
        char chr = kata[i];

        if(chr >= 'A' && chr <= 'Z'){
            chr = chr + 32;
        }

        if(chr >= 'a' && chr <= 'z'){
            chrBersih[id++] = chr;
        }
    }

    chrBersih[id] = '\0';

    if(id == 0){
        return;
    }

    for(int i = 0; i < *ptrTotal; i++){
        if(strcmp(dataBase[i].kata, chrBersih) == 0){
            dataBase[i].frekuensi++;
            return;
        }
    }


    strcpy(dataBase[*ptrTotal].kata, chrBersih);
    dataBase[*ptrTotal].panjang = id;
    dataBase[*ptrTotal].frekuensi = 1;
    (*ptrTotal)++;
}

void bukaFile(char *namaFile, DataKata *dataBase, int *ptrTotal){
    char buffer[1024];
    char *token;
    int ambilData = 0; // 0 = skip, 1 = ambil
    int dalamUrl = 0; //ngecek apakah baris itu dalam url atau tidak 

    FILE *fp = fopen(namaFile, "r");
    if(fp == NULL){
        printf("Error, Gagal membuka file!!!\n");
        return;
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL){

        if(strstr(buffer, "<url>")){
            dalamUrl = 1;
            ambilData = 0;
            continue;
        }

        if(strstr(buffer, "</url>")){
            dalamUrl = 0;
            ambilData = 0;
            continue;
        }

        if(dalamUrl){
            continue;
        }

        if(strstr(buffer, "<title>") || strstr(buffer, "<body>")){
            ambilData = 1;
        }
       
        if(ambilData){
            token = strtok(buffer, " \n\t\r");
            while(token != NULL){
                if(token[0] != '<'){
                    cleanSafe(token, dataBase, ptrTotal);
                }
                token = strtok(NULL, " \n\t\r");
            }
        }
        if(strstr(buffer, "</title>") || strstr(buffer, "</body>")){
            ambilData = 0;
        }
    }
    fclose(fp);
}