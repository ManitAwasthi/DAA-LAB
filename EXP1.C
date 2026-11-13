#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

struct Node* recursiveSearch(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return recursiveSearch(root->left, key);

    return recursiveSearch(root->right, key);
}

struct Node* iterativeSearch(struct Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (recursiveSearch(root, key))
        printf("Recursive Search: Element found\n");
    else
        printf("Recursive Search: Element not found\n");

    if (iterativeSearch(root, key))
        printf("Iterative Search: Element found\n");
    else
        printf("Iterative Search: Element not found\n");

    return 0;
}
