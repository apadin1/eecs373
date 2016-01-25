#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	
	list_t *old_head = head;
	
	// Iterate through the list until reaching the last element
	while (head != NULL)
	{
		// If the very first element in the list is already greater
		// than the ne being inserted, we must insert at the front
		if (head->index > new_element->index) 
		{
			new_element->next = head;
			return new_element;	// This becomes the new head
		}
		
		// If we have reached the end of the list without yet
		// inserting, the index of new_element must be greater
		// than the remaining elements, and we can insert it
		// on the end.
		else if (head->next == NULL)
		{
			head->next = new_element; // Insert new_element
			new_element->next = NULL; // Point to end of list
			return old_head;
		}

		// If the next element in the list (after the head) has
		// a greater index, we have reached the point in the list
		// where new_element should be inserted
		else if ( head->next->index > new_element->index )
		{
			new_element->next = head->next; // Point to next element
			head->next = new_element;		// Add to list
			return old_head;
		}

		// Otherwise, move to the next element in the list
		else 
			head = head->next;
	}

	return old_head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	// Need to keep track of the previous, current, and next
	// list pointers
	list_t* next_head = NULL;
	list_t* previous_head = NULL;

	// Iterate through the list until you reach the end
	while (head != NULL)
	{
		// Make the next element lead to the current element,
		// and make the previous element lead to the current element
		next_head = head->next;
		head->next = previous_head;
		previous_head = head;
		head = next_head;
	}
	
	return previous_head;
}

