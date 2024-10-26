temp = input()
person = []
while temp != '.':
    person.append(temp)
    temp = input()
if len(person) < 2:
    print("Momo... No one is for you ...")
elif 2 <= len(person) < 14:
    print(f"{person[1]} is the only one for you...")
else:
    print(f"{person[1]} and {person[13]} are inviting you to dinner...")
