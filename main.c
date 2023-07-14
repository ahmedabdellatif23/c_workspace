#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

bool exists(int ints[], int count, int k)
{
    /* Linear search */
    int idx;
    for (int i = 0; i < count; i++)
    {
        if (ints[i] == k)
        {
            idx = i;
            return true; // target found
        }
    }
    return false;
}

int main()
{
    int ints[] = {-9, 14, 37, 102};
    int ret = exists(ints, 4, 102); // 1
    ret = exists(ints, 4, 36);      // 0
    return 0;
}
