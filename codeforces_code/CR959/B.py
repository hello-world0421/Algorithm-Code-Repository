# 找规律
def solve():
    for i in range(len(s)):
        if s[i] != '0':
            break
        elif t[i] != '0':
            print('NO')
            return
    print('YES')

for _ in range(int(input())):
    n = int(input())
    s = input()
    t = input()
    solve()