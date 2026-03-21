import pygame, sys
from constants import *
class Cell:
    def __init__(self, value, row, col):
        self.value = value
        self.row = row
        self.col = col
    def draw(self, screen):
        chip_font = pygame.font.Font(None, CHIP_FONT)

        chip_x_surf = chip_font.render("x", 0, CROSS_COLOR)
        chip_o_surf = chip_font.render("o", 0, CIRCLE_COLOR)

        if self.value == 'x':
            chip_x_rect = chip_x_surf.get_rect(
                center=(self.col * SQUARE_SIZE + SQUARE_SIZE / 2, self.row * SQUARE_SIZE + SQUARE_SIZE / 2))
            screen.blit(chip_x_surf, chip_x_rect)
        elif self.value == 'o':
            chip_o_rect = chip_o_surf.get_rect(
                center=(self.col * SQUARE_SIZE + SQUARE_SIZE / 2, self.row * SQUARE_SIZE + SQUARE_SIZE / 2))
            screen.blit(chip_o_surf, chip_o_rect)
class Board:
    def __init__(self, rows, cols, screen):
        self.rows = rows
        self.cols = cols
        self.screen = screen
        self.board = initialize_board(self)
        self.cells = [
            [Cell(self.board[i][j], i, j) for j in range(self.cols)]
            for i in range(self.rows)
        ]

        def draw(self):
            for i in range(1, BOARD_ROWS):
                pygame.draw.line(
                    screen,
                    LINE_COLOR,
                    (0, i * SQUARE_SIZE),
                    (WIDTH, i * SQUARE_SIZE),
                    LINE_WIDTH
                )
            for i in range(1, BOARD_COLS):
                pygame.draw.line(
                    screen,
                    LINE_COLOR,
                    (i * SQUARE_SIZE, 0),
                    (i * SQUARE_SIZE, HEIGHT),
                    LINE_WIDTH
                )

        for i in range(self.rows):
            for j in range(self.cols):
                self.cells[i][j].draw(self.screen)
def initialize_board(self):
    # 1st approach
    return [["-" for i in range(3)] for j in range(3)]


def print_board(self):
    for row in self.board:    # row: ["-", "-", "-"]
        for col in row:
            print(col, end=" ")
        print()


def available_square(self, row, col):
    return self.board[row][col] == '-'

def mark_square(self, row, col, chip_type):
    self.board[row][col] = chip_type
    self.update_cells()

def update_cells(self):
    self.cells = [
        [Cell(self.board[i][j], i, j) for j in range(self.cols)]
        for i in range(self.rows)
    ]

def board_is_full(self):
    for row in self.board:
        for chip in row:
            if chip == "-":
                return False
    return True


def check_if_winner(self, chip_type):
    # check all rows
    for row in range(3):
        if self.board[row][0] == self.board[row][1] == self.board[row][2] == chip_type:
            return True

    # check all columns
    for col in range(3):
        if self.board[0][col] == self.board[1][col] == self.board[2][col] == chip_type:
            return True

    if self.board[0][0] == self.board[1][1] == self.board[2][2] == chip_type:
        return True
    if self.board[0][2] == self.board[1][1] == self.board[2][0] == chip_type:
        return True

    return False


# row: row index, col: col index
def is_valid(self, row, col):
    if 0 <= row <= 2 and 0 <= col <= 2 and self.board[row][col] == '-':
        return True
    return False
if __name__ == "__main__":
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption('Tic Tac Toe')
    screen.fill(BG_COLOR)
    x = Cell('x', 1, 1)
    x.draw(screen)
    o = Cell('o', 2, 2)
    o.draw(screen)
    board = Board(3, 3, screen)
    board.draw()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        pygame.display.update()