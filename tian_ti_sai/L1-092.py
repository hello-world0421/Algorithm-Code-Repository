n = int(input())
for _ in range(n):
    a, b, c = map(int, input().split())
    if a * b == c:
        print("Lv Yan")
    elif a + b == c:
        print("Tu Dou")
    else:
        print("zhe du shi sha ya!")
