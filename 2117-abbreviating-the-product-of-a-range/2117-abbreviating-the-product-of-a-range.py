class Solution:
    def abbreviateProduct(self, left: int, right: int) -> str:
        sys.set_int_max_str_digits(0)
        ans = str(prod(list(range(left, right+1))))
        prefix = ans.rstrip('0')
        zero = len(ans) - len(prefix)
        if len(prefix) > 10:
            return f"{prefix[:5]}...{prefix[-5:]}e{str(zero)}"
        return f"{prefix}e{str(zero)}"
