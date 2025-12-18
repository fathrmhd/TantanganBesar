#include <stdio.h>
#include <string.h>

1
#define maxPanjang 100

typedef struct {
    char kata[maxPanjang];
    int panjang;
    int frekuensi;
} DataKata;

void cleanSafe(char *kata, DataKata *dataBase, int *ptrTotal);
void bukaFile(char *namaFile, DataKata *dataBase, int *ptrTotal);
void urutkanData(DataKata *dataBase, int totalKata);
void simpanBinary(DataKata *dataBase, int totalKata, char *namaFileBin);
void tampilkanData(char *namaFileBin);