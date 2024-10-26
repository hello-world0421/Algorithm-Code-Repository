def convert(B, num):
    ans = []
    while num > 0:
        num, rem = divmod(num, B)
        if rem <= 9:
            ans.append(str(rem))
        else:
            ans.append(chr(ord('A') + rem - 10))
    return ''.join(ans[::-1])

B = int(input())
for num in range(1, 301):
    s = convert(B, num ** 2)
    if s == s[::-1]:
        s0 = convert(B, num)
        print(s0, s)
