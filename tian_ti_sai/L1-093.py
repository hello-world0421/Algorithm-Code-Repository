n = int(input())
caps = [int(x) for x in input().split()]
k = int(input())
for i in range(k):
    anwser = [int(x) for x in input().split()]
    result = []
    for j in range(n):
        if anwser[j] == caps[j]:
            result.append(1)
        elif anwser[j] != caps[j] and anwser[j] != 0:
            result.append(0)
        else:
            result.append(2)
    if result.count(1) >= 1 and result.count(0) == 0:
        print("Da Jiang!!!")
    elif result.count(2) == n or result.count(0) >= 1:
        print("Ai Ya")
