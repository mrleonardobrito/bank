#include <stdio.h>
#include <string.h>
#include "src/cliente/cliente.h"
#include "src/report/report.h"
#include "src/fila/fila.h"
#include "src/utils/utils.h"
#include <stdlib.h>

int main() {
    Node* fila = iniciar_fila();
  
    int opcao;
    do {
        CLEAR_SCREEN;
        opcao = menu(fila);
        limpar_buffer();
    } while(opcao != 4);

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