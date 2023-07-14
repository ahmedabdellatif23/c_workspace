#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/* Binary search */
bool exists(int ints[], int count, int k)
{
    int lowerBound = 0;
    int upperBound = count - 1;
    while (lowerBound <= upperBound)
    {
        int idxMid = lowerBound + (upperBound - lowerBound) / 2;
        if (ints[idxMid] == k)
        {
            return true;
        }
        else if (ints[idxMid] < k) {
            lowerBound = idxMid + 1;
        }
        else {
            upperBound = idxMid - 1;
        }
    }
    return false;
}

int main()
{
    int ints[] = {-9, 14, 37, 102};
    int ret = exists(ints, 4, 102); // 1
    ret = exists(ints, 4, 36); // 0
    return 0;
}
