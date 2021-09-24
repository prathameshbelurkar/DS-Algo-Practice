#include<stdio.h>
#include<stdlib.h>

struct Array 
{
    int A[20];
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

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

int LinearSearch(struct Array arr, int key) 
{
    int i;
    for (i=0;i<arr.length;i++)
    {
        if (key == arr.A[i])
            return i;
    }
    return -1;
}

// Using Transposition
int ImprovedLinearSearch1(struct Array *arr, int key)
{
    int i;
    for (i=0;i<arr->length;i++)
    {
        if (key == arr->A[i])
        {
            Swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

// Using move to Front
int ImprovedLinearSearch2(struct Array *arr, int key)
{
    int i;
    for (i=0;i<arr->length;i++)
    {
        if (key == arr->A[i])
        {
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    // Array Initialization
    struct Array arr = {{2,5,4,7,8,5}, 20, 6};

    // Linear Search
    // printf("Element found at Index %d", LinearSearch(arr, 4));
    
    // Transposition: Linear Search
    // printf("Element found at Index %d", ImprovedLinearSearch1(&arr, 4));

    // Using Move to Front: Linear Search
    // printf("Element found at Index %d", ImprovedLinearSearch2(&arr, 4));


    // Display Elements
    Display(arr);


    return 0;
}