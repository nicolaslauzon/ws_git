#ifndef SORT_H
#define SORT_H

#include "folder.h"
#include "note.h"

#include <iostream>
#include <vector>
#include <string>

namespace Sort {
    template<typename T>
    void QuickSortNote(T min, T max) {
    /*    std::vector<T>::iterator left, pivot, right;
        left = pivot = min;
        right = max;
        while (left != right) {
            if (left->Name() > right->Name()) {
                std::vector<T>::iterator tmp = left;
                *left = *right;
                *right = *tmp;
                (pivot == left) ? pivot = right : pivot = left;
            }
            (pivot == left) ? --right : ++left;
        }
        if (min < pivot - 1) {
            QuickSortNote(min, pivot - 1);
        }
        if (max > pivot + 1) {
            QuickSortNote(pivot + 1, max);
        }*/
    }

    void QuickSortFolder(std::vector<Folder>::iterator min, std::vector<Folder>::iterator max) {
        std::vector<Folder>::iterator left, pivot, right;
        left = pivot = min;
        right = max;
        while (left != right) {
            if (left->Name() > right->Name()) {
                std::vector<Folder>::iterator tmp = left;
                *left = *right;
                *right = *tmp;
                (pivot == left) ? pivot = right : pivot = left;
            }
            (pivot == left) ? --right : ++left;
        }
        if (min < pivot - 1) {
            QuickSortFolder(min, pivot - 1);
        }
        if (max > pivot + 1) {
            QuickSortFolder(pivot + 1, max);
        }
    }
}
#endif // SORT_H
