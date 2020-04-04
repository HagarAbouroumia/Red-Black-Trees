
void inorder(struct node *root, struct node *nill);

int maxDepth(struct node *node);

int search(struct node *node, char *key);

int search_insert(struct node *node, char *key);


struct node *insert(struct node *node, char *key) {

    int check = search_insert(node, key);
    if (check == 0) {
        printf("\nERROR: Word already in the dictionary\n");
        return root;
    } else {
        struct node *temp;
        temp = newNode(key, node, black, nill);
        if (node == nill) {
            root = temp;
            return root;
        } else {
            red_black_insert_fixup(helper);
            return root;
        }
    }


}

void inorder(struct node *root, struct node *nill) {
    if (root != nill) {
        inorder(root->left, nill);
        //  printf("parent is %d and left child is %d right child is %d and color is %d\n", root->key, root->left->key, root->right->key,root->color);
        printf("%s\n", root->key);
        inorder(root->right, nill);
    }
}


int maxDepth(struct node *node) {
    if (node == nill)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else return (rDepth + 1);
    }
}


int search(struct node *node, char *key) {
    char *s = (char *) malloc(sizeof(char *));
    strcpy(s, key);

    if (node == nill)
        printf("NO\n");
    else if (strcasecmp(node->key, key) == 0 || (strcasecmp(node->key,strcat(s,"\n"))==0))
        printf("YES\n");
    else if (strcasecmp(key, node->key) < 0)
        search(node->left, key);
    else if (strcasecmp(key, node->key) > 0)
        search(node->right, key);
}

int search_insert(struct node *node, char *key) {
    char *s = (char *) malloc(sizeof(char *));
    strcpy(s, key);
    if (node == nill)
        return 1;
    else if (strcasecmp(node->key, key) == 0 || (strcasecmp(node->key,strcat(s,"\n"))==0))
        return 0;
    else if (strcasecmp(key, node->key) < 0)
        search_insert(node->left, key);
    else if (strcasecmp(key, node->key) > 0)
        search_insert(node->right, key);
}

