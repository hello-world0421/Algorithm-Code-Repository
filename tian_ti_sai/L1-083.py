l1, l2, y1, y2 = map(int, input().split())
if y1 < l1 and y2 < l1:
    print(f"{y1}-N {y2}-N")
    print("zhang da zai lai ba")
elif y1 < l1 and y2 >= l2:
    print(f"{y1}-Y {y2}-Y")
    print("qing 2 zhao gu hao 1")
elif y1 >= l2 and y2 < l1:
    print(f"{y1}-Y {y2}-Y")
    print("qing 1 zhao gu hao 2")
elif y1 < l1 and l1 <= y2 < l2:
    print(f"{y1}-N {y2}-Y")
    print("2: huan ying ru guan")
elif l1 <= y1 < l2 and y2 < l1:
    print(f"{y1}-Y {y2}-N")
    print("1: huan ying ru guan")
elif y1 >= l1 and y2 >= l1:
    print(f"{y1}-Y {y2}-Y")
    print("huan ying ru guan")
