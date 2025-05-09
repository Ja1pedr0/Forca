#include "forca.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
	//Definir qual será a palavra através do palavras.txt
	char palavra[50];
	carregarPalavras(palavra);
	//Rodar o jogo da forca:
	//Exibir o desenho da forca
	//exibir a quantidade de _ de acordo com o número de letras
	//pedir ao jogador para entrar com uma letra
	//se a letra não foi usada:
	//verificar se existe a letra na palavra.
	//se existe: deve substituir o _ pela letra
	//se não existe: adicionar uma parte do boneco na forca.
	//se a letra foi usada: avisar na tela e pedir para inserir outra.
	//escrever derrota ou vitoria dependendo da condição
	//exibir a palavra
	//guardar o nome do jogador
	//escrever em resultados.txt o nome, a palavra sorteada, e se perdeu ou ganhou.
	//perguntar se deseja jogar novamente
	system("pause");
}