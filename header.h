#include <stdio.h>
#include <string.h>

#define maxKata 20000
#define maxPanjang 100

typedef struct{
    char kata[maxPanjang];
    int panjang;
    int frekuensi;
}DataKata;