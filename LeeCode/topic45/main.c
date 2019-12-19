#include<stdio.h>


/*
* @brief 贪婪算法，局部最优解即全局最优解。找出步长最长的即跳转最少
*/
int jump(int* nums, int numsSize)
{
      int step=0;
    for(int i=0, maxpos=0, curpos=0; i < numsSize; ++i)
    {
        if (i>curpos)
        {  
	        curpos = maxpos;
	        ++step;
	    }
	    maxpos = maxpos > (i + nums[i]) ? maxpos : (i + nums[i]);
	}
	return step;
}

int main(void)
{
//    int nums[5] = {2,3,1,1,4};
    int nums[3] = {1,2,3};
//    int nums[2] = {2,1};
    int nJump = 0;
    int i = 0;
    int nLen = sizeof(nums)/sizeof(int);

    nJump = jump(nums,nLen);

    printf("game input is:\n");
    for(i = 0; i < nLen; i++)
    {
        printf("%d\t",nums[i]);
    }

    printf("\njump least step is %d\n",nJump);

    return 0;
}
