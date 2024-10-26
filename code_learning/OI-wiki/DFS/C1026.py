import sys
from math import inf

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def are_coprime(num, arr):
    return all(gcd(i, num) == 1 for i in arr)

ans = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    def dfs(a, start, current):
        if start == len(a):
            return current
        
        longest = current
        for i in range(start, len(a)):
            if are_coprime(a[i], current) and \
                len(sublist := dfs(a, i + 1, current + [a[i]])) \
                    > len(longest):
                        longest = sublist
        return longest
    ans.append(len(dfs(a, 0, [])))
sys.stdout.write('\n'.join(map(str, ans)))
