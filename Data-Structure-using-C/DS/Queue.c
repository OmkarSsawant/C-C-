#include <stdio.h>
#define MAX 20

int queue[MAX];
int front = -1,rear=-1;

int INPUT();
void insert();
void delete ();
void printQUEUE();
int main()
{
    int ch, ctrl;
    do
    {
        printf("\n\t1 : insert \n\t2 : delete \n\t3 : PRINT\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            printQUEUE();
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
void insert()
{
    
    if (rear==MAX-1)
    {
        printf("QUEUE IS FULL");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear]=INPUT();
        
    }
    
    
    

}

void delete()
{
    if (rear==-1)
    {
        printf("\n\tThe QUEUE is EMPTY");
    }
    else
    {
        rear--;
    }
    
    
}
void printQUEUE()
{
    int i;
    if (rear == -1)
    {
        printf("\n\t \bQUEUE EMPTY");
    }
    else
    {
        printf("\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}