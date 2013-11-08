#include <stdio.h>
#include <string.h>

char *fgetln(FILE *stream, size_t *len) {
	char *line;
	size_t line_length;

	*len = (size_t) getline(&line, &line_length, stream);
	if (-1 == *len) {
		*len = 0;
		return NULL;
	}

	*len = line_length;
	return line;
}