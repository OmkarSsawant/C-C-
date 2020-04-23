#include <stdio.h>
#include<stdlib.h>
//LINKED LIST
struct Note
{
    int data;
    struct Note *next;
};

typedef struct Note Note;

Note *START = NULL, *p = NULL;

Note *CreateLinkedList(int n)
{
    Note *head;
    int i;
    for (i = 0; i < n; i++)
    {
        Note *temp = (Note *)malloc(sizeof(Note));
        printf("\nEnter the node data :\t");
        scanf("%d",&(temp->data));
        temp->next=NULL;
        if (START == NULL)
        {
            START=temp;
        }
        else
        {
            p=START;
            while (p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            
        }
        
    }
    head=START;

    return head;

    
}

Note* DeleteFnode(Note * head){
    Note *frt,*rethead;
    if(START==NULL){
        printf("\nThe Linked LIst is empty ");

    }
    else{

        frt=head;
        head=head->next;
        rethead=head;
        free(frt);
    }
    return rethead;
}
Note *DeleteMnode(Note *head,int loc)
{
    Note *p,*q, *rethead=head,*freeP;
    if (START == NULL)
    {
        printf("\nThe Linked List is empty ");
    }
    else
    {
        int i;
        p=head;
        q=head->next;
        for ( i = 1; i < loc-1; i++)
        {
            p=p->next;
            q=p->next;
            
        }
        p->next=q->next;
        freeP=q;
        free(freeP);

        
        
        
    }
    return rethead;
}


void printLL(Note *head){
    Note *ptr=head;
    while (ptr!=NULL)
    {
        printf("\n\t %d -> %d",ptr,ptr->data);
        ptr=ptr->next;
    }
    
}

int main()
{
    Note * HEAD=NULL;

    HEAD = CreateLinkedList(4);

    printLL(HEAD);

    printf("\n\tAfter Deletion :");

    HEAD = DeleteMnode(HEAD,27);

    printLL(HEAD);

    return 0;
}