#ifndef FILA_H
#define FILA_H

#include "../cliente/cliente.h"

Node* iniciar_fila();
void receber_cliente(Node* fila, Node* cliente);
void exibir_fila(Node* fila);

#endif
