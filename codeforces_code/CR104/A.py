n = int(input())
num = input()

if set(num) == {'4', '7'} and sum(map(int, list(num[:n // 2]))) == sum(map(int, list(num[n // 2:]))):
    print("YES")
else:
    print("NO")