nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
prices = {6: 10000,
          7: 36,
          8: 720,
          9: 360,
          10: 80,
          11: 252,
          12: 108,
          13: 72,
          14: 54,
          15: 180,
          16: 72,
          17: 180,
          18: 119,
          19: 36,
          20: 306,
          21: 1080,
          22: 144,
          23: 1800,
          24: 3600,}
games = []
for i in range(3):
    games.append(list(map(int, input().split())))
for i in range(3):
    for j in range(3):
        if games[i][j] == 0:
            for num in nums:
                if num not in games[0]+games[1]+games[2]:
                    games[i][j] = num
                    break
for i in range(3):
    a, b = map(int, input().split())
    print(games[a-1][b-1])
d = input()
if d == '1' or d == '2' or d == '3':
    print(prices[sum(games[int(d)-1])])
elif d == '4' or d == '5' or d == '6':
        print(prices[sum([games[i][int(d)-4] for i in range(3)])])
elif d == '7':
        print(prices[sum([games[i][i] for i in range(3)])])
elif d == '8':
        print(prices[sum([games[i][2-i] for i in range(3)])])
