#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
	(void)argc;
	if(argv[1] == NULL) {
		const char *error = "no file path provided\n";
		write(1, error, strlen(error));
		return 1;
	}

	int fd = open(argv[1], O_RDONLY);
	struct stat buf;
	fstat(fd, &buf);
	char *file = calloc(buf.st_size, sizeof(char));
	read(fd, file, buf.st_size);
	write(1, file, buf.st_size);
	return 0;
}
