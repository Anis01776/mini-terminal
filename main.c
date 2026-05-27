#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

void listDirectory(const char *basePath)
{
    struct dirent *reading;
    DIR *rep = opendir(basePath);
    while (reading = readdir(rep))
    {
        printf("%s\n", reading->d_name);
    }
    closedir(rep);
}
int main()
{
    char entry[255];
    while (1)
    {
        fgets(entry, 255, stdin);
        entry[strcspn(entry, "\n")] = '\0'; // input remove the next line
        char *token = strtok(entry, " ");
        if (token != NULL && strcmp(token, "ls") == 0)
        {
            listDirectory(".");
        }
        else
        {
            printf("couldn't find the command\n");
        }
        int argument = 0;
        int size = 1;
        char **commande = malloc(size * sizeof(commande));
        while (token != NULL)
        {
            commande[argument] = token;
            token = strtok(NULL, " ");
            argument++;
            if (token != NULL)
            {
                size++;
                commande = realloc(commande, size * sizeof(commande));
            }
        }
        for (int i = 0; i < size; i++)
        {
            printf("%s\n", commande[i]);
        }
        printf("%d", argument);
        free(commande);
    }
}