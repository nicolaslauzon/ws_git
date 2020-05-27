#ifndef SORT_H
#define SORT_H

#include <iostream>

namespace Sort {
    void QuickSort(int* min, int* max) {
        int* left, *pivot, *right;
        left = pivot = min;
        right = max;
        while (left != right) {
            if (*left > *right) {
                int tmp = *left;
                *left = *right;
                *right = tmp;
                (pivot == left) ? pivot = right : pivot = left;
            }
            (pivot == left) ? --right : ++left;
        }
        if (min < pivot - 1) {
            QuickSort(min, pivot - 1);
        }
        if (max > pivot + 1) {
            QuickSort(pivot + 1, max);
        }
    }
}
#endif // SORT_H
