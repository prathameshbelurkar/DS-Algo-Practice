#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n) 
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data =  A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p != NULL) 
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Max(struct Node *p)
{
    int max = -32767;
    while(p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int RMax(struct Node *p)
{
    int x = 0;

    if (p == 0)
        return -32767;
    x = RMax(p->next);
    if (x>p->data)
        return x;
    else
        return p->data; 
}


int main()
{
    int A[] = {3,5,7,13,15};

    // Create a Linked List 
    create(A, 5);

    // Display
    Display(first);

    // Max
    // printf("Max is %d\n", Max(first));

    // RMax
    printf("Max is %d\n", RMax(first));
    
    

    return 0;
}