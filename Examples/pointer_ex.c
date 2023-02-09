
#include <stdio.h>

/*
    1. Create a char type variable & initialize it to value 100
    2. Print the address of the above variable
    3. Create a pointer variable & store the address of the above variable
    4. Perform read operation on the pointer variable to fetch 1 byte of data from the pointer
    5. Print the data obtained from the read operation on the pointer
    6. Perform write operation on the pointer to store the value 65
    7. Print the value of the variable defined in step 1
*/

int main()
{
    int c = 100;
    
    printf("The address of c is %p and its value is %d.\n", &c, c);

    int* pAdrs = &c;
    int value = *pAdrs; // dereferencing

    printf("The value stored in the pointer is %d.\n", value);

    return 0;
}