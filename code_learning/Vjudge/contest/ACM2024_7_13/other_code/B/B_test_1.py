def stable_marriage(men_preferences, women_preferences):
    men = list(men_preferences.keys())
    women = list(women_preferences.keys())
    free_men = set(men)
    engaged = {}
    proposals = {m: 0 for m in men}

    while free_men:
        for man in list(free_men):
            woman = men_preferences[man][proposals[man]]
            proposals[man] += 1
            if woman not in engaged:
                engaged[woman] = man
                free_men.remove(man)
            else:
                current_man = engaged[woman]
                if women_preferences[woman].index(man) < women_preferences[woman].index(current_man):
                    engaged[woman] = man
                    free_men.remove(man)
                    free_men.add(current_man)

    return engaged

men_preferences = {
    "A": ["X", "Y", "Z"],
    "B": ["Y", "Z", "X"],
    "C": ["Z", "X", "Y"]
}

women_preferences = {
    "X": ["C", "B", "A"],
    "Y": ["B", "A", "C"],
    "Z": ["A", "C", "B"]
}

engaged_couples = stable_marriage(men_preferences, women_preferences)
print(engaged_couples)