#ifndef REPORT_H
#define REPORT_H

#define MAX_RELATORIO 100      

#include "../cliente/cliente.h"  
#include "../fila/fila.h"  
#include "../utils/utils.h"  

extern Cliente relatorio[MAX_RELATORIO];
extern int contador;

void preencher_relatorio(Cliente* cliente, Cliente* relatorio);
void exibir_relatorio(Cliente* relatorio);

#endif 
