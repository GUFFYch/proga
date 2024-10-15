#include <stdio.h>

// Структура для хранения фигуры
typedef struct {
    int numSides;
    int sides[100];
} Figure;

// Функция для вычисления периметра фигуры
int calculatePerimeter(Figure* fig) {
    int perimeter = 0;
    for (int i = 0; i < fig->numSides; i++) {
        perimeter += fig->sides[i];
    }
    return perimeter;
}

// Функция для поиска фигуры с максимальным периметром
void findMaxPerimeter(Figure* figures, int numFigures, Figure* maxFigure) {
    int maxPerimeter = 0;
    for (int i = 0; i < numFigures; i++) {
        int perimeter = calculatePerimeter(&figures[i]);
        if (perimeter > maxPerimeter) {
            *maxFigure = figures[i];
            maxPerimeter = perimeter;
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    Figure figures[100];
    int numFigures = 0;

    // Чтение длин сторон фигур из файла input.txt
    while (fscanf(inputFile, "%d", &figures[numFigures].numSides) != EOF) {
        for (int i = 0; i < figures[numFigures].numSides; i++) {
            fscanf(inputFile, "%d", &figures[numFigures].sides[i]);
        }
        numFigures++;
    }

    // Поиск фигуры с максимальным периметром
    Figure maxFigure;
    findMaxPerimeter(figures, numFigures, &maxFigure);

    // Запись результата в файл output.txt
    fprintf(outputFile, "%d", maxFigure.numSides);
    for (int i = 0; i < maxFigure.numSides; i++) {
        fprintf(outputFile, " %d", maxFigure.sides[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
