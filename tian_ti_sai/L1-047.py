n = int(input())
for i in range(n):
    name, hz, mai = input().split()
    hz = int(hz)
    mai = int(mai)
    if (hz < 15 or hz > 20) or (mai <50 or mai > 70):
        print(name)
