#include <stdio.h>
#include <string.h>
#include "report.h"

Cliente relatorio[MAX_RELATORIO];
int contador = 0;

void preencher_relatorio(Cliente* cliente, Cliente* relatorio) {
    if (contador < MAX_RELATORIO) {
        strcpy(relatorio[contador].nome, cliente->nome);
        relatorio[contador].idade = cliente->idade;
        relatorio[contador].tempo_atendimento = cliente->tempo_atendimento;
        strcpy(relatorio[contador].transacao, cliente->transacao);
        relatorio[contador].tempo_espera = cliente->tempo_espera;
        contador++;
    } else {
        printf("O relatório está cheio.\n");
    }
}

void printar_relatorio(Cliente* relatorio) {
    for (int i = 0; i < contador; i++) {
        printf("Cliente %d: %s | %d anos | %s\n\n", i + 1, relatorio[i].nome, relatorio[i].idade, relatorio[i].transacao);
    }
}
