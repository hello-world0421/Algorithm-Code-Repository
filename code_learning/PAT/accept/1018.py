player = {'胜': 0, '平': 0, '负': 0}
result = {'C': [0, 0], 'J': [0, 0], 'B': [0, 0]}

def custom_compare(a, b):
    if a == 'C' and b == 'J':
        return 1
    elif a == 'J' and b == 'B':
        return 1
    elif a == 'B' and b == 'C':
        return 1
    elif a == b:
        return 0
    else:
        return -1

for _ in range(int(input())):
    res_1, res_2 = input().split()
    if custom_compare(res_1, res_2) > 0:
        player['胜'] += 1
        result[res_1][0] += 1
    elif custom_compare(res_1, res_2) < 0:
        player['负'] += 1
        result[res_2][1] += 1
    elif custom_compare(res_1, res_2) == 0:
        player['平'] += 1

print(*list(player.values()))
print(*list(player.values())[::-1])

result_1 = sorted(result.items(), key=lambda x: (-x[1][0], x[0]))
result_2 = sorted(result.items(), key=lambda x: (-x[1][1], x[0]))
print(result_1[0][0], result_2[0][0])
