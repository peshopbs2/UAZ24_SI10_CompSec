#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_encrypt(char* plaintext, char* key)
{
    int length = strlen(plaintext);
    int key_length = strlen(key);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    int index = 0;
    while(plaintext[index] != '\0')
    {
        int shift = tolower(key[index % key_length]) - 'a';
        
        if(islower(plaintext[index]))
        {
            cipher[index] = 'a' + (plaintext[index] - 'a' + shift) % 26;
        }
        else if(isupper(plaintext[index]))
        {
            cipher[index] = 'A' + (plaintext[index] - 'A' + shift) % 26;
        }
        else
        {
            cipher[index] = plaintext[index];    
        }
        index++;
    }
    cipher[index] = '\0';
    return cipher;
}

int main()
{
    char plaintext[MAXN];
    scanf("%s", plaintext);
    
    char key[MAXN];
    scanf("%s", key);
    
    char* result = vigenere_encrypt(plaintext, key);

    printf("Result: %s", result);
    return EXIT_SUCCESS;
}
