#include <stdio.h>  
#include "utils.h"  


void menu(Node* fila){
    CLEAR_SCREEN;
    int selecao;
    printf("O que você gostaria de ver:\n 1 - Inserir cliente na fila \n 2 - Retirar cliente da fila \n 3 - Verificar estado da fila \n 4 - visualizar relatorio\n");
    scanf("%d", &selecao);
    limpar_buffer(); 
    switch (selecao)
    {
    case 1:
    {
        Cliente *cliente = criar_cliente();
        inserir_na_fila(fila, cliente);
    }
        break;
        
    case 2:
        remover_da_fila(&fila, relatorio);
        break;

    case 3:
        printar_fila(fila);
        break;

    case 4:
        printar_relatorio(relatorio);
        break;

    default:
        printf("Opção inválida.\n");
        break;
    }
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
