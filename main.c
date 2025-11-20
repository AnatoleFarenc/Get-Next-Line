#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *dest;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while ((dest = get_next_line(42)))
	{
		printf("%s", dest);
		free(dest);
	}
	return (0);
}