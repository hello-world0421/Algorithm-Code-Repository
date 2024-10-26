import sys

s = []
for _ in range(int(input())):
    s.append(set(input()))
for _ in range(int(input())):
    op = input()
    ans = set(s[ord(op[0]) - ord('A')])
    for i in range(1, len(op), 2):
        if i + 1 > len(op):
            break
        if op[i] == '+':
            ans |= s[ord(op[i + 1]) - ord('A')]
        elif op[i] == '-':
            ans -= s[ord(op[i + 1]) - ord('A')]
        elif op[i] == '*':
            ans &= s[ord(op[i + 1]) - ord('A')]
    sys.stdout.write(''.join(sorted(ans)) + '\n' if ans else 'NO\n')