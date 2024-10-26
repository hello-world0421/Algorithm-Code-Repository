def genarete_raw_string(s):
    raw_s = ''
    for i in range(len(s)-1):
        if int(s[i]) % 2 == int(s[i+1]) % 2:
            raw_s += max(s[i], s[i+1])
    return raw_s

s1 = input()
s2 = input()
raw_s1 = genarete_raw_string(s1)
raw_s2 = genarete_raw_string(s2)
if raw_s1 == raw_s2:
    print(raw_s1)
else:
    print(raw_s1)
    print(raw_s2)
