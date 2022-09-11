class Solution:
    def lengthOfLIS(self, nums: List[int], k: int) -> int:
        n = 2 ** int(math.log2(len(nums) + 1) + 1)
        segtree = [0] * 1000002

        def update(i, x):
            i += n
            while i:
                segtree[i] = max(segtree[i], x)
                i //= 2

        def query(i, j):
            ans = -float("inf")
            i += n
            j += n + 1
            while i < j:
                if i % 2 == 1:
                    ans = max(ans, segtree[i])
                    i += 1
                if j % 2 == 1:
                    j -= 1
                    ans = max(ans, segtree[j])
                i //= 2
                j //= 2
            return ans

        snums = sorted(nums)
        index = {x: i for i, x in enumerate(snums)}

        ans = 0
        for x in nums:
            lo = bisect.bisect_left(snums, x - k)
            hi = bisect.bisect_right(snums, x - 1) - 1
            count = max(query(lo, hi), 0)
            
            update(index[x], count + 1)
            ans = max(ans, count + 1)
        return ans