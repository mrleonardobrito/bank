#include <stdio.h>
#include <string.h>
#include "cliente/cliente.h"
#include "report/report.h"
#include "node/node.h"
#include "utils/utils.h"
#include <stdlib.h>

int main() {
    Node* fila = iniciar_fila();
    int continuar = 1;

    while (continuar) {
        CLEAR_SCREEN;
        menu(fila);
        printf("Deseja realizar outra ação? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
        limpar_buffer();
    }

    printf("FINALIZANDO...\n");

    Node* temp;
    while (fila != NULL) {
        temp = fila;
        fila = fila->prox;
        free(temp->cliente);
        free(temp);
    }

    return 0;
}