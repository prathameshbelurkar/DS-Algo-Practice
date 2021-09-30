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

void InsertSort(struct Array *arr, int x) 
{
    int i = arr->length-1;
    if (arr->length == arr->size)
        return;
    
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for (i=0; i<arr.length-1;i++)
    {
        if (arr.A[i] > arr.A[i+1])
            return 0;
    }
    return 1;
}

// Rearrange Positives and Negatives 
void Rearrange(struct Array *arr)
{
    int i, j;
    i=0;
    j=arr->length-1;

    while(i<j)
    {
        while(arr->A[i] < 0) i++;
        while(arr->A[j] >= 0) j--;
        if (i<j)
            Swap(&arr->A[i], &arr->A[j]);
        
    }
}

int main()
{
    // Array Initialization
    struct Array arr = {{2,4,5,7,8,9}, 20, 6};
    struct Array arr2 = {{2,-4,5,-7,-8,9}, 20, 6};

    // InsertSort
    // InsertSort(&arr, 10); 

    // isSorted
    // printf("%d", isSorted(arr));
    
    // Rearrange
    // Rearrange(&arr2);

    // Display Elements
    Display(arr);


    return 0;
}