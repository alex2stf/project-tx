#include <tx_core.h>

void tx_dump_build_details(){
    printf("tx lib version 0.0.0-alhpa");
};


struct TXObject * new_tx_object(){
    return (struct TXObject *) malloc(sizeof(struct TXObject));
};


struct TXObject * tx_create_object_string(char * data){
    struct TXObject * r = new_tx_object();
    r->type = STRING;
    r->value.s = data;

    return r;
}


struct TXObject * tx_create_object_int(int data){
    struct TXObject * r = new_tx_object();
    r->type = INT;
    r->value.i = data;
    return r;
}


struct TXObject * tx_create_object_list(struct TXArrayList * list){
    struct TXObject * r = new_tx_object();
    r->type = LIST;
    r->value.list = list;
    return r;
}




void tx_dump(struct TXObject *object){
    switch(object->type){
        case STRING:
            printf("\nSTRING: %s", (char *)object->value.s);
            break;
        case INT:
            printf("\nINT:    %i", (int) object->value.i);
            break;
        case LIST:

            break;
    }

};
