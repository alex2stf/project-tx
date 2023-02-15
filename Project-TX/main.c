

#include <tx.h>


void test_1(){
    tx_dump_build_details();
    struct TXObject * r = tx_create_object_string("Object type string created");
    tx_dump(r);
    r = tx_create_object_int(5);
    tx_dump(r);
    struct TXObject z = {STRING, (void *)"inline struct declaration"};
    tx_dump(&z);

    struct TXObject list[2];
    list[0] = *r;
    list[1] = z;

    struct TXObject * list2[2];
    list2[0] = r;
    list2[1] = &z;

    tx_dump(&list2[0]);

    struct TXObject ** list3 = malloc(2 * sizeof(struct TXObject));;
    list3[0] = r;
    list3[1] = &z;

    list3 = realloc(list3, 20 * sizeof(struct TXObject));
    list3[17] = &z;

    tx_dump(&list3[17]);

    printf("\n---- test 1 complete");
}

#define TXObj  struct TXObject

int main()
{

    test_1();

    struct TXArrayList * arraylist = tx_create_array_list(1);

    tx_array_list_add(arraylist, tx_create_object_string("one"));


    int i;
    for(i = 0; i < 10; i++){
        tx_array_list_add(arraylist, tx_create_object_int(i));
    }

    tx_dump_array_list(arraylist, " ");;


    TXObj * list = tx_create_object_list(arraylist);





















    /*
    struct TXObject * r = (TXObject *) malloc(sizeof (struct TXObject));
    r->data = (void *) "xxxx";


    */

    return 0;
}
