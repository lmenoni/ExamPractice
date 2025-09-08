
#ifndef ARGO_H
#define ARGO_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

typedef struct  pair {
	char *key;
	json value;
} pair;

void print_ast(json j);
void print_json_compact(json j);
int argo(json *dst, FILE *stream);
json    parse_map(FILE *stream);
char    *parse_string(FILE *stream);
int     parse_integer(FILE *stream);
int	peek(FILE *stream);
void	unexpected(FILE *stream);
int	accept(FILE *stream, char c);
int	expect(FILE *stream, char c);

#endif