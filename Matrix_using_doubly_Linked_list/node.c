// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <string.h> // includes strlen(), memcpy()
#include <ctype.h>	// includes toupper(), tolower()

// user-defined header files
#include "node.h" // do not modify this file

// put your function prototypes for additional helper functions below:

// implementation
void insert_node_before(list *lst, int index, char *word)
{
	// Create a new node
	node *newNode = (node *)malloc(sizeof(node));

	if (newNode == NULL)
	{
		printf("Memory allocation failed.\n");
		return;
	}
	// newNode->word = (char *)malloc(strlen(word) + 1);
	newNode->word = word; // Assign the word pointer directly
	// strcpy(newNode->word, word);
	//  If the list is empty, make newNode the head
	if (lst->head == NULL)
	{

		newNode->prev = newNode;
		newNode->next = newNode;
		lst->head = newNode; // if the only node is head so, the previous and next also be itself.

		return;
	}

	else
	{

		// Find the node before which to insert the new node
		node *current = lst->head;

		if (index >= 0)
		{

			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
		}
		else
		{
			for (int i = 0; i < -index; i++)
			{
				current = current->prev;
			}
		}
		// Insert the new node before the current node
		current->prev->next = newNode;
		newNode->prev = current->prev;
		newNode->next = current;
		current->prev = newNode;
	}
}

void insert_node_after(list *lst, int index, char *word)
{

	int afterIndex = index + 1;

	// Call the insert_node_before function with the adjusted index

	insert_node_before(lst, afterIndex, word);
}

char *list_to_sentence(list *lst)
{
	if (lst->head == NULL)
	{
		return NULL;
	}

	// Calculate the length of the sentence
	int totalLength = 0;
	node *current = lst->head;
	do
	{
		totalLength += strlen(current->word);
		current = current->next;
	} while (current != lst->head);

	// Allocate memory for the sentence
	char *sentence = (char *)malloc(totalLength + 1);
	if (sentence == NULL)
	{
		printf("Memory allocation failed.\n");
		return NULL;
	}

	// Build the sentence by concatenating words
	sentence[0] = '\0'; // Initialize the sentence as an empty string
	current = lst->head;
	do
	{
		strcat(sentence, current->word);
		current = current->next;
		if (current != lst->head)
		{
			strcat(sentence, " "); // Add a space between words
		}
	} while (current != lst->head);

	return sentence;
}

void delete_node(list *lst, int index)
{
	// Find the node to delete
	node *current = lst->head;
	if (index >= 0)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}
	else
	{
		for (int i = 0; i < -index; i++)
		{
			current = current->prev;
		}
	}
	// Update the neighboring nodes to bypass the current node
	current->prev->next = current->next;

	current->next->prev = current->prev;

	// If the head is being deleted, update the head
	if (current == lst->head)
	{
		lst->head = current->next;
	}

	// Free memory for the word and the node
	// free(current->word);
	free(current);
}
// void delete_node(list *lst, int index)
// {
// 	if (index >= 0)
// 	{
// 		node *temp = lst->head;
// 		for (int i = index; i > 0; i--)
// 		{
// 			temp = temp->next;
// 		}

// 		if (temp == lst->head)
// 		{
// 			lst->head = temp->next;
// 			lst->head->prev = temp->prev;
// 			temp->prev->next = lst->head;
// 		}

// 		else
// 		{
// 			temp->prev->next = temp->next;
// 			temp->next->prev = temp->prev;
// 		}
// 		free(temp);
// 	}
// 	else
// 	{
// 		node *temp = lst->head;
// 		for (int i = index; i < 0; i++)
// 		{
// 			temp = temp->prev;
// 		}
// 		temp->prev->next = temp->next;
// 		temp->next->prev = temp->prev;
// 		free(temp);
// 	}
// }

void delete_list(list *lst)
{
	node *current = lst->head;
	if (current != NULL)
	{
		while (1)
		{
			node *nextnode = current->next;
			free(current->word);
			free(current);
			current = nextnode;
			if (current == lst->head)

			{
				free(current->word);
				free(current);
				break;
			}
		}
	}
	else
	{
		printf("%s\n", "The list is empty");
	}
}

// create a main
/*
int main()
{
	// create string list

	list *lst = (list *)malloc(sizeof(list));
	lst->head = NULL;

	// add some words for it
	insert_node_after(lst, 0, " Sri ");
	insert_node_after(lst, 0, " Lanka ");
	insert_node_after(lst, 1, " is ");
	insert_node_after(lst, 2, " a ");
	insert_node_after(lst, 3, " country ");
	insert_node_before(lst, 4, " small ");
	insert_node_after(lst, -1, " in ");
	insert_node_after(lst, -1, " south ");
	insert_node_after(lst, -1, " Asia ");
	delete_node(lst, 5);
	insert_node_before(lst, 5, " nation ");
	delete_node(lst, 0);
	// insert_node_after(lst, -1, " question ");
	//  insert_node_before(lst, -1, " lazy ");
	// delete_node(lst, -3);
	// insert_node_after(lst, -1, " dog ");
	//   delete_list(lst);

	// print the list
	node *current = lst->head;

	if (current != NULL)
	{
		do
		{
			printf("%s", current->word);
			current = current->next;
		} while (current != lst->head);
		printf("\n"); // Print a newline at the end to separate from other outputs
	}

	// Clean up memory
	delete_list(lst);
	free(lst);

	return 0;
}
*/