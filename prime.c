#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool primeCheck(int x)
{
    if(x < 2)
    {
        return false;
    }
    
    bool prime = true;
    for(int i = 2; i <= x / 2; i++)
    {
        if(x % i == 0)
        {
            prime = false;
        }
    }
    
    return prime;
}

int main()
{
    int x;
    scanf("%d", &x);
    
    bool prime = primeCheck(x);
    
    if(prime)
    {
        printf("The number %d is prime", x);
    }
    else
    {
        printf("The number %d is not prime", x);
    }
    
    return EXIT_SUCCESS;
}
