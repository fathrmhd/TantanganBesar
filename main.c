#include "header.h"

static DataKata dataBase[maxKata];

int main(){
    int totalKata = 0;
    char namaFile[100];
    char namaFileBin[] = "hasil.bin";
    int pilihan = 0;
    int statusSimpan = 0; 

    printf("Masukkan nama file input (txt): ");
    scanf("%[^\n]", namaFile);
    getchar();
    
    printf("Sedang membuka file...\n");
    bukaFile(namaFile, dataBase, &totalKata);
    printf("Selesai buka file. Total kata unik: %d\n", totalKata);

    printf("Sedang mengurutkan data...\n");
    urutkanData(dataBase, totalKata);
    printf("Selesai mengurutkan.\n");

    while(pilihan != 3){
        printf("\n--- MENU PROJECT BIG CHALLENGE ---\n");
        printf("1) Simpan luaran dalam file binari\n");
        printf("2) Tampilkan di layar monitor n kata\n");
        printf("3) Selesai\n");
        printf("Pilihan anda: ");
        scanf("%d", &pilihan);

        switch(pilihan){
            case 1:
                simpanBinary(dataBase, totalKata, namaFileBin);
                statusSimpan = 1;
                break;
            case 2:
                if(statusSimpan == 0){
                    printf("Menjalankan penyimpanan otomatis ke binari...\n");
                    simpanBinary(dataBase, totalKata, namaFileBin);
                    statusSimpan = 1;
                }
                tampilkanData(namaFileBin);
                break;
            case 3:
                printf("Program berakhir\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}