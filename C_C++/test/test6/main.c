#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int k = 0;
    int i = 0;
    int j = 0;
    int tmp = 0;

    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[0])
        {
            ++i;
        }

        if (nums1[i] > nums2[0])
        {
            tmp = nums1[i];
            nums1[i] = nums2[0];
            k = 0;
            while (tmp > nums2[k + 1] && k < n - 1)
            {
                nums2[k] = nums2[k + 1];
                ++k;
            }
            nums2[k] = tmp;
            ++i;
        }

    }

    while (j < n)
    {
        nums1[i++] = nums2[j++];
    }

}

int main(int argc, char* argv[])
{
    int nums1[6] = { 1, 3, 5, 0, 0, 0 };
    int m = 3;
    int nums2[3] = { 2, 4, 6 };
    int n = 3;
    merge(nums1, 0, m, nums2, 0, n);
    printf("\n");
    return 0;
}