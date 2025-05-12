#include "forca.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void main()
{
	char palavra[50];
	char letrasused[28] = {0};
	int vidas;
	int tamanhoused;
	char novaletra;
	int i, temletra;
	int venceu;
	char nome[50];
	char jogardnv = 's';


	while(jogardnv=='s'){
		system("cls");
		vidas =4;
		tamanhoused = 0;
		venceu = 0;
		printf("Digite seu nome: ");
		fgets(nome, sizeof(nome), stdin);
		carregarPalavras(palavra);
		int tamanhopalavra = strlen(palavra);
		resetarray(letrasused, 28);
		system("cls");
		desenharForca(vidas);
		desenharJogo(palavra, letrasused, tamanhoused);
		while(1)
		{
			temletra = 0;
			printf("Digite uma letra: ");
			scanf(" %c", &novaletra);
			getchar();
			if(verificarLetra(novaletra, letrasused, tamanhoused))
			{
				printf("Essa letra ja foi usada, tente novamente!");
				Sleep(1700);
				system("cls");
				desenharForca(vidas);
				desenharJogo(palavra, letrasused, tamanhoused);
				continue;
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
				printf("Deseja jogar novamente? (s/n)\n");
				scanf("%c", &jogardnv);
				getchar();
				Sleep(2000);
				break;
			}
			venceu = verificarVitoria(letrasused, palavra, tamanhopalavra, tamanhoused);
			desenharForca(vidas);
			desenharJogo(palavra, letrasused, tamanhoused);
			if(venceu)
			{
				Sleep(1000);
				system("cls");
				printf("Parabens!!! Voce Venceu!\n");
				printf("Deseja jogar novamente? (s/n)\n");
				scanf("%c", &jogardnv);
				getchar();
				break;
			}
		}
	}	
	system("pause");
}