def recommend_students(N, K, S, students):
    students.sort(key=lambda x: (x[0], x[1]), reverse=True)  # 按天梯赛成绩和PAT成绩排序
    count = 0  # 推荐学生人数计数
    pre_student = 0  # 记录上一个推荐学生
    # 记录之前推荐学生中PAT成绩的最高分
    for i in range(N):
        # if students[i][0] >= 175 and (students[i][1] >= S or max_pat_score >= S):
        #     count += 1
        #     if students[i][1] > max_pat_score:
        #         max_pat_score = students[i][1]
        if pre_student == students[i][0] and students[i][1] >= S:
            count += 1
        elif pre_student != students[i][0]:
            count += 1
            pre_student = students[i][0]
    return min(count, K * 10)  # 最多能向企业推荐的学生人数，最多为K批次的10倍

n, k, s = map(int, input().split())
students = []
for i in range(n):
    students.append(list(map(int, input().split())))
print(recommend_students(n, k, s, students))
