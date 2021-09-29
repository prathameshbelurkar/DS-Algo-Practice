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

int Get(struct Array arr, int index)
{
    if (index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index>=0 && index<arr->length)
        arr->A[index] = x;

}

int Max(struct Array arr) 
{
    int max = arr.A[0];
    int i;
    for (i=1;i<arr.length;i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr) 
{
    int min = arr.A[0];
    int i;
    for (i=1;i<arr.length;i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s=0;
    int i;
    for (i=0;i<arr.length;i++)
        s += arr.A[i];
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

int main()
{
    // Array Initialization
    struct Array arr = {{2,5,4,7,8,5}, 20, 6};

    // Get
    // printf("%d", Get(arr, 2));

    // Set
    // Set(&arr, 0, 15);

    // Max
    // printf("%d\n", Max(arr));

    // Min
    // printf("%d\n", Min(arr));

    // Sum
    // printf("%d\n", Sum(arr));

    // Avg
    // printf("%f\n", Avg(arr));

    
    // Display Elements
    Display(arr);


    return 0;
}