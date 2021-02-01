#include "sort.h"

/**
 * swap_node - Swaps the nodes
 * @prev: previous node
 * @nod: node
 * @head: doubly linked list
 */
void swap_node(listint_t *prev, listint_t *nod, listint_t **head)
{
	listint_t *tmp;

	tmp = prev->prev;
	if (tmp)
		tmp->next = nod;
	nod->prev = tmp;
	prev->prev = nod;
	prev->next = nod->next;
	nod->next = prev;
	if (prev->next != NULL)
		prev->next->prev = prev;
	if (nod->prev == NULL)
		*head = nod;
	print_list(*head);
}

/**
 * cocktail_sort_list - sort a doubly linked list in ascending order
 * @list: Head to doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int x = 1, fst = 0, lst = 0, i;

	if (list == NULL)
		return;
	head = *list;

	while (head->next != NULL)
		head = head->next, lst++;
	head = *list;

	while (x == 1)
	{
		i = fst;
		while (i < lst)
		{
			if (head->n > head->next->n)
			{
				swap_node(head, head->next, list);
				x = 1;
			}
			else
				head = head->next;
			i++;
		}
		i = lst, x = 0;
		while (i > fst)
		{
			if (head->n < head->prev->n)
			{
				swap_node(head->prev, head, list);
				x = 1;
			}
			else
				head = head->prev;
			i--;
		}
		fst++;
	}
}
