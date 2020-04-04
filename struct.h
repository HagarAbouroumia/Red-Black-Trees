#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node *root, *nill, *helper;
#define red          1
#define black        2
#define redUncle     3
#define rightRight   5
#define leftLeft     6
#define rightLeft    7
#define leftRight    8
struct node {
    char *key;
    int color;
    struct node *left, *right, *parent;
};

int RBT_size=0;

int casesCheck(struct node *node, struct node *nill);

int getCurrentLevel(struct node *node, struct node *nill, int counter);

void red_black_insert_fixup(struct node *node);

void leftRotation(struct node *node);

void rightRotation(struct node *node);

struct node *newNode(char *key, struct node *node, int color, struct node *pa) {
    if (node == nill) {
        RBT_size++;
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->key = key;
        temp->left = temp->right = nill;
        temp->parent = pa;
        temp->color = color;
        helper = temp;
        return temp;
    } else {
        if (strcmp(key, node->key) < 0) {
            node->left = newNode(key, node->left, red, node);
        } else if (strcmp(key, node->key) > 0) {
            node->right = newNode(key, node->right, red, node);
        }
    }
}

int getCurrentLevel(struct node *node, struct node *nill, int counter) {

    if (node->parent == nill) {
        return counter + 1;
    } else if (node->parent->parent == nill) {
        return counter + 2;
    } else {
        counter = counter + 1;
        getCurrentLevel(node->parent, nill, counter);
    }
}

int casesCheck(struct node *node, struct node *nill) {
    if (node->parent->color == red) {
        if (getCurrentLevel(node, nill, 0) >= 3) {
            struct node *grandpa = node->parent->parent, *pa = node->parent;
            if (grandpa->left == node->parent) // opp
            {
                if (grandpa->right->color == red) {
                    return redUncle;
                } else {
                    if (grandpa->left->left == node)
                        return leftLeft;
                    else
                        return leftRight;
                }
            } else {
                if (grandpa->right == node->parent) {
                    if (grandpa->left->color == red) {
                        return redUncle;
                    } else {
                        if (grandpa->right->right == node)
                            return rightRight;
                        else
                            return rightLeft;
                    }
                }
            }
        }
    }
    return 0;
}

void red_black_insert_fixup(struct node *node) {
    struct node *pa = node->parent, *grandpa = node->parent->parent;
    switch (casesCheck(node, nill)) {
        case redUncle: {
            if (grandpa->left == node->parent) {
                pa->color = grandpa->right->color = black;
                grandpa->color = red;
            } else {
                pa->color = grandpa->left->color = black;
                grandpa->color = red;
            }
            if (grandpa->parent == nill) {
                grandpa->color = black;
            } else {
                red_black_insert_fixup(grandpa);
            }
            break;
        }
        case rightRight: {
            pa->right = node;
            pa->color = black;
            grandpa->color = red;
            leftRotation(grandpa);
            // casesCheck(pa, nill);
            break;
        }
        case leftLeft: {
            pa->left = node;
            pa->color = black;
            grandpa->color = red;
            rightRotation(grandpa);
            // casesCheck(node, nill);
            break;
        }
        case rightLeft: {
            pa->left = node;
            rightRotation(pa);
            red_black_insert_fixup(pa);
            break;
        }
        case leftRight: {
            pa->right = node;
            leftRotation(pa);
            red_black_insert_fixup(pa);
            break;

        }
        default: {
            break;
        }

    }
}

void leftRotation(struct node *node) {
    int flag = 0;
    struct node *temp, *temp2, *temp3, *temp4;
    temp = node->parent;
    temp2 = node;
    temp3 = node->right;
    temp4 = node->right->left;
    if (node == node->parent->left)
        flag = 1;
    node = temp3;
    node->parent = temp;
    if (flag == 0)
        node->parent->right = node;
    else
        node->parent->left = node;
    node->left = temp2;
    node->left->parent = node;
    node->left->right = temp4;
    node->left->right->parent = node->left;
    if (node->parent == nill) {
        root = node;
    }

}

void rightRotation(struct node *node) {
    int flag = 0;
    struct node *temp, *temp2, *temp3, *temp4;
    temp = node->parent;
    temp2 = node;
    temp3 = node->left;
    temp4 = node->left->right;
    if (node == node->parent->left)
        flag = 1;
    node = temp3;
    node->parent = temp;
    if (flag == 0)
        node->parent->right = node;
    else
        node->parent->left = node;
    node->right = temp2;
    node->right->parent = node;
    node->right->left = temp4;
    node->right->left->parent = node->right;
    if (node->parent == nill)
        root = node;
}

