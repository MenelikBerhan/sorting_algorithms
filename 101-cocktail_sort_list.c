#include "sort.h"

/**
 * forward_swap - a helper function to handle swap while going forward
 * @list: pointer to a doubly linked list of integers to be sorted
 * @current: pointer to the current node being swapped forward
 *
*/
void forward_swap(listint_t **list, listint_t *current)
{
	listint_t *next_node;

	next_node = current->next;
	if (current->prev)
		(current->prev)->next = next_node;
	else
		*list = next_node;
	next_node->prev = current->prev;

	if (next_node->next)
		(next_node->next)->prev = current;
	current->next = next_node->next;

	current->prev = next_node;
	next_node->next = current;
	print_list(*list);
}

/**
 * backward_swap - a helper function to handle swap while going backward
 * @list: pointer to a doubly linked list of integers to be sorted
 * @current: pointer to the current node being swapped backward
 *
*/
void backward_swap(listint_t **list, listint_t *current)
{
	listint_t *prev_node;

	prev_node = current->prev;
	if (prev_node->prev)
		(prev_node->prev)->next = current;
	else
		*list = current;
	current->prev = prev_node->prev;

	if (current->next)
		(current->next)->prev = prev_node;
	prev_node->next = current->next;

	current->next = prev_node;
	prev_node->prev = current;
	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm. Prints the list after
 * each swap.
 * @list: pointer to a doubly linked list of integers to be sorted
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped, swapped_bfr, frwrd = 1;
	listint_t *current;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = *list;
	do {
		swapped = 0;
		while (current)
		{
			swapped_bfr = 0;
			if ((frwrd && !(current->next)) || (!frwrd && !(current->prev)))
				break;
			if (frwrd && current->n > (current->next)->n)
			{
				swapped = swapped_bfr = 1;
				forward_swap(list, current);
			}
			if (!frwrd && current->n < (current->prev)->n)
			{
				swapped = swapped_bfr = 1;
				backward_swap(list, current);
			}
			current = swapped_bfr ? current : (frwrd ? current->next : current->prev);
		}
		frwrd = frwrd ? 0 : 1;
	} while (swapped);
}
