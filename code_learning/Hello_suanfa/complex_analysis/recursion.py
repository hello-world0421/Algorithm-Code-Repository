def recur(n: int) -> int:
    """递归"""
    if n == 1:
        return 1
    res = recur(n-1)
    return res + n

def tail_recur(n: int, res: int = 0):
    """尾递归"""
    if n == 0:
        return res
    return tail_recur(n - 1, res + n)

def fib(n: int) -> int:
    """斐波那契数列：递归"""
    if n == 1 or n == 2:
        return n - 1
    return fib(n - 1) + fib(n - 2)

def for_loop_recur(n: int) -> int:
    """使用迭代模拟递归"""
    stack = []
    res = 0
    for i in range(n, 0, -1):
        stack.append(i)
    while stack:
        res += stack.pop()
    return res
