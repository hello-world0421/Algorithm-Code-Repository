import sys
# p = sys.stdin.readlines()
# print(p)
alpha = 'abcdefghijklmnopqrstuvwxyz'
nums = '0123456789'

ans = []
A = sys.stdin.readlines()
for i in range(len(A)):
    s = list(A[i].rstrip())
    for j in range(len(s)):
        if s[j] in alpha:
            s[j] = str(ord(s[j]) - ord('a'))
    ans.append(''.join(s))
sys.stdout.write(' '.join(ans))
