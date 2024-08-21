#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* criar_cliente() {
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    if (cliente == NULL) {
        fprintf(stderr, "Erro ao alocar memória para cliente.\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite o nome do cliente: ");
    fgets(cliente->nome, sizeof(cliente->nome), stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0'; 

    printf("Digite a idade do cliente: ");
    scanf("%d", &cliente->idade);
    limpar_buffer(); 

    printf("Digite o código de transação (1 - Saque, 2 - Deposito, 3 - Pagamento, 4 - Transferencia): ");
    scanf("%d", &cliente->cod);
    limpar_buffer();

    selecionar_transacao(cliente);

    return cliente;
}

void selecionar_transacao(Cliente *cliente) {
    switch (cliente->cod) {
        case 1:
            strcpy(cliente->transacao, "Saque");
            cliente->tempo_atendimento = 50;
            break;
        case 2:
            strcpy(cliente->transacao, "Deposito");
            cliente->tempo_atendimento = 70;
            break;
        case 3:
            strcpy(cliente->transacao, "Pagamento");
            cliente->tempo_atendimento = 100;
            break;
        case 4:
            strcpy(cliente->transacao, "Transferencia");
            cliente->tempo_atendimento = 60;
            break;
        default:
            printf("Código de transação inválido.\n");
            cliente->transacao[0] = '\0'; 
            cliente->tempo_atendimento = 0;
            break;
    }
}
