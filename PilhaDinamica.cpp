#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura para um n� da pilha
struct no {
    int valor;
    struct no *anterior;
};

typedef struct no No; // Defini��o de um alias para "struct no" como "No"

No *topo; // Ponteiro global para o topo da pilha

// Fun��o para inicializar a pilha como vazia
void pilhaVazia() {
    topo = NULL; // Inicializa o topo como NULL, indicando pilha vazia
}

// Fun��o para empilhar um elemento na pilha
void empilha(int pvalor) {
    No *novo = (No*)malloc(sizeof(No)); // Aloca mem�ria para um novo n�
    novo->valor = pvalor; // Define o valor do novo n�
    novo->anterior = topo; // O n� anterior ao novo ser� o topo atual
    topo = novo; // Atualiza o topo para o novo n�
    printf("Elemento %d inserido com sucesso.\n", pvalor); // Mensagem de sucesso
    getchar(); // Limpa o buffer do teclado
    system("cls"); // Limpa a tela do console
}

// Fun��o para mostrar todos os elementos da pilha
void mostra() {
    No *aux = topo; // Cria um ponteiro auxiliar para percorrer a pilha
    printf("Elementos na pilha:\n");
    while (aux != NULL) { // Enquanto houver elementos na pilha
        printf("%d\n", aux->valor); // Imprime o valor do n� atual
        aux = aux->anterior; // Move para o pr�ximo n�
    }
    getchar(); // Limpa o buffer do teclado
    system("cls"); // Limpa a tela do console
}

// Fun��o para exibir o valor no topo da pilha
void exibeTopo() {
    if (topo != NULL) {
        printf("Valor no topo da pilha: %d\n", topo->valor);
    } else {
        printf("Pilha vazia!\n");
    }
    getchar();
    system("cls");
}

// Fun��o para excluir todos os elementos da pilha
void excluir() {
    No *aux = topo; // Ponteiro auxiliar para percorrer a pilha
    while (aux != NULL) { // Enquanto houver elementos na pilha
        topo = aux->anterior; // Atualiza o topo para o pr�ximo n�
        free(aux); // Libera a mem�ria do n� atual
        aux = topo; // Move para o pr�ximo n�
    }
    printf("Pilha exclu�da com sucesso!\n");
    getchar();
    system("cls");
}

// Fun��o para desempilhar o elemento do topo da pilha
void desempilha() {
    if (topo != NULL) {
        No *aux = topo; // Ponteiro auxiliar para o n� que ser� desempilhado
        topo = topo->anterior; // Atualiza o topo para o pr�ximo n�
        printf("Elemento %d desempilhado com sucesso!\n", aux->valor);
        free(aux); // Libera a mem�ria do n� desempilhado
    } else {
        printf("Pilha vazia!\n");
    }
    getchar();
    system("cls");
}

// Fun��o principal
int main() {
    pilhaVazia(); // Inicializa a pilha como vazia
    int opcao, valor;

    do {
        // Menu de op��es
        printf("Escolha uma opcao:\n");
        printf("1. Empilhar\n");
        printf("2. Mostrar a pilha\n");
        printf("3. Exibir valor no topo\n");
        printf("4. Excluir toda pilha\n");
        printf("5. Desempilhar\n");
        printf("6. Sair\n");
        scanf("%d", &opcao); // L� a op��o escolhida pelo usu�rio

        // Executa a op��o escolhida
        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilha(valor); // Chama a fun��o para empilhar o valor
                break;
            case 2:
                mostra(); // Chama a fun��o para mostrar os elementos da pilha
                break;
            case 3:
                exibeTopo(); // Chama a fun��o para exibir o valor no topo da pilha
                break;
            case 4:
                excluir(); // Chama a fun��o para excluir todos os elementos da pilha
                break;
            case 5:
                desempilha(); // Chama a fun��o para desempilhar o elemento do topo
                break;
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6); // Loop continua at� o usu�rio escolher sair

    return 0;
}
  return 0;
}

