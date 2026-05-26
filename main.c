#include <stdio.h>

int main()
{
    char entry[255];
    while (1)
    {
        fgets(entry, 255, stdin);
        printf(entry);
    }
}