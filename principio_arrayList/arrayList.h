#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED
typedef struct
{
    int size;
    int r_size;
    void* pElements;
}ArrayList;


#endif // ARRAYLIST_H_INCLUDED
#define INIT_SIZE 10
ArrayList* al_new(void);
int al_add (ArrayList* pArray, void* pElement);
