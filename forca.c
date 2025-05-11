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
		printf("  ________\n |       |\n |       |\n |       O\n |       |\n |       \n |       \n_|___\n");

	}
	if(vidas==1)
	{
		printf("  ________\n |       |\n |       |\n |       O\n |      /|\\\n |       \n |       \n_|___\n");

	}
	if(vidas==0)
	{
		printf("  ________\n |       |\n |       |\n |       O\n |      /|\\\n |      / \\\n |       \n_|___\n");

	}
	printf("\n");
}

void desenharJogo(char palavra[], char letrasused[],int tamanhoused)
{
	int tamanho = strlen(palavra);
	int i, t, achou;
	for(i=0; i<tamanho;i++)
	{
		achou = 0;
		for(t=0;t<tamanhoused;t++)
		{
			if(palavra[i] == letrasused[t])
			{
				printf(" %c", palavra[i]);
				achou = 1;
				break;
			}
		}
			if(achou==0)
			{
				printf(" _");
			}	
	}
	printf("\n");
	printf("===========================================================\n");
}

int verificarLetra(char novaletra, char letrasused[],int tamanhoused)
{
	int i;
	for(i=0;i<tamanhoused;i++)
	{
		if(novaletra == letrasused[i])
		{
			return 1;
		}
	}	
	return 0;
}

int verificarVitoria(char letrasused[], char palavra[],int tamanhopalavra, int tamanhoused)
{
	int i, t;
	int progresso = 0;
	for(i=0;i<tamanhopalavra;i++)
	{
		for(t=0;t<tamanhoused;t++)
		{
			if(letrasused[t] == palavra[i])
			{
				progresso++;
			}
		}
	}
	if(progresso==tamanhopalavra){return 1;}
	else{return 0;}
}
