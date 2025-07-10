#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 1, j;
    char c;

    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                c = argv[i][j];

                // Mettre en minuscule toute lettre
                if (c >= 'A' && c <= 'Z')
                    c = c + 32;

                // Si c'est une lettre et la prochaine n'est pas une lettre => mettre en majuscule
                if ((c >= 'a' && c <= 'z') &&
                    !((argv[i][j + 1] >= 'a' && argv[i][j + 1] <= 'z') ||
                      (argv[i][j + 1] >= 'A' && argv[i][j + 1] <= 'Z')))
                    c = c - 32;

                write(1, &c, 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
        }
    }
    return 0;
}