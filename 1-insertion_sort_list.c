#include "sort.h"

/**
 * insertion_sort_list - use insertion method to sort out node list
 *
 * @list : the sorted list to be printed
 */

void insertion_sort_list(listint_t **list)
{
listint_t *current, *insertion;
if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;
current = (*list)->next;
while (current != NULL)
{
insertion = current;
while (insertion->prev != NULL && insertion->n < insertion->prev->n)
{
listint_t *tmp_next = insertion->next;
listint_t *tmp_prev = insertion->prev;
if (tmp_prev->prev != NULL)
tmp_prev->prev->next = insertion;
else
*list = insertion;
insertion->prev = tmp_prev->prev;
insertion->next = tmp_prev;
tmp_prev->prev = insertion;
tmp_prev->next = tmp_next;
if (tmp_next != NULL)
tmp_next->prev = tmp_prev;
print_list(*list);
}
current = current->next;
}
}
