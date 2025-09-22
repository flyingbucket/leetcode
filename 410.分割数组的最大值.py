#
# @lc app=leetcode.cn id=410 lang=python3
#
# [410] 分割数组的最大值
#

import random
import time
from typing import List
# @lc code=start
class Solution:
    @staticmethod
    def reachable(nums,k,sum):
        current=0
        current_k=k
        i=0
        while current_k>0 and i<len(nums):
            current+=nums[i]
            if current>sum:
                if i>0:
                    current=0
                    current_k-=1
                    if current_k==0:
                        return False
                else:
                    return False
            else:
                # current+=nums[i]
                i+=1
        return True

    def splitArray(self, nums: List[int], k: int) -> int:
        left=max(nums)
        right=sum(nums)
        while left<right:
            # mid=(left+right)//2
            mid=(left+right)>>1
            if self.reachable(nums,k,mid):
                right=mid
            else:
                left=mid+1
        return left
# @lc code=end

class Solution_opt:
    def splitArray(self, nums: List[int], k: int) -> int:
        left=max(nums)
        right=sum(nums)
        while left<right:
            # mid=(left+right)//2
            mid=(left+right)>>1
            current=0
            current_k=k
            i=0
            ok=False
            while current_k>0 and i<len(nums):
                current+=nums[i]
                if current>mid:
                    if i>0:
                        current=0
                        current_k-=1
                        if current_k==0:
                            # return False
                            break
                    else:
                        # return False
                        break
                else:
                    # current+=nums[i]
                    i+=1
            # return True
            else:
                ok=True
            # if self.reachable(nums,k,mid):
            if ok:
                right=mid
            else:
                left=mid+1
        return left
class SolutionFast:
    def splitArray(self, nums: List[int], k: int) -> int:
        left = max(nums)
        right = sum(nums)
        while left < right:
            mid = (left + right) >> 1

            # 贪心 + 早停（count 超过 k 就 break）
            count = 1
            current = 0
            for num in nums:
                if current + num > mid:
                    count += 1
                    if count > k:  # 早停
                        break
                    current = num
                else:
                    current += num

            if count <= k:
                right = mid
            else:
                left = mid + 1
        return left

class Solution_qwen:
    def splitArray(self, nums: List[int], k: int) -> int:
        # 预处理：避免重复计算
        total = sum(nums)
        left = max(nums)
        right = total
        
        while left < right:
            mid = (left + right) >> 1  # 位运算更快
            # 贪心计算所需子数组数
            count = 1
            current = 0
            
            for num in nums:
                if current + num > mid:
                    count += 1
                    current = num
                else:
                    current += num
            
            if count <= k:
                right = mid
            else:
                left = mid + 1
        
        return left
    

class TestGenerator:
    @staticmethod
    def generate_random_case(size, k_range=None, max_value=1000):
        """
        生成随机测试案例
        
        Args:
            size: 数组大小
            k_range: 子数组数量范围 (min_k, max_k)
            max_value: 数组元素最大值
        """
        if k_range is None:
            k_range = (1, max(1, size // 2))
        
        # 生成随机数组
        nums = [random.randint(1, max_value) for _ in range(size)]
        
        # 生成随机k值
        k = random.randint(k_range[0], min(k_range[1], size))
        
        return nums, k
    
    @staticmethod
    def generate_edge_cases():
        """生成边界测试案例"""
        test_cases = []
        
        # 单个元素
        test_cases.append(([5], 1))
        
        # 两个元素
        test_cases.append(([3, 5], 1))
        test_cases.append(([3, 5], 2))
        
        # 已知答案的测试用例
        test_cases.append(([7,2,5,10,8], 2))  # 期望: 18
        test_cases.append(([1,2,3,4,5], 2))   # 期望: 9
        test_cases.append(([1,4,4], 3))       # 期望: 4
        
        return test_cases
    
    @staticmethod
    def generate_large_cases():
        """生成大数组测试案例"""
        test_cases = []
        
        # 大数组测试
        large_nums = [random.randint(1, 100) for _ in range(1000)]
        test_cases.append((large_nums, 5))
        test_cases.append((large_nums, 10))
        
        # 极端情况：大部分元素都很小，少数很大
        extreme_nums = [1] * 999 + [10000]
        test_cases.append((extreme_nums, 3))
        
        return test_cases
    
    @staticmethod
    def benchmark_function(func, nums, k, iterations=1000):
        """
        基准测试函数
        
        Args:
            func: 要测试的函数
            nums: 测试数组
            k: 子数组数量
            iterations: 测试迭代次数
        """
        times = []
        
        for _ in range(iterations):
            start_time = time.perf_counter()
            result = func(nums, k)
            end_time = time.perf_counter()
            times.append(end_time - start_time)
        
        avg_time = sum(times) / len(times)
        min_time = min(times)
        max_time = max(times)
        
        return {
            'average': avg_time,
            'min': min_time,
            'max': max_time,
            'result': result
        }
if __name__ == "__main__":
    random.seed(23)  # For reproducibility

    sol = Solution()
    sol_qwen = Solution_qwen()
    sol_opt = Solution_opt()
    sol_fast = SolutionFast()
    tests=[]
    for i in range(20000):
        nums1, k1 = TestGenerator.generate_random_case(50, (2, 25), 1000)
        tests.append((nums1,k1))
        if i % 10 == 0:
            nums2, k2 = TestGenerator.generate_large_cases()[i % 10]
            tests.append((nums2,k2))
    tests+=TestGenerator.generate_edge_cases()
    start=time.time()
    for nums,k in tests:
        res=sol.splitArray(nums, k)
    end=time.time()
    print("My Solution time:", end-start)
    start=time.time()
    for nums,k in tests:
        res=sol_qwen.splitArray(nums, k)
    end=time.time()
    print("Qwen Solution time:", end-start)

    start=time.time()
    for nums,k in tests:
        res=sol_opt.splitArray(nums, k)
    end=time.time()
    print("Optimized Solution time:", end-start)
    start=time.time()
    for nums,k in tests:
        res=sol_fast.splitArray(nums, k)
    end=time.time()
    print("Fast Solution time:", end-start)
# 使用方法示例：
# 1. 生成随机测试案例
# nums, k = TestGenerator.generate_random_case(50, (2, 25), 1000)

# 2. 生成边界测试案例
# edge_cases = TestGenerator.generate_edge_cases()

# 3. 生成大数组测试案例
# large_cases = TestGenerator.generate_large_cases()

# 4. 基准测试
# result = TestGenerator.benchmark_function(your_function, nums, k, 10000)