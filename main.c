#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 1e6

bool check(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // Check if the current element is greater than the next element
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

bool exists(int ints[], int count, int k)
{
    // handlers
    bool isValid = (ints != NULL);
    bool isBound = (count < MAX + 1);
    bool isArranged = check(ints, count);

    if (isValid && isBound && isArranged)
    {
        /* Linear search */
        for (int i = 0; i < count; i++)
        {
            if (ints[i] == k)
            {

                return true; // target found
            }
        }
    }

    return false;
}

int main()
{
    int ints[] = {1, 14, 37, 102};
    int ret = exists(ints, 4, 102); // 1
    ret = exists(ints, 4, 36);      // 0
    return 0;
}
