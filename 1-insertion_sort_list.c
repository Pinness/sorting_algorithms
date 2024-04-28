#include "sort.h"

/**
 * insert_node - A function to insert a node at
 * the appropraite position in a doubly linked
 * list
 *
 * @tail: The tail of the doubly linked list
 * @node: The node we want to insert
 */

void insert_node(listint_t *list, listint_t *tail, listint_t *node)
{
	listint_t *temp;

	if (node)
	{
		while (tail)
		{
			if (node->n < tail->n)
			{
				temp = node;
				tail->next = node->next;
				tail->prev = node->prev;
				node->next = temp->next;
				node->prev = temp->prev;
				print_list(list);
			}
			tail = tail->prev;
		}
	}
}

/**
 * insertion_sort_list - An implementation of the insertion sorting algorithm
 *
 * @list: A singly linked list of the array to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *moving;
	listint_t *next;
	listint_t *sorted_tail;

	sorted_tail = *list;
	moving = sorted_tail->next;
	while (moving)
	{
		next = moving->next;
		insert_node(*list, &sorted_tail, moving);
		moving = next;
	}
}
