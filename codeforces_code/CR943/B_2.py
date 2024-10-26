import sys
input = sys.stdin.readline

for _ in range(int(input())) :
    N, M = map(int,input().split()) ; T1 = input().strip() ; T2 = input().strip()

    cnt = 0
    for i in range(M) :
        if cnt == N : break
        if T1[cnt] == T2[i] : cnt += 1

    print(cnt)