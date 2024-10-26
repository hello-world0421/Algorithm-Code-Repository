alphabet = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

for _ in range(int(input())):
    n, c, k = map(int, input().split())
    s = input()
    cnt = 0
    for ch in alphabet[:c]:
        temp = ''
        if ch not in s:
            continue
        for i in range(n):
            temp += ch if s[i] == ch else '#'
        i, ok = 0, True
        while i < n:
            if (ind := s[i:i + k].find(ch)) != -1:
                i = ind + 1
            else:
                ok = False
                break
        else:
            if ok:
                cnt += 1
            break
    print(cnt)