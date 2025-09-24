/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */
#include <stdio.h>
// @lc code=start

int get_tPoint(int *nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    int tPoint = -1;
    if (nums[0] < nums[numsSize - 1])
    {
        printf("nums not twisted");
        return numsSize - 1;
    }
    int mid;
    while (left < right)
    {
        mid = left + (right - left + 1) / 2;
        if (nums[mid] >= nums[0])
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

int search(int *nums, int numsSize, int target)
{
    if (numsSize == 1)
    {
        if (target == nums[0])
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    int tPoint = get_tPoint(nums, numsSize);
    int left, right;
    printf("target>=nums[0]:%d\n", target >= nums[0]);
    if (target >= nums[0])
    {
        left = 0;
        right = tPoint;
    }
    else
    {
        left = tPoint + 1;
        right = numsSize - 1;
    }
    int res = -1;
    printf("left:%d\nright:%d\n", left, right);
    while (left <= right)
    {
        int mid = (left + right) / 2;
        printf("mid:%d\n", mid);
        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            res = mid;
            break;
            // return mid;
        }
    }
    return res;
}
// @lc code=end
