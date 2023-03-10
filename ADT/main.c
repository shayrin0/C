#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Display all the elements in an array
void Display (struct Array arr)
{
    printf("\nElements are\n");
    for(int i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}

// Add an element at the end of the array
void Append (struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

// Insert a value at a given index
void Insert (struct Array *arr, int index, int x)
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
int Delete (struct Array *arr, int index)
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
void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Linearly search for an element
int LinearSearch (struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            // LinearSearch improvement: Transposition
            // swap(&arr->A[i], &arr->A[i-1]);
            // return i-1;
            // LinearSearch improvement: Move to front/head
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}

// Bineary search to find an element
int BinarySearch (struct Array arr, int key)
{
    int l, mid, h;
    l=0;
    h=arr.length-1;
    
    while(l <= h)
    {
        mid = (l+h)/2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    
    return -1;
}

// Recursive Binary Search
int RBinSearch (int a[], int l, int h, int key)
{
    int mid;
    
    if (l<=h)
    {
        mid = (l+h)/2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid-1, key);
        else
            return RBinSearch(a, mid+1, h, key);
    }
    return -1;
}

// Get a value from a certain index in the array
int Get (struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

// Set a value at a specific index of the array
void Set (struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

// Find the max element in the array
int Max (struct Array arr)
{
    int max = arr.A[0];
    for (int i=0; i<arr.length; i++)
        if (arr.A[i] > max)
            max = arr.A[i];
    return max;
}

// Find the min element in the array
int Min (struct Array arr)
{
    int min = arr.A[0];
    for (int i=0; i<arr.length; i++)
        if (arr.A[i] < min)
            min = arr.A[i];
    return min;
}

// Calculate the sum of elements in an array
int Sum (struct Array arr)
{
    int s=0;
    for (int i=0; i<arr.length; i++)
        s += arr.A[i];
    return s;
}

// Calculate the average in an array
float Avg (struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Reverse (struct Array *arr)
{
    int *B;
    B = (int *) malloc(arr->length * sizeof(int));
    
    for (int i=arr->length-1, j=0; i>=0; i--, j++)
        B[j] = arr->A[i];
    for (int i=0; i<arr->length; i++)
        arr->A[i] = B[i];
}

void Reverse2 (struct Array *arr)
{
    for(int i=0, j=arr->length-1; i<j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

void InsertSort (struct Array *arr, int x)
{
    int i = arr->length-1;
    if (arr->length == arr->size)
        return;
    while(i>=0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted (struct Array arr)
{
    for (int i=0; i<arr.length-1; i++)
        if (arr.A[i] > arr.A[i+1])
            return 0;
    return 1;
}

void Rearrange (struct Array *arr)
{
    int i=0;
    int j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0) j--;
        if(i<j) swap(&arr->A[i], &arr->A[j]);
    }
}

// Merge two arrays
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    
    for (;i<arr1->length ; i++)
        arr3->A[k++] = arr1->A[i];
    for (;j<arr2->length ; j++)
        arr3->A[k++] = arr2->A[j];
        
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    
    return arr3;
}

// Union of two arrays
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    for (;i<arr1->length ; i++)
        arr3->A[k++] = arr1->A[i];
    for (;j<arr2->length ; j++)
        arr3->A[k++] = arr2->A[j];
        
    arr3->length = k;
    arr3->size = 10;
    
    return arr3;
}

// Intersection of two arrays
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
        
    arr3->length = k;
    arr3->size = 10;
    
    return arr3;
}

// Difference of two arrays
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    
    for (;i<arr1->length ; i++)
        arr3->A[k++] = arr1->A[i];
        
    arr3->length = k;
    arr3->size = 10;
    
    return arr3;
}

int main()
{
    struct Array arr1={{1,2,3,4,5}, 10,5};
    struct Array arr2={{2,5,16,18,20}, 10,5};
    struct Array *arr3;
    
    // arr3 = Merge(&arr1, &arr2);
    // arr3 = Union(&arr1, &arr2);
    // arr3 = Intersection(&arr1, &arr2);
    arr3 = Difference(&arr1, &arr2);
    Display(*arr3);

    // Append(&arr, 10);
    // Insert(&arr, 3, 10);
    // printf("%d\n", Delete(&arr, 1));
    // printf("%d\n", LinearSearch(&arr, 4));
    // printf("%d\n", BinarySearch(arr, 4));
    // printf("%d\n", RBinSearch(arr.A, 0, arr.length, 4));
    // Set(&arr, 0, 15);
    // printf("%d\n", Get(arr,0));
    // printf("%d\n", Max(arr));
    // printf("%d\n", Min(arr));
    // printf("%d\n", Sum(arr));
    // printf("%f\n", Avg(arr));
    // Reverse2(&arr);
    // InsertSort(&arr, 1);
    // printf("%d\n", isSorted(arr));
    // Rearrange(&arr);
    // Display(arr);

    return 0;
}