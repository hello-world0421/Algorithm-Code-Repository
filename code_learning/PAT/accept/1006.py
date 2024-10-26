num: list[int] = list(map(int, list(input())))

output: str = ''
if len(num) >= 1:
    output += ''.join(map(str, range(1, num[-1] + 1)))
if len(num) >= 2:
    output = 'S' * num[-2] + output
if len(num) >= 3:
    output = 'B' * num[-3] + output

print(output)
