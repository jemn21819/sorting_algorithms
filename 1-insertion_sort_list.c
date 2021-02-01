#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *cn, *pn, *nn;

	head = *list;
	cn = head->next;

	if (list == NULL)
		return;

	while (cn)
	{
		if (cn->prev != NULL)
		{
			if (cn->n < cn->prev->n)
			{
				pn = cn->prev;
				nn = cn->next;

				cn->prev = pn->prev;
				cn->next = pn;
				if (cn->prev != NULL)
					cn->prev->next = cn;

				pn->prev = cn;
				pn->next = nn;

				if (nn != NULL)
					nn->prev = pn;

				if (cn->prev == NULL)
					head = cn;

				print_list(head);
			}
			else
				cn = cn->next;
		}
		else
			cn = cn->next;
	}
	*list = head;
}
