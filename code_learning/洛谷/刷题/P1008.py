for a in range(123, 988):
    if a * 3 >= 1000:
        break
    ans = f"{a} {a * 2} {a * 3}"
    for i in range(1, 10):
        if f"{i}" not in ans:
            break
    else:
        print(ans)