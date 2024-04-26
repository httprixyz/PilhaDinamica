#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó da pilha
struct no {
    int valor;
    struct no *anterior;
};

typedef struct no No; // Definição de um alias para "struct no" como "No"

No *topo; // Ponteiro global para o topo da pilha

// Função para inicializar a pilha como vazia
void pilhaVazia() {
    topo = NULL; // Inicializa o topo como NULL, indicando pilha vazia
}

// Função para empilhar um elemento na pilha
void empilha(int pvalor) {
    No *novo = (No*)malloc(sizeof(No)); // Aloca memória para um novo nó
    novo->valor = pvalor; // Define o valor do novo nó
    novo->anterior = topo; // O nó anterior ao novo será o topo atual
    topo = novo; // Atualiza o topo para o novo nó
    printf("Elemento %d inserido com sucesso.\n", pvalor); // Mensagem de sucesso
    getchar(); // Limpa o buffer do teclado
    system("cls"); // Limpa a tela do console
}

// Função para mostrar todos os elementos da pilha
void mostra() {
    No *aux = topo; // Cria um ponteiro auxiliar para percorrer a pilha
    printf("Elementos na pilha:\n");
    while (aux != NULL) { // Enquanto houver elementos na pilha
        printf("%d\n", aux->valor); // Imprime o valor do nó atual
        aux = aux->anterior; // Move para o próximo nó
    }
    getchar(); // Limpa o buffer do teclado
    system("cls"); // Limpa a tela do console
}

// Função para exibir o valor no topo da pilha
void exibeTopo() {
    if (topo != NULL) {
        printf("Valor no topo da pilha: %d\n", topo->valor);
    } else {
        printf("Pilha vazia!\n");
    }
    getchar();
    system("cls");
}

// Função para excluir todos os elementos da pilha
void excluir() {
    No *aux = topo; // Ponteiro auxiliar para percorrer a pilha
    while (aux != NULL) { // Enquanto houver elementos na pilha
        topo = aux->anterior; // Atualiza o topo para o próximo nó
        free(aux); // Libera a memória do nó atual
        aux = topo; // Move para o próximo nó
    }
    printf("Pilha excluída com sucesso!\n");
    getchar();
    system("cls");
}

// Função para desempilhar o elemento do topo da pilha
void desempilha() {
    if (topo != NULL) {
        No *aux = topo; // Ponteiro auxiliar para o nó que será desempilhado
        topo = topo->anterior; // Atualiza o topo para o próximo nó
        printf("Elemento %d desempilhado com sucesso!\n", aux->valor);
        free(aux); // Libera a memória do nó desempilhado
    } else {
        printf("Pilha vazia!\n");
    }
    getchar();
    system("cls");
}

// Função principal
int main() {
    pilhaVazia(); // Inicializa a pilha como vazia
    int opcao, valor;

    do {
        // Menu de opções
        printf("Escolha uma opcao:\n");
        printf("1. Empilhar\n");
        printf("2. Mostrar a pilha\n");
        printf("3. Exibir valor no topo\n");
        printf("4. Excluir toda pilha\n");
        printf("5. Desempilhar\n");
        printf("6. Sair\n");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

        // Executa a opção escolhida
        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilha(valor); // Chama a função para empilhar o valor
                break;
            case 2:
                mostra(); // Chama a função para mostrar os elementos da pilha
                break;
            case 3:
                exibeTopo(); // Chama a função para exibir o valor no topo da pilha
                break;
            case 4:
                excluir(); // Chama a função para excluir todos os elementos da pilha
                break;
            case 5:
                desempilha(); // Chama a função para desempilhar o elemento do topo
                break;
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6); // Loop continua até o usuário escolher sair

    return 0;
}
  return 0;
}

