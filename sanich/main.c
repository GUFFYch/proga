#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_PRODUCTS 100

typedef struct {
    char name[MAX_NAME];
    float price;
} Product;

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (input == NULL || output == NULL) {
        printf("Ошибка при открытии файлов\n");
        return 1;
    }

    int n;
    fscanf(input, "%d", &n);

    Product initial[MAX_PRODUCTS], final[MAX_PRODUCTS];
    float initial_price, final_price;
    fscanf(input, "%f", &initial_price);

    for (int i = 0; i < n; i++) {
        fscanf(input, "%s %f", initial[i].name, &initial[i].price);
    }

    fscanf(input, "%f", &final_price);

    for (int i = 0; i < n; i++) {
        fscanf(input, "%s %f", final[i].name, &final[i].price);
    }

    char max_drop_name[MAX_NAME];
    float max_drop = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(initial[i].name, final[j].name) == 0) {
                float drop = (initial[i].price / initial_price) - (final[j].price / final_price);
                if (drop > max_drop) {
                    max_drop = drop;
                    strcpy(max_drop_name, initial[i].name);
                }
                break;
            }
        }
    }

    fprintf(output, "%s", max_drop_name);

    fclose(input);
    fclose(output);

    return 0;
}
