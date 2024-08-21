#ifndef CLIENTE_H
#define CLIENTE_H
#include "../utils/utils.h"

typedef struct cliente {
    char nome[60];
    int idade;
    int cod;
    char transacao[15];
    int tempo_atendimento;
    int tempo_espera;
} Cliente;

Cliente* criar_cliente();
void selecionar_transacao(Cliente *cliente);

#endif
