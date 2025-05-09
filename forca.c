#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "forca.h"

void carregarPalavras(char *palavra)
{
	//declarar variaveis
	int linhaSorteada;
	char linha[50];
	int numLinhas = 0;
	int cont = 1;
	//abrir arquivo
	FILE *palavras = fopen("palavras.txt", "r");
	if(palavras==NULL)
	{
		printf("Erro ao abrir arquivo!\n");
		exit(1);
	}
	//verificar a quantidade de linhas
	while(fgets(linha, sizeof(linha), palavras) != NULL)
	{
		numLinhas = numLinhas + 1;
	}
	//copiar uma linha aleatória
	srand(time(NULL));
	linhaSorteada = (rand() % numLinhas) +1;
	fseek(palavras, 0, SEEK_SET); 
	//colar no *palavra
	while(fgets(linha, sizeof(linha), palavras) != NULL)
	{
		if(cont == linhaSorteada)
		{
			strcpy(palavra, linha);
			break;
		}
		cont = cont + 1;
	}
	//tirar o \n da palavra
	palavra[strcspn(palavra, "\n")] = '\0';
	//fechar arquivo
	fclose(palavras);
}

void desenharForca(int vidas)
{
	printf("===========================================================\n");
	if(vidas==4)
	{
		printf("  ________\n |       |\n |       |\n |       \n |       \n |       \n |       \n_|___\n");
	}
	if(vidas==3)
	{
		printf("  ________\n |       |\n |       |\n |       O\n |       \n |       \n |       \n_|___\n");
	}
	if(vidas==2)
	{
		printf("  ________\n |       |\n |       |\n |       O\n |       |\n |       \n   |       \n_|___\n");

	}
	if(vidas==1)
	{
		printf("  ________\n |       |\n |       |\n |       O\n |      /|\\\n |       \n |       \n_|___\n");

	}
	if(vidas==0)
	{
		printf("  ________\n |       |\n |       |\n |       O\n |      /|\\\n |      / \\\n |       \n_|___\n");

	}
}
