#include <stdio.h>

/*
    The importance of data types in pointers
    Note that although we can use different data types for pointers,
    always 8 bytes of memory will be allocated to them regardless of their type.
*/

long long int g_data = 0xFFFEABCD11112345;

int main()
{
    char *pAddress1;
    pAddress1 = (char*)&g_data;
    printf("Value at address %p is %x.\n", pAddress1, *pAddress1);

    int *pAddress2;
    pAddress2 = (int*)&g_data;
    printf("Value at address %p is %x.\n", pAddress2, *pAddress2);

    short *pAddress3;
    pAddress3 = (short*)&g_data;
    printf("Value at address %p is %x.\n", pAddress3, *pAddress3);

    long long *pAddress4;
    pAddress4 = (long long*)&g_data;
    printf("Value at address %p is %x.\n", pAddress4, *pAddress4);

    return 0;
}