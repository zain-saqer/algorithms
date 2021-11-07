/* implements median of medians algorithm from Wikipedia https://en.wikipedia.org/wiki/Median_of_medians
 * this algorithm is used to select the pivot in Quick-sort algorithms to make it most efficient.
 * */

#include <stdlib.h>


size_t partition(int *list, size_t left, size_t right, size_t pivotIndex, size_t n);

size_t pivot(int *list, size_t left, size_t right);

size_t partition5(int *list, size_t left, size_t right);

void swap(int *a, int *b);

size_t median(int *list, size_t left, size_t right, size_t n) {
    while (1) {
        if (left == right)
            return left;
        size_t pivotIndex = pivot(list, left, right);
        pivotIndex = partition(list, left, right, pivotIndex, n);
        if (n == pivotIndex) {
            return n;
        } else if (n < pivotIndex) {
            right = pivotIndex - 1;
        } else {
            left = pivotIndex + 1;
        }
    }
}

size_t partition(int *list, size_t left, size_t right, size_t pivotIndex, size_t n) {
    int pivotValue = list[pivotIndex];
    swap(&list[pivotIndex], &list[right]);
    size_t index = left;
    // Move all elements smaller than the pivot to the left of the pivot
    for (size_t i = left; i < right - 1; ++i) {
        if (list[i] < pivotValue) {
            swap(&list[index], &list[i]);
            index++;
        }
    }
    // Move all elements equal to the pivot right after
    // the smaller elements
    size_t indexEq = index;
    for (size_t i = index; i < right - 1; ++i) {
        if (list[i] == pivotValue) {
            swap(&list[indexEq], &list[i]);
            indexEq++;
        }
    }
    swap(&list[right], &list[indexEq]);
    // Return location of pivot considering the desired location n
    if (n < index) {
        return index;  // n is in the group of smaller elements
    } else if (n <= indexEq) {
        return n;  // n is in the group equal to pivot
    }
    return indexEq; // n is in the group of larger elements
}

size_t pivot(int *list, size_t left, size_t right) {
    // for 5 or less elements just get median
    if ((right - left) < 5)
        return partition5(list, left, right);
    // otherwise move the medians of five-element subgroups to the first n/5 positions
    for (size_t i = left; i < right; i = i + 5) {
        // get the median position of the i'th five-element subgroup
        size_t subRight = i + 4;
        if (subRight > right)
            subRight = right;
        size_t median5 = partition5(list, i, subRight);
        swap(&list[median5], &list[left + (i - left) / 5]);
    }
    // compute the median of the n/5 medians-of-five
    size_t mid = (right - left) / 10 + left;
    return median(list, left, left + (right - left) / 5, mid);
}

size_t partition5(int *list, size_t left, size_t right) {
    size_t i = left + 1;
    while (i <= right) {
        size_t j = i;
        while (j > left && list[j - 1] > list[j]) {
            swap(&list[j - 1], &list[j]);
            j = j - 1;
        }
        i++;
    }
    return (left + right) / 2;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}