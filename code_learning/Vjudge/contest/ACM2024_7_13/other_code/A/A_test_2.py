class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rob(self, root: TreeNode) -> int:
        def helper(node):
            # 返回 (rob, not_rob)
            if not node:
                return (0, 0)
            
            left = helper(node.left)
            right = helper(node.right)

            # 抢劫当前节点，不能抢劫其子节点
            rob = node.val + left[1] + right[1]
            # 不抢劫当前节点，可以选择抢劫或不抢劫其子节点
            not_rob = max(left) + max(right)

            return (rob, not_rob)
        
        return max(helper(root))