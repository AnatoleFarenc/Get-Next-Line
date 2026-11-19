# Get-Next-Line

A C function that reads a file descriptor one line at a time.

```c
char *get_next_line(int fd);
```

It returns the next line, including the `\n` when there is one. It returns `NULL` at end of file or on error. The caller must `free` each line it gets back.

## Files

| File | Role |
|------|------|
| `get_next_line.c` / `.h` | Reads from one file descriptor at a time |
| `get_next_line_bonus.c` / `.h` | Keeps a separate buffer for each file descriptor (fd < `MAX_FD`, 4096), so you can switch between several open files |
| `get_next_line_utils*.c` | Helper functions: `ft_calloc`, `ft_strchr`, `ft_strlen`, `ft_strjoin` |

## Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		fd = open("file.txt", O_RDONLY);
	char	*line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
```

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 main.c get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE` sets how many bytes each `read` call reads. If you don't set it, it is 1 in the standard version and 10 in the bonus version.
