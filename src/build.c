#include "stdio.h"
#include "bintreebangunan.h"
#include "bangunan.h"

// bangunan dobuild(posisi,arrayofapa,bangunan,stack bahan){
//     movebottom{}
//     edit itu pos jadi w
//     kurangin bahan
// }

void build(BinTree* wahana){
    char input[50];
    int i = 0;
    printf("Ingin membangun apa? \n");
    printf("list:\n");
    for(i=0;i<=2;i++){
        printf("[%d] ",i+1);
        puts(tipe(wahana[i]));
    }
        // do {
        //     scanf("%c", input + idxInput);
        // } while (input[idxInput++] != '\n');
        // input[--idxInput] = '\0';
        // printf("\n");
        // printf("sampai sini");
    //     i = searchtipetree(wahana,input,3);
    printf("Pilih tipe yang diinginkan :");
    scanf("%d",&i);
    printf("tipe yang dipilih : ");
    puts(tipe(wahana[i-1]));
    int idxInput = 0;
    printf("Masukkan nama bangunan :");
    getchar(); //buffer
    do {
            scanf("%c", input + idxInput);
    } while (input[idxInput++] != '\n');
    input[--idxInput] = '\0';
    printf("\n");
    
} 
    
//     fgets(str1, 20, stdin);
//     i=0;
//     int no_wahana;
//     boolean found = false;
//     while (i<3&&!found)
//     {
//         no_wahana = comparestring(Tipe(wahana[i]),str1) ? i : 0;
//     }
    
//     sprintf(str1, "Value of Pi = %f", M_PI);
// }