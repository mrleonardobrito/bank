#ifndef REPORT_H
#define REPORT_H

#include "../cliente/cliente.h"  
#include "../node/node.h"  
#include "../utils/utils.h"  

#define MAX_RELATORIO 100      

extern Cliente relatorio[MAX_RELATORIO];
extern int contador;

void preencher_relatorio(Cliente* cliente, Cliente* relatorio);
void printar_relatorio(Cliente* relatorio);

#endif 
