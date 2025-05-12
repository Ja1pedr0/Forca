void carregarPalavras(char *palavra);
void desenharForca(int vidas);
void desenharJogo(char palavra[], char palavrasused[], int tamanhoused);
int verificarLetra(char novaletra, char letrasused[], int tamanhoused);
int verificarVitoria(char letrasused[],char palavra[], int tamanhopalavra, int tamanhoused);
void resetarray(char array[],int tamanhoarray);
void registrarResultado(char nome[],int venceu,char palavra[]);
