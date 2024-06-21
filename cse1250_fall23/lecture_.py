score - input('Please enter your grade: ').upper()

while score not in ('A', 'B', 'C', 'D', 'F'):
    score = input('Please enter a valid grade: ').upper()

print('Good Job!')
