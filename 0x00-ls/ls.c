#include "ls.h"

/**
 * main - create my own ls
 * Return: 0 on success
 */
int main(void)
{
	int i;
	DIR *dir;
	struct dirent *read;

	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Error, unable to open the directory!");
		exit(1);
	}

	i = 0;
		while ((read = readdir(dir)) != NULL)
		{
			if (i)
			{
				printf(" ");
			}
			printf("%s", read->d_name);

			i++;
		}
	printf("\n");

		closedir(dir);

	return (0);
}
