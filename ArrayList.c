#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ArrayList {
    int* data;
    int size;
};
typedef struct ArrayList ArrayList;

struct ArrayList new_ArrayList() {
    ArrayList arr;
    arr.size = 10;
    arr.data = malloc(sizeof(int) * 10);
    memset(arr.data, 0, arr.size * sizeof(int));
    return arr;
}

void addElement(ArrayList* arr, int e) {
    arr->size++;
    int* tem = arr->data;
    arr->data = malloc(sizeof(int) * arr->size);
    memcpy(arr->data, tem, sizeof(int) * (arr->size - 1));
    arr->data[arr->size - 1] = e;
    free(tem);
}

void removeElementByIndex(ArrayList* arr, int index) {
    if (index >= arr->size || index < 0) return;
    int* tem = arr->data;
    arr->size--;
    arr->data = malloc(sizeof(int) * arr->size);
    if (index == 0) {
        memcpy(arr->data, tem + 1, arr->size * sizeof(int));
        return;
    }
    if (index == arr->size) {
        memcpy(arr->data, tem, arr->size * sizeof(int));
        return;
    }
    memcpy(arr->data, tem, index * sizeof(int));
    memcpy(arr->data + index, tem + index + 1, (arr->size - index) * sizeof(int));
    free(tem);
}
