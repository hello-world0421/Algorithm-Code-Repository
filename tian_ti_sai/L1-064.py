n = int(input())
for i in range(n):
    s = input()
    print(s)
    s = s.strip()
    s = ' '.join(s.split())
    for i in range(len(s)):
        if s[i] == "I":
            continue
        else:
            s = s.replace(s[i], s[i].lower())
    s = s.replace("can you", "I can")
    s = s.replace("could you", "I could")
    s = s.replace("me", "you")
    s = s.replace("I", "you")
    s = s.replace("?", "!")
    print(f"AI: {s}")

def reply_to_questions(text):
    sentences = text.split("?")
    for sentence in sentences:
        if sentence.strip():
            print(sentence.strip() + "?")
            print("AI: " + sentence.strip().lower() + "!")
