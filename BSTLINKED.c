#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *insert(Node *root, int value) {
    if (!root) {
        root = malloc(sizeof(Node));
        root->data = value;
        root->left = root->right = NULL;
    } else if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(void) {
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);

    inorder(root);
    return 0;
}