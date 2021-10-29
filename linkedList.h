typedef struct
{
    char firstName[20];
    char lastName[20];
} dataStructure_t;

typedef struct linkListElement_t
{
    dataStructure_t data;
    struct linkListElement_t* next;
} linkListElement_t;

int linkedList_add(dataStructure_t* x);
int linkedList_print(void);
int linkedList_destroy(void);
int linkedList_remove(char* lastName);