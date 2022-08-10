#include <stdio.h>
#include "binary_tree.c"

int main(){

    Tree t, taux;
    definir(&t);
    int op;    //op sera usado pro switch case,
    int aux;    //aux ira tomar os valores a serem inseridos
    int aux1;   //aux1 ira tomar os valores a serem inseridos, quando necessario
    int id;     //id ira tomar os ids dos elementos

    do {
        printf("\n1 - Cria raiz"
        "\n2 - Insere a esquerda"
        "\n3 - Insere a direita"
        "\n4 - Imprime a altura da arvore"
        "\n5 - Imprime o numero de nos da arvore"
        "\n6 - Imprime os nos em pre-ordem"
        "\n7 - Imprime os nos em ordem"
        "\n8 - Imprime os nos em pos-ordem"
        "\n9 - Remover elemento"
        "\n0 - Sair\n\n");
        scanf("%d", &op);

        switch(op){
            case 1: //cria raiz
                printf("\nInsira o numero do elemento raiz: ");
                scanf("%d", &aux);
                printf("\nInsira o id do elemento raiz: ");
                scanf("%d", &id);
                printf("\n");

                criaRaiz(&t, id, aux);
                break;
            case 2: //insere a esquerda
                printf("\nInsira o id do elemento pai no qual o elemento sera inserido a esquerda: ");
                scanf("%d", &aux1);
                printf("\nInsira o numero do elemento a ser inserido: ");
                scanf("%d", &aux);

                do{
                    printf("\nInsira o id do elemento a ser inserido: ");
                    scanf("%d", &id);

                    taux = busca(t, id);
                    if(!taux) break;

                    printf("\nId ja esta sendo usado por outro elemento: ");
                    mostraNo(taux);
                }while(1);

                printf("\n");

                insereEsquerda(t, id, aux, aux1);
                break;
            case 3: //insere a direita
                printf("\nInsira o numero do elemento pai no qual o elemento sera inserido a direita: ");
                scanf("%d", &aux1);
                printf("\nInsira o numero do elemento a ser inserido: ");
                scanf("%d", &aux);
                printf("\n");

                do{
                    printf("\nInsira o id do elemento a ser inserido: ");
                    scanf("%d", &id);
                    
                    taux = busca(t, id);
                    if(!taux) break;

                    printf("\nId ja esta sendo usado por outro elemento: ");
                    mostraNo(taux);
                }while(1);
                
                insereDireita(t, id, aux, aux1);
                break;
            case 4: //imprime altura
                printf("\nAltura da arvore: %d\n", altura(t));

                break;
            case 5: //imprime numero de nos
                printf("\nNumero de nos da arvore: %d\n", numeroNos(t));

                break;
            case 6: //imprime os nos em pre ordem
                printf("\nElementos da arvore em pre ordem: \n");
                preOrdem(t);
                printf("\n");
            
                break;
            case 7: //imprime os nos em ordem
                printf("\nElementos da arvore em ordem: \n");
                emOrdem(t);
                printf("\n");
            
                break;
            case 8: //imprime os nos em pos ordem
                printf("\nElementos da arvore em pos ordem: \n");
                posOrdem(t);
                printf("\n");
            
                break;

            case 9: //remove no
                do{
                    printf("\nInsira o id do elemento a ser removido: ");
                    scanf("%d", &id);

                    taux = busca(t, id);
                    if(taux) break;

                    printf("\nElemento não encontrado");
                }while(1);
                removeNo(&t, id);
                break;


        }
    }while(op!=0);

    return 0;
}