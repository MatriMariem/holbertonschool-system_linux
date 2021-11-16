#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
 * main - create my own ls
 * Return: 0 on success
 */
int main(int ac, char **av)
{
  DIR *dir;
  char *path;


  struct dirent *read;
  path = ac > 1 ? av[1] : ".";

  dir = opendir(path);
	if (dir == NULL)
	{
    if (errno == EACCES)
    {
      fprintf(stderr, "%s: cannot open directory \'%s\': ", av[0], av[1]);
    }
    else
    {
      fprintf(stderr, "%s: cannot access \'%s\': ", av[0], av[1]);
    }
    perror("");
		exit(errno);
	}

	while ((read = readdir(dir)) != NULL)
			printf("%s\n", read->d_name);


	closedir(dir);

	return (0);
}
