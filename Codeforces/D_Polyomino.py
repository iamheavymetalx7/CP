#!/usr/bin/env python3

YES = "Yes"  # type: str
NO = "No"  # type: str

def can_fill_grid(polyominos):
    def dfs(index):
        if index == 3:
            return True

        for r in range(4):
            for c in range(4):
                if grid[r][c] == '.' and can_place(polyominos[index], r, c):
                    place(polyominos[index], r, c)
                    if dfs(index + 1):
                        return True
                    remove(polyominos[index], r, c)
        return False

    def can_place(polyomino, r, c):
        for i in range(4):
            for j in range(4):
                if polyomino[i][j] == '#' and (r + i >= 4 or c + j >= 4 or grid[r + i][c + j] == '#'):
                    return False
        return True

    def place(polyomino, r, c):
        for i in range(4):
            for j in range(4):
                if polyomino[i][j] == '#':
                    grid[r + i][c + j] = '#'

    def remove(polyomino, r, c):
        for i in range(4):
            for j in range(4):
                if polyomino[i][j] == '#':
                    grid[r + i][c + j] = '.'

    grid = [['.' for _ in range(4)] for _ in range(4)]
    return "Yes" if dfs(0) else "No"


def main():
  polyominos = []
  for _ in range(3):
      polyomino = [input().split() for _ in range(4)]
      polyominos.append(polyomino)

  result = can_fill_grid(polyominos)
  print(result)

if __name__ == '__main__':
  main()