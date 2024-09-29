#include "pch.h"
#include "DynamicLib.h"

namespace func {
    void BubbleSort(int* a, int n) {
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (a[i] > a[i + 1]) {
                    int x = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = x;
                }
            }
        }
    }
}