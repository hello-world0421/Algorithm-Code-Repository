n = int(input())
for i in range(1, n+1):
    books = {}
    times = {}
    num = 0
    s = input().split()
    while s[0] != '0':
        if s[0] not in books and s[1] == 'S':
            books[s[0]] = {s[1]: s[2]}
        elif s[0] in books and s[1] == 'E':
            sh, sm = map(int, books[s[0]]['S'].split(':'))
            eh, em = map(int, s[2].split(':'))
            time = (eh - sh) * 60 + (em - sm)
            num += 1
            if s[0] not in times:
                times[s[0]] = time
            
        s = input().split()
    if num != 0:
        print(f"{num}, {sum(times.values()) / num:.0f}")
