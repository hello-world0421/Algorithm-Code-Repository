pa, pb = map(int, input().split())
w = list(map(int, input().split()))
if sum(w) == 0:
    print(f"The winner is a: {pa} + 3")
elif sum(w) == 3:
    print(f"The winner is b: {pb} + 3")
elif pa > pb and w.count(0) >= 1:
    print(f"The winner is a: {pa} + {w.count(0)}")
elif pb > pa and w.count(1) >= 1:
    print(f"The winner is b: {pb} + {w.count(1)}")
