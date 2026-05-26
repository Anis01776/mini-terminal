#include <stdio.h>
#include <string.h>
#include <dirent.h>

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
            printf("first command\n");
        }
        else
        {
            printf("wrong command\n");
        }
        while (token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }
}