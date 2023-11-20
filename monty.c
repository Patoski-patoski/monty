#define _GNU_SOURCE
#include "monty.h"

/**
 * main - the entry point of the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 **/

int main(int argc, char *argv[])
{
	FILE *fptr;
	int line_num = 1;
	size_t len = 0;
	char *line, *lineptr = NULL;
	ssize_t read;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = openFile(argv[1]);
	while ((read = getline(&lineptr, &len, fptr)) != -1)
	{
		char *opcode, *num;
		int value = 0;

		line = parse_line(lineptr);

		if (line == NULL || line[0] == '#')
		{
			line_num++;
			continue;
		}
		opcode = line;
		if (opcode == NULL)
		{
			fprintf(stderr, "Error opcode!\n");
			exit(EXIT_FAILURE);
		}
		num = strtok(NULL, " ");
		if (num != NULL)
			value = atoi(num);
		exec_instruct(opcode, value, line_num, &stack);
		line_num++;
	}
	fclose(fptr);
	free(lineptr);
	return (0);
}

/**
 * openfile- a function to open a file
 * @filename: the filename
 *
 * Return: Pointer to the file
 **/

FILE *openFile(char *filename)
{
	FILE *fptr = fopen(filename, "r");

	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fptr);
}

/**
 * exec_instruct- a function to execute instruction
 *
 * @opcode: the opcode:
 * @line_num: the line number
 * @value: the value of the instruction
 * @stack: a pointer to a stack (struct)
 *
 * Return: 0
 **/

void exec_instruct(char *opcode, int value, int line_num, stack_t **stack)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
<<<<<<< HEAD
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
<<<<<<< HEAD
=======
>>>>>>> parent of 500694c... add: pop function
=======
>>>>>>> ad3b50b5edefc14794b49c38db1df20d72f7ec17
		{NULL, NULL},
	};

	int len = sizeof(instruct) / sizeof(instruct[0]);
	int j, found = 0;

	for (j = 0; j < len; j++)
	{
		if (strcmp(opcode, instruct[j].opcode) == 0)
		{
			instruct[j].f(stack, value);
			found = 1;
			break;
		}
	}

	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * parse_line- a function to parse the line
 * @line: the line to be parsed
 *
 * Return: a poiner to characters
 **/

char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}
