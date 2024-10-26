for _ in range(int(input())):
    s = input()
    if len(s) == 1:
        if s[0] != 'z':
            s = s + chr(ord(s[0]) + 1)
        else:
            s = s + chr(ord(s[0]) - 1)
        print(s)
    else:
        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:

                if s[i] != 'z':
                    s = s[:i + 1] + chr(ord(s[i]) + 1) + s[i + 1:]
                else:
                    s = s[:i + 1] + chr(ord(s[i]) - 1) + s[i + 1:]
                break
        else:
            if s[-1] != 'z':
                s = s + chr(ord(s[-1]) + 1)
            else:
                s = s + chr(ord(s[-1]) - 1)
        print(s)