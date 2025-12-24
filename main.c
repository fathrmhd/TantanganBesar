#include "header.h"

static DataKata dataBase[maxKata];

int main(void){
    int totalKata = 0;
    int pilihan = 0;
    int statusSimpan = 0;

    char namaFile[100];
    char namaFileBin[] = "hasil.bin";

    printf("Masukkan nama file input (txt): ");
    scanf("%[^\n]", namaFile);
    getchar();
    
    printf("\nSedang membuka file...\n");
    bukaFile(namaFile, dataBase, &totalKata);
    printf("Selesai buka file. Total kata unik yang berhasil dibaca : %d\n", totalKata);

    printf("\nSedang mengurutkan data...\n");
    urutkanData(dataBase, totalKata);
    printf("Selesai mengurutkan.\n");

    do{
        printf("\n================ MENU ================\n");
        printf("1) Simpan output ke dalam file binary\n");
        printf("2) Tampilkan hasil output\n");
        printf("3) Selesai\n");
        printf("Pilih: ");

        if (scanf("%d", &pilihan) != 1){
            printf("Input tidak valid!\n");
            break;
        }

        switch(pilihan){
            case 1:
                simpanBinary(dataBase, totalKata, namaFileBin);
                statusSimpan = 1;
                break;
            
            case 2:
                if(!statusSimpan == 0){
                    printf("\nMenyimpan data ke file binary terlebih dahulu\n");
                    simpanBinary(dataBase, totalKata, namaFileBin);
                    statusSimpan = 1;
                }
                tampilkanData(namaFileBin);
                break;
            
            case 3:
                printf("\nProgram selesai\n");
                break;
            
            default:
                printf("\nPilihan tidak valid!\n");
        }
    } while (pilihan != 3);

    return 0;
}
