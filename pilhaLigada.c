#include <stdio.h>  // para operações de entrada e saída

#include <stdlib.h>  // para alocação dinâmica de memória

#include <stdbool.h> // para uso do tipo de dados “bool”

#include <assert.h>  // para uso da instrução “assert”

struct No {
    int info;
    struct No* proximo;
};

struct Pilha {
    struct No* topo;
    int tamanho;
};

struct Pilha* criar() {
    struct Pilha* nova_pilha = (struct Pilha*) malloc(sizeof(struct Pilha));
    if (nova_pilha != NULL) {
        nova_pilha->topo = NULL;
        nova_pilha->tamanho = 0;
    }
    return nova_pilha;
}

void empilhar(struct Pilha* p, int item) {
    assert(p != NULL);    
    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    if (novo_no != NULL) {
        novo_no->info = item;
        novo_no->proximo = p->topo;
        p->topo = novo_no;
        p->tamanho++;
    }
}

int desempilhar(struct Pilha* p) {
    assert(p != NULL);    
    assert(p->topo != NULL);
    struct No* aux = p->topo;
    int elemento = aux->info;
    p->topo = aux->proximo;
    p->tamanho--; 
    free(aux);
    return elemento;    
}

int main() {
    

    return 0;
}
//