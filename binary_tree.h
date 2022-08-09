// Struct: 
struct tree{
    int num;
    struct tree* ln;
    struct tree* rn;
};

typedef struct tree* Tree;

//Functions: 
int definir(Tree*); //Define uma arvore vazia;
int criaRaiz(Tree*, int num); //Define o nó raiz
int vazia(Tree); //Retorna se a arvore está vazia
Tree busca(Tree, int num); //Busca o no que armazena num
int insereEsquerda(Tree, int num, int numPai); //Insere data no filho da esquerda
int insereDireita(Tree, int num, int numPai); //Insere data no filho da direita
int altura(Tree); //Retorna a altura da arvore
int numeroNos(Tree); //Retorna o numero de nos
void preOrdem(Tree); //Mostra os nos em pre ordem
void emOrdem(Tree); //Mostra os nos em ordem
void posOrdem(Tree); //Mostra os nos em pos ordem
