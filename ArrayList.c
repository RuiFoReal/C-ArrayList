#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"ArrayList.h"
struct ArrayList new_ArrayList() {
    ArrayList arr = { .size = 0 , .capacity = 0 };
    return arr;
}

void addElement(ArrayList* arr, int e) {
    // init capacity
    if (arr->size == 0) {
        arr->data = malloc(sizeof(int) * (arr->capacity = DEFAULT_CAPACITY));
        arr->data[arr->size++] = e;
        return;
    }
    // need to expend data array
    if (arr->size == arr->capacity) {
        arr->capacity *= 1.5;
        int* tem = arr->data;
        arr->data = malloc(sizeof(int) * arr->capacity);
        memcpy(arr->data, tem, sizeof(int) * arr->size);
        arr->data[(arr->size)++] = e;
        free(tem);
        return;
    }
    arr->data[(arr->size)++] = e;
}

void addElementByIndex(ArrayList* arr, int index, int e) {
    if (index > arr->size && index < 0)
        return;
    if ((arr->size++) >= arr->capacity)
        arr->capacity *= 1.5;
    int* tem = arr->data;
    arr->data = malloc(sizeof(int) * arr->capacity);
    memcpy(arr->data, tem, sizeof(int) * index);
    arr->data[index] = e;
    memcpy(arr->data + index + 1, tem + index, sizeof(int) * (arr->size - index - 1));
    free(tem);
}

void removeElementByIndex(ArrayList* arr, int index) {
    if (index >= arr->size || index < 0) return;
    int* tem = arr->data;
    arr->size--;
    arr->data = malloc(sizeof(int) * arr->capacity);
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

bool containsElement(ArrayList* arr, int e) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == e)
            return true;
    }
    return false;
}

bool equals(ArrayList* arr1, ArrayList* arr2) {
    if (arr1->size != arr2->size)
        return false;
    if (arr1 == arr2)
        return true;
    for (int i = 0; i < arr1->size; i++) {
        if (arr1->data[i] != arr2->data[i])
            return false;
    }
    return true;
}

void clear(ArrayList* arr) {
    if (arr->size == 0 || arr->data == NULL)
        return;
    arr->size = 0;
    arr->capacity = 0;
    free(arr->data);
    arr->data = NULL;
}

void printfArrayList(ArrayList* arr) {
    // printf("%p", arr->data);
    if (arr->size == 0) {
        puts("[]");
        return;
    }
    putchar('[');
    for (int i = 0; i < arr->size; i++) {
        if (i == arr->size - 1)
            printf("%d", arr->data[i]);
        else
            printf("%d,", arr->data[i]);
    }
    puts("]");
}
