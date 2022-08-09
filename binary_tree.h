// Struct: 
struct tree{
    void* data;
    struct tree* ln;
    struct tree* rn;
};

typedef struct tree* Tree;

//Functions: 
int definir(Tree); //Define uma arvore vazia;
int criaRaiz(Tree, void* data); //Define o nó raiz
int vazia(Tree); //Retorna se a arvore está vazia
int insereEsquerda(Tree, void* data); //Insere data no filho da esquerda
int insereDireita(Tree, void* data); //Insere data no filho da direita
int altura(Tree); //Retorna a altura da arvore
int numeroNos(Tree); //Retorna o numero de nos
int preOrdem(Tree); //Mostra os nos em pre ordem
int emOrdem(Tree); //Mostra os nos em ordem
int posOrdem(Tree); //Mostra os nos em pos ordem
