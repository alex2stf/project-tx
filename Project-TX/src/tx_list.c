
#include <tx_core.h>

// Initial capacity of the arraylist
#define TX_ARRAYLIST_INITIAL_CAPACITY 4


struct TXArrayList * tx_create_array_list(int init_capacity){
    struct TXArrayList * r = malloc(sizeof(struct TXArrayList));
    r->size = 0;
    r->capacity = init_capacity;
    r->items = malloc(sizeof(struct TXArrayList) * init_capacity);
    return r;
}

void tx_arraylist_allocate(struct TXArrayList * data, unsigned int size){
    if (size > data->capacity) {
        unsigned int new_capacity = data->capacity;
        while (new_capacity < size) {
            new_capacity *= 2;
        }
        data->items = realloc(data->items, sizeof(struct TXObject) * new_capacity);
        data->capacity = new_capacity;
    }
}

void tx_array_list_add(struct TXArrayList * data, struct TXObject * item){
    tx_arraylist_allocate(data, data->size + 1);
    data->items[data->size++] = item;
}


void tx_dump_array_list(struct TXArrayList * list, char * tab){
    int i;
    for(i = 0; i < list->size; i++){
        tx_dump(list->items[i]);
    }
}
