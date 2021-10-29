#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkedList.h"

linkListElement_t* head = 0;

int linkedList_add(dataStructure_t* x)
{
    if (!x) return __LINE__;

    linkListElement_t* newItem = malloc(sizeof(linkListElement_t));
    if (!newItem) return __LINE__;

    newItem->data = *x;

    if (!head)
    {
        //handle case where this is the first element in the list
        head = newItem;
        newItem->next = 0;
    }
    else
    {
        //sort alphabetically by last name...
        linkListElement_t* currentItem = head;

        // 1-off - check to see if the new item is ahead of the head...
        if (strcmp(newItem->data.lastName, currentItem->data.lastName) <= 0)
        {
            //new item is lower
            head = newItem;
            newItem->next = currentItem;
        }
        else
        {
            //traverse the list...
            do
            {
                linkListElement_t* nextItem = currentItem->next;
                if (!nextItem)
                {
                    // at the end of the list... just add here.
                    currentItem->next = newItem;
                    newItem->next = 0;
                    break;
                }
                else
                {
                    if (strcmp(newItem->data.lastName, nextItem->data.lastName) <= 0)
                    {
                        //new item is lower than next item
                        currentItem->next = newItem;
                        newItem->next = nextItem;
                        break;
                    }
                }
            } while (1);
        }
    }
    return 0;
}

int linkedList_print(void)
{
    linkListElement_t* currentItem = head;
    printf("\n\nLIST:\n");
    while (currentItem != 0)
    {
        printf("%s, %s\n",currentItem->data.lastName, currentItem->data.firstName);
        currentItem = currentItem->next;
    }
    return 0;
}

int linkedList_remove(char* lastName)
{
    if (!lastName) return __LINE__;
    if (!head) return __LINE__;

    //sort alphabetically by last name...
    linkListElement_t* currentItem = head;

    // 1-off - check to see if the first item matches...
    if (strcmp(lastName, currentItem->data.lastName) == 0)
    {
        head = currentItem->next;
        free(currentItem);
    }
    else
    {
        //traverse the list...
        do
        {
            linkListElement_t* nextItem = currentItem->next;
            if (!nextItem)
            {
                // at the end of the list... no matches found...
                return __LINE__;
            }
            else
            {
                if (strcmp(lastName, nextItem->data.lastName) == 0)
                {
                    //next item matches
                    currentItem->next = nextItem->next;
                    free(nextItem);
                    break;
                }
            }
            currentItem = nextItem;
        } while (1);
    }
    return 0;
}


int linkedList_destroy(void)
{
    linkListElement_t* currentItem = head;
    while (currentItem != 0)
    {
        linkListElement_t* nextItem = currentItem->next;
        free(currentItem);

        //update currentItem for next loop
        currentItem = nextItem;
    }
    head = 0;
    return 0;
}