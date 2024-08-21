#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
# define CLEAR_SCREEN system("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

#define MAX_RELATORIO 100

typedef struct cliente {
    char nome[60];
    int idade;
    int cod;
    char transacao[15];
    int tempo_atendimento;
    int tempo_espera;
} Cliente; 

typedef struct node {
    Cliente *cliente;
    struct node *prox;
} Node;

Cliente relatorio[MAX_RELATORIO];
int contador = 0;

void limpar_buffer();
Cliente* criar_cliente();
void selecionar_transacao(Cliente *cliente);
Node* criar_node(Cliente* cliente);
Node* iniciar_fila();
void inserir_na_fila(Node* fila, Cliente* cliente);
void remover_da_fila(Node** fila, Cliente* relatorio);
void printar_fila(Node* fila);
void preencher_relatorio(Cliente* cliente, Cliente* relatorio);
void printar_relatorio(Cliente* relatorio);

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

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

void fazer_outra_transacao(Cliente *cliente) {
    int prosseguir = 1;

    while (prosseguir) {
        CLEAR_SCREEN;
        printf("Deseja que o cliente faça outra ação? (1 - Sim, 0 - Não): ");
        scanf("%d", &prosseguir);
        limpar_buffer();

        if (prosseguir) {
            printf("Digite o codigo de transacao\n 1 - Saque\n 2 - Deposito\n 3 - Pagamento\n 4 - Transferencia\n");
            scanf("%d", &cliente->cod);
            limpar_buffer();

            selecionar_transacao(cliente);
        }
    }
}

Cliente* criar_cliente() {
    CLEAR_SCREEN;
    Cliente *cliente = malloc(sizeof(Cliente));
    
    if (cliente == NULL) {
        fprintf(stderr, "Erro ao alocar memória para cliente.\n");
        exit(1);
    }

    printf("Digite o nome do cliente: ");
    fgets(cliente->nome, sizeof(cliente->nome), stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0'; 

    printf("Digite a idade do cliente: ");
    scanf("%d", &cliente->idade);
    limpar_buffer();

    strcpy(cliente->transacao, "");
    cliente->tempo_atendimento = 0;

    do {
        printf("Por ultimo, digite o codigo de transacao\n 1 - Saque\n 2 - Deposito\n 3 - Pagamento\n 4 - Transferencia\n");
        scanf("%d", &cliente->cod);
        limpar_buffer();
        selecionar_transacao(cliente);
    } while (cliente->tempo_atendimento == 0);

    fazer_outra_transacao(cliente);

    return cliente;
}

void selecionar_transacao(Cliente *cliente) {
    switch (cliente->cod) {
        case 1:
            strcat(cliente->transacao, " Saque ");
            cliente->tempo_atendimento += 50;
            break;
        case 2:
            strcat(cliente->transacao, " Deposito ");
            cliente->tempo_atendimento += 70;
            break;
        case 3:
            strcat(cliente->transacao, " Pagamento  ");
            cliente->tempo_atendimento += 100;
            break;
        case 4:
            strcat(cliente->transacao, " Transferencia  ");
            cliente->tempo_atendimento += 60;
            break;
        default:
            printf("O cliente deve possuir um codigo de transacao valido! Por favor, preencha novamente\n");
            free(cliente);
            cliente = criar_cliente();
            break;
    }
}

Node* criar_node(Cliente* cliente) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Erro ao alocar memória para nó.\n");
        exit(1);
    }
    node->cliente = cliente;
    node->prox = NULL;
    return node;
}

Node* iniciar_fila() {
    Node* fila = malloc(sizeof(Node));
    if (fila == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    fila->prox = NULL;
    return fila;
}

void inserir_na_fila(Node* fila, Cliente* cliente) {
    Node *novo = criar_node(cliente);

    
    if (fila->prox == NULL) {
        fila->prox = novo;
        return;
    }

    Node *ultimo = fila;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }
    ultimo->prox = novo;
}

void remover_da_fila(Node** fila, Cliente* relatorio) {
    if (*fila == NULL || (*fila)->prox == NULL) {
        printf("A fila está vazia\n");
        return;
    }

    Node* aux = (*fila)->prox;
    (*fila)->prox = aux->prox;

    printf("Removendo o %s da fila\n", aux->cliente->nome);

    preencher_relatorio(aux->cliente, relatorio);

    free(aux->cliente);
    free(aux);
}

void preencher_relatorio(Cliente* cliente, Cliente* relatorio) {
    if (contador < MAX_RELATORIO) {
        strcpy(relatorio[contador].nome, cliente->nome);
        relatorio[contador].idade = cliente->idade;
        relatorio[contador].tempo_atendimento = cliente->tempo_atendimento;
        strcpy(relatorio[contador].transacao, cliente->transacao);
        for (int i = 0; i < contador; i++){
            relatorio[contador-i].tempo_espera += cliente->tempo_atendimento;
        }
        contador++;
    } else {
        printf("O relatório está cheio.\n");
    }
}

void printar_relatorio(Cliente* relatorio) {
    CLEAR_SCREEN;
    int tempo_passado = 0;
    for (int i = 0; i < contador; i++) {
        printf("Cliente %d: %s | %d anos | %s | teve que esperar: %d segundos\n\n", i + 1, relatorio[i].nome, relatorio[i].idade, relatorio[i].transacao, relatorio[i].tempo_espera
        );
        tempo_passado += relatorio[i].tempo_atendimento;
    }
    printf("Tempo passado até o momento: %d segundos\n", tempo_passado);
}

void printar_fila(Node* fila) {
    Node* aux = fila->prox;
    CLEAR_SCREEN;

    if(aux == NULL){
        printf("Não tem nenhum cliente na fila\n\n");
        return;
    }

    while (aux != NULL) {
        printf("%s | %d anos | %s\n\n", aux->cliente->nome, aux->cliente->idade, aux->cliente->transacao);
        aux = aux->prox;
    }
    int continuar = 9999;
    printf("Digite qualquer numero pra continuar.\n\n ");
    scanf("%d", &continuar);
}

int main() {
    Node* fila = iniciar_fila();
    int continuar = 1;

    while (continuar) {
        CLEAR_SCREEN;
        menu(fila);
        printf("Deseja realizar outra ação? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
        limpar_buffer();
    }

    printf("FINALIZANDO...\n");

    Node* temp;
    while (fila != NULL) {
        temp = fila;
        fila = fila->prox;
        free(temp->cliente);
        free(temp);
    }

    return 0;
}
