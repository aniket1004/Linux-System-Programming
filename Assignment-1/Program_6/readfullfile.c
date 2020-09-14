#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

int main(int argc, char *argv[])
{
	int fd = 0;
	char buf[BUFFER_SIZE] = {'\0'};
	if (argc != 2)
	{
		printf ("Invalid number of arguments\n");
		printf ("Use --help\n");
		return -1;
	}
	else
	{
		if (strcmp(argv[1],"--help") == 0)
		{
			printf ("Usage : executable_file filename\n");
			printf ("Example : %s demo.txt\n",argv[0]);
			return -1;
		}

		fd = open(argv[1],O_RDONLY);	
		if (fd == -1)
		{
			printf ("%s\n",strerror(errno));
			return -1;
		}
		while ((read(fd,&buf,BUFFER_SIZE) > 0))
		{
			printf("%s",buf);
		}
		printf ("\n");
		if (close(fd) == -1)
		{
			printf ("%s\n",strerror(errno));
			return -1;
		}
	}
	return 0;
}
