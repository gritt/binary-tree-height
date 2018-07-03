#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int data) {

    if (root == NULL) {

        struct node *node = (struct node *) malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;

    } else {

        struct node *cur;

        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }

        return root;
    }
}

int getHeight(struct node *root) {

    return 1;
}

int main() {

    struct node *root = NULL;

    int treeSize;
    int data;

    scanf("%d", &treeSize);

    while (treeSize-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("%d", getHeight(root));
    return 0;
}