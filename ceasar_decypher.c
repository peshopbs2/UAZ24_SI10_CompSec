#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* caesar_decypher(char* cypher, int key)
{
    int length = strlen(cypher);
    char* result = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(cypher[i] != '\0')
    {
        //TODO: check for lower, upper, digits and special
        result[i] = ((cypher[i] - 'A' - key + 26) % 26) + 'A';
        i++;
    }
    result[i] = '\0';
    
    return result;
}

int main() {
    const int MAXN = 1000;
    char cypher[MAXN];
    scanf("%s", cypher);
    
    int key;
    printf("Enter key:");
    scanf("%d", &key);
    
    char* result = caesar_decypher(cypher, key);
    
    printf("%s", result);
    
    return EXIT_SUCCESS;
}
