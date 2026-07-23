# https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        directions = [
            [-1, 0],
            [0, -1],
            [0, 1],
            [1, 0]
        ]

        dq = deque([entrance])
        visited = {tuple(entrance)}
        steps = 0

        while len(dq) > 0:
            steps += 1

            for _ in range (len(dq)):
                cell = dq.popleft()

                for direction in directions:
                    newRow = cell[0] + direction[0]
                    newCol = cell[1] + direction[1]

                    if self.isValid(maze, entrance, [newRow, newCol], visited):
                        if self.isExit(maze, [newRow, newCol]):
                            return steps
                        dq.append([newRow, newCol])
                        visited.add(tuple([newRow, newCol]))

        return -1

    def isValid(self,  maze: List[List[str]], entrance: List[int], cell: List[int],  visited: set) -> bool:
        if cell[0] < 0 or cell[0] >= len(maze):
            return False
        if cell[1] < 0 or cell[1] >= len(maze[0]):
            return False
        if maze[cell[0]][cell[1]] != ".":
            return False
        if tuple(cell) in visited:
            return False
        return True

    def isExit(self, maze: List[List[str]], cell: List[int]) -> bool:
        return cell[0] == 0 or cell[0] == len(maze) - 1 or cell[1] == 0 or cell[1] == len(maze[0]) - 1