#include<stdio.h>

int maxArea(int* height, int heightSize)
{
    int i = 0,j = heightSize - 1;
    int nArea = 0;

    while(i < j)
    {
        if(height[i] < height[j])
        {
            nArea = nArea > height[i]*(j - i) ? nArea : height[i]*(j - i);
            i++;
        }
        else
        {
            nArea = nArea > height[j]*(j - i) ? nArea : height[j]*(j - i);
            j--;
        }
    }

    return nArea;
}

int main(void)
{
    int nMaxArea = 0;
    int nHeight[9] = {1,8,6,2,5,4,8,3,7};

    nMaxArea = maxArea(nHeight, 9);

    printf("max area is %d\n",nMaxArea);

    return 0;
}


