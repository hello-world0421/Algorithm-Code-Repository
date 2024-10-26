N, D = map(int, input().split())
stores = list(map(int, input().split()))
prices = list(map(int, input().split()))
tatol_store = sum(stores)
profits = [price / store if store != 0 else 0 for store, price in zip(stores, prices)]
goods = list(zip(stores, profits))

profit = 0
goods = sorted(goods, key=lambda x: x[1], reverse=True)

while D != 0 and tatol_store != 0:
    if goods[0][0] == 0:
        goods.pop(0)
        continue
    if D >= goods[0][0]:
        D -= goods[0][0]
        tatol_store -= goods[0][0]
        profit += goods[0][0] * goods[0][1]
        goods.pop(0)
    else:
        profit += D * goods[0][1]
        D = 0
print(f"{profit:.2f}")
