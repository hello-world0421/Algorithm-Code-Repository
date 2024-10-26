# (1) 两个字典
stu_score: dict[str, int] = {}
stu_id: dict[str, str] = {}

for _ in range(int(input())):
    info = input().split()
    stu_score[info[0]] = int(info[2])
    stu_id[info[0]] = info[1]
sorted_stu_score = sorted(stu_score.items(), key=lambda x: x[1], reverse=True)

print(
    f'{sorted_stu_score[0][0]} {stu_id[sorted_stu_score[0][0]]}',
    f'{sorted_stu_score[-1][0]} {stu_id[sorted_stu_score[-1][0]]}',
    sep='\n'
)
