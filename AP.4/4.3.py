num = 0

def whereis(n, srow, scol, row, col):
    m = n // 2
    if row - srow < m:
        if col - scol < m:
            return 1
        return 2
    else:
        if col - scol < m:
            return 3
        return 4

def fill(n, board, srow, scol, where):
    global num
    if where != 1: board[srow][scol] = num
    if where != 2: board[srow][scol + 1] = num
    if where != 3: board[srow + 1][scol] = num
    if where != 4: board[srow + 1][scol + 1] = num

def hole(part, where, n, srow, scol, row, col):
    m = n // 2
    if part != where:
        row, col = srow + m - 1, scol + m - 1
        if part == 2 or part == 4:
            col += 1
        if part == 3 or part == 4:
            row += 1
    return row, col

def tromino(n, board, srow, scol, row, col):
    global num
    num += 1
    where = whereis(n, srow, scol, row, col)
    if n == 2:
        fill(n, board, srow, scol, where)
    else:
        m = n // 2
        fill(n, board, srow + m - 1, scol + m - 1, where)
        hrow, hcol = hole(1, where, n, srow, scol, row, col)
        tromino(m, board, srow, scol, hrow, hcol)
        hrow, hcol = hole(2, where, n, srow, scol, row, col)
        tromino(m, board, srow, scol + m, hrow, hcol)
        hrow, hcol = hole(3, where, n, srow, scol, row, col)
        tromino(m, board, srow + m, scol, hrow, hcol)
        hrow, hcol = hole(4, where, n, srow, scol, row, col)
        tromino(m, board, srow + m, scol + m, hrow, hcol)

n, row, col = map(int, input().split())
board = [[0 for _ in range(n)] for _ in range(n)]
srow = 0
scol = 0
tromino(n, board, srow, scol, row, col)

for i in range(n):
    for j in range(n-1):
        print(board[i][j], end = " ")
    print(board[i][j+1])
