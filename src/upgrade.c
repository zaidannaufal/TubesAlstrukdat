#include <stdio.h>
#include "upgrade.h"
#include <string.h>
int TipeRootWahana(char* NamaWahana, ListBangunan * LB)
{
	addressbangunan Current = First(*LB);
	while(Current != NULL)
	{
		if (strcmp(nama(Current),NamaWahana)==0)
		{
			return tipe(Current);
		}
		Current = Next(Current);
	}
	return -1;
}


void Upgrade(ListBangunan * LB, BinTree* BT, BAHAN bb,BAHAN *bbs, int * Bill, int * Aksi, int CurrentMoney, int * TambahanWaktu)
{
	printf("Mau upgrade apa?\nList:\n");
	addressbangunan Current = First(*LB);
	while(Current != NULL) // Print semua wahana yang dipunya
	{
		printf("- ");
		puts(nama(Current));
		Current = Next(Current);
	}
	char NamaBangunan[50];
	int idxNBangunan = 0;
    do {
        scanf("%c", NamaBangunan + idxNBangunan);
    } while (NamaBangunan[idxNBangunan++] != '\n');
    NamaBangunan[--idxNBangunan] = '\0';
	int TipeRoot = TipeRootWahana(NamaBangunan,LB); //Nyari Root Wahana Yang Dimaksud
	addressbangunan BangunanTujuan = First(*LB);
	while (BangunanTujuan != NULL && (strcmp(nama(BangunanTujuan),NamaBangunan)) != 0)
	{
		BangunanTujuan = Next(BangunanTujuan);
	}
	int Keuangan = CurrentMoney - (*Bill) - HUpgrade(BangunanTujuan);
	if (Keuangan >= 0)
	{
		BinTree Root = BT[TipeRoot]; //Root Wahananya dalam bentukk bintree
		if (history(BangunanTujuan) == 0 && BBcukup(bb,*bbs,((Left(BT[TipeRoot]))->info).resource.resource))
		{
			(*Bill) += HUpgrade(BangunanTujuan);
			//Belum bahan bangunan
			Root = Left(Root);
			Harga(BangunanTujuan) = harga(Root);
			durasibangunan(BangunanTujuan) = durasibt(Root);
			KapasitasBang(BangunanTujuan) = kapasitas(Root);
			HUpgrade(BangunanTujuan) = HUpgrade(Root);
			(*TambahanWaktu)+=90;
			(*Aksi)++;
			history(BangunanTujuan)++;
		}else if (history(BangunanTujuan) == 1&& BBcukup(bb,*bbs,((Left(Left(BT[TipeRoot])))->info).resource.resource))
		{
			(*Bill) += HUpgrade(BangunanTujuan);
			//Belum bahan bangunan
			Root = Left(Left(Root));
			Harga(BangunanTujuan) = harga(Root);
			durasibangunan(BangunanTujuan) = durasibt(Root);
			KapasitasBang(BangunanTujuan) = kapasitas(Root);
			HUpgrade(BangunanTujuan) = HUpgrade(Root);
			(*TambahanWaktu)+=90;
			(*Aksi)++;
			history(BangunanTujuan)++;
		}else if (history(BangunanTujuan) == 2)
		{
			printf("Tidak bisa diupgrade lagi, wahan sudah mencapai tingkatan upgrade maksimum\n");
		}
	}else printf("Uang tidak mencukupi!\n");
}

void printwahana(addressbangunan wahana){
	printf("nama wahana: ");
	puts(nama(wahana));
	printf("tipe : %d\n",tipe(wahana));
	printf("point : ");
	TulisPOINT(point(wahana));
	printf("\n");
	printf("Harga : %d\n",Harga(wahana));
	printf("Durasi: %d\n",durasibangunan(wahana));
	printf("Kapasitas : %d\n",KapasitasBang(wahana));
	printf("History: %d\n",history(wahana));
	printf("Durability : %d\n",durability(wahana));
	printf("Harga : %d\n",Harga(wahana));
	printf("Status : %d\n",status(wahana));
	printf("Hupgrade : %d\n",HUpgrade(wahana));
}
