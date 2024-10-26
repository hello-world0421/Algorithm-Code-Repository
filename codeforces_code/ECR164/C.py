t = int(input())
for _ in range(t):
    num1 = list(input())
    num2 = list(input())
    flag = 1
    for i in range(len(num1)):
        if flag == 1:
            if num1[i] < num2[i]:
                num1[i], num2[i] = num2[i], num1[i]
                flag = 2
            elif num1[i] > num2[i]:
                flag = 2
        elif flag == 2:
            if num1[i] > num2[i]:
                num1[i], num2[i] = num2[i], num1[i]
    print(''.join(num1), ''.join(num2), sep='\n')