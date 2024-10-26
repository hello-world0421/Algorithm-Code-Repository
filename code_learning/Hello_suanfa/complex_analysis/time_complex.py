def constant(n: int) -> int:
    """常数阶"""
    count = 0
    size = 100000
    for _ in range(size):
        count += 1
    return count

def linear(n: int) -> int:
    """线性阶"""
    count = 0
    for _ in range(n):
        count += 1
    return count

def array_traversal(nums: list[int]) -> int:
    """线性阶（遍历数组）"""
    count = 0
    for num in nums:
        count += 1
    return count

def quadratic(n: int) -> int:
    """平方阶"""
    count = 0
    for _ in range(n):
        for _ in range(n):
            count += 1
    return count

def bubble_sort(nums: list[int]) -> int:
    """平方阶（冒泡排序）"""
    count = 0
    for i in range(len(nums) - 1, 0, -1):
        for j in range(i):
            if nums[j] > nums[j + 1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
                count += 3
    return count

def exponential(n: int) -> int:
    """指数阶（循环实现）"""
    count = 0
    base = 1
    for _ in range(n):
        for _ in range(base):
            count += 1
        base *= 2
    return count

def exp_recur(n: int) -> int:
    """指数阶（递归实现）"""
    if n == 1:
        return 1
    return exp_recur(n-1) + exp_recur(n-1) + 1

def logarithmic(n: int) -> int:
    """对数阶（循环实现）"""
    count = 0
    while n > 1:
        n //= 2
        count += 1
    return count

def log_recur(n: int) -> int:
    """对数阶（递归实现）"""
    if n == 1:
        return 0
    return 1 + log_recur(n // 2)

def linear_log_recur(n: int) -> int:
    """线性对数阶（递归实现）"""
    if n <= 1:
        return 1
    count: int = linear_log_recur(n // 2) + linear_log_recur(n // 2)
    for _ in range(n):
        count += 1
    return count

def factorial_recur(n: int) -> int:
    """阶乘阶（递归实现）"""
    if n == 0:
        return 1
    count = 0
    for _ in range(n):
        count += factorial_recur(n-1)
    return count

def random_number(n: int) -> list[int]:
    """随机生成数组"""
    import random
    nums = [i for i in range(1, n+1)]
    random.shuffle(nums)
    return nums

def find_one(nums: list[int]) -> int:
    """查找数组中的一个元素"""
    for i in range(len(nums)):
        if nums[i] == 1:
            return i
    return -1
