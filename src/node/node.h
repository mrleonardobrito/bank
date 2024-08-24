#ifndef NODE_H
#define NODE_H

#include "../cliente/cliente.h"  
typedef struct node {
    Cliente *cliente;
    struct node *prox;
} Node;

Node* criar_node(Cliente* cliente);
Node* iniciar_fila();
void inserir_na_fila(Node* fila, Cliente* cliente);
void remover_da_fila(Node** fila, Cliente* relatorio);
void printar_fila(Node* fila);

#endif
