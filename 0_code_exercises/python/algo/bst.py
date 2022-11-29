class Node:
    def __init__(self, val):
        self.right = None
        self.left = None
        self.val = val


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, val):
        new_node = Node(val)
        if self.root is None:
            self.root = new_node
            return

        curr_node = self.root
        while True:
            if val == curr_node.val:
                return
            elif val > curr_node.val:
                if curr_node.right:
                    curr_node = curr_node.right
                else:
                    curr_node.right = new_node
                    break
            else:
                if curr_node.left:
                    curr_node = curr_node.left
                else:
                    curr_node.left = new_node
                    break

    def lookup(self, val, find_parent=False):
        node = self.root
        if node is None:
            return

        while node:
            if node.val == val:
                return node
            elif val > node.val and node.right:
                if find_parent and node.right.val == val:
                    return node
                node = node.right
            elif node.left:
                if find_parent and node.left.val == val:
                    return node
                node = node.left
            else:
                return None
        return node

    def remove(self, val):
        parent = self.lookup(val, find_parent=True)
        if not parent:
            return

        if parent.val == val:  # if its root, bcs we cant return parent of root
            direction = None
            node = parent
        elif parent.left.val == val:
            direction = 0
            node = parent.left
        else:
            direction = 1
            node = parent.right

        if node.right:
            temp = node.right
            temp_parent = node
        else:
            temp = node
            temp_parent = parent

        while True:
            if temp.left:
                temp_parent = temp
                temp = temp.left
            else:
                break

        if temp == node:
            temp = None
        else:
            if temp_parent.left == temp:
                temp_parent.left = None
            else:
                temp_parent.right = None
            temp.left = node.left
            temp.right = node.right

        if direction == 1:
            parent.right = temp
        elif direction == 0:
            parent.left = temp
        else:
            self.root = temp


test = BinarySearchTree()
test.insert(9)
test.insert(4)
test.insert(6)
test.insert(20)
test.insert(170)
test.insert(15)
test.insert(1)
test.remove(20)
print()
