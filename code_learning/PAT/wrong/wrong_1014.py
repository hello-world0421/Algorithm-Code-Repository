from typing import List

# 定义星期几的映射
week_day = {
    'A': 'MON',
    'B': 'TUE',
    'C': 'WED',
    'D': 'THU',
    'E': 'FRI',
    'F': 'SAT',
    'G': 'SUN',
}

# 读取输入字符串
info_str: List[str] = [input() for _ in range(4)]

# 初始化特殊字符列表
special_ch: List[List[str]|List[int]] = [[], []]

# 查找前两个字符串中相同的大写英文字母
for i, (a, b) in enumerate(zip(info_str[0], info_str[1])):
    if a.isupper() and a == b:
        special_ch[0].append(a)
        if len(special_ch[0]) == 2:
            break

# 查找后两个字符串中相同的英文字母
for i, (a, b) in enumerate(zip(info_str[2], info_str[3])):
    if a.isalpha() and a == b:
        special_ch[1].append(i)
        break

# 解析日期和时间
day = week_day[special_ch[0][0]]
hh = 10 + ord(special_ch[0][1]) - ord('A')
mm = special_ch[1][0]

# 输出结果
print(f"{day} {hh:02d}:{mm:02d}")
