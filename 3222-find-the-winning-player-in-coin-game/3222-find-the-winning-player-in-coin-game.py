class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        return ["Bob", "Alice"][min(x, y // 4) % 2]