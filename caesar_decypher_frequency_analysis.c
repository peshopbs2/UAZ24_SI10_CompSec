#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1024
#define LETTER_COUNT 26
#define COMMON_COUNT 10

char* caesar_decypher(char* cypher, int key)
{
    int length = strlen(cypher);
    char* result = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(cypher[i] != '\0')
    {
        result[i] = ((cypher[i] - 'a' - key + 26) % 26) + 'a';
        i++;
    }
    result[i] = '\0';
    
    return result;
}

int get_max_index(int* counts)
{
    int max_index = 0;
    for(int i = 0; i < LETTER_COUNT; i++)
    {
        if(counts[i] > counts[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}
char most_common_letter(char * cypher)
{
    int* counts = (int*) malloc(LETTER_COUNT * sizeof(int));
    memset(counts, 0, LETTER_COUNT * sizeof(int));
    int position = 0;
    while(cypher[position] != '\0')
    {
        int index = tolower(cypher[position]) - 'a';
        if(index < 0 || index >= LETTER_COUNT)
        {
            //if the symbol is not a letter, just ignore it.
            position++;
            continue;
        }
        
        counts[index]++;
        position++;
    }
    int max_index = get_max_index(counts);
    
    return max_index + 'a';
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
    
    char letters[COMMON_COUNT] = {'e', 't', 'a', 'o', 'i',
        'n', 's', 'r', 'h', 'l'};
    
    for(int i = 0; i < COMMON_COUNT; i++)
    {
        printf("The common letter is: %c\n", letters[i]);
        int key = most_common_letter(cypher) - letters[i];
        printf("The key is: %d\n", key);
        char* text = caesar_decypher(cypher, key);
        printf("Message: %s\n", text);
        printf("------------------------------------\n");
    }
    
    return EXIT_SUCCESS;
}
