n = int(input())
data = list(map(int, input().split()))
aver = sum(data) / n
print(f"{sum((data[i] - aver) ** 2 for i in range(n)) / (n - 1):.2f}")
