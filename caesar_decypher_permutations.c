#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1024

char* caesar_decypher(char* cypher, int key)
{
    int length = strlen(cypher);
    char* result = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(cypher[i] != '\0')
    {
        result[i] = ((cypher[i] - 'A' - key + 26) % 26) + 'A';
        i++;
    }
    result[i] = '\0';
    
    return result;
}


int main() {
    char cypher[MAXN];
    scanf("%s", cypher);
    
    for(int i = 0; i < 26; i++)
    {
        char* text = caesar_decypher(cypher, i);
        printf("Key %d, message: %s\n", i, text);
    }
    
    return EXIT_SUCCESS;
}
