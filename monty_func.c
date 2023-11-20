#include "monty.h"

/**
 * push- a function to push element into a stack
 * @stack: a struct(stack)
 * @value: the element to be pushed
 *
 * Return: Nothing
 **/

void push(stack_t **stack, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall- a function to push element into a stack
 * @stack: a struct(stack)
 * @line_number: unused
 *
 * Return: Nothing
 **/

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
