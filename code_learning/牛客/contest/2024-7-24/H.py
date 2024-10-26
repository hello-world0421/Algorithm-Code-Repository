messages: dict[str, list[str]] = {}
for _ in range(int(input())):
    name, num, *info = input().split()
    messages[name] = messages.get(name, []) + info
for name, info in messages.items():
    temp = list(info)
    for ch in set(info):
        for c in info:
            if ch == c:
                continue
            if ch.endswith(c) and c in temp:
                temp.remove(c)
    messages[name] = sorted(set(temp))
print(len(messages.keys()))
for name in sorted(messages.keys()):
    print(f"{name} {len(messages[name])}", *messages[name])