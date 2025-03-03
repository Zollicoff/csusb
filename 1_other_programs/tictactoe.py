# Tic Tac Toe Game in Python

def print_board(board):
    print(f"\n {board[0]} | {board[1]} | {board[2]} ")
    print("---+---+---")
    print(f" {board[3]} | {board[4]} | {board[5]} ")
    print("---+---+---")
    print(f" {board[6]} | {board[7]} | {board[8]} \n")

def check_win(board, player):
    # Check horizontal, vertical, and diagonal win conditions
    win_conditions = [
        [0,1,2], [3,4,5], [6,7,8],  # rows
        [0,3,6], [1,4,7], [2,5,8],  # columns
        [0,4,8], [2,4,6]            # diagonals
    ]
    for condition in win_conditions:
        if board[condition[0]] == board[condition[1]] == board[condition[2]] == player:
            return True
    return False

def check_tie(board):
    return all([space != ' ' for space in board])

def play_game():
    board = [' '] * 9
    current_player = 'X'

    while True:
        print_board(board)

        try:
            move = int(input(f"{current_player}'s turn. Enter a position (1-9): ")) - 1
            if move < 0 or move > 8 or board[move] != ' ':
                print("Invalid input or spot taken. Try again.")
                continue
        except ValueError:
            print("Please enter a valid number (1-9).")
            continue

        board[move] = current_player

        if check_win(board, current_player):
            print_board(board)
            print(f"Congratulations! Player {current_player} wins!")
            break

        if check_tie(board):
            print_board(board)
            print("It's a tie!")
            break

        current_player = 'O' if current_player == 'X' else 'X'

if __name__ == "__main__":
    play_game()