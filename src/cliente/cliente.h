#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
    int senha;
    int tempo_atendimento;
} Cliente;

typedef struct node {
    Cliente *cliente;
    struct node *prox;
} Node;

Node* criar_cliente(int senha);
int selecionar_transacao(Cliente *cliente);
void atender_cliente(Node** fila, Cliente* relatorio);

#include "../utils/utils.h"

#endif
