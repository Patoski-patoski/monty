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



/**
 * pint- a function to print first element in a stack
 * @stack: a struct(stack)
 * @line_number: in case of error! the line number
 *
 * Return: Nothing
 **/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}


/**
 * pop- a function to remove the top element of the stack.
 * @stack: a struct(stack)
 * @line_number: the element to be pushed
 *
 * Return: Nothing
 **/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * swap- a function to swaps the top two elements of the stack.
 * @stack: a struct(stack)
 * @line_number: the line number(in case of error)
 *
 * Return: Nothing
 **/

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

