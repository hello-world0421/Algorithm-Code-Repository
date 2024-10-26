"""
思维题
时间复杂度 O(n)
"""
for _ in range(int(input())):
    n = int(input())
    s = input()
    print(sum(min(n, s.count(c)) for c in "ABCD"))