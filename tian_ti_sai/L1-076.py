n, m = map(int, input().split())
m = float(m)
for i in range(n):
    price = float(input())
    if price < m:
        print(f"On Sale! {price:.1f}")
