#include "forca.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void main()
{
	char palavra[50];
	char letrasused[28] = {0};
	int vidas = 4;
	int tamanhoused =0;
	char novaletra;
	int tamanhopalavra = strlen(palavra);
	int i, temletra;

	carregarPalavras(palavra);
	system("cls");
	desenharForca(vidas);
	desenharJogo(palavra, letrasused, tamanhoused);

	while(1)
	{
		if(tamanhoused<28)
		{
			temletra = 0;
			printf("Digite uma letra: ");
			scanf(" %c", &novaletra);
			getchar();
			if(verificarLetra(novaletra, letrasused, tamanhoused))
			{
				printf("Essa letra ja foi usada, tente novamente!");
				Sleep(1700);
			}
			else if(verificarLetra(novaletra, letrasused, tamanhoused)==0)
			{
				letrasused[tamanhoused] = novaletra;
				tamanhoused++;
			}
			for(i=0;i<tamanhopalavra;i++)
			{
				if(palavra[i]==novaletra)
				{
					temletra = 1;
				}
			}
			if(temletra==0){vidas = vidas-1;}
			system("cls");
			if(vidas==0)
			{
				desenharForca(vidas);
				printf("===========================================================\n");
				printf("Game Over!!\n");
				printf("A resposta era: %s\n", palavra);
				Sleep(2000);
				break;
			}
			desenharForca(vidas);
			desenharJogo(palavra, letrasused, tamanhoused);
		}
		else
		{
			system("cls");
			printf("Erro de memoria, voce ja usou todas as letras possiveis!!\n");
			Sleep(2000);
			exit(1);
		}
	}	
	system("pause");
}