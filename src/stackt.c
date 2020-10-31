#include "stackt.h"
//Randy Zakya Suchrady
//13519061
//K01

void CreateEmpty (Stack *S)
{
	Top(*S) = Nil;
}

boolean IsEmpty (Stack S)
{
	return (Top(S)==Nil);
}

boolean IsFull (Stack S)
{
	return (Top(S)==MaxEl-1);
}

void Push (Stack * S, infotype X)
{
	Top(*S)++;
	InfoTop(*S)=X;
}

void Pop (Stack * S, infotype* X)
{
	*X = InfoTop(*S);
	Top(*S)--;
}