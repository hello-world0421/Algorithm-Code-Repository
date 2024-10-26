S = input()
if S[0] == "<" and S[-1] == ">" and "<" not in S[1:-1] and ">" not in S[1:-1]:
    print("Yes")
else:
    print("No")
