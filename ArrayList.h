#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include<stdbool.h>
struct ArrayList {
    int* data;
    int size;
    int capacity;
};
#define DEFAULT_CAPACITY 10
typedef struct ArrayList ArrayList;
struct ArrayList new_ArrayList();
void addElement(ArrayList*, int);
void addElementByIndex(ArrayList*, int, int);
void removeElementByIndex(ArrayList*, int);
void printfArrayList(ArrayList*);
bool containsElement(ArrayList*, int);
bool equals(ArrayList*, ArrayList*);
void clear(ArrayList*);
#endif  // ARRAYLIST_H_
