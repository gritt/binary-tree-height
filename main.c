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

    int rightPath = 0;
    int leftPath = 0;

    if (root == NULL) {
        return 0;
    }

    /*
     * Solution:
     *
     * Recursively calls getHeight passing the next node (right or left) as root and summing +1
     * Do it till there are no more left or right nodes left to go
     *
     * 7
     * 3 5 2 1 4 6 7
     *
     *             3
     *          2     5
     *       1      4   6
     *                    7
     *
     *
     */

    if (root->left != NULL) {
        leftPath = 1 + getHeight(root->left);
    }

    if (root->right != NULL) {
        rightPath = 1 + getHeight(root->right);
    }

    return rightPath > leftPath ? rightPath : leftPath;
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
