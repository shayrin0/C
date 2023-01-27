#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Display all the elements in an array
void Display(struct Array arr)
{
    printf("\nElements are\n");
    for(int i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}

// Add an element at the end of the array
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

// Insert a value at a given index
void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for(int i=arr->length; i>index; i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}

// Delete a value at a given index
int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index <= arr->length-1)
    {
        x = arr->A[index];
        for(int i=index; i<arr->length-1; i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

// Swap two elements
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Linearly search for an element
int LinearSearch(struct Array arr, int key)
{
    for(int i=0; i<arr.length; i++)
    {
        if(key == arr.A[i])
            return i;
    }
    return -1;
}

int main()
{
    struct Array arr={{2,3,4,5,6}, 10,5};

    // Append(&arr, 10);
    // Insert(&arr, 3, 10);
    // printf("%d\n", Delete(&arr, 1));
    printf("%d\n", LinearSearch(arr, 4));
    Display(arr);

    return 0;
}