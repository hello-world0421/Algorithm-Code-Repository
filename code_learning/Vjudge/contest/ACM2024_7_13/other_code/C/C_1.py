import sys


def solve():
    # 读取输入值
    n, m, k = map(int, input().split())
    nk = n * m // 2 - k
    
    # 初始化结果标志
    ok = False
    
    # 检查k的情况
    if k % 2 == 0:
        if n % 2 == 0 and (k + n - 1) // n * 2 <= m:
            ok = True
        elif m % 2 == 0 and k % (m // 2) == 0 and (n - k // (m // 2)) % 2 == 0:
            ok = True
            
    # 检查nk的情况
    if nk % 2 == 0:
        if m % 2 == 0 and (nk + m - 1) // m * 2 <= n:
            ok = True
        elif n % 2 == 0 and nk % (n // 2) == 0 and (m - nk // (n // 2)) % 2 == 0:
            ok = True
            
    # 输出结果
    print("YES" if ok else "NO")

def main():
    # 读取测试用例数量
    t = int(input())
    
    # 循环处理每个测试用例
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()