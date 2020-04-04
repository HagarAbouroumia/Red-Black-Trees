#include <stdio.h>
#include "struct.h"
#include "file.h"
#include "functions.h"

int main() {

    nill = (struct node *) malloc(sizeof(struct node));
    root = nill;
    char **str = read_from_file();
    for (int i = 0; i < size_file; i++) {
        root = insert(root, str[i]);
    }



    int choice = 0;


    while (choice != 3) {
        char* string=(char *)malloc(sizeof(char*)) ;

        printf("\nThe size of the dixtionary is %d\n", RBT_size);
        printf("The height of the RBT after insertion is  %d\n\n", maxDepth(root));
        printf("Choose from the following\n");
        printf("(1) Insert\n");
        printf("(2) Search\n");
        printf("(3) Terminate\n");
        scanf("%d", &choice);


        switch (choice) {

            case 1:
                printf("Enter the word\n");
                scanf("%s", string);
                root = insert(root, string);
                string = NULL;
                choice = 0;
                break;

            case 2:
                printf("Enter the word\n");
                scanf("%s", string);
                search(root, string);
                string = NULL;
                choice = 0;
                break;

            case 3:
                choice = 3;
                break;

            default:
                printf("Wrong input!\n");
                choice = 3;
                break;
        }
        printf("_______________________________________________");
    }

    return 0;
}
