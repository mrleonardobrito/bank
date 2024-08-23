#include <stdio.h>
#include <string.h>
#include "report.h"

Cliente relatorio[MAX_RELATORIO];
int contador = 0;

void preencher_relatorio(Cliente* cliente, Cliente* relatorio) {
    if (contador < MAX_RELATORIO) {
        contador++;
    } else {
        printf("O relatório está cheio.\n");
    }
}

void exibir_relatorio(Cliente* relatorio) {
    for (int i = 0; i < contador; i++) {
        printf("Cliente %d:%d", relatorio[i].senha, relatorio[i].tempo_atendimento);
    }
}
