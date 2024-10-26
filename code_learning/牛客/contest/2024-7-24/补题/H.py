info: dict[str, list[str]] = {}
for _ in range(int(input())):
    name, cnt, *meses = input().split()
    info[name] = info.get(name, []) + meses
    temp = list(info[name])
    for ch in set(info[name]):
        for c in set(info[name]):
            if ch != c and ch.endswith(c):
                while c in temp:
                    temp.remove(c)
    info[name] = list(set(temp))
print(len(info.keys()))
for name, mes in sorted(info.items(), key=lambda x: x[0]):
    print(f"{name} {len(mes)} {' '.join(sorted(mes))}")