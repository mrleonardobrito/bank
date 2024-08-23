#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Node* criar_cliente(int senha) {
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    if (cliente == NULL) {
        fprintf(stderr, "Erro ao alocar memória para cliente.\n");
        exit(EXIT_FAILURE);
    }
    cliente->senha = senha;

    Node* node = malloc(sizeof(Node));
    node->cliente = cliente;
    node->prox = NULL;
    return node;
}

void atender_cliente(Node** fila, Cliente* relatorio) {
    if (*fila == NULL || (*fila)->prox == NULL) {
        printf("A fila está vazia\n");
        return;
    }

    Node* aux = (*fila)->prox;
    (*fila)->prox = aux->prox;

    printf("Atendendo o cliente com senha %d\n", aux->cliente->senha);
    int opcao;
    do{
        printf("Quais transações deseja realizar?\n");
        printf("1 - Saque\n");
        printf("2 - Depósito\n");
        printf("3 - Pagamento\n");
        printf("4 - Transferência\n");

        opcao = selecionar_transacao(aux->cliente);
    } while (opcao != -1);

    preencher_relatorio(aux->cliente, relatorio);

    free(aux->cliente);
    free(aux);
}

int selecionar_transacao(Cliente *cliente) {
    int opcao;
    scanf("%d", &opcao);
   
    switch (opcao) {
        case 1:
            // Saque
            cliente->tempo_atendimento += 50;
            return 1;
        case 2:
            // Depósito
            cliente->tempo_atendimento += 70;
            return 2;
        case 3:
            // Pagamento
            cliente->tempo_atendimento += 100;
            return 3;
        case 4:
            // Transferência
            cliente->tempo_atendimento += 60;
            return 4;
        default:       
            return -1; 
    }
}
