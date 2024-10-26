import string

def generate_lexicographic_sequences(L):
    alphabet = string.ascii_lowercase  # 获取小写英文字母表
    base = len(alphabet)
    total_strings = base ** L  # 确定序列的总长度
    sequences = []

    for i in range(total_strings):
        sequence = ''
        temp = i
        for _ in range(L):
            sequence = alphabet[temp % base] + sequence
            temp //= base
        sequences.append(sequence)

    return sequences

def find_nth_lexicographic_sequence(L, N):
    sequences = generate_lexicographic_sequences(L)
    return sequences[-N]

L, N = map(int, input().split())
result = find_nth_lexicographic_sequence(L, N)
print(result)
