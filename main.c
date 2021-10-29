#include <stdio.h>
#include "linkedList.h"

int main(void)
{
    printf("linked list demo\n");
    linkedList_print();
    linkedList_add(&(dataStructure_t){"jake","romano"});
    linkedList_add(&(dataStructure_t){"fred","smith"});
    linkedList_add(&(dataStructure_t){"mike","daniels"});
    linkedList_add(&(dataStructure_t){"gloria","dinoso"});
    linkedList_remove("romano");
    linkedList_print();
    linkedList_destroy();
    linkedList_print();
}
