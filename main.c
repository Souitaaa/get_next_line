#include "get_next_line.h"


int	main()
{
	int	fd = open("tet.text", 00);
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}