#include "monty.h"

/**
 * add- a functuon that adds the top two elements of the stack.
 * @stack: a struct(stack)
 * @line_number: line number incase of error
 *
 * Return: Nothing
 **/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * nop- a function that does nothing
 * @stack: a struct(stack)
 * @line_number: line number incase of error
 *
 * Return: Nothing
 **/

void nop(stack_t **stack, unsigned int line_number)
{
	void(stack);
	void(line_number);
   /* Do nothing */
}

