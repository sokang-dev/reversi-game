#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "windowsCompatibility.h"

void question3();
void question4();
void question5();
void question6();
void funct(int * p, int num);

int main()
{
    enableWindowsCompatibility();

    question3();
    /* question4(); */
    /* question5(); */
    /* question6(); */

    return EXIT_SUCCESS;
}

void question3()
{
    int x[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    printf("%d \n", x);
    printf("%p \n", x);
    printf("%p \n", x + 2);
    printf("%d \n", *x);
    printf("%d \n", *x + 2);
    printf("%d \n", *(x + 2));
}

void question4()
{
    int a[5] = {10, 20, 30, 40, 50};

    funct(a + 3, 2);
}

void funct(int * p, int num)
{
    int i, sum = 0;

    for(i = 1; i < num; ++i)
        sum += *(p + i);

    printf("sum=%d\n", sum);
}

void question5()
{
    const char * day[] =
    {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    int dayNum;

    printf("Please enter a day number (0-6): ");
    scanf("%d", &dayNum);
    printf("That day is %s\n", day[dayNum]);
}

void question6()
{
    char name[10];
    char colour[10];

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your favourite colour: ");
    scanf("%s", colour);

    printf("Thank you, %s. ", name);

    if(!strcmp(colour, "Red"))
        printf("Red is a good colour.\n");
    else
        printf("%s is an okay colour.\n", colour);
}
