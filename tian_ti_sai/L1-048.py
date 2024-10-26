ra, ca = map(int, input().split())
mat_a = []
for i in range(ra):
    mat_a.append(list(map(int, input().split())))

rb, cb = map(int, input().split())
mat_b = []
for i in range(rb):
    mat_b.append(list(map(int, input().split())))

if ca != rb:
    print(f"Error: {ca} != {rb}")
else:
    mat_c = [[0 for j in range(cb)] for i in range(ra)]
    for i in range(ra):
        for j in range(cb):
            for k in range(ca):
                mat_c[i][j] += mat_a[i][k] * mat_b[k][j]
    print(ra, cb) 
    for i in range(ra):
            print(" ".join(map(str, mat_c[i][::])))
