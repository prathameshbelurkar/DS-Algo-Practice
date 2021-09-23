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

void Append(struct Array *arr, int x) 
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

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

int Delete(struct Array *arr, int index) 
{
    int x = 0, i;

    if (index>=0 && index<arr->length)
    {
        x = arr->A[index];
        for (i=index;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{
    // Array Initialization
    struct Array arr = {{2,5,4,7,8,5}, 20, 6};

    // Append
    // Append(&arr, 10);

    // Insert 
    // Insert(&arr, 4, 10);

    // Delete
    // printf("\n %d is the Deleted Element", Delete(&arr, 4));

    // Display Elements
    Display(arr);


    return 0;
}