#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    int altura;
    struct NO *esquerdo;
    struct NO *direito;
} typedef ArvAVL;

ArvAVL **raiz;

struct NO * busca (struct NO *arvore , ArvAVL **pai , int chave ){
    struct No *aux = arvore;
    if (!arvore) {
        return NULL; // chave nao encontrada
    }

    if (arvore->info == chave) {
        return arvore; // chave encontrada
    }
    
    (*pai) = arvore;

    if(arvore->info > chave ) { // a chave, se existir, esta na subarvore esquerda de T.
        return busca (arvore->esquerdo, pai, chave);
    } 
    else {
        return busca (arvore->direito, pai, chave);
    }
}

struct NO *criaNo (int chave){
    struct NO *novo = (struct NO*) calloc (1, sizeof(struct NO));
    if (!novo) {
        printf (" ERRO: nao foi possivel alocar novo no.\n");
        return NULL;
    }

    novo->info = chave;
    return novo;
}

// Calcula a altura de um nó
int altura_no (struct NO* no) {
    if(no == NULL){
        return -1;
    }
    else
    {
        return no->altura;
    }
}

// Calcula o fator de balanceamento de um nó
int fatorBalanceamento (struct NO* no){
    return (altura_no(no->esquerdo) - altura_no(no->direito));
}

// CALCULA o maior valor
int maior(int x, int y) {
    if (x>y)
        return x;
    else
        return y;
}

void rotacaoLL (ArvAVL **raiz) {
    struct NO *no;
    no = (*raiz)->esquerdo;
    (*raiz)->esquerdo = no->direito;
    no->direito = (*raiz);
    (*raiz)->altura = maior(altura_no((*raiz)->esquerdo), altura_no((*raiz)->direito)) + 1;
    no->altura = maior(altura_no(no->esquerdo), altura_no((*raiz)->altura)) + 1;    
    (*raiz) = no;
}

void rotacaoRR (ArvAVL **raiz) {
    struct NO *no;
    no = (*raiz)->direito;
    no->esquerdo = (*raiz);
    (*raiz)->altura = maior(altura_no((*raiz)->esquerdo), altura_no((*raiz)->direito)) + 1;
    no->altura = maior(altura_no(no->direito), altura_no((*raiz)->altura)) + 1;    
    (*raiz) = no;
}

void rotacaoLR(ArvAVL **raiz) {
    rotacaoRR(&(*raiz)->esquerdo);
    rotacaoLL(raiz);
} 

void rotacaoRL (ArvAVL **raiz) {
    rotacaoLL(&(*raiz)->direito);
    rotacaoRR(raiz);
}

int insere (ArvAVL **raiz, int valor) {
    int res;
    if (*raiz == NULL)
    {
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if (novo == NULL)
        {
            return 0;
        }

        novo->info = valor;
        novo->altura = 0;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if (valor < atual->info)
    {
        res = insere( &(atual->esquerdo), valor);
        if (res == 1)
        {
            if (fatorBalanceamento(atual) >= 2)
            {
                if (valor < (*raiz)->esquerdo->info)
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }
            }
        }
    }
    else
    {
        if (valor > atual->info)
        {
            res = insere( &(atual->direito), valor);
            if (res == 1)
            {
                if (fatorBalanceamento(atual) >= 2)
                {
                    if ((*raiz)->direito->info < valor)
                    {
                        rotacaoRR(raiz);
                    }
                    else
                    {
                        rotacaoRL(raiz);
                    }
                }
            }
        }
        else
        {
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_no(atual->direito), altura_no(atual->esquerdo)) + 1;

    return res;
}

int remove(ArvAVL **raiz, int valor){
    int res;
    if (*raiz == NULL)
    {
        printf("Valor não existe!!\n");
        return 0;
    }

    if (valor < (*raiz)->info)
    {
        res = remove( &(*raiz)->esquerdo, valor);
        if (res == 1)
        {
            if (fatorBalanceamento(*raiz) >= 2)
            {
                if (altura_no((*raiz)->direito->esquerdo) <= altura_no((*raiz)->direito->direito))
                {
                    rotacaoRR(raiz);
                }
                else
                {
                    rotacaoRL(raiz);
                }
            }
        }
    }
    else
    {
        if (valor > atual->info)
        {
            res = insere( &(atual->direito), valor);
            if (res == 1)
            {
                if (fatorBalanceamento(atual) >= 2)
                {
                    if ((*raiz)->direito->info < valor)
                    {
                        rotacaoRR(raiz);
                    }
                    else
                    {
                        rotacaoRL(raiz);
                    }
                }
            }
        }
        else
        {
            printf("Valor duplicado!!\n");
            return 0;
        }
    }
    

    return res;
}

struct NO* procuraMenor(struct NO* atual) {

}

int main() {
    int valor = 10;
    int x = insere(raiz, valor);
    int y = remove(raiz, valor);
}