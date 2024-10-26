N = int(input())
M = input()

for step in range(30):
    tM = M[::-1]
    ans = ''
    t = 0
    for i in range(-1, -len(tM)-1, -1):
        total = int(M[i]) + int(tM[i]) + t
        t = 1 if total >= N else 0
        ans = str(total % N) + ans
    if t == 1:
        ans = '1' + ans
    if ans == ans[::-1]:
        print(f'STEP={step+1}')
        break
    else:
        M = ans
else:
    print('Impossible!')
