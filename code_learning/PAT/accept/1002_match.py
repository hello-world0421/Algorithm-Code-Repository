nums: list[int] = list(map(int, list(input())))

ans: list[str] = []

for num in str(sum(nums)):
    match num:
        case '0':
            ans.append('ling')
        case '1':
            ans.append('yi')
        case '2':
            ans.append('er')
        case '3':
            ans.append('san')
        case '4':
            ans.append('si')
        case '5':
            ans.append('wu')
        case '6':
            ans.append('liu')
        case '7':
            ans.append('qi')
        case '8':
            ans.append('ba')
        case '9':
            ans.append('jiu')

print(' '.join(ans))
