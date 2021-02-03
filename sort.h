#ifndef SHORT_H
#define SHORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototypes */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);



void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

void _recursion(int *array, size_t min, size_t max, size_t size);
void swap(int *array, int i, int j);

/* Advanced Tasks */
void shell_sort(int *array, size_t size);

void swap_node(listint_t *prev, listint_t *nod, listint_t **head);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void make_heap(int *array, size_t size);
void sift_down(int *array, size_t root, size_t end, size_t size);
void radix_sort(int *array, size_t size);
unsigned int pow_10(unsigned int power);
unsigned int count_sort(int *array, size_t size, unsigned int digit);
void bitonic_sort(int *array, size_t size);
void bitonic_compare(char up, int *array, size_t size);
void bitonic_merge(char up, int *array, size_t size);
void bit_sort(char up, int *array, size_t size, size_t t);
void quick_sort_hoare(int *array, size_t size);
void _sorting(int *array, ssize_t min, ssize_t max, size_t size);
size_t _partition(int *array, ssize_t min, ssize_t max, size_t size);


#endif
