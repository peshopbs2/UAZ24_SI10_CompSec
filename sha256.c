#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>
#define MAXN 1024

void print_sha256(unsigned char* hash)
{
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main()
{
    char input[MAXN];    
    scanf("%s", input);
    
    unsigned char result[SHA256_DIGEST_LENGTH];
    SHA256( (unsigned char*) input, strlen(input), result);
    
    printf("SHA256(%s) = ", input);
    print_sha256(result);
    
    return EXIT_SUCCESS;
}
