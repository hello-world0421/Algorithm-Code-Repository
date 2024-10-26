import sys

ans = []
for _ in range(int(input())):
    s = input()
    i = size = ans0 = 0
    while i < len(s):
        size += 1
        if s[i] == '0':
            if size != 1:
                ans0 += size
            size -= 1
        i += 1
    ans.append(str(ans0))
sys.stdout.write('\n'.join(ans))
import sys

ans = []
for _ in range(int(input())):
    pass

sys.stdout.write('\n'.join(ans))