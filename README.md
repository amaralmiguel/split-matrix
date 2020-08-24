# Split Matrix @ Unicamp
Olá! Este repositório contém um programa em C, que divide uma matriz em outras duas: uma superior e uma inferior. Os dados da Matriz original vêm de um arquivo e as matrizes resultantes são gravadas em arquivos com extensões ".diag1" e ".diag2". O projeto foi desenvolvido para a disciplina de **Sistemas Operacionais da Faculdade de Tecnologia da Unicamp**. Nesse diretório estão os arquivos fonte e um makefile. O arquivo makefile contém as instruções para compilar e gerar os programas. Faça o download do repositório e salve onde preferir.

#### Importante:
Este programa está disponível somente para Linux, pois utiliza bibliotecas que não estão presentes no Windows.

# Instruções de Compilação
Para compilar o programa basta executar o comando "make" (sem aspas). Após a compilação, insira:

-   ./divideMatriz (que é o nome do programa)
-   A dimensão da matriz 
-   A quantidade de Threads 
-   Nome do arquivo 

Exemplo:

./divideMatriz 2000 16 TesteMatriz

# Saídas
Após compilar e executar o programa, você verá novos arquivos dentro da pasta:

-   Um arquivo .dat com dados gerados de forma aleatória;
-   A Matriz superior gravada em um arquivo com extensão ".diag1";
-   A Matriz inferior gravada em um arquivo com extensão ".diag2".

### Observações
Ao compilar e executar o programa no terminal, também é exibido o tempo de execução das threads em milissegundos e em segundos. Para saber o tempo de execução total do programa, basta inserir o comando time antes de inserir os dados, da seguinte forma: 
-   "time ./divideMatriz dimensao_matriz qtd_threads nome_arquivo" (sem aspas).
