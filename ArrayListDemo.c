#include<stdio.h>
#include"ArrayList.h"
int main(int argc, char const* argv[]) {
    ArrayList arr = new_ArrayList();
    printfArrayList(&arr);
    for (int i = 0; i < 10; i++) {
        addElement(&arr, i);
    }
    printfArrayList(&arr);
    for (int i = 0; i < 20; i++) {
        addElement(&arr, i);
    }
    printfArrayList(&arr);
    removeElementByIndex(&arr, arr.size - 1);
    removeElementByIndex(&arr, arr.size - 1);
    removeElementByIndex(&arr, arr.size - 1);
    removeElementByIndex(&arr, arr.size - 1);
    printfArrayList(&arr);
    addElementByIndex(&arr, arr.size, 100);
    printfArrayList(&arr);
    for (int i = 1; i < 100; i++) {
        addElementByIndex(&arr, 0, i);
    }
    printfArrayList(&arr);
    printf("%d %d\n", arr.size, arr.capacity);
    printf("%d\n", containsElement(&arr, 1000));
    ArrayList a;
    printf("%d\n", equals(&arr, &a));
    clear(&arr);
    printfArrayList(&arr);
    return 0;
}
