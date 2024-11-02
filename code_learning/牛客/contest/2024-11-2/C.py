artical = input().replace(',', '').replace('.', '').split()
dict = {}
for char in artical:
    dict[char] = dict.get(char, 0) + 1
for char, cnt in sorted(dict.items(), key=lambda a: (-a[1], a[0])):
    print(char, cnt)