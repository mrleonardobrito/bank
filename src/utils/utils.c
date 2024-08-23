#include <stdio.h>  
#include "utils.h"  

int menu(Node* fila){
    CLEAR_SCREEN;
    int selecao;
    printf("O que você gostaria de ver:\n 1 - Inserir cliente na fila \n 2 - Atender cliente \n 3 - Verificar estado da fila \n 4 - Visualizar relatorio e terminar o dia\n");
    scanf("%d", &selecao);
    limpar_buffer(); 
    switch (selecao)
    {
    case 1:
        receber_cliente(fila);
        return 1;
        
    case 2:
        atender_cliente(&fila, relatorio);
        return 2;

    case 3:
        exibir_fila(fila);
        return 3;

    case 4:
        printar_relatorio(relatorio);
        return 4;

    default:
        printf("Opção inválida.\n");
        menu(fila);
    }
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
