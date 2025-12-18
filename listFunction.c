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
    char buffer[4096]; 
    char *token;
    int ambilData = 0; 

    FILE *fp = fopen(namaFile, "r");
    if(fp == NULL){
        printf("Error, Gagal membuka file!!!\n");
        return;
    }

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        token = strtok(buffer, " <>+\n\t\r"); 
        
        while(token != NULL){
            if(strcmp(token, "url") == 0) {
                while(token != NULL && strcmp(token, "/url") != 0) {
                    token = strtok(NULL, " <>+\n\t\r");
                }
            } else if(strcmp(token, "title") == 0 || strcmp(token, "body") == 0) {
                ambilData = 1;
            } else if(strcmp(token, "/title") == 0 || strcmp(token, "/body") == 0) {
                ambilData = 0;
            } else {
                if(ambilData && strlen(token) > 0) {
                    if(strstr(token, "http") == NULL) {
                        cleanSafe(token, dataBase, ptrTotal);
                    }
                }
            }
            if (token != NULL) {
                token = strtok(NULL, " <>+\n\t\r");
            }
        }
    }
    fclose(fp);
}

void urutkanData(DataKata *dataBase, int totalKata) {
    for (int i = 0; i < totalKata - 1; i++) {
        for (int j = 0; j < totalKata - i - 1; j++) {
            int tukar = 0;
            DataKata *saatIni = &dataBase[j];
            DataKata *selanjutnya = &dataBase[j + 1];

            if (saatIni->frekuensi < selanjutnya->frekuensi) {
                tukar = 1;
            } else if (saatIni->frekuensi == selanjutnya->frekuensi) {
                if (saatIni->panjang < selanjutnya->panjang) {
                    tukar = 1;
                } else if (saatIni->panjang == selanjutnya->panjang) {
                    if (strcmp(saatIni->kata, selanjutnya->kata) < 0) {
                        tukar = 1;
                    }
                }
            }
            if (tukar) {
                DataKata temp = *saatIni;
                *saatIni = *selanjutnya;
                *selanjutnya = temp;
            }
        }
    }
}

void simpanBinary(DataKata *dataBase, int totalKata, char *namaFileBin) {
    FILE *fbin = fopen(namaFileBin, "wb");
    if (fbin == NULL) return;

    for (char huruf = 'a'; huruf <= 'z'; huruf++) {
        int jmlKataAbjad = 0;
        for (int i = 0; i < totalKata; i++) {
            if (dataBase[i].kata[0] == huruf) jmlKataAbjad++;
        }

        fwrite(&huruf, sizeof(char), 1, fbin);
        fwrite(&jmlKataAbjad, sizeof(int), 1, fbin);

        for (int i = 0; i < totalKata; i++) {
            if (dataBase[i].kata[0] == huruf) {
                fwrite(&dataBase[i].panjang, sizeof(int), 1, fbin); // 
                fwrite(dataBase[i].kata, sizeof(char), maxPanjang, fbin); // 
                fwrite(&dataBase[i].frekuensi, sizeof(int), 1, fbin); // 
            }
        }
    }
    fclose(fbin);
    printf("Data berhasil disimpan ke %s\n", namaFileBin);
}

void tampilkanData(char *namaFileBin) {
    int n;
    printf("Berapa abjad yang ingin anda lihat (max = 26): "); 
    scanf("%d", &n);

    FILE *fbin = fopen(namaFileBin, "rb");
    if (fbin == NULL) return;

    char abjad;
    int jmlKata;
    
    printf("abjad {kata (frekuensi)}\n"); 
    
    while (fread(&abjad, sizeof(char), 1, fbin) == 1) {
        fread(&jmlKata, sizeof(int), 1, fbin);
        printf("%c {", abjad);
        
        int limit = (jmlKata < n) ? jmlKata : n;
        
        for (int j = 0; j < jmlKata; j++) {
            int pjg;
            char kata[maxPanjang];
            int frek;
            
            fread(&pjg, sizeof(int), 1, fbin);
            fread(kata, sizeof(char), maxPanjang, fbin);
            fread(&frek, sizeof(int), 1, fbin);
            
            if (j < limit) {
                printf("%s (%d)", kata, frek);
                if (j < limit - 1) printf(", ");
            }
        }
        printf("}\n"); 
    }
    fclose(fbin);
}