#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void caregarPalavras(char *palavra)
{
	//abrir o arquivo
	FILE *palavras = fopen("palavras.txt", "r");
	//copiar uma linha aleatória
	srand(time(NULL));
	//colar no *palavra
}