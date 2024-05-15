#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <openssl/md5.h>
#define MAXN 33
#define DICTIONARY_SIZE 3000
#define BUFFER_SIZE

struct Entry {
    char key[4];
    char hash[33];
} dictionary[DICTIONARY_SIZE];

int main()
{
    char hash[MAXN];
    scanf("%s", hash);
    FILE *file = fopen("dictionary.txt", "r");
    
    int index = 0;
    //TODO: fix null terminator problem
    while (fread(&dictionary[index++], sizeof(struct Entry), 1, file))
    {
    }

    fclose(file);
    
    bool flag = false;
    for(int i = 0; i < index; i++)
    {
        dictionary[i].hash[32] = '\0';
        if(strcmp(hash, dictionary[i].hash) == 0)
        {
            printf("%s %s\n", dictionary[i].key, dictionary[i].hash);
            flag = true;
        }
    }
    
    if(!flag)
    {
        printf("Not found!");
    }
    
    return EXIT_SUCCESS;
}
