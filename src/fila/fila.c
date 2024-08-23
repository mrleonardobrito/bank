#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../report/report.h"
#include "fila.h"

Node* iniciar_fila() {
    Node* fila = malloc(sizeof(Node));
    fila->prox = NULL;
    return fila;
}

void receber_cliente(Node* fila, Node* cliente) {
    if (fila->prox == NULL) {
        fila->prox = cliente;
        return;
    }

    while (fila->prox != NULL) {
        fila = fila->prox;
    }
    fila->prox = cliente;
}

void exibir_fila(Node* fila) {
    Node* aux = fila->prox;
    while (aux != NULL) {
        printf("cliente %d\n", aux->cliente->senha);
        aux = aux->prox;
    }
    int continuar = 9999;
    printf("Digite qualquer numero pra continuar.\n\n ");
    scanf("%d", &continuar);
}
