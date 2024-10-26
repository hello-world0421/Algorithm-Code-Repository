t = int(input())

for i in range(t):
    n = int(input())
    for i in range(n):
        for _ in range(2):
            for j in range(n):
                if not (i + j) % 2:
                    ch = '#'
                else:
                    ch = '.'
                print(ch * 2, end='')
            print()
