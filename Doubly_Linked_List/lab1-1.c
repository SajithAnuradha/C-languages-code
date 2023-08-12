// general purpose standard C lib
#include <stdio.h>
// #include <stdlib.h>

#include <string.h> // stdlib includes malloc() and free()

// user-defined header files
#include "node.h"

// macros

#define INSERT_BEFORE 1
#define INSERT_AFTER 2
#define DELETE_NODE 3
#define DELETE_LIST 4

// function prototypes
void print_list(list *lst);
void run(list *lst);

int main()
{
    list *lst = (list *)malloc(sizeof(list));
    lst->head = NULL;

    run(lst);
    print_list(lst);
    free(lst);
    return 0;
}

// parse the input
void run(list *lst)
{
    char *input = (char *)malloc(sizeof(char) * 20);
    printf("Enter a list of words separated by commas: ");
    scanf("%s", input);

    char *token = strtok(input, ",");
    int i = 0;
    while (token != NULL)
    {
        insert_node_before(lst, i, token);

        i++;
        token = strtok(NULL, ",");
    }

    // free(input);
    int query = 0;
    // printf("%s\n", "query");
    scanf("%d", &query);
    while (query != 0)
    {
        // read the op code and the values
        int index;
        scanf("%d", &index);
        char *word = (char *)calloc(MAX_WORD_LENGTH, sizeof(char));
        switch (query)
        {
        case INSERT_BEFORE:
            scanf("%s", word);
            insert_node_before(lst, index, word);
            break;

        case INSERT_AFTER:
            scanf("%s", word);
            insert_node_after(lst, index, word);
            break;
        case DELETE_NODE:
            delete_node(lst, index);
            break;
        }
        scanf("%d", &query);
    }
}

// Print the list contents

void print_list(list *lst)
{
    node *current = lst->head;
    if (current != NULL)
    {
        // print the list with space after each word
        do
        {
            printf("%s ", current->word);
            current = current->next;
        } while (current != lst->head);
    }

    else
    {
        printf("The list is empty.\n");
    }
}
