from copy import deepcopy
import collections

def findLives(live):
    count = collections.Counter()
    for i, j in live:
        for x in range(i-1, i+2):
            for y in range(j-1, j+2):
                if x == i and y == j: 
                    continue
                count[x, y] += 1
    result = {}
    for i, j in count:
        if count[i, j] == 3:
            result.add((i, j))
        elif count[i, j] == 2 and (i, j) in live:
            result.add((i, j))
    return result

def updateBoard(board):
    live = {(i, j) for i, row in enumerate(board) for j, v in enumerate(row) if v == 1}
    live = findLives(live)
    for r, row in enumerate(board):
        for c, v in enumerate(row):
            board[r][c] = int((r, c) in live)
    for row in board:
        print(" ".join(row))
            
with open("input.txt") as f1:
    prev = f1.readline()
    pointer = f1.readline()
    cur = next_ = None
    while pointer:
        if not cur:
            cur = pointer
            pointer = f1.readline()
            continue
        
        if next_ == None:
            next_ = pointer
            pointer = f1.readline()
        if prev == None:
            tmpBoard = [ cur, next_]
            nextStateBoard = updateBoard(tmpBoard)
        else:
            tmpBoard = [deepcopy(prev), cur, next_]
            nextStateBoard =  updateBoard(tmpBoard)
            
        prev = cur
        cur = next_
        next_ = None