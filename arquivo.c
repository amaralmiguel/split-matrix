/* Inclusao do cabecalho de Bibliotecas e Funcoes. */
#include "arquivo.h"

/* Gera valores entre 0 e 1, em ponto flutuante. */
double geraDados()
{
	return 0.00 + ( rand() / ( RAND_MAX / ( 1.00 - 0.00 ) ) );
}

/**
 * Funcao para gravar dados aleatorios em um Arquivo.
 * @Parametro nomeArquivo -> Nome do Arquivo a ser aberto.
 * @Parametro n -> Quantidade de elementos a serem gerados (n * n).
 */
void gravaArquivo(char nomeArquivo[], int n)
{
	/* Adiciona a extensao ".dat" ao nome do Arquivo. */
	char extensao[31];
	strcpy(extensao,nomeArquivo);
	strcat(extensao,".dat");

	/* Abrindo o Arquivo para escrita: */
	FILE *arquivo = fopen(extensao,"wb");
	//Em caso de falha:
	if(arquivo == NULL)
	{
		perror("Falha ao abrir arquivo para gravar dados");
		exit(EXIT_FAILURE);
	}

	/* Utilizando registradores para um acesso mais veloz: */
	register int i;

	/* Garante a geração de números aleatorios: */
	srand(time(NULL));

	/* Gravando dados no Arquivo: */
	for (i=0; i < (n*n); i++)
		fprintf (arquivo, "%lf ", geraDados());

	/* Fecha o arquivo apos gravar os dados. */
	fclose(arquivo);
}

/**
 * Funcao para gravar dados do Arquivo em uma Matriz
 * @Parametro nomeArquivo -> Nome do Arquivo a ser aberto.
 * @Parametro matriz -> Matriz que sera gravada.
 * @Parametro n -> Dimensao da Matriz.
 * @return Matriz preenchida.
 */
double gravaMatriz(char nomeArquivo[], double *matriz, int n)
{
	/* Adiciona a extensao ".dat" ao nome do Arquivo. */
	char extensao[31];
	strcpy(extensao,nomeArquivo);
	strcat(extensao,".dat");

	/* Abrindo o Arquivo para leitura: */
	FILE *arquivo = fopen(extensao,"rb");
	//Em caso de erro:
	if(arquivo == NULL)
	{
		perror("Falha ao abrir arquivo para leitura de dados");
		exit(EXIT_FAILURE);
	}

	/* Utilizando registradores para um acesso mais veloz: */
	register int i,j;

	/* Gravando dados na Matriz: */
	for (i=0; i<n; i++){  //Percorre linhas.
		for(j=0; j<n; j++){ //Percorre colunas.
			fscanf(arquivo, "%lf ", &matriz[i*n+j]);
		}
		fprintf(arquivo, "%s", "\n");
	}

	/* Fecha o arquivo apos gravar os dados. */
	fclose(arquivo);

	/* Retorna a Matriz preenchida. */
	return *matriz;
}

/**
 * Funcao para gravar dados da Matriz Superior no Arquivo _diag1
 * @Parametro nomeArquivo -> Nome do Arquivo a ser aberto.
 * @Parametro matriz -> Matriz que sera gravada.
 * @Parametro n -> Dimensao da Matriz.
 */
void gravaArquivo_Diag1(char nomeArquivo[], double *matriz, int n)
{
	/* Adiciona a extensao ".diag1" ao nome do Arquivo: */
	char extensao[31];
	strcpy(extensao,nomeArquivo);
	strcat(extensao,".diag1");

	/* Abrindo o Arquivo para escrita: */
	FILE *arquivo = fopen(extensao,"wb");
	//Em caso de erro:
	if(arquivo == NULL)
	{
		perror("Falha ao abrir arquivo para leitura de dados");
		exit(EXIT_FAILURE);
	}

	/* Utilizando registradores para um acesso mais veloz: */
	register int i,j;

	/* Gravando a Matriz no Arquivo: */
	for (i=0; i<n; i++){ //Percorre Linhas.
		for(j=0; j<n; j++){ //Percorre Colunas.
			fprintf(arquivo, "%lf ", matriz[i*n+j]);
		}
		fprintf(arquivo, "%s", "\n");
	}

	/* Fecha o arquivo apos gravar os dados. */
	fclose(arquivo);
}

/**
 * Funcao para gravar dados da Matriz Inferior no Arquivo _diag2
 * @Parametro nomeArquivo -> Nome do Arquivo a ser aberto.
 * @Parametro matriz -> Matriz que sera gravada.
 * @Parametro n -> Dimensao da Matriz.
 */
void gravaArquivo_Diag2(char nomeArquivo[], double *matriz, int n){

	/* Adiciona a extensão ".diag2" ao nome do Arquivo: */
	char extensao[31];
	strcpy(extensao,nomeArquivo);
	strcat(extensao,".diag2");

	/* Abrindo o Arquivo para escrita: */
	FILE *arquivo = fopen(extensao,"wb");
	//Em caso de erro:
	if(arquivo == NULL)
	{
		perror("Falha ao abrir arquivo para leitura de dados");
		exit(EXIT_FAILURE);
	}

	/* Utilizando registradores para um acesso mais veloz: */
	register int i,j;

	/* Gravando a Matriz no Arquivo: */
	for (i=0; i<n; i++){ //Percorre Linhas.
		for(j=0; j<n; j++){ //Percorre Colunas.
			fprintf(arquivo, "%lf ", matriz[i*n+j]);
		}
		fprintf(arquivo, "%s", "\n");
	}

	/* Fecha o arquivo apos gravar os dados. */
	fclose(arquivo);
}
