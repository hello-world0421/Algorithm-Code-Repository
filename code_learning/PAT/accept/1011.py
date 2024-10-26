ans: list[str] = []

for i in range(int(input())):
    A, B, C = map(int, input().split())
    if A + B > C:
        ans.append(f"Case #{i + 1}: true")
    else:
        ans.append(f"Case #{i + 1}: false")

print('\n'.join(ans))
