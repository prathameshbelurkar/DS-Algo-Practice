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

struct Node * LSearch(struct Node *p, int key) 
{
    while(p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// Using move to front 
struct Node * LSearch2(struct Node *p, int key) 
{
    struct Node *q = NULL;
    while(p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;        
        }

        q = p;
        p = p->next;
    }
    return NULL;
}


struct Node * RLSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RLSearch(p->next, key);
}



int main()
{
    struct Node *temp;
    int A[] = {3,5,7,13,15};

    // Create a Linked List 
    create(A, 5);

    // Display
    Display(first);

    // LSearch
    // temp = LSearch(first, 7);
    // if (temp)
    //     printf("Key is Found: %d\n", temp->data);
    // else 
    //     printf("Key is Not Found\n");

    // RLSearch
    // temp = RLSearch(first, 7);
    // if (temp)
    //     printf("Key is Found: %d\n", temp->data);
    // else 
    //     printf("Key is Not Found\n");

    // LSearch1
    temp = LSearch2(first, 7);
    if (temp)
        printf("Key is Found: %d\n", temp->data);
    else 
        printf("Key is Not Found\n");
    Display(first);


    
    
    return 0;
}