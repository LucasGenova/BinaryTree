#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

#define MAX(x, y) ((x>=y)?x:y)

int definir(Tree *t) {
    (*t) = NULL;
    return  0;
}

int criaRaiz(Tree* t, int id, int num) {
    if(vazia((*t))) {
        (*t) = (Tree) malloc(sizeof(struct tree));
    }

    (*t)->id = id; //Associamos um id unico ao elemento 
    (*t)->num = num; //Associamos o numero ao elemento raiz da árvore
    (*t)->ln = NULL; //Colocamos seus filhos como NULL
    (*t)->rn = NULL;
    return 1;
}

int vazia(Tree t){
    return(!t); //Retorna 0 se estiver vazia e 1 se estiver cheia
}

Tree busca(Tree t, int id){
    Tree aux;
    if(!t) return NULL;

    if(t->id == id) {
        return t;
    }
    if(t->ln){
        if(t->ln->id == id) return t->ln;
        aux = busca(t->ln, id);
        if(aux) return aux;
    }
    if(t->rn){
        if(t->rn->id == id) return t->rn;
        aux = busca(t->rn, id);
        if(aux) return aux;
    }
    return NULL;
}

int insereEsquerda(Tree t, int id, int num, int idPai){
    if(vazia(t)) return 0;

    Tree aux, aux2;

    Tree novo;
    definir(&novo); //Cria um novo nó
    
    criaRaiz(&novo, id, num); //Associa os valores ao novo nó

    aux = busca(t, idPai); //Associa ao aux o nó do pai

    if(!aux) {
        printf("\nO pai nao foi encontrado\n");
        return 0;
    }

    if(aux->ln) { //Se o nó já tiver um filho à esquerda
        aux2 = aux->ln; //Salva o filho da esquerda no auxiliar
        aux->ln = novo; //Associa o novo nó como filho da esquerda
        novo->ln = aux2; //Associa o filho da esquerda como o antigo filho

        return 1;
    }
    
    aux->ln = novo; //Insere o novo nó no filho da esquerda
    return 1;
}

int insereDireita(Tree t, int id, int num, int idPai) {
    if(vazia(t)) return 0;

    Tree aux, aux2;

    Tree novo;
    definir(&novo); //Cria um novo nó
    
    criaRaiz(&novo, id, num); //Associa os valores ao novo nó

    aux = busca(t, idPai); //Associa ao aux o nó do pai

    if(!aux) {
        printf("\nO pai nao foi encontrado\n");
        return 0;
    }

    if(aux->rn) { //Se o nó já tiver um filho à direita
        aux2 = aux->rn; //Salva o filho da direita no auxiliar
        aux->rn = novo; //Associa o novo nó como filho da direita
        novo->rn = aux2; //Associa o filho da direita como o antigo filho

        return 1;
    }
    
    aux->rn = novo; //Insere o novo nó no filho da direita
    return 1;
}

Tree removeNo(Tree* t, int id){
    Tree aux, aux1;
    
    if(!(*t)) return NULL;
    if((*t)->id == id){
        if(!(*t)->ln && !(*t)->rn){
            aux = (*t);
            (*t) = NULL;
            return aux;
        }
        if((*t)->ln && !(*t)->rn){
            aux = (*t);
            (*t) = (*t)->ln;
            return aux;
        }

        if(!(*t)->ln && (*t)->rn){
            aux = (*t);
            (*t) = (*t)->rn;
            return aux;
        }

        aux = (*t)->rn;

        while(aux->ln)
            aux = aux->ln;

        aux1 = (*t);
        (*t) = removeNo(&aux, aux->id);
        return aux1;       
    }

    if((*t)->ln){
        aux = removeNo(&(*t)->ln, id);
        if(aux) return aux;
    }
    if((*t)->rn){
        aux = removeNo(&(*t)->rn, id);
        if(aux) return aux;
    }
    return NULL;
}
    

int altura(Tree t){
    if(vazia(t)) return 0;

    return(1 + MAX(altura(t->ln), altura(t->rn))); //Função recursiva em que, observa a altura dos filhos da direita e da esquerda e pega o seu valor máximo
}

int numeroNos(Tree t) {
    int nnl=0, nnr=0;
    if(!t)
        return 0;
        
    if(t->ln)
        nnl = numeroNos(t->ln);
    if(t->rn)
        nnr = numeroNos(t->rn);
    
    return 1 + nnl + nnr;
}

void mostraNo(Tree t){
    printf("(id:%d - num:%d)", t->id, t->num); //Printa no console o numero do nó
}

void preOrdem(Tree t){
    if(!t) return; //Se t for NULL, não há o que printar
    
    mostraNo(t); //Se não tiver filho nem à direita, nem à esquerda, chama a função que printará o numero associado ao nó no console
    if(t->ln) preOrdem(t->ln); //Se tiver filho à esquerda, chama a função novamente, mandando o filho da esquerda 
    if(t->rn) preOrdem(t->rn); //Se tiver filho à direita, chama a função novamente, mandando o filho da direita 
}
void emOrdem(Tree t){
    if(!t) return;

    if(t->ln) emOrdem(t->ln); //Se tiver filho à esquerda chama a função novamente mandando o filho da esquerda
    mostraNo(t); //Se não tiver filho à esquerda, chama a função que printará o numero associado ao nó no console
    if(t->rn) emOrdem(t->rn); //Se tiver filho à direita chama a função novamente mandando o filho da direita
    
}
void posOrdem(Tree t){
    if(!t) return;
    
    if(t->ln) posOrdem(t->ln); //Se tiver filho à esquerda chama a função novamente mandando o filho da esquerda
    if(t->rn) posOrdem(t->rn); //Se tiver filho à direita chama a função novamente mandando o filho da direita
    mostraNo(t); //Chama a função que printará o número associado ao nó no console
}
