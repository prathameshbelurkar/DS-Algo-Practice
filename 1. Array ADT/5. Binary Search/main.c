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

// Iteration: Binary Search
int BinarySearch(struct Array arr, int key) 
{
    int l, h, mid;
    l = 0;
    h = arr.length - 1;

    while(l<=h)
    {
        mid = (l+h)/2;
        if (arr.A[mid] == key) 
            return mid;
        else if (key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1; 
    }
    return -1;
}

// Recursion: Binary Search
int RBinarySearch(int a[], int l, int h, int key)
{
    int mid;

    if (l<=h)
    {
        mid=(l+h)/2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinarySearch(a, l, mid-1, key);
        else 
            return RBinarySearch(a, mid-1, h, key);
    }
    return -1;
}

int main()
{
    // Array Initialization
    struct Array arr = {{2,8,14,17,33,45,48}, 20, 6};

    // Iteration: Binary Search
    // printf("Element found at Index %d", BinarySearch(arr, 17));

    // Recursion: Binary Search
    printf("Element found at Index %d", RBinarySearch(arr.A, 0, arr.length, 17));

    // Display Elements
    Display(arr);


    return 0;
}