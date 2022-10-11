#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findMaxCrossingSubarray(int* a, int low, int mid, int high);
int* findMaximumSubarray(int* a, int low, int high);

int main(void)
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }

    int h =  sizeof(a) / sizeof(a[0]) - 1;
    int* temp = findMaximumSubarray(a, 0, h);

    printf("%d %d %d", temp[0], temp[1], temp[2]);

    return 0;
}
int* findMaxCrossingSubarray(int* a, int low, int mid, int high)
{
    int leftSum = -2147483647;
    int rightSum = -2147483647;
    int i, j;
    int maxLeft, maxRight;

    int sum = 0;
    for (i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum >= leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }
    sum = 0;
    for (j = mid + 1; j <= high; j++)
    {
        sum += a[j];
        if (sum >= rightSum)
        {
            rightSum = sum;
            maxRight = j;
        }
    }

    int* temp = (int*)malloc(sizeof(int) * 3);
    temp[0] = maxLeft;
    temp[1] = maxRight;
    temp[2] = leftSum + rightSum;

    return temp;
}
int* findMaximumSubarray(int* a, int low, int high)
{
    int* res = (int*)malloc(sizeof(int) * 3);

    if (low == high)
    {
        res[0] = low;
        res[1] = high;
        res[2] = a[low];

        return res;
    }
    else
    {
        int* left = (int*)malloc(sizeof(int) * 3);
        int* right = (int*)malloc(sizeof(int) * 3);
        int* cross = (int*)malloc(sizeof(int) * 3);
        int mid = (low + high) / 2;

        memcpy(left, findMaximumSubarray(a, low, mid), sizeof(int) * 3);
        memcpy(right, findMaximumSubarray(a, mid + 1, high), sizeof(int) * 3);
        memcpy(cross, findMaxCrossingSubarray(a, low, mid, high), sizeof(int) * 3);

        if (left[2] >= right[2] && left[2] >= cross[2])
            return left;
        else if (right[2] >= left[2] && right[2] >= cross[2])
            return right;
        else if (cross[2] >= left[2] && cross[2] >= right[2])
            return cross;
    }
}
