#include "mesinkata.h"
#include <stdio.h>
#include "scankata.h"
#include <stdlib.h>

char* ScanKata()
{
	str Path = "../external/riwayatinput.txt";
	totalstr HistoryInput;
	STARTKATA(Path);
	int i = 1;
	int a;
	for (a = 0; a < 50; ++a)
	{
		HistoryInput[0][a] = CKata.TabKata[a];
	}
	while (CC != MARK)
	{
		ADVKATA();
		int j;
		for (j = 0; j < CKata.Length; ++j)
		{
			HistoryInput[i][j] = CKata.TabKata[j];
		}
		i++;
	}
	str Word;
	scanf("%[^\n]%*c", &Word);
	FILE* fw = fopen(Path,"w");
	int k;
	for (k = 0; k < i; ++k)
	{
		fputs(HistoryInput[k], fw);
		fputs("\n" , fw);
	}
	fputs(Word , fw);
	fputs("." , fw);
	fclose(fw);
	STARTKATA(Path);
	int l = 1;
	while (CC != MARK)
	{
		ADVKATA();
		l++;
		if (l == i+1)
		{
			int length = CKata.Length;
			int counter;
			char* Hasil = malloc(sizeof (char) * length+1);
			for (counter = 0; counter < length; ++counter)
			{
				Hasil[counter] = CKata.TabKata[counter];
			}
			Hasil[counter+1] = '\0';
			return Hasil;
		}
	}
}

// void main()
// {
// 	char* Dapat = ScanKata();
// 	puts(Dapat);
// }