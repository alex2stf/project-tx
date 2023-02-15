#ifndef TX_CORE_
#define TX_CORE_

#include <stdio.h>
#include <stdlib.h>



struct TXArrayList;

struct TXObject {

    enum {
        STRING = 1,
        INT,
        LIST,
        LINKED_LIST,
        MAP,
        FUNCTION,
        DATE
    } type;

    union {
        int i;
        char * s;
        struct TXObject * node;
        struct TXArrayList * list;

    } value;
};


struct TXArrayList {
    unsigned int size;
    unsigned int capacity;
    struct TXObject ** items;
};


//tx_core.c
struct TXObject * tx_create_object_string(char * data);
struct TXObject * tx_create_object_int(int data);
struct TXObject * tx_create_object_list(struct TXArrayList * array_list);
void tx_dump(struct TXObject * object);
void tx_dump_build_details();

//tx_list.c
struct TXArrayList * tx_create_array_list(int init_capacity);
void tx_array_list_add(struct TXArrayList * data, struct TXObject * item);
void tx_dump_array_list(struct TXArrayList * object, char * tab);









#endif // TX_CORE
