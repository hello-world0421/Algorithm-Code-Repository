num: int = int(input())
s_num: str = '0' * (4 - len(str(num))) + str(num)

if len(set(s_num)) == 1 and len(s_num) == 4:
    print(f"{s_num} - {s_num} = 0000")
elif num == 6174:
    num_1: str = ''.join(sorted(s_num))
    num_2: str = ''.join(sorted(s_num, reverse=True))
    s_num: str = '0' * (4 - len(str(num))) + str(num)

    print(f"{num_2} - {num_1} = {s_num}")
else:
    while num != 6174:
        num_1: str = ''.join(sorted(s_num))
        num_2: str = ''.join(sorted(s_num, reverse=True))

        num: int = int(num_2) - int(num_1)
        s_num: str = '0' * (4 - len(str(num))) + str(num)

        print(f"{num_2} - {num_1} = {s_num}")
