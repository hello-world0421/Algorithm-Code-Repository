import sys

s = input()
if 1 <= int(s[3:6]) < 350 and int(s[3:6]) != 316:
    ans = "Yes"
else:
    ans = "No"
sys.stdout.write(ans)