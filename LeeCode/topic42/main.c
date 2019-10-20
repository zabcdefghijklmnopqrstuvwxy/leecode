#include<stdio.h>

int trap(int* height, int heightSize)
{
    int nSlow = 0;
    int nFast = 0;
    int nArea = 0;
    int i = 0;

    if((height == NULL) || (heightSize <= 2))
    {
        return 0;
    }

    while(i < heightSize)
    {   
        if(height[i] > 0)
        {
            break;
        }
        ++i;
    }

    nSlow = i;
    nFast = i;

    while(nFast < heightSize)
    {
        if(height[nFast] >= height[nSlow])
        {
            if(nFast - nSlow - 1 > 0)
            {
                nArea = nArea + (nFast - nSlow - 1)*height[nSlow];
                for(i = nSlow + 1; i < nFast; i++)
                {
                    nArea = nArea - height[i];
                }
            }
            nSlow = nFast;
        }
        nFast++;
    }

    i = heightSize - 1;

    while(i > 0)
    {   
        if(height[i] > 0)
        {
            break;
        }
        --i;
    }

    nSlow = i;
    nFast = i;
    
    while(nFast >= 0)
    {
        if(height[nFast] >= height[nSlow])
        {
            if(nSlow - nFast - 1 > 0)
            {
                nArea = nArea + (nSlow - nFast - 1)*height[nSlow];
                for(i = nSlow - 1; i > nFast; i--)
                {
                    nArea = nArea - height[i];
                }
            }
            nSlow = nFast;
        }
        nFast--;
    }
    return nArea;
}

int main(void)
{
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int nArea = 0;

    nArea = trap(height, sizeof(height)/sizeof(int));

    printf("water area is %d\n",nArea);

    return 0;
}
