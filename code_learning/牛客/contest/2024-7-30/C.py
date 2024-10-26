n = int(input())
s = input()
x, y, z = map(int, input().split())
ans = 0
while '01' in s:
    ans += s.count('01')
    s = s.replace('01', '')
print(min(ans, y))