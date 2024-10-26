import sys

ans = []
for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    friend = {i+1: p[i] for i in range(len(p))}
    for i in friend.keys():
        if friend[friend[i]] == i:
            ans.append('2')
            break
    else:
        ans.append('3')
sys.stdout.write('\n'.join(ans))
