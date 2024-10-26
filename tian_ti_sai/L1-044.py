k = int(input())
s = []
victor = {"ChuiZi": "Bu",
          "Bu": "JianDao",
          "JianDao": "ChuiZi"}
while (temp := input()) != "End":
    s.append(temp)
for i in range(len(s)):
    if i % (k+1) == k:
        print(s[i])
    else:
        print(victor[s[i]])
