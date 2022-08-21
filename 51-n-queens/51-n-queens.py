class Solution:    
    
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = []
        for i in range(n):
            row = []
            for j in range(n):
                row.append(".")
            board.append(row)
        
        result = []
    
        def is_safe(row, col, n, board):
            # print(row, col)
            for j in range(col):
                if board[row][j] == "Q":
                    return False

            i, j = row, col
            while i >= 0 and j >= 0:
                if board[i][j] == "Q":
                    return False
                i -= 1
                j -= 1

            i, j = row, col
            while i < n and j >= 0:
                if board[i][j] == "Q":
                    return False
                i += 1
                j -= 1

            return True

        def solve(col, n, board, result):
            def display_board(board):
                for row in board:
                    print(row)
            
            if col == n:
                # display_board(board)
                # print()
                curr = [''.join(r) for r in board]
                result.append(curr)
                return

            # print(col)
            for row in range(n):
                if is_safe(row, col, n, board):
                    board[row][col] = "Q"
                    # display_board(board)
                    # print()
                    solve(col+1, n, board, result)
                    board[row][col] = "."
        
        # print("Initial Board")
        
        
        # display_board(board)
        
        solve(0, n, board, result)
        return result