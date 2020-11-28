#include <stdio.h>
#include "upgrade.h"

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


void Upgrade(ListBangunan * LB, BinTree* BT, BAHAN* bb, int * Bill, int * Aksi, int CurrentMoney, int TambahanWaktu)
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
	scanf("%s" , &NamaBangunan); //Nyari wahana apa
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
		if (history(BangunanTujuan) == 0)
		{
			(*Bill) += HUpgrade(BangunanTujuan);
			//Belum bahan bangunan
			Root = Left(Root);
			Harga(BangunanTujuan) = harga(Root);
			durasibangunan(BangunanTujuan) = durasibt(Root);
			KapasitasBang(BangunanTujuan) = kapasitas(Root);
			HUpgrade(BangunanTujuan) = HUpgrade(Root);
			(*Aksi)++;
			history(BangunanTujuan)++;
		}else if (history(BangunanTujuan) == 1)
		{
			(*Bill) += HUpgrade(BangunanTujuan);
			//Belum bahan bangunan
			Root = Left(Left(Root));
			Harga(BangunanTujuan) = harga(Root);
			durasibangunan(BangunanTujuan) = durasibt(Root);
			KapasitasBang(BangunanTujuan) = kapasitas(Root);
			HUpgrade(BangunanTujuan) = HUpgrade(Root);
			(*Aksi)++;
			history(BangunanTujuan)++;
		}else if (history(BangunanTujuan) == 2)
		{
			printf("Tidak bisa diupgrade lagi, wahan sudah mencapai tingkatan upgrade maksimum\n");
		}
	}else printf("Uang tidak mencukupi!\n");
}