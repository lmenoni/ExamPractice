
#include "argo.h"

void print_json_compact(json j) {
    switch (j.type) {
        case INTEGER:
            printf("%d", j.integer);
            break;

        case STRING:
            printf("\"");
            for (int i = 0; j.string[i] != '\0'; i++) {
                if (j.string[i] == '"' || j.string[i] == '\\') {
                    printf("\\");
                }
                printf("%c", j.string[i]);
            }
            printf("\"");
            break;

        case MAP:
            printf("{");
            for (size_t i = 0; i < j.map.size; i++) {
                printf("\"%s\":", j.map.data[i].key);
                print_json_compact(j.map.data[i].value);
                if (i < j.map.size - 1) {
                    printf(",");
                }
            }
            printf("}");
            break;
    }
}

void print_ast(json j) {
    print_json_compact(j);
    printf("\n");
}

int main(int ac, char **av) {
    
    if (ac != 2)
        return (printf("Invalid Number Of Arguments\n"));
    FILE    *stream;
    json    tree;
    stream = fopen(av[1], "r");
    
    if (argo(&tree, stream) == 0)
        return (printf("ERROR\n"), 1);
    print_ast(tree);
    
}