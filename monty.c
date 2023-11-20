#define _GNU_SOURCE
#include "monty.h"

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
	FILE *fptr;
	int line_num = 1;
	size_t len = 0;
	char *lineptr = NULL;
	ssize_t read;
	char *line;
	/*	stack_t *stack = NULL; */

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	openFile(argv[1]);

	while ((read = getline(&lineptr, &len, fptr)) != -1)
	{
		line = parse_line(lineptr);
		if (line == NULL || line[0] == '#')
		{
			line_num++;
			continue;
		}

		char *delim = " ";
		char *opcode = line;
		if (opcode == NULL)
		{
			fprintf(stderr, "Error opcode!\n");
			exit(EXIT_FAILURE);
		}

		char *num = strtok(NULL, delim);
		int value = 0;

		if (num != NULL)
			value = atoi(num);

		executeInstruction(opcode, value, line_num);

		line_num++;
	}

	fclose(fptr);
	free(lineptr);

	return (0);
}

void openFile(char *filename)
{

	FILE *fptr = fopen(filename, "r");
	if (fptr == NULL) {
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/*file = fptr;*/
}

void executeInstruction(char *opcode, int value, int line_num)
{
	instruction_t instruct[] =
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	int len = sizeof(instruct) / sizeof(instruct[0]);
	int j, found = 0;

	for (j = 0; j < len; j++) {
		if (strcmp(opcode, instruct[j].opcode) == 0) {
			instruct[j].f(&stack, value);
			found = 1;
			break;
		}
	}

	if (!found) {
		fprintf(stderr,"L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
}


/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}
