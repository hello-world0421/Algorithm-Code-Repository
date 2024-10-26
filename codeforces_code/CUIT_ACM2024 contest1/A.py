for _ in range(int(input())):
    n, p, q = map(int, input().split())
    a = list(map(int, input().split()))
    negatives, positives = [], []
    for num in a:
        if num > 0:
            positives.append(num)
        elif num < 0:
            negatives.append(num)
    positives.sort(reverse=True)
    negatives.sort()
    ans = sum(positives[:min(p, len(positives))]) - sum(negatives[:min(q, len(negatives))])
    print(ans)