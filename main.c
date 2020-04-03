#include <stdio.h>
#include "struct.h"

int main() {

    nill = (struct node *) malloc(sizeof(struct node));
    root = nill;
    root = insert(root, 10);
    root = insert(root, 18);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 16);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 70);
printf("%d\n\n",root->key);

    inorder(root, nill);


    return 0;
}