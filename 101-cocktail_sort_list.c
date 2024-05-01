#include "sort.h"

/**
 * swap_node - A function to swap two nodes of a
 * linked list
 *
 * @list: The linked list
 * @node1: The first node of the linked list
 * @node2: The second node of the linked list
 */

void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		(node1->prev)->next = node2;
	else
		*list = node2;
	if (node2->next)
		(node2->next)->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - A sorting scheme using the cocktail shaker algorithm
 *
 * @list: A linked list we want to sort
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *next;
	int swapped, direction;

	node = *list;
	direction = 1;
	do {
		swapped = 0;
		if (direction == 1)
		{
			while (node->next)
			{
				next = node->next;
				if (node->n > (node->next)->n)
				{
					swap_node(list, node, node->next);
					swapped = 1;
					print_list(*list);
				}
				else
				node = next;
			}
		}
		else if (direction == -1)
		{
			while (node->prev)
			{
				next = node->prev;
				if (node->n < (node->prev)->n)
				{
					swap_node(list, node->prev, node);
					swapped = 1;
					print_list(*list);
				}
				else
				node = next;
			}

		}
		direction = direction * -1;
	} while (swapped);
}
