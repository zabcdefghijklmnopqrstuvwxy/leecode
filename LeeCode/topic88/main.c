#include<stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int nEndIndex = m + n - 1;
    int i = m - 1,j = n - 1;
    
    while(nEndIndex >= 0)
    {
        if(i >= 0 && j >= 0)
        {
            if(nums1[i] >= nums2[j])
            {
                nums1[nEndIndex--] = nums1[i];
                i--;
            }
        }

        if(i >= 0 && j >= 0)
        {
            if(nums1[i] < nums2[j])
            {
                nums1[nEndIndex--] = nums2[j];
                j--;
            }
        }

        if(i >= 0 && j < 0)
        {
            nums1[nEndIndex--] = nums1[i];
            i--;
        }

        if(i < 0 && j >= 0)
        {
            nums1[nEndIndex--] = nums2[j];
            j--;
        }

    }
}

int main(void)
{
	//int nums1[] = {1, 2, 3, 0, 0, 0};
    //int nums2[] = {2, 5, 6};
	int nums1[] = {2, 0};
    int nums2[] = {1};
    int m = 1;
    int n = 1;
    int i = 0;

    printf("nums1 value is\t");
    for(i = 0; i < sizeof(nums1)/sizeof(int); i++)
    {
        printf("%d\t",nums1[i]);
    }
    
    printf("nums2 value is\t");
    for(i = 0; i < sizeof(nums2)/sizeof(int); i++)
    {
        printf("%d\t",nums2[i]);
    }

    merge(nums1, sizeof(nums1)/sizeof(int), m, nums2, sizeof(nums2)/sizeof(int), n);

    printf("merge value is\t");
    for(i = 0; i < sizeof(nums1)/sizeof(int); i++)
    {
        printf("%d\t",nums1[i]);
    }

	return 0;
}
