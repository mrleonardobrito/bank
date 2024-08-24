#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../report/report.h"
#include "node.h"

Node* criar_node(Cliente* cliente) {
    Node* node = malloc(sizeof(Node));
    node->cliente = cliente;
    node->prox = NULL;
    return node;
}

Node* iniciar_fila() {
    Node* fila = malloc(sizeof(Node));
    fila->prox = NULL;
    return fila;
}

void inserir_na_fila(Node* fila, Cliente* cliente) {
    Node *novo = criar_node(cliente);

    if (fila->prox == NULL) {
        fila->prox = novo;
        return;
    }

    Node *ultimo = fila;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }
    ultimo->prox = novo;
}

void remover_da_fila(Node** fila, Cliente* relatorio) {
    if (*fila == NULL || (*fila)->prox == NULL) {
        printf("A fila está vazia\n");
        return;
    }

    Node* aux = (*fila)->prox;
    (*fila)->prox = aux->prox;

    printf("Removendo o %s da fila\n", aux->cliente->nome);

    preencher_relatorio(aux->cliente, relatorio);

    free(aux->cliente);
    free(aux);
}

void printar_fila(Node* fila) {
    Node* aux = fila->prox;
    while (aux != NULL) {
        printf("%s | %d anos | %s\n\n", aux->cliente->nome, aux->cliente->idade, aux->cliente->transacao);
        aux = aux->prox;
    }
    int continuar = 9999;
    printf("Digite qualquer numero pra continuar.\n\n ");
    scanf("%d", &continuar);
}
