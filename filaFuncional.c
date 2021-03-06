#include <stdio.h>    // para operações de entrada e saída
#include <stdlib.h>   // para alocação dinâmica de memória
#include <stdbool.h>  // para uso do tipo de dados “bool”
#include <assert.h>   // para uso da instrução “assert”

struct No {
    int info;
    struct No* proximo;
};

struct Fila {
    struct No* inicio;
    struct No* fim;
    int tamanho;
};


struct Fila* criar() {
    struct Fila* nova_fila = (struct Fila*) malloc(sizeof(struct Fila));
    if (nova_fila != NULL) {
        nova_fila->inicio = NULL;
        nova_fila->fim = NULL;
        nova_fila->tamanho = 0;
    }
    return nova_fila;
}

void enfileirar(struct Fila* f, int item) {
    assert(f != NULL);
    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    if (novo_no != NULL) {
        novo_no->info = item;
        novo_no->proximo = NULL;

    if (f->fim != NULL) {
        f->fim->proximo = novo_no;
        } else {
            f->inicio = novo_no;
        }
        f->fim = novo_no;
        f->tamanho++;
    }
}

int desenfileirar(struct Fila* f) {
    assert(f != NULL);
    assert(f->inicio != NULL);
    struct No* aux = f->inicio;
    int elemento = aux->info;
    f->inicio = aux->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    f->tamanho--;
    free(aux);
    return elemento;
}

bool vazia(struct Fila* f) {
    assert(f != NULL);
    return (f->inicio == NULL);
}

int tamanho(struct Fila* f) {
    assert(f != NULL);
    return f->tamanho; 
}

int inicio(struct Fila* f) {
    assert(f != NULL);
    assert(f->inicio != NULL);
    return f->inicio->info;
}

void liberar(struct Fila* f) {
    assert(f != NULL);
    while(f->inicio != NULL) {
        desenfileirar(f);
    }
    free(f);
}

int main() {
    struct Fila* minha_fila = criar();
    enfileirar(minha_fila, 1);
    enfileirar(minha_fila, 2);
    enfileirar(minha_fila, 3);
    printf("Tamanho: %d ", tamanho(minha_fila));

    printf("\nMinha fila: [%d ", desenfileirar(minha_fila));
    printf("%d ", desenfileirar(minha_fila));
    printf("%d]", desenfileirar(minha_fila));

    printf("\nEstá vazia (1 - Sim, 0 - Não)? %d ", vazia(minha_fila));

    liberar(minha_fila);

    return 0;

}
//=====================================================================================//

// (False) Só é possível retirar um elemento da lista do seu final;

// (True) Só é possível retirar um elemento da pilha do seu final;

// (True) Para inserir e retirar um elemento da lista deve-se atualizar o valor do ponteiro;

// (True) A struct é uma varável que armazena valores de tipos diferentes.

// (False) Uma pilha é uma estrutura de dados do tipo LIFO (, onde o primeiro elemento
//    elemento a ser inserido, será o primeiro a ser retirado.

// (True) As filas são estruturas de dados do tipo FIFO (first-infirst-out), adiciona-se
//    itens no fim e remove-se do início.

// (False) As principais funções da fila são push e pop;

// Lista: podemos remover um item de qualquer lugar da lista
// Pilha: podemos remover apenas do ultimo local alocado (topo da pilha)
// Fila: podemos remover apenas do inicio da fila, adicionamos no final e tiramos no inicio da fila.