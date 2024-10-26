import sys
input = sys.stdin.readline

for _ in range(int(input())) :
    N = int(input()) ; A = list(map(int,input().split()))

    Ans = [10000]
    for i in range(N-1) : Ans.append(Ans[-1]+A[i])

    print(*Ans)