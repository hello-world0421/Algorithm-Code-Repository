ans: list[str] = []

for _ in range(int(input())):
    s: str = input()
    if set(s).issubset({'P', 'T', 'A'}):
        if s.count('P') == s.count('T') == 1 and ('PAT' in s or 'PAAT' in s):
            ans.append('YES')
        else:
            ans.append('NO')
    else:
        ans.append('NO')
print('\n'.join(ans))
