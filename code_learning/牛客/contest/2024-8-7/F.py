num = map(int, input().split('+'))
num = sorted(num, reverse=True)
print('+'.join(map(str, num)))
print(sum(num))