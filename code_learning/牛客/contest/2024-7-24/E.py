n = int(input())
s1 = input()
s2 = input()
ans = 0
for ch in set(s1):
    if s2.count(ch) != s1.count(ch):
        continue
    if s1.count(ch) == s2.count(ch) == 1:
        ans += 1
        continue
    pos, i = [], 0
    while (temp := s1.find(ch, i)) != -1:
        pos.append(temp)
        i = temp + 1
    ind, i = [], 0
    while (temp := s2.find(ch, i)) != -1:
        ind.append(temp)
        i = temp + 1
    for _ in range(n):
        if ind == pos:
            ans += 1
            break
        ind = sorted([(i + 1) % n for i in ind])
print(ans)