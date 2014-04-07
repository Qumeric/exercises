#include <stdio.h>
#include <time.h>

void perfomance(int (*search)(int, int[], int), unsigned long long, int, char[]);
int binsearch(int x, int v[], int n);
int mybinsearch(int x, int v[], int n);

#define MAX_ELEMENT 20000


int main(void) {
    unsigned long testsize = 10000000;
    int element = -1;
    perfomance(binsearch,   testsize, element, "K&R binsearch");
    perfomance(mybinsearch, testsize, element, "New binsearch");

    return 0;
}


void perfomance(int (*search)(int, int[], int),
                unsigned long long l, int n, char name[])
{
    int testdata[MAX_ELEMENT];
    int index;
    int i;
    clock_t time_taken;

    for ( i = 0; i < MAX_ELEMENT; ++i )
        testdata[i] = i;
    
    for ( i = 0, time_taken = clock(); i < l; ++i ) {
        index = search(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;
    
    if (index < 0)
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);
    
    printf("%s took %lu clocks (%lu seconds)\n", name,
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
}


int binsearch(int x, int v[], int n) 
{
    int low = 0;
    int high = n - 1; 
    int mid;
    
    while(low<=high)
    {
       mid = (low + high)/2;
       
       if(x > v[mid])
       low = mid + 1;
       
       else if(x < v[mid])
       high = mid - 1;
       
       else return mid;
    }
    return -1;
}

int mybinsearch(int x, int v[], int n) 
{
    int low = 0;
    int high = n - 1; 
    int mid;
    
    while(low<high)
    {
       mid = (low + high)/2;
       
       if(x > v[mid])
           low = mid + 1; 
       else
           high = mid;
    }
    if (x == v[high])
        return high;
    return -1;
}

