/* Cabecalho de Bibliotecas e Funcoes */
#include <stdio.h> //fscanf(), fprinft(), fclose() e perror()
#include <stdlib.h> //exit(), rand() e srand()
#include <time.h> //Para a função srand()
#include <string.h> //strcat() e strcpy()

/* Gera dados aleatórios. */
double geraDados();

/* Função para gravar dados de um Arquivo na Matriz. */
double gravaMatriz(char nomeArquivo[], double *matriz, int n);

/* Funções para gravar dados em Arquivo. */
void gravaArquivo(char nomeArquivo[], int n);
void gravaArquivo_Diag1(char nomeArquivo[], double *matriz, int n);
void gravaArquivo_Diag2(char nomeArquivo[], double *matriz, int n);


