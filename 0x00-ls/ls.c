#include "ls.h"

/**
 * main - create my own ls
 * Return: 0 on success
 */
int main(void)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Error, unable to open the directory!");
		exit(1);
	}

	while ((read = readdir(dir)) != NULL)
	{
		if(read->d_name[0] != '.')
			printf("%s\t", read->d_name);
	}
	printf("\n");

	closedir(dir);

	return (0);
}
