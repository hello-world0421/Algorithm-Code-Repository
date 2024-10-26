N, L, H = map(int, input().split())

stu_scores: dict[dict] = {}
for _ in range(N):
    info = input().split()
    stu_scores[info[0]] = {'德分': int(info[1]), '才分': int(info[2])}

sorted_stu = {
    'first_stu': {},
    'second_stu': {},
    'third_stu': {},
    'end_stu': {},
}
for stu, score in stu_scores.items():
    if score['德分'] < L or score['才分'] < L:
        N -= 1
        continue
    elif score['德分'] >= H and score['才分'] >= H:
        sorted_stu['first_stu'][stu] = (score['德分'], score['才分'])
    elif score['德分'] >= H:
        sorted_stu['second_stu'][stu] = (score['德分'], score['才分'])
    elif score['德分'] < H and score['才分'] < H and score['德分'] >= score['才分']:
        sorted_stu['third_stu'][stu] = (score['德分'], score['才分'])
    else:
        sorted_stu['end_stu'][stu] = (score['德分'], score['才分'])

print(N)
for grade in sorted_stu.keys():
    for stu, score in sorted(sorted_stu[grade].items(), key=lambda x: (-sum(x[1]), -x[1][0], stu)):
        print(stu, *score)
