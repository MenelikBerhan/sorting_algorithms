#include "sort.h"

/**
 * insertion_sort_list_helper - Goes through a doubly linked list backwards
 * starting from node `next_node`, and swaps it if a previous node has
 * a greater n field value.
 * @list: pointer to a doubly linked list of integers to be sorted
 * @next_node: node swapped with current and starting point of backward loop
 *
 */
void insertion_sort_list_helper(listint_t **list, listint_t *next_node)
{
	listint_t *prev_node;

	prev_node = next_node->prev;
	while (prev_node && prev_node->n > next_node->n)
	{
		if (prev_node->prev)
			(prev_node->prev)->next = next_node;
		else
			*list = next_node;
		next_node->prev = prev_node->prev;

		(next_node->next)->prev = prev_node;
		prev_node->next = next_node->next;

		prev_node->prev = next_node;
		next_node->next = prev_node;

		prev_node = next_node->prev;
		print_list(*list);
	}
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm. Prints the list after each swap.
 * @list: pointer to a doubly linked list of integers to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node;
	int swapped;

	if (!list || !(*list))
		return;

	current_node = *list;
	while (current_node->next)
	{
		swapped = 0;
		if (current_node->n > (current_node->next)->n)
		{
			swapped = 1;
			next_node = current_node->next;

			if (current_node->prev)
				(current_node->prev)->next = next_node;
			else
				*list = next_node;
			next_node->prev = current_node->prev;

			if (next_node->next)
				(next_node->next)->prev = current_node;
			current_node->next = next_node->next;

			current_node->prev = next_node;
			next_node->next = current_node;
			print_list(*list);

			insertion_sort_list_helper(list, next_node);
		}
		current_node = swapped ? current_node : current_node->next;
	}
}
