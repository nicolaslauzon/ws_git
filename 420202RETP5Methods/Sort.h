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
                if (pivot == left) {
                    pivot = right;
                    ++left;
                }
                else {
                    pivot = left;
                    --right;
                }
            }
        }
        if (min < pivot - 1) {
            QuickSort(min, pivot - 1);
        }
        else if (max > pivot + 1) {
            QuickSort(pivot + 1, pivot - 1);
        }
    }
}
#endif // SORT_H
