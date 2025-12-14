#include "header.h"  

void cleanSafe(char *kata, DataKata *dataBase, int *ptrTotal){
      
}

void bukaFile(char *namaFile, DataKata *dataBase, int *ptrTotal){
    char buffer[1024];
    char *token;
    int ambilData = 0; // 0 = skip, 1 = ambil

    FILE *fp = fopen(namaFile, "r");
    if(fp == NULL){
        printf("Error, Gagal membuka file!!!\n");
        return;
    }

    while(fgets(buffer, 1024, fp) != NULL){
        if(strstr(buffer, "<title>") || strstr(buffer, "<body>")){
            ambilData = 1;
        }
        if(strstr(buffer, "<url>")){
            continue;
        }
        if(ambilData){
            token = strtok(buffer, " \n\t\r");
            while(token != NULL){
                if(token[0] != '<'){
                    cleanSafe(token, dataBase, totalKata);
                }
                token = strtok(NULL, "\n\t\r");
            }
        }
        if(strstr(buffer, "</tittle>") || strstr(buffer, "</body>")){
            ambilData = 0;
        }
    }
    fclose(fp);
}