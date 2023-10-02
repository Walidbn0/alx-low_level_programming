#include <stdlib.h>
#include <unistd.h>

/**
 * main- a program that prints its name
 *
 * @argc: holds the number of arguments passed
 * @argv: array pointer that holds the arguments passed
 *
 * Return: Always 0 (Success)
*/

void ft_putstr(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
         write(1, &str[i], 1);
        i++;
    }

}

int main(int argc, char **argv)
{
    int j;
    j = argc;
    ft_putstr(argv[0]);
    write(1, "\n", 1);
    return 0;
}
