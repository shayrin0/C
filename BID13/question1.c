/******************************************************************************

                            Shirin Panahi Moghadam
                          Embedded Software Engineer
                               2023 - 01 - 31

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int count=0;

int* squareMaker (int n, int m)
{
    int *new_dim;
    int temp, m1;
    
    temp=n;
    new_dim = malloc(n * sizeof(int));
    
    while (temp>0)
    {
        if (temp>m)
        {
            new_dim[count] = m;
            temp -= m;
        }
        else if (temp<m)
        {
            new_dim[count] = temp;
            m1 = temp;
            temp = m-temp;
            m = m1;
        }
        else
        {
            new_dim[count] = temp;
            temp -= m;
        }
        count++;
    }
    
    return new_dim;
}

void Display(int* new_dim, int n, int m)
{
    if (n>m)
    {
        for (int i=0; i<count; i++)
        {
            printf("%dx%d", new_dim[i],new_dim[i]);
            if (i!=count-1)
                printf(", ");
        }
    }
    else
        printf("%dx%d", new_dim[0],new_dim[0]);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, m;
    int *new_dim;
    
    printf("Please enter the dimensions of the rectangle:\n");
    scanf("%d %d", &n, &m);
    
    if (n>m)
    {
        new_dim = squareMaker(n, m);
    }
    else if (n<m)
    {
        swap(&n, &m);
        new_dim = squareMaker(n, m);
    }
    else
    {
        new_dim = malloc(sizeof(int));
        new_dim[0] = n;
    }
    
    Display(new_dim, n, m);

    return 0;
}
