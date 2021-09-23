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

int main()
{
    // Array Initialization
    struct Array arr = {{2,5,4,7,8,5}, 20, 6};

    // Display Elements
    Display(arr);


    return 0;
}