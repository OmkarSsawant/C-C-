#include <stdio.h>
#define MAX 20

int arr[MAX], n = 0;

int flagB = 0;
int mid, l = 0, h;
void insert_pos(int, int);
void delete_pos(int, int);
int linear_search(int);

int binary_searchR(int, int, int); //Recursion method
int binary_searchN(int, int, int); //Normal Method
void printARRAY(int);

int main()
{
    int pos, value, flag, flagBB;
    printf("\nEnter size of the ARRAY :\t");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the number :\t");
        scanf("%d", &arr[i]);
    }
    printf("\n \t\tThe OLD Array :\n");
    printARRAY(n);
    
    printf("\nEnter the position at which you want to enter :\t");
    scanf("%d", &pos);
    insert_pos(pos, n);
    printf("\nEnter the position at which you want to delete :\t");
    scanf("%d", &pos);
    delete_pos(pos - 1, n);
 
    printf("\nEnter the value you want to search :\t");
    scanf("%d", &value);
      flag = linear_search(value);
    if (flag == 0)
    {
        printf("\n\tthere  %d is not present[FROM LINEAR SEARCH]", value);
    }
    else
    {
        printf("\n\tthe  value  %d is present[FROM LINEAR SEARCH]", value);
    } 
    //binary search
    l = 0;
    h = n ;
     flagBB = binary_searchR(l, h, value);
    if (flagBB == 0)
    {
        printf("\n\tthere  %d is not present[FROM BINARY SEARCH R]", value);
    }
    else
    {
        printf("\n\tthe  value  %d is present[FROM BINARY SEARCH R]", value);
    }

    flagBB = binary_searchN(l, h, value);

    if (flagBB == 0)
    {
        printf("\n\tthere  %d is not present[FROM BINARY SEARCH N]", value);
    }
    else
    {
        printf("\n\tthe  value  %d is present[FROM BINARY SEARCH N]", value);
    }
    printf("\n \t\tThe NEW Array :\n");
    printARRAY(n);

    return 0;
}

void insert_pos(int pos, int c_n)
{
    int num, i = 0;
    for (i = c_n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    printf("\nEnter the number you want to insert :\t");
    scanf("%d", &num);

    arr[pos] = num;
    n++;
}

void delete_pos(int pos, int c_n)
{
    int i = 0;
    for (i = pos; i <= c_n; i++)
    {
        arr[i - 1] = arr[i];
    }
    n--;
}

int linear_search(int value)
{
    int flag = 0, i = 0;

    while (i != n && flag == 0)
    {
        if (arr[i] == value)
        {
            flag = 1;
        }
        i++;
    }
    return flag;
}

int binary_searchR(int l, int h, int value)
{

    mid = (l + h) / 2;
    if (arr[mid] == value)
    {
        return 1;
    }
    else if (arr[mid] > value)
    {
        h = mid - 1;
        binary_searchR(l, h, value);
    }
    else if (arr[mid] < value)
    {
        l = mid + 1;
        binary_searchR(l, h, value);
    }
    else if (l > h)
    {
        return 0;
    }
}

int binary_searchN(int l, int h, int value)
{

    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;

        if (arr[mid] > value)
        {
            h = mid - 1;
        }
        else if (arr[mid] < value)
        {
            l = mid + 1;
        }
        else if (arr[mid] == value)
        {
            return 1;
        }
        else if (l > h)
        {
            break;
        }
    }
    return 0;
}

void printARRAY(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\narr[%d] : %d\t", i, arr[i]);
    }
}