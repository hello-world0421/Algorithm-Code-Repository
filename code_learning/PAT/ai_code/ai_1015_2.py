from typing import Dict, Tuple, List

def read_input() -> Tuple[int, int, int, Dict[str, Dict[str, int]]]:
    N, L, H = map(int, input().split())
    stu_scores: Dict[str, Dict[str, int]] = {}
    for _ in range(N):
        info = input().split()
        stu_scores[info[0]] = {'德分': int(info[1]), '才分': int(info[2])}
    return N, L, H, stu_scores

def categorize_students(N: int, L: int, H: int, stu_scores: Dict[str, Dict[str, int]]) -> Tuple[int, Dict[str, List[Tuple[str, int, int]]]]:
    categories = {
        'first_stu': [],
        'second_stu': [],
        'third_stu': [],
        'end_stu': [],
    }
    for stu, score in stu_scores.items():
        de_score, cai_score = score['德分'], score['才分']
        if de_score < L or cai_score < L:
            N -= 1
            continue
        if de_score >= H and cai_score >= H:
            categories['first_stu'].append((stu, de_score, cai_score))
        elif de_score >= H:
            categories['second_stu'].append((stu, de_score, cai_score))
        elif de_score >= cai_score:
            categories['third_stu'].append((stu, de_score, cai_score))
        else:
            categories['end_stu'].append((stu, de_score, cai_score))
    return N, categories

def print_sorted_students(N: int, categories: Dict[str, List[Tuple[str, int, int]]]):
    print(N)
    for category in ['first_stu', 'second_stu', 'third_stu', 'end_stu']:
        for stu, de_score, cai_score in sorted(categories[category], key=lambda x: (-(x[1] + x[2]), -x[1], x[0])):
            print(stu, de_score, cai_score)

def main():
    N, L, H, stu_scores = read_input()
    N, categories = categorize_students(N, L, H, stu_scores)
    print_sorted_students(N, categories)

if __name__ == "__main__":
    main()
