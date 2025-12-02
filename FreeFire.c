#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

// ------------------------
// STRUCT DO ITEM
// ------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// ------------------------
// FUNÇÕES
// ------------------------
void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\n=== Cadastro de Item ===\n");
    printf("Nome: ");
    scanf("%s", novo.nome);

    printf("Tipo (arma, munição, cura, ferramenta): ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[*total] = novo;
    (*total)++;

    printf("\nItem adicionado com sucesso!\n");
}

void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("\nA mochila está vazia! Nada para remover.\n");
        return;
    }

    char nomeBusca[30];
    int encontrado = -1;

    printf("\nInforme o nome do item a remover: ");
    scanf("%s", nomeBusca);

    // Busca sequencial pelo item
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nItem não encontrado!\n");
        return;
    }

    // Remoção ajustando vetor
    for (int i = encontrado; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--;
    printf("\nItem removido com sucesso!\n");
}

void listarItens(Item mochila[], int total) {
    printf("\n--- ITENS NA MOCHILA (%d/10) ---\n", total);
    printf("--------------------------------------------------------\n");
    printf("%-20s | %-15s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("--------------------------------------------------------\n");

    if (total == 0) {
        printf("A mochila está vazia.\n");
        printf("--------------------------------------------------------\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("%-20s | %-15s | %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }

    printf("--------------------------------------------------------\n");
}

void buscarItem(Item mochila[], int total) {
    char nomeBusca[30];
    int encontrado = -1;

    printf("\nInforme o nome do item que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nItem não encontrado.\n");
    } else {
        printf("\n=== Item encontrado ===\n");
        printf("Nome: %s\n", mochila[encontrado].nome);
        printf("Tipo: %s\n", mochila[encontrado].tipo);
        printf("Quantidade: %d\n", mochila[encontrado].quantidade);
    }
}

// ------------------------
// FUNÇÃO PRINCIPAL
// ------------------------
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n======= MENU DO INVENTÁRIO =======\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                listarItens(mochila, total);
                break;

            case 2:
                removerItem(mochila, &total);
                listarItens(mochila, total);
                break;

            case 3:
                listarItens(mochila, total);
                break;

            case 4:
                buscarItem(mochila, total);
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}