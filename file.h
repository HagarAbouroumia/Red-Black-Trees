int size_file=0;

char **read_from_file() {
    FILE *ptr;
    ptr = fopen("C:\\Users\\user\\Downloads\\dictionary.txt", "r");
    char **sub_str = malloc(100 * sizeof(char *));
    char str[100];
    char *x = malloc(10 * sizeof(char));
    while (fgets(str, 50, ptr) != NULL) {
        sub_str[size_file] = malloc(10 * sizeof(char));
        strcpy(sub_str[size_file++], str);
    }
    fclose(ptr);
    return sub_str;
}