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


// Merge
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    
    for (;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for (;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 20;

    return arr3;
}

// Union
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else 
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    for (;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for (;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}

// Intersection
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
            i++;
        else if (arr2->A[j]<arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}

// Difference
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])
            j++;
        else 
        {
            i++;
            j++;
        }
    }
    
    for (;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 20;

    return arr3;
}



int main()
{
    // Array Initialization
    // Sorted Array 1
    struct Array arr1 = {{2,4,5,7,8,9}, 20, 6};
    // Sorted Array 2
    struct Array arr2 = {{3,4,10,12,17}, 20, 5};

    struct Array *arr3;

    // Merged Array 
    // arr3 = Merge(&arr1, &arr2);

    // Union
    // arr3 = Union(&arr1, &arr2);

    // Intersection
    // arr3 = Intersection(&arr1, &arr2);

    // Difference
    // arr3 = Difference(&arr1, &arr2);

    
    // Display Elements
    Display(*arr3);


    return 0;
}