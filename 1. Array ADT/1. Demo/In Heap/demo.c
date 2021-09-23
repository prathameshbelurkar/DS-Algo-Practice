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

    printf("Enter All Elements");
    for (i=0;i<n;i++)   
        scanf("%d", &arr.A[i]);
    arr.length = n;

    // Display Elements
    Display(arr);


    return 0;
}