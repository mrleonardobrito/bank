#ifndef UTILS_H
#define UTILS_H

#include "../cliente/cliente.h" 
#include "../fila/fila.h"  
#include "../report/report.h" 

#ifdef _WIN32
# define CLEAR_SCREEN system("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

void limpar_buffer();
int menu(Node* fila);
#endif
