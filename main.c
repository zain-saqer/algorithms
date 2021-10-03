//
// Created by zain on 02.10.21.
//
#include "median.h"
#include <assert.h>

int main() {
    // test median
    int list[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    assert(8 == list[median(list, 0, 14, 7)]);

    int list1[] = {10,1,2,3,4,5,6,7,8,9,11,12,13,14,15};
    assert(8 == list[median(list1, 0, 14, 7)]);
    assert(1 == list1[median(list1, 0, 14, 0)]);

    int list2[] = {15,6,14,4,5,2,7,11,9,10,8,12,13,3,1};
    assert(8 == list2[median(list2, 0, 14, 7)]);

    int list3[] = {9,1,9,1,1,1,1,9,9,9,8,9,9,1,1};
    assert(8 == list3[median(list3, 0, 14, 7)]);
    assert(1 == list3[median(list3, 0, 14, 0)]);
    assert(9 == list3[median(list3, 0, 14, 14)]);

    return 0;
}