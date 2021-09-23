#include<stdio.h>
#include<stdlib.h>

struct Array 
{
    int *A;
    int size;
    int length;
};

// Display
void Display(struct Array arr)
{
    int i;
    printf("\nElements are \n");
    for (i=0;i<arr.length;i++) 
        printf("%d ", arr.A[i]);
    printf("\n");
}

// Append 
void Append(struct Array *arr, int x) 
{
    if (arr->length<arr->size)
        arr->A[arr->length++] = x;
}

// Insert
void Insert(struct Array *arr, int index, int x) 
{
    int i;
    if (index>=0 && index<=arr->length)
    {
        for (i=arr->length;i>index;i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;       
    }
}

int main()
{
    // Array Initialization
    struct Array arr;
    printf("Enter size of an Array");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    // Input to an Array
    int n, i;
    printf("Enter the Elements to be insert: ");
    scanf("%d", &n);

    printf("Enter All Elements\n");
    for (i=0;i<n;i++)   
        scanf("%d", &arr.A[i]);
    arr.length = n;

    // Display Elements
    while (1)
    {
        char ch;
        printf("\nWant to Exit?(y/n): ");
        scanf("%c", &ch);
        if (ch == 'y' || ch == 'Y')
            break;
        else
        {
            int choice;
            printf("\nEnter the Choice in Number");
            printf("\n1. Display");
            printf("\n2. Append\n");
            scanf("%d", &choice);

            if (choice == 1)
                Display(arr);
            else if (choice == 2)
            {
                int x;
                printf("\nEnter the Element: ");
                scanf("%d", &x);
                Append(&arr, x);
            }
            else if (choice == 3)
            {
                int x, ind;
                printf("\nEnter the Element: ");
                scanf("%d", &x);
                printf("\nEnter the Index: ");
                scanf("%d", &ind);
                Insert(&arr, ind, x);
            }
                
        }
    }


    return 0;
}