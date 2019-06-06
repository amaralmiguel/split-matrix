/* Inclusoes Padrao. */
#include <stdio.h> //printf(), fscanf(), fprinft() e perror().
#include <stdlib.h> //malloc(), free(), exit(), atoi(), rand() e srand().
#include <pthread.h> //Biblioteca POSIX Threads.
#include <string.h> //strcpy().
#include <sys/time.h> //gettimeofday() e struct timeval.

/* Inclusao criada. */
#include "arquivo.h"

/* Prototipo das Funcoes. */
void *divideMatriz(void *tArg);
void thread (int t, int n);
void alocaMatriz (int n);
double diferencaTempo_miliseg(struct timeval inicio, struct timeval fim);

/* Estrutura com o Argumento para as Threads executarem. */
struct new
{
	int n; //Dimensao da Matriz (N x N).
}flag;

/* Declaracao das Matrizes que serao utilizadas. */
double *matriz; //Matriz original.
double *matrizSuperior;
double *matrizInferior;

/**
 * Funcao principal do programa.
 * @Parametro argc -> Quantidade de argumentos.
 * @Parametro argv -> Vetor que contem os argumentos.
 * @return zero, caso tudo ocorra bem.
 */
int main(int argc, char *argv[])
{
	/* Declarando as variaves: */
	/* Armazenam que foi digitado pelo usuario na linha de comandos. */
	int n = atoi(argv[1]); //Armazena a dimensao da matriz (N x N).
	int t = atoi(argv[2]); // Armazena o numero de Threads.
	char nomeArquivo[31]; //Armazena o nome do Arquivo com os dados para a Matriz.
	strcpy(nomeArquivo,argv[3]);

	flag.n = n; //Preenche a Struct com a dimensao da Matriz.

	/* Tratamento de erro para caso a qtd de parametros fornecidos for invalida: */
	if (argc != 4)
	{
		perror("Numero de parametros invalido, tente novamente!");
		exit(EXIT_FAILURE);
	}

	/* Alocando as Matrizes que serao utilizadas. */
	alocaMatriz(n);

	/* Abre o Arquivo e grava (n*n) dados nele. */
	gravaArquivo(nomeArquivo, n);

	/* Grava os dados do Arquivo acima na Matriz Original. */
	gravaMatriz(nomeArquivo, matriz, n);

	/* Invoca a funcao responsavel pelas threads. */
	thread(t, n);

	/* Gravando os resultados nos arquivos correspondentes. */
	gravaArquivo_Diag1(nomeArquivo, matrizSuperior, n);
	gravaArquivo_Diag2(nomeArquivo, matrizInferior, n);

	/* Liberando a memoria alocada para as Matrizes. */
	free (matriz);
	free (matrizSuperior);
	free (matrizInferior);

	/* Fim da funcao principal. */
	return 0;
}

/**
 * Funcao que as Threads executam. Dividem a Matriz em Superior e Inferior.
 * @Parametro tArg -> Dimensao da Matriz.
 * @return NULL.
 */
void *divideMatriz(void *tArg)
{
	/* Carregando a Struct nesta Funcao. */
	struct new *args = tArg;

	/* Carregando dado da Struct. */
	int n = (args->n);

	/* Divide a Matriz Original em duas: Superior e Inferior. */
	int i, j;
	//Superior
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i > j)
				matrizSuperior[i*n+j] = 0;

			else if (i <= j)
				matrizSuperior[i*n+j] = matriz[i*n+j];
		}
	}
	//Inferior
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i > j)
				matrizInferior[i*n+j] = matriz[i*n+j];

			else if (i <= j)
				matrizInferior[i*n+j] = 0;
		}
	}
	/* Retorno valido para funcao do tipo (void*). */
	return (NULL);
}

/**
 * Funcao para criar e programar o que as Threads devem executar.
 * @Parametro t -> Quantidade de Threads.
 * @Parametro n -> Vetor que contem os argumentos.
 */
void thread (int t, int n)
{
	/* Declarando as estruturas e variaveis de contagem de tempo: */
	struct timeval inicio;
	struct timeval fim;
	double tempo;

	/* Inicio da contagem de tempo: */
	gettimeofday(&inicio, 0);

	/* Armazenando a quantidade de Threads. */
	pthread_t threads[t];

	/* Cria e executa as Threads a partir da quantidade informada */
	int i;
	for (i=0; i<t; i++)
		pthread_create(&threads[i], NULL, divideMatriz, (void*)&flag);

	/* Garante que todas as Threads serão executadas antes do programar acabar */
	for (i=0; i<t; i++)
		pthread_join(threads[i], NULL);

	/* Fim da contagem de tempo: */
	gettimeofday(&fim,0);

	/* Imprime o resultado: */
	tempo = diferencaTempo_miliseg(inicio, fim);
	printf("Tempo de execucao das Threads para t = %i em:\n", t);
	printf("- Milisegundos: %.2f ms.\n", tempo);
	printf("- Segundos: %f s.\n", tempo/1000);
}

/**
 * Funcao para alocar as Matrizes do programa.
 * @Parametro n -> Dimensao da Matriz.
 */
void alocaMatriz (int n)
{
	/* Alocando as Matrizes: */
	matriz = (double*) malloc(sizeof(double)*n*n);
	matrizSuperior = (double*) malloc(sizeof(double)*n*n);
	matrizInferior = (double*) malloc(sizeof(double)*n*n);
	//Caso o processo de alocacao falhe:
	if (matriz == NULL || matrizSuperior == NULL || matrizInferior == NULL)
	{
		perror("Falha ao alocar a Matriz");
		exit(EXIT_FAILURE);
	}
}

/**
 * Funcao para calcular a diferenca de tempo entre duas marcacoes, em milisegundos.
 * @Parametro inicio -> Membro da estrutura que marca o inicio da contagem.
 * @Parametro fim -> Membro da estrutura que marca o fim da contagem.
 * @return Resultado em ms.
 */
double diferencaTempo_miliseg(struct timeval inicio, struct timeval fim)
{   
	return (fim.tv_sec - inicio.tv_sec) * 1000.0f + (fim.tv_usec - inicio.tv_usec) / 1000.0f;
}
