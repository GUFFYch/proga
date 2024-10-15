#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct Student
{
    char name[50];
    int marks_amount;
    int *marks;
};

float calculate_average(struct Student *student)
{
    float sum = 0;
    for (int i = 0; i < student->marks_amount; i++)
    {
        sum += student->marks[i];
    }
    return sum / student->marks_amount;
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL)
    {
        printf("Error opening input file\n");
        return 1;
    }

    int n;
    fscanf(input, "%d", &n);

    struct Student *students = malloc(n * sizeof(struct Student));
    float lowest_average = FLT_MAX;
    int lowest_average_index = 0;

    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%s %d", students[i].name, &students[i].marks_amount);
        students[i].marks = malloc(students[i].marks_amount * sizeof(int));

        for (int j = 0; j < students[i].marks_amount; j++)
        {
            fscanf(input, "%d", &students[i].marks[j]);
        }

        float average = calculate_average(&students[i]);
        if (average < lowest_average)
        {
            lowest_average = average;
            lowest_average_index = i;
        }
    }

    fclose(input);

    FILE *output = fopen("output.txt", "w");
    if (output == NULL)
    {
        printf("Error opening output file\n");
        return 1;
    }

    fprintf(output, "%s\n", students[lowest_average_index].name);
    fclose(output);

    for (int i = 0; i < n; i++)
    {
        free(students[i].marks);
    }
    free(students);

    return 0;
}
