/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int compare(const void* a,const void* b){
    int x=*(const int*)a;
    int y=*(const int*)b;
    return (x>y)-(x<y);
}
int **threeSum(int *nums, int numssize, int *returnsize, int **returncolumnsizes)
{
    *returnsize = 0;
    *returncolumnsizes = NULL;
    if (numssize < 3)
        return NULL;
    
    qsort(nums,numssize,sizeof(int),compare);
    int capacity = 16;
    int **res = (int **)malloc(sizeof(int *) * capacity);
    if (!res)
    {
        printf("failed to malloc res! retun null");
        return NULL;
    }

    int count = 0;

    for (int i = 0; i < numssize - 1; i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numssize - 1;
        int target = -nums[i];
        while (left < right)
        {
            if (nums[left] + nums[right] == target)
            {
                // pass
                if (count == capacity)
                {
                    capacity <<= 1;
                    int **tmp = (int **)realloc(res, sizeof(int *) * capacity);
                    if (!tmp)
                    { // 极端：扩容失败，释放已分配内存后安全返回
                        for (int k = 0; k < count; ++k)
                            free(res[k]);
                        free(res);
                        return NULL;
                    }
                    res = tmp;
                }

                int *new_sol = malloc(sizeof(int) * 3);
                new_sol[0] = nums[i];
                new_sol[1] = nums[left];
                new_sol[2] = nums[right];
                res[count++] = new_sol;

                while (left < right && nums[left] == nums[left + 1])
                {
                    left += 1;
                }
                while (left < right && nums[right] == nums[right - 1])
                {
                    right -= 1;
                }
                left += 1;
                right -= 1;
            }
            else if (nums[left] + nums[right] < target)
            {
                /* code */
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
    }
    
    int *colsizes = NULL;
    if (count > 0)
    {
        colsizes = (int *)malloc(sizeof(int) * count);
        for (int i = 0; i < count; ++i)
            colsizes[i] = 3;
    }
    *returncolumnsizes=colsizes;
    *returnsize=count;
    return res;
}
// @lc code=end
