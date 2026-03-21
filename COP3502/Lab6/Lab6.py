def initialize_board(num_rows, num_cols):
    board = [["-" for i in range(num_cols)] for j in range(num_rows)]
    return board

def print_board(board):
    reversed_board = board[::-1]
    for row in reversed_board:
        for col in row:
            print(col, end=" ")
        print()
row = 0
def insert_chip(board, col, chip_type):
    global row
    for row in range(len(board)):
        if board[row][col] == "-" :
            board[row][col] = chip_type
            break

def check_if_winner(board, col, row, chip_type):
    count = 1
    c = col - 1
    while c >= 0 and board[row][c] == chip_type:
        count += 1
        c -= 1
    negative_col = -1 * (len(board[0]) - col)
    c = negative_col + 1
    while c <= -1  and board[row][c] == chip_type:
        count += 1
        c += 1
    if count >= 4:
        return True
    count = 1
    c = row - 1
    while c >= 0 and board[c][col] == chip_type:
        count += 1
        c -= 1
    negative_row = -1 * (len(board) - row)
    c = negative_row + 1
    while c <= -1 and board[c][col] == chip_type:
        count += 1
        c += 1
    if count >= 4:
        return True
    return False



def main():
    height = int(input("What would you like the height of the board to be? "))
    length = int(input("What would you like the length of the board to be? "))
    board = initialize_board(height, length)
    print_board(board)
    print()
    print("Player 1: x")
    print("Player 2: o")
    print()
    max_move = height * length
    move = 0
    tie = True
    while move < max_move:
        col = int(input("Player 1: Which column would you like to choose? "))
        insert_chip(board, col, "x")
        print_board(board)
        print()
        if check_if_winner(board, col, row, "x"):
            print("Player 1 won the game!")
            tie = False
            break
        move += 1
        col = int(input("Player 2: Which column would you like to choose? "))
        insert_chip(board, col, "o")
        print_board(board)
        print()
        if check_if_winner(board, col, row, "o"):
            print("Player 2 won the game!")
            tie = False
            break
        move += 1
    if tie:
        print("Draw. Nobody wins.")
if __name__ == "__main__":
    main()

