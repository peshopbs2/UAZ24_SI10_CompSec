#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#define MAXN 1024

int main()
{
    char hash[MAXN];    
    scanf("%s", hash);
    const char hexDigits[16] = "0123456789abcdef";

    for(char l1 = 'a'; l1 <= 'z'; l1++)
    {
        for(char l2 = 'a'; l2 <= 'z'; l2++)
        {
            for(char l3 = 'a'; l3 <= 'z'; l3++)
            {
                    char input[] = {l1, l2, l3, '\0'};
                    unsigned char result[MD5_DIGEST_LENGTH];
                    char str[2*MD5_DIGEST_LENGTH+1];
                    MD5( (unsigned char*) input, strlen(input), result);
                    for(int i = 0; i < MD5_DIGEST_LENGTH; i++ )
                    {
                        str[i*2]   = hexDigits[(result[i] >> 4) & 0xF];
                        str[i*2+1] = hexDigits[result[i] & 0xF];
                    }
                    str[MD5_DIGEST_LENGTH*2] = '\0';
                    
                    if(strcmp(str, hash) == 0)
                    {
                        printf("%s", input);
                    }

                
            }
        }
    }
    
    return EXIT_SUCCESS;
}
