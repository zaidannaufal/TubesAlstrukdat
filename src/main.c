#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "stdlib.h"
#include "asset.c"
#include "matriks.h"
#include "bintreebangunan.h"
#include "graphmap.h"
#include "bangunan.h"
#include "upgrade.h"
#include "jam.h"
#include "build.h"
#include "office.h"
#include "mekanismepermainan.h"
#include "scankata.h"

int main() {
    FILE* f;
    f = fopen("../external/riwayatinput.txt" , "w");
    fputs("line1." , f);
    fclose(f);
    boolean game=true;
    int gamestart = 0; // kalo 0 berarti game belum jalan
    ListBangunan BangunanNonEx, BangunanEx;
    char* nama;
    char* menu;
    char* input;
    BAHAN bb,bbs;
    wood(bb) = 100000;
    stone(bb) = 100000;
    gold(bb) = 100000;
    wood(bbs) = 0;
    stone(bbs) = 0;
    gold(bbs) = 0;
    Menu();
    printf("\n");
    Menuawal();
    CreateEmptyBangunan(&BangunanEx);
    CreateEmptyBangunan(&BangunanNonEx);
    //sudah pake mesin kata sort of :( 
    // int idxMenu = 0;
    // do {
    //     scanf("%c", menu + idxMenu);
    // } while (menu[idxMenu++] != '\n');
    // menu[--idxMenu] = '\0';
    menu = ScanKata();
    if(Comparestr(menu,"New")==0){
        // int idxNama = 0;
        printf("Memulai permainan baru...\n");
        printf("Masukkan Nama: ");
        // do {
        //     scanf("%c", nama + idxNama);
        // } while (nama[idxNama++] != '\n');
        // nama[--idxNama] = '\0';
        nama = ScanKata();
        gamestart = 1;
    }else {
        return 0;
    }
    printf("\n");
    
    MATRIKS map;
    POINT playerpos;
    Stack stackawal, stacktarget;
    StackCond Conawal;
    CreateEmptyKondisi(&Conawal);
    BinTree wahana[4];
    bacatree(wahana);
    CreateEmptyStack(&stackawal);
    CreateEmptyStack(&stacktarget);
    JAM waktu = MakeJAM(0,0,0);
    JAM waktubuka = MakeJAM(9,0,0);
    
    int money = 50000;
    int totalaksi = 0 ;
    int totalwaktu = 0; 
    int totaluang=0;
    int hari=1;
    GraphMap G = BacaMapTXT();    
    InitiatePlayerPosition(&G);
    Elmt(Wilayah(G,0).Map,8,8) = 'O';    
    do{
        do{
            printf("Preparation Phase Day %d\n",hari);
            TulisMATRIKS(Wilayah(G,SearchWilayahPlayer(G)).Map);
            printf("\n");
            printf("Legend:\n");
            printf("A = Antrian\n");
            printf("P = Player\n");
            printf("W = Wahana\n");
            printf("O = Office\n");
            printf("<, ^, >, V = Gerbang\n");
            printf("\n");
            
            printf("Name: ");
            puts(nama);
            printf("Money: %d\n",money);
            printf("Current Time: ");TulisJAM(waktu);printf("\n");
            printf("Opening Time: ");TulisJAM(waktubuka);printf("\n");
            printf("Time Remaining: ");TulisJAM(DetikToJAM(Durasi(waktu,waktubuka))); printf("\n");
            printf("Total aksi yang akan dilakukan: %d\n",totalaksi);
            printf("Total waktu yang dibutuhkan: ");
            printSisaWaktu(totalwaktu);
            printf("\n");
            printf("Total uang yang dibutuhkan: %d\n",totaluang);
            printf("\n");
            printbahan(bb);
            printbahan(bbs);
            printf("\n");
            printf("command:");
            
            // int idxInput = 0;
            // do {
            //     scanf("%c", input + idxInput);
            // } while (input[idxInput++] != '\n');
            // input[--idxInput] = '\0';
            input = ScanKata();
            printf("\n");
            
            if((Comparestr(input,"w")==0)||(Comparestr(input,"a")==0)||(Comparestr(input,"s")==0)||(Comparestr(input,"d")==0)){
                if (isWaktuCukup(waktu,waktubuka,totalwaktu,5)){
                    Move(&G,input);
                    waktu = NextNDetik(waktu,5*60);
                }
            }else if (Comparestr(input,"Build")==0){
                if (isWaktuCukup(waktu,waktubuka,totalwaktu,15)){
                    
                    inputbefore(bbs,G,totalwaktu,totaluang,&Conawal,BangunanEx);
                    // build(wahana, bb,&bbs,&G,&BangunanNonEx,&totalwaktu,money,&totaluang);
                    build(wahana, bb,&bbs,&G,&BangunanNonEx,&totalwaktu,money,&totaluang);
                    totalaksi++;
                    char B[20];
                    Stringcopy(B,"build");
                    Push(&stackawal,B);
                    
                }else{
                    printf("waktu tidak mencukupi");
                }
                // tinggal si address p nya kemanain
            // }else if (Comparestr(input,"Execute")) // execute
            // {
            //     execute(stackawal, stacktarget);
            }else if (Comparestr(input,"Upgrade")==0){
                if (!IsEmptyBangunan(BangunanEx)){
                    inputbefore(bbs,G,totalwaktu,totaluang,&Conawal,BangunanEx);
                    Upgrade(&BangunanEx,wahana,bb,&bbs,&totaluang,&totalaksi,money,&totalwaktu);
                    char B[20];
                    Stringcopy(B,"upgrade");
                    Push(&stackawal,B);
                    printwahana(First(BangunanEx));
                }else {
                    printf("tidak ada wahana yang bisa diupgrade");
                }
            }else if(Comparestr(input,"Execute")==0){
                execute(stackawal,stacktarget,&BangunanNonEx,&BangunanEx);
                wood(bb) -= wood(bbs);
                stone(bb) -= stone(bbs);
                gold(bb) = gold(bb);
                money -= totaluang;
                totalwaktu = 0;
                totaluang = 0;
                wood(bbs) = 0;
                stone(bbs) = 0;
                gold(bbs) = 0;
                totalaksi = 0;
                gamestart = 2;
            }else if (Comparestr(input,"Buy")==0){
                if (isWaktuCukup(waktu,waktubuka,totalwaktu,15)){
                    inputbefore(bbs,G,totalwaktu,totaluang,&Conawal,BangunanEx);
                    buy(money,&totaluang,&totalaksi,&totalwaktu,&bbs);
                    char bu[20];
                    Stringcopy(bu,"buy");
                    Push(&stackawal,bu);
                }else {
                printf("waktu tidak mencukupi");
                }
            }else if (Comparestr(input,"Undo")==0){
                if (!IsEmptyKondisi(Conawal)){
                    POINT Pbefore; 
                    Absis(Pbefore) = Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition);
                    Ordinat(Pbefore) = Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition);
                    char* buffer;
                    Pop(&stackawal, &buffer);
                    if (Comparestr(buffer,"build")==0){
                        addressbangunan bufferP;
                        DelLast(&BangunanNonEx,&bufferP);
                        Dealokasi(&bufferP);
                    }// }else if(Comparestr(buffer,"upgrade")==0){

                    // }
                    undo(&bbs,&G,&totalwaktu,&totaluang,&Conawal,&BangunanEx);
                    Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition) = Absis(Pbefore);
                    Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition) = Ordinat(Pbefore);
                    Elmt(Wilayah(G,SearchWilayahPlayer(G)).Map,Ordinat(Pbefore),Absis(Pbefore)) = 'P';
                    totalaksi--;
                }else{
                    printf("ga ada yg bisa di undo\n");
                }
                
            }else if (Comparestr(input,"Main")==0){
                DelAll(&BangunanNonEx);
                POINT Pbeforemain; 
                Absis(Pbeforemain) = Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition);
                Ordinat(Pbeforemain) = Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition);
                char* buffermain;
                addressbangunan bufferP;
                while (!IsEmptyStack(stackawal)){
                    Pop(&stackawal,&buffermain);
                    undo(&bbs,&G,&totalwaktu,&totaluang,&Conawal,&BangunanEx);    
                }
                Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition) = Absis(Pbeforemain);
                Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition) = Ordinat(Pbeforemain);
                Elmt(Wilayah(G,SearchWilayahPlayer(G)).Map,Ordinat(Pbeforemain),Absis(Pbeforemain)) = 'P';
                totalwaktu = 0;
                totaluang = 0;
                wood(bbs) = 0;
                stone(bbs) = 0;
                gold(bbs) = 0;
                totalaksi = 0;
                gamestart = 2;

            }else if (Comparestr(input,"Exit")==0){
                gamestart = 0;
            }else{
                printf("Input salah, silakan coba lagi.\n");
            }
            
        }while (gamestart == 1);

        JAM waktututup = MakeJAM(21,0,0);
        waktu = MakeJAM(9,0,0);
        Antrian QueueAntrian;
        InitAntrian(&QueueAntrian,BangunanEx);
          
        do {
            // PrintPrioQueueChar(QueueAntrian);
            int IntervalWaktu;
            printf("Main Phase Day %d\n",hari); // HAHAHAHAHAHAHAHAHAHHA
            TulisMATRIKS(Wilayah(G,SearchWilayahPlayer(G)).Map);
            printf("\n");
            
            
            printf("Legend:\n");
            printf("A = Antrian\n");
            printf("P = Player\n");
            printf("W = Wahana\n");
            printf("O = Office\n");
            printf("<, ^, >, V = Gerbang\n");
            printf("\n");
            
            printf("Name: ");
            puts(nama);
            printf("Money: %d\n",money);
            printf("Current Time: ");TulisJAM(waktu);printf("\n");
            printf("Closing Time: ");TulisJAM(waktututup);printf("\n");
            printf("Time Remaining: ");TulisJAM(DetikToJAM(Durasi(waktu,waktututup))); printf("\n");
            printf("Antrian [%d/5]:\n", NBElmtAntrian(QueueAntrian)); // HAHAHAHAHAHAHAHAHHA
            addressbangunan broken = Nil;
            broken = brokenWahana(BangunanEx);
            breakWahana(&BangunanEx,waktu);
            if (broken!= Nil){
                printf("Terdapat Bangunan yang rusak : ");
                puts(nama(broken));
                printf("bangunan tersebut terdapat di ");
                TulisPOINT(point(broken));
                printf(" pada wilayah %d\n",wilayah(broken));

            }else
            {
                printf("Tidak ada bangunan yang rusak\n");
            }
            
            printf("\n");
            printf("command:");

            // int idxInput = 0;
            // do {
            //     scanf("%c", input + idxInput);
            // } while (input[idxInput++] != '\n');
            // input[--idxInput] = '\0';
            input = ScanKata();
            printf("\n");
            
            if((Comparestr(input,"w")==0)||(Comparestr(input,"a")==0)||(Comparestr(input,"s")==0)||(Comparestr(input,"d")==0)){
                if (isWaktuCukup(waktu,waktubuka,totalwaktu,5)){
                    Move(&G,input);
                    waktu = NextNDetik(waktu,5*60);
                    IntervalWaktu = 300;
                }
            } else if (Comparestr(input,"Serve")==0){ 
                int moneycompare = money;
                Serve(&(QueueAntrian),&BangunanEx,&money);
                if (moneycompare != money)
                {
                    waktu = NextNDetik(waktu,30*60);
                    IntervalWaktu = 1800;
                }
            } else if (Comparestr(input,"Repair")==0){ 
                int waktuawal = JAMToDetik(waktu);
                repair(&money,&waktu,G,&BangunanEx,wahana,&bb);
                IntervalWaktu = JAMToDetik(waktu) - waktuawal;
            } else if (Comparestr(input,"Detail")==0){ 
                detail(G,BangunanEx,&waktu);
                waktu = NextNDetik(waktu,10*60);
                IntervalWaktu = 600;
            } else if(Comparestr(input,"Office")==0){ 
                if(IsinOffice(G)){
                Office(&BangunanEx);
                char getoutoffice[2];
                Stringcopy(getoutoffice,"w");
                Move(&G,getoutoffice);
                Elmt(Wilayah(G,0).Map,8,8) = 'O';
                waktu = NextNDetik(waktu,10*60);
                IntervalWaktu = 600;
                }else {
                    printf("Anda tidak berada di office\n");
                }
            } else if (Comparestr(input,"Prepare")==0){
                NgosonginAntrian(&QueueAntrian);
                addressbangunan P;
                P = First(BangunanEx);
                while (P != NULL)
                { 
                    JmlPakaiToday(P) = 0;
                    HasilToday(P) = 0;
                    P = Next(P);
                }
                printf("sampai akhirloop\n");
                hari++;
                gamestart = 1;   
            } else if(Comparestr(input,"exit")==0){ // HAHAHHAHAHAHDAKWFBHGWFUIGFBMEJGFUW
                gamestart=0;
                game = false;
            } else if(JEQ(waktu,waktututup)){
                NgosonginAntrian(&QueueAntrian);
                addressbangunan P;
                P = First(BangunanEx);
                while (P != NULL)
                { 
                    JmlPakaiToday(P) = 0;
                    HasilToday(P) = 0;
                    P = Next(P);
                }
                printf("sampai akhirloop\n");
                hari++;
                gamestart = 1;
            }else{
                printf("Input salah, silakan coba lagi.\n");
            }
            MekanismeGaSabar(&QueueAntrian, IntervalWaktu);
            MekanismeNaikWahana(&QueueAntrian,&BangunanEx,IntervalWaktu);

        } while (gamestart == 2);

    } while (game);
    return 0;
}
