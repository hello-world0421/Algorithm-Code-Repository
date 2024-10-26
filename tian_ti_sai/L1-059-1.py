def zhaogai_poem(poem):
    upper, lower = poem.split(', ')
    upper_words = upper.split()
    lower_words = lower.split()
    lower_words = lower_words[0:len(lower_words)-1]
    if upper_words[-1][-3:] == "ong" and lower_words[-1][-3:] == "ong":
        lower_words[-3] = "qiao"
        lower_words[-2] = "ben"
        lower_words[-1] = "zhong"
        return ' '.join(upper_words) + ',' + ' '.join(lower_words) + '.'
    else:
        return "Skipped"

n = int(input())
for _ in range(n):
    poem = input()
    result = zhaogai_poem(poem)
    print(result)
