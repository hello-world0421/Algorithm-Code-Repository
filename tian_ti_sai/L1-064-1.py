import re

def english_qa(sentence):
    # 消除原文中多余空格
    sentence = ' '.join(sentence.split())

    # 把原文中所有大写英文字母变成小写，除了 I
    sentence = re.sub(r'(?<!I)[A-Z](?![a-z])', lambda x: x.group().lower(), sentence)

    # 把原文中所有独立的 can you、could you 对应地换成 I can、I could
    # sentence = re.sub(r'\b(can|could) you\b', lambda x: 'I ' + x.group(), sentence)
    sentence = re.sub(r'\b(can) you\b', r'I \1', sentence)
    sentence = re.sub(r'\b(could) you\b', r'I \1', sentence)

    # 把原文中所有独立的 I 和 me 换成 you
    sentence = re.sub(r'\bI\b', 'you', sentence)
    sentence = re.sub(r'\bme\b', 'you', sentence)

    # 把原文中所有的问号 ? 换成惊叹号 !
    sentence = sentence.replace('?', '!')

    return sentence

# 测试
user_input = " Can you help me? "
print(user_input)
response = english_qa(user_input)
print(response)
