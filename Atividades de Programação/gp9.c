#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 1024
#define MAX_OPERATIONS 1024
#define MAX_ELEMENTS 1024

// Estrutura para representar um nó da árvore de diretórios
typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node *children[MAX_ELEMENTS];
    int childCount;
} Node;

// Função para criar um novo nó do diretório
Node *createNode(char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->childCount = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Função para adicionar um diretório ou arquivo como filho a um nó do diretório
void addChild(Node *parent, Node *child) {
    if (parent->childCount < MAX_ELEMENTS) {
        parent->children[parent->childCount] = child;
        parent->childCount++;
    } else {
        printf("Limite máximo de elementos atingido para este diretório.\n");
    }
}

// Função para buscar um arquivo no diretório e seus subdiretórios
void searchFile(Node *current, char *filename, char *path, int *found) {
    if (current != NULL && *found == 0) {
        char currentPath[MAX_NAME_LENGTH];
        strcpy(currentPath, path);
        strcat(currentPath, "/");
        strcat(currentPath, current->name);

        if (strcmp(current->name, filename) == 0) {
            *found = 1;
            printf("%s %s\n", filename, currentPath);
            return;
        }

        for (int i = 0; i < current->childCount; i++) {
            searchFile(current->children[i], filename, currentPath, found);
        }
    }
}

int main() {
    int numOperations;
    scanf("%d", &numOperations);

    char rootName[] = "\\root";
    Node *root = createNode(rootName);

    for (int i = 0; i < numOperations; i++) {
        char filename[MAX_NAME_LENGTH];
        scanf("%s", filename);

        // Simulando operações (adicionar arquivos/diretórios)
        // Aqui você pode implementar a lógica para adicionar os arquivos/diretórios na árvore

        // Exemplo de adição de arquivo (substitua por lógica real)
        Node *newFile = createNode(filename);
        addChild(root, newFile);
    }

    char searchFilename[MAX_NAME_LENGTH];
    scanf("%s", searchFilename);

    int found = 0;
    char rootPath[MAX_NAME_LENGTH];
    strcpy(rootPath, "");
    searchFile(root, searchFilename, rootPath, &found);

    if (!found) {
        printf("Arquivo nao encontrado!\n");
    }

    // Liberando a memória alocada
    // Aqui você pode implementar uma função para liberar a memória da árvore

    return 0;
}
