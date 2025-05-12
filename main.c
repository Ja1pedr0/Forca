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
		nome[strcspn(nome, "\n")] = '\0';
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
				registrarResultado(nome, venceu, palavra);
				desenharForca(vidas);
				printf("===========================================================\n");
				Sleep(1500);
				system("cls");
				printf(" ________  ________  _____ ______   _______      \n");
    			printf("|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\     \n");
			    printf("\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|    \n");
			    printf(" \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__  \n");
			    printf("  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\ \n");
			    printf("   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\\n");
			    printf("    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|\n");
			    printf("                                                 \n");
			    printf("                                                 \n");
			    printf("                                                 \n");
			    printf(" ________  ___      ___ _______   ________       \n");
			    printf("|\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\      \n");
			    printf("\\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\     \n");
			    printf(" \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\    \n");
			    printf("  \\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\|   \n");
			    printf("   \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\   \n");
			    printf("    \\|_______|\\|__|/       \\|_______|\\|__|\\|__|  \n\n");
				printf("A resposta era: %s\n", palavra);
				printf("Deseja jogar novamente? (s/n)\n");
				scanf("%c", &jogardnv);
				getchar();
				break;
			}
			venceu = verificarVitoria(letrasused, palavra, tamanhopalavra, tamanhoused);
			desenharForca(vidas);
			desenharJogo(palavra, letrasused, tamanhoused);
			if(venceu)
			{
				registrarResultado(nome, venceu, palavra);
				Sleep(1000);
				system("cls");
				printf("__     __         //\\  __     __                        _ \n");
    			printf("\\ \\   / /__   ___|/_\\| \\ \\   / /__ _ __   ___ ___ _   _| |\n");
			    printf(" \\ \\ / / _ \\ / __/ _ \\  \\ \\ / / _ \\ '_ \\ / __/ _ \\ | | | |\n");
			    printf("  \\ V / (_) | (_|  __/   \\ V /  __/ | | | (_|  __/ |_| |_|\n");
			    printf("   \\_/ \\___/ \\___\\___|    \\_/ \\___|_| |_|\\___\\___|\\____(_)\n\n");
				printf("Deseja jogar novamente? (s/n)\n");
				scanf("%c", &jogardnv);
				getchar();
				break;
			}
		}
	}	
	system("pause");
}