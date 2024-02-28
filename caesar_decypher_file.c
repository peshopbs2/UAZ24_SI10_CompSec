#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 1000
    
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

char* read_cypher(char* filename)
{
    FILE* file;
    file = fopen(filename, "r");
    
    if(file == NULL)
    {
        printf("Error reading from file.");
        return NULL;
    }
    
    char* cypher = (char*) malloc(MAXN * sizeof(char));
    if(fgets(cypher, MAXN, file) == NULL)
    {
        printf("Error reading from file.");
        
        return NULL;
    }
    
    fclose(file);
    return cypher;
}

int main() {
    printf("Enter filename: ");
    char filename[MAXN];
    scanf("%s", filename);
    
    char* cypher = read_cypher(filename);
    if(cypher == NULL)
    {
        return EXIT_FAILURE;
    }
    
    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    
    char* result = caesar_decypher(cypher, key);
    
    printf("%s", result);
    
    return EXIT_SUCCESS;
}
