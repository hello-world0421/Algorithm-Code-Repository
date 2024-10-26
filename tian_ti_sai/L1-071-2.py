class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        if self.root is None:
            self.root = TreeNode(value)
        else:
            self._insert_recursively(self.root, value)

    def _insert_recursively(self, current_node, value):
        if value < current_node.value:
            if current_node.left is None:
                current_node.left = TreeNode(value)
            else:
                self._insert_recursively(current_node.left, value)
        else:
            if current_node.right is None:
                current_node.right = TreeNode(value)
            else:
                self._insert_recursively(current_node.right, value)

    def inorder_traversal(self, node):
        if node is not None:
            self.inorder_traversal(node.left)
            print(node.value)
            self.inorder_traversal(node.right)

# 创建一个二叉树
tree = BinaryTree()

# 插入节点
tree.insert(5)
tree.insert(3)
tree.insert(8)
tree.insert(2)
tree.insert(4)
tree.insert(7)
tree.insert(9)

# 中序遍历
tree.inorder_traversal(tree.root)

