#include <stdio.h>
#include <string.h>

#define MAX_NODES 10 // Número máximo de nós (nomes)
#define MAX_NAME_LENGTH 16 // Comprimento máximo do nome

// Função para adicionar um nome ao grafo
void addName(char names[][MAX_NAME_LENGTH + 1], int *numNodes) {
    char name[MAX_NAME_LENGTH + 1];
    printf("Digite o nome (ate 16 letras): ");
    scanf("%s", name);

    if (*numNodes < MAX_NODES) {
        strcpy(names[*numNodes], name);
        (*numNodes)++;
        printf("Nome adicionado com sucesso!\n");
    } else {
        printf("Limite de nos atingido. Não eh possivel adicionar mais nomes.\n");
    }
}

// Função para encontrar o índice de um nome no vetor de nomes
int findNameIndex(char names[][MAX_NAME_LENGTH + 1], int numNodes, char *name) {
    for (int i = 0; i < numNodes; ++i) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    return -1; // Retorna -1 se o nome não for encontrado
}

// Função para criar uma matriz de adjacência para o grafo
void createAdjacencyMatrix(int adjacencyMatrix[][MAX_NODES], int numNodes) {
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            adjacencyMatrix[i][j] = 0; // Inicializa a matriz com 0
        }
    }
}

// Função para adicionar uma conexão entre dois nomes
void addConnection(int adjacencyMatrix[][MAX_NODES], char names[][MAX_NAME_LENGTH + 1], int numNodes) {
    char name1[MAX_NAME_LENGTH + 1], name2[MAX_NAME_LENGTH + 1];
    printf("Digite o primeiro nome: ");
    scanf("%s", name1);
    printf("Digite o segundo nome: ");
    scanf("%s", name2);

    int index1 = findNameIndex(names, numNodes, name1);
    int index2 = findNameIndex(names, numNodes, name2);

    if (index1 != -1 && index2 != -1) {
        adjacencyMatrix[index1][index2] = 1;
        adjacencyMatrix[index2][index1] = 1;
        printf("Conexao entre %s e %s adicionada com sucesso!\n", name1, name2);
    } else {
        printf("Um ou ambos os nomes nao foram encontrados.\n");
    }
}

// Função para imprimir a matriz de adjacência
void printAdjacencyMatrix(int adjacencyMatrix[][MAX_NODES], char names[][MAX_NAME_LENGTH + 1], int numNodes) {
    printf("Matriz de adjacencia:\n");
    printf("   ");
    for (int i = 0; i < numNodes; ++i) {
        printf("%-16s", names[i]);
    }
    printf("\n");
    for (int i = 0; i < numNodes; ++i) {
        printf("%-4s", names[i]);
        for (int j = 0; j < numNodes; ++j) {
            printf("%-16d", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    char names[MAX_NODES][MAX_NAME_LENGTH + 1];
    int adjacencyMatrix[MAX_NODES][MAX_NODES] = {0};
    int numNodes = 0;
    int choice;

    createAdjacencyMatrix(adjacencyMatrix, numNodes);


    do {
        printf("\nRede Social - Operacoes Disponiveis:\n");
        printf("1. Adicionar nome\n");
        printf("2. Adicionar conexao\n");
        printf("3. Mostrar matriz de adjacencia\n");
        printf("4. Sair\n");
        printf("Escolha uma operacao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addName(names, &numNodes);
                break;
            case 2:
                if (numNodes < 2) {
                    printf("Adicione pelo menos dois nomes para criar uma conexao.\n");
                } else {
                    addConnection(adjacencyMatrix, names, numNodes);
                }
                break;
            case 3:
                if (numNodes < 1) {
                    printf("Adicione pelo menos um nome para mostrar a matriz de adjacencia.\n");
                } else {
                    printAdjacencyMatrix(adjacencyMatrix, names, numNodes);
                }
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Escolha invalida. Por favor, tente novamente.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
