#include "graphmap.h"
#include <stdio.h>

void main()
{
	GraphMap G = BacaMapTXT();
	InitiatePlayerPosition(&G);
	// for (int i = 0; i < 4; ++i)
	// {
	// 	TulisMATRIKS(Wilayah(G,i).Map);
	// }

	int CurrentPos = SearchWilayahPlayer(G);
	TulisMATRIKS(Wilayah(G,CurrentPos).Map);
	printf("\n");
	char C;
	do{
		scanf("%c", &C);
		Move(&G,C);
		TulisMATRIKS(Wilayah(G,SearchWilayahPlayer(G)).Map);
		printf("%d", SearchWilayahPlayer(G) );
		printf("\n\n");
	}while (C != 'x');
}