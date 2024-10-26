n = int(input())
s1 = input()
s2 = input()
ans = ''
for i in range(n):
    if s1[i] == s2[i]:
        ans += chr(ord(s1[i]) + 1)
    elif s1[i] < s2[i]:
        print(-1)
        break
    else:
        ans += s2[i]
else:
    print(ans)
