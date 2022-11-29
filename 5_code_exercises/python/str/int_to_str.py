class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

    def append(self, val):
        self.root = getattr(self, "root", self)
        i = self.root
        while i.next:
            i = i.next
        i.next = Node(val)

    def print(self):
        c = ""
        i = self.root
        while i.next:
            c += str(i.val)
            i = i.next
        c += str(i.val)
        return c


def int_to_str(n):
    c = None
    while 1:
        n, m = divmod(n, 10)
        if c is None:
            c = Node(m)
        else:
            c.append(m)
        if n == 0:
            break
    return c.print()


print(int_to_str(1234567890))