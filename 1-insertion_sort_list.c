#include "sort.h"


void insert_node(listint_t **head, listint_t *node)
{
	listint_t *moving_node;

	if (*head == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		*head = node;
	}
	else
	{
		moving_node = *head;

		while (moving_node->next != NULL)
			moving_node = moving_node->next;

		node->next = NULL;
		node->prev = moving_node;
		moving_node->next = node;
	}
}

void swap_node(listint_t *first_node, listint_t *second_node)
{
	listint_t *temp;

	if (first_node == second_node)
		return;
	temp = malloc(sizeof(listint_t));
	if (!temp)
		return;
	temp = {.n = first_node->n, .next = , .prev = };
}

/**
 * insertion_sort_list - An implementation of the insertion sorting algorithm
 *
 * @list: A singly linked list of the array to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *moving_node;
	listint_t *smallest;
	listint_t *sorted;
	listint_t *next_node;

	sorted = NULL;
	moving_node = *list;
	next_node = moving_node;
	while (moving_node)
	{
		next_node = moving_node->next;
		smallest = moving_node;
		while (next_node)
		{
			next_node = next_node->next;
			if (smallest->n > next_node->)
				swap_node(&smallest, &next_node);
		}
		insert_node(tail_of_sorted, smallest);
		moving_node = smallest->next;
	}

}
