#include <stdio.h>
#define MAX 20

int arr[MAX], n = 0;
void printARRAY(int);
void bubble_sort(int );

int main()
{
    printf("\nEnter size of the ARRAY :\t");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the number :\t");
        scanf("%d", &arr[i]);
    }

    printf("\n ARRAY BEFORE :\n");
    printARRAY(n);

    bubble_sort(n);

    printf("\n ARRAY AFTER :\n");
    printARRAY(n);
    return 0;
}
void printARRAY(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\narr[%d] : %d\t", i, arr[i]);
    }
}

void bubble_sort(int n)
{
    int temp;
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
