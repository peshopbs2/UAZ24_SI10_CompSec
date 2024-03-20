#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_decrypt(char* cipher, char* key)
{
    int length = strlen(cipher);
    int key_length = strlen(key);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0;
    while(cipher[index] != '\0')
    {
        int shift = tolower(key[index % key_length]) - 'a';
        
        if(islower(cipher[index]))
        {
            plaintext[index] = 'a' + (cipher[index] - 'a' - shift + 26) % 26; //?
        }
        else if(isupper(cipher[index]))
        {
            plaintext[index] = 'A' + (cipher[index] - 'A' - shift + 26) % 26; //?
        }
        else
        {
            plaintext[index] = cipher[index];    
        }
        index++;
    }
    plaintext[index] = '\0';
    return plaintext;
}

int main()
{
    char cipher[MAXN];
    scanf("%s",  cipher);
    
    char key[MAXN];
    scanf("%s", key);
    
    char* plaintext = vigenere_decrypt(cipher, key);

    printf("Plaintext: %s", plaintext);
    return EXIT_SUCCESS;
}
