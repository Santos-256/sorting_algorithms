#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @num1: A pointer to the first node to swap.
 * @num2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **num1, listint_t *num2)
{
	(*num1)->next = num2->next;
	if (num2->next != NULL)
		num2->next->prev = *num1;
	num2->prev = (*num1)->prev;
	num2->next = *num1;
	if ((*num1)->prev != NULL)
		(*num1)->prev->next = num2;
	else
		*h = num2;
	(*num1)->prev = num2;
	*num1 = num2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *Variab_Name;
	listint_t *insert;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (Variab_Name = (*list)->next; Variab_Name != NULL; Variab_Name = tmp)
	{
		tmp = Variab_Name->next;
		insert = Variab_Name->prev;
		while (insert != NULL && Variab_Name->n < insert->n)
		{
			swap_nodes(list, &insert, Variab_Name);
			print_list((const listint_t *)*list);
		}
	}
}
