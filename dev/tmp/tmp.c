#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main()
{
	int beforepipe[2];

	printf("1");
	fflush(stdout);
	if (pipe(beforepipe) == -1)
	{
		perror("dang");
		return (1);
	}
	printf("2");
	fflush(stdout);
	if (dup2(beforepipe[0], 2) == -1)
	{
		perror("damn");
		return (2);
	}
	printf("3");
	fflush(stdout);
	if (write(beforepipe[1], "hey!", 4) == -1)
	{
		printf("5");
		fflush(stdout);
		perror("nnnng");
		return (3);
	}
	printf("4");
	fflush(stdout);
}
