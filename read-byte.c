#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


void configurarMatriz(int *numeroLinhas,int *numeroColunas){
int dimensao;
printf("Qual dimensao voce deseja para sua matriz:\n");
printf("\n[0] Padrao 8-8 \n[1] Outra dimensao \n\n");

scanf("%d",&dimensao);

if( dimensao == 0 ){
    *numeroLinhas = 8;
    *numeroColunas = 8;
    printf("Voce escolheu padrao a Matriz sera 8-8 \n\n\n");
}else if ( dimensao == 1){
printf("Quantas linhas voce deseja:\n");

scanf("%d",numeroLinhas);
printf("\nQuantas Colunas voce deseja:\n");
scanf("%d",numeroColunas);

printf("Voce escolheu a matriz personalizada a Matriz sera %d-%d :\n",*numeroLinhas,*numeroColunas);

}

}
void printVetor(int * vetor,int tamanho)
{

    printf("O resultado da leitura da matriz foi : \n\n\t");
    for(int i = 0 ; i < tamanho ; i++){
            printf("%d", vetor[i]);
    }
    printf(".\n\n");

    int i;
    for(i = 0 ; i < tamanho ; i++){
    if(i == 0){
        printf("[ %d ", vetor[i]);
    }else{
          printf(",%d ", vetor[i]);
    }

   }
    printf("] ");
}

int*  converter_matriz_para_vetor(int** matriz,int numeroLinhas,int numeroColunas)
{
    int* vetorPrinter;
    int tamanho = numeroColunas * numeroLinhas;

    int iterator_vetor = 0;

    int iterator,iteratorSecundario;

    vetorPrinter = (int*) malloc( tamanho * sizeof(int) );

    for( iterator = 0 ; iterator < numeroLinhas ; iterator ++)
    {

        for(iteratorSecundario = 0; iteratorSecundario < numeroColunas; iteratorSecundario++ )

        {

           vetorPrinter[iterator_vetor] = matriz[iterator][iteratorSecundario];

           iterator_vetor++;
        }

    }

        return vetorPrinter;
        //printVetor(*vetorPrinter,tamanho);




}




int randomNumero (void){

return rand()%2;

}

int** criarMatriz(int numeroLinhas,int numeroColunas)
{
    int** matriz;
    int iterator;

    matriz = malloc(numeroLinhas * sizeof(int*) );

    matriz[0] = malloc( numeroColunas * numeroLinhas * sizeof(int) );

    for ( iterator = 1 ; iterator < numeroLinhas ; iterator++ )
    {

        matriz[iterator] = matriz[iterator - 1] +  numeroColunas ;

    }


    return matriz;


}

void popularMatrizManualmente(int** matriz,int numeroLinhas,int numeroColunas)
{
    int iterator,iteratorSecundario,numero;

    for( iterator = 0 ; iterator < numeroLinhas ; iterator ++)
    {

        for(iteratorSecundario = 0; iteratorSecundario < numeroColunas; iteratorSecundario++ )

        {
            printf("Digite o valor na posicao [ %d ][ %d ]",iterator,iteratorSecundario);
            scanf("%d",&numero);
            matriz[iterator][iteratorSecundario] = numero;
        }

    }
}

void popularMatrizAleatoriamente(int** matriz,int numeroLinhas,int numeroColunas)
{
    int iterator,iteratorSecundario;

    for( iterator = 0 ; iterator < numeroLinhas ; iterator ++)
    {

        for(iteratorSecundario = 0; iteratorSecundario < numeroColunas; iteratorSecundario++ )

        {
            matriz[iterator][iteratorSecundario] = randomNumero();
        }

    }
}


void printMatriz(int** matriz,int numeroLinhas,int numeroColunas){
    int iterator,iteratorSecundario;


     for( iterator = 0 ; iterator < numeroLinhas ; iterator ++)
        {
            if(iterator == 0){
                    printf("\n\n----------------------------------------------- \n");
            }


            for(iteratorSecundario = 0; iteratorSecundario < numeroColunas; iteratorSecundario++ )

            {

               printf("| %d | " ,matriz[iterator][iteratorSecundario]);
            }
            if(iterator< numeroLinhas){
            printf("\n");}

     }

      printf("-----------------------------------------------\n\n");
}





int main (void){

    int numeroLinhas, numeroColunas, iterator, iteratorSecundario;
    int* vetor_convertido_da_matriz;
    int **matriz;
    int popular;

    configurarMatriz(&numeroLinhas,&numeroColunas);
    matriz = criarMatriz(numeroLinhas,numeroColunas);

    printf("Como deseja popular a Matriz:\n");
    printf("[0]: Manualmente\n[1] Com seed aleatoria\n\n");

    scanf("%d", &popular);


    if(popular == 0){

         popularMatrizManualmente(matriz,numeroLinhas,numeroColunas);

    }else if (popular == 1){

        popularMatrizAleatoriamente(matriz,numeroLinhas,numeroColunas);
    }


    printMatriz(matriz,numeroLinhas,numeroColunas);


    vetor_convertido_da_matriz = converter_matriz_para_vetor(matriz,numeroLinhas,numeroColunas);

    printVetor(vetor_convertido_da_matriz,numeroColunas*numeroLinhas);


    free(matriz[0]);
    free(matriz);



    return 0;


}
