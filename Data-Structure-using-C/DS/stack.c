#include <stdio.h>
#define MAX 20

int stack[MAX];
int top = -1;

int INPUT();
void push();
void pop();
void printSTACK();
int main()
{
    int ch, ctrl;
    do
    {
        printf("\n\t1 : PUSH \n\t2 : POP \n\t3 : PRINT\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            printSTACK();
            break;
        default:
            printf("\n\t\tSOMETHING WENT WRONG");
            break;
        }

        printf("\n\tPress 1 to Continue...\t");
        scanf("%d", &ctrl);
    } while (ctrl == 1);
}
int INPUT()
{
    int temp;

    printf("\nEnter the number :\t");
    scanf("%d", &temp);
    return temp;
}
void push()
{
    if (top == MAX - 1)
    {
        printf("\n\tSTACK OVERFLOW ");
    }
    else
    {
        top++;
        stack[top] = INPUT();
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\n\tSTACK UNDERFLOW ");
    }
    else
    {
        top--;
    }
}
void printSTACK()
{
    int i;
    if (top == -1)
    {
        printf("\n\t \bSTACK EMPTY");
    }
    else
    {
        printf("\n");
        for (i = 0; i <=top ; i++)
        {
            printf("%d\t", stack[i]);
        }
    }
}