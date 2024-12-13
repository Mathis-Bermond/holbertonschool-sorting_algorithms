#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
* order using the insertion sort algorithm
*
* @list: The list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *mnt, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	mnt = (*list)->next;
	while (mnt)
	{
		next = mnt->next;
		prev = mnt->prev;
		while (prev && prev->n > mnt->n)
		{
			prev->next = mnt->next;
			if (mnt->next)
				mnt->next->prev = prev;
			mnt->next = prev;
			mnt->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = mnt;
			else
				*list = mnt;
			prev->prev = mnt;
			prev = mnt->prev;
			print_list(*list);
		}
		mnt = next;
	}
}
