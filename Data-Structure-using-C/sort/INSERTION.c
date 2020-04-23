#include <stdio.h>
#define MAX 20

int arr[MAX], n = 0;
void printARRAY(int);
void insertion_sort(int);
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

    insertion_sort(n);

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

void insertion_sort(int n)
{

    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}