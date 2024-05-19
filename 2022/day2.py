## Part 1 ##
"""Game Rules"""
"""
game_rules = {'A': {'X':'Draw','Y':'Win','Z':'Lose'},
            'B':{'X':'Lose','Y':'Draw','Z':'Win'},
            'C':{'X':'Win','Y':'Lose','Z':'Draw'}}

def parser():
    #Parse the Input File
    game_results = {'A': {'X': 0,'Y': 0,'Z': 0},
                    'B':{'X': 0,'Y': 0,'Z': 0},
                    'C':{'X': 0,'Y': 0,'Z': 0}}
    with open("input-day2.txt", "r") as f:
        ## Parse Input File ##
        for i, line in enumerate(f):
            game_results[line[0]][line[2]] += 1
    return game_results

def determine_score(game_results):
    #Determine Score Based on Score Conditions
    game_score = {'Win': 6, 'Draw': 3, 'Lose': 0}
    selection_score = {'X': 1, 'Y': 2, 'Z': 3}
    score = 0
    for elf_move in game_results:
        for player_move in game_results[elf_move]:
            score += (selection_score[player_move] +
            game_score[game_rules[elf_move][player_move]])\
                 * game_results[elf_move][player_move]
    return score

game_results = parser() # Dictionary of Results
print(f'The final score is {determine_score(game_results)}') # Final Score
"""

#part2
f = open("input-day2.txt").read().split("\n")

score = 0

for i in f:
    a,b = i.split(" ")
    if b == "X": # lose
        #score += 0
        if a == "A":
            score += 3
        elif a == "B":
            score += 1
        elif a == "C":
            score += 2
    elif b == "Y": # draw
        score += 3
        if a == "A":
            score += 1
        elif a == "B":
            score += 2
        elif a == "C":
            score += 3
    elif b == "Z": # win
        score += 6
        if a == "A":
            score += 2
        elif a == "B":
            score += 3
        elif a == "C":
            score += 1

print(score)
