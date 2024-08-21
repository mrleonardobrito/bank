#ifndef UTILS_H
#define UTILS_H

#ifdef _WIN32
# define CLEAR_SCREEN system("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

#include "../cliente/cliente.h" 
#include "../node/node.h"  
#include "../report/report.h" 

void limpar_buffer();
void menu(Node* fila);
#endif
