#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


//@author



void menudoPrograma(){
    printf("=======MENU========\n");
    printf("(1) - Criar um registro de COVID19\n");
    printf("(2) - Mostrar a Estatistica COVID19\n");
    printf("(3) - \n");



}




typedef struct covid{
        char nomePais[MAX];
        int casos;
        int recuperados;
        int obitos;
        int casosAtivos;
        struct covid *proximo;
    }COVID;


    //Allocation memory

    COVID *alocaCOVID (){
    //Alocar COVID
    COVID *covid = (COVID *)malloc(sizeof (COVID));
    return covid;
    }

//procurar se a lista esta vazia

    int listaVazia (COVID * lista)
      {
        if (lista->proximo == NULL)
        return 1;

        else
        return 0;
      }


    void iniciarLista (COVID * lista){
        lista->proximo = NULL;
      }


    void inserir (COVID * lista, int numerocasos, int numerorecuperados,int numeroobitos, int numerocasosAtivos){
        //funC'ao para inserir dados na lista
        //InserC'ao de dados no inicio da lista

        COVID *novo = alocaCOVID ();

        char nomePais[MAX];

        printf ("PAIS:");fflush (stdin);
        fgets (novo->nomePais, MAX, stdin);


        novo->nomePais[strlen (novo->nomePais) - 1] = '\0';
        novo->casos = numerocasos;
        novo->obitos = numeroobitos;
        novo->casosAtivos = numerocasosAtivos;


        if (listaVazia (lista)){

        lista->proximo = novo;
        novo->proximo = NULL;
        }
        else{
        novo->proximo = lista->proximo;
        lista->proximo = novo;
          }

      }


//funC'ao para exibir a lista;

    void imprimirLista (COVID * lista){
        COVID *head = lista->proximo;
        if (head == NULL){
            printf ("NULL\n");
      }
        else{

            while (head != NULL){

            printf ("NOME do Pais: %s\n", head->nomePais);
            printf ("Casos: %d \n", head->casos);
            printf ("Recuperados: %d \n", head->recuperados);
            printf ("Obitos: %d \n", head->obitos);
            printf("Casos Ativos: %d\n",head->casosAtivos);
            head = head->proximo;
	  }

}
 }



 //Esta funçao permite procurar um elemento na lista
 void procurarElemento(COVID* lista,char *nomePaisAprocurar){
    if(listaVazia(lista)){
        printf("\nLista Vazia\n");
        return;
    }

    COVID* target=NULL;
    int pos;
    COVID* auxiliar = lista->proximo;

    for(pos = 1 ,auxiliar!=NULL ; auxiliar = auxiliar->proximo ; pos++ ){
        if(strcmp(auxiliar->nomePais, nomePaisAprocurar) == 0){
            target = auxiliar;
            break;}
    }
    if(target){
        printf("\n Pais: %s", target->nomePais);
        printf("Numero De Casos: %d\n",target->casos);
        printf("Numero de Recuperados: %d\n",target->recuperados);
        printf("Numero de Obitos: %d \n",target->obitos);
        printf("Numero de Casos Recuperados:%d",target->recuperados);
    }else{
        printf("\n%s não encontrado na lista",&nomePaisAprocurar);
    }

 }

//Funcao para retornar o total de casos ativos
void totaldeCasos(COVID* lista){
    int pos;
    int contadorTotalCasos;
    int soma;
    COVID* auxiliar = lista->proximo;

    if(listaVazia(lista)){
        printf("\nLista Vazia\n");

    }
    else{

        for(auxiliar!=NULL; auxiliar=auxiliar->proximo;pos++){
            contadorTotalCasos+=auxiliar->casos;
            soma = contadorTotalCasos;
            }
            printf("Total de numero de Casos = %d",soma);
        }
}

void numeroElementosLista(COVID* lista){
    int numeroElementosLista;
    int i;
    COVID* auxiliar = lista->proximo;

    if(listaVazia(lista)){
        printf("\nLista Vazia\n");
}

    else{
        for(i=1;auxiliar=auxiliar->proximo;i++){

        }
        printf("A lista possui %d",i);
    }




}







int main (){
    COVID *lista = alocaCOVID();
    iniciarLista(lista);
    int option,numeroCasos,numeroRecuperados,numeroObitos,numeroCasosAtivos;
    char nomePais[MAX];
    /*menu()//Apresentando o mmenu para o utilizador
    printf("Escolhe a sua Operacao"):
      */

    menudoPrograma();

    printf("Introduzir o numero de Casos:");
    scanf("%d",&numeroCasos);
    printf("Introduzir o numero de Casos Recuperados:");
    scanf("%d",&numeroRecuperados);
    printf("Introduzir o numero de Obitos:");
    scanf("%d",&numeroObitos);
    numeroCasosAtivos = numeroCasos - numeroRecuperados;
    inserir(lista,numeroCasos,numeroRecuperados,numeroObitos,numeroCasosAtivos);

    //imprimirLista(lista);

    //totaldeCasos(lista);
    //numeroElementosLista(lista);
    numeroElementosLista(lista);







    //Apresentar Lista






    //Tester





   /* while(){
        system("CLS");
        switch(){

            case 1 :
                printf("Introduzir o numero de Casos:");
                scanf("%d",&numeroCasos);
                printf("Introduzir o numero de Casos Recuperados:");
                scanf("%d",&numeroRecuperados);
                printf("Introduzir o numero de Obitos:");
                scanf("%d",&numeroObitos);
                numeroCasosAtivos = numeroCasos - numeroRecuperados;
                inserir(lista,numeroCasos,numeroRecuperados,numeroObitos,numeroCasosAtivos);
                break;
                }

            case 2:

    }*/

    return 0;
}
