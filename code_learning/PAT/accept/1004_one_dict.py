# (2) 一个字典
stu_scores: dict[int, list[str]] = {}

for _ in range(int(input())):
    info = input().split()
    stu_scores[int(info[2])] = f'{info[0]} {info[1]}'
sorted_stu_scores = sorted(stu_scores.items(), key=lambda x: x[0], reverse=True)

print(
    stu_scores[sorted_stu_scores[0][0]],
    stu_scores[sorted_stu_scores[-1][0]],
    sep='\n'
)
