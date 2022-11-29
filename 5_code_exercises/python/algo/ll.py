# class DoublyLinkedList:
#     class Node:
#         def __init__(self, val):
#             self.val = val
#             self.head = None
#             self.next = None

#     def __init__(self, val=0):
#         self.head = DoublyLinkedList.Node(val)
#         self.tail = self.head
#         self.length = 1

#     def is_empty(self):
#         return self.tail is self.head

#     def print_list(self):
#         temp = self.head
#         while temp is not None:
#             print(temp.val, end=' ')
#             temp = temp.next
#         print()

#     def push(self, val):
#         new_node = DoublyLinkedList.Node(val)
#         new_node.head = self.tail
#         self.tail.next = new_node
#         self.tail = new_node
#         self.length += 1

#     def push_front(self, val):
#         old_head = self.head
#         new_node = DoublyLinkedList.Node(val)
#         self.head = new_node
#         self.head.next = old_head
#         old_head.head = new_node
#         self.length += 1

#     def pop(self):
#         self.tail.head.next = None
#         self.tail = self.tail.head
#         self.length -= 1

#     def pop_front(self):
#         self.head.next.head = self.head.next
#         self.head = self.head.next
#         self.length -= 1

#     def remove(self, pos):
#         if pos == 0:
#             return self.pop_front()
#         elif pos >= self.length:
#             return self.pop()

#         prev_node = self.get_node_at(pos - 1)
#         next_node = prev_node.next.next
#         next_node.head = prev_node
#         prev_node.next = next_node

#         self.length -= 1

#     def get_node_at(self, pos):
#         counter = self.head
#         for i in range(pos + 1):
#             if i == pos:
#                 return counter
#             counter = counter.next

#     def insert(self, val, pos):
#         if pos == 0:
#             return self.push_front(val)
#         elif pos >= self.length:
#             return self.push(val)

#         new_node = DoublyLinkedList.Node(val)

#         prev_node = self.get_node_at(pos - 1)
#         new_node.next = prev_node.next
#         prev_node.next = new_node

#         self.length += 1


# # 4 5 10 16
# test_ll = DoublyLinkedList(5)
# test_ll.push(10)
# test_ll.push(16)
# test_ll.push_front(4)
# test_ll.print_list()
# test_ll.push(0)
# test_ll.push_front(16)
# test_ll.push(4)
# test_ll.push_front(0)
# # 0 16 4 5 10 16 0 4
# test_ll.print_list()

# # 0 16 4 5 33 10 16 0 4
# test_ll.insert(33, 4)
# test_ll.print_list()

# # 3 0 16 4 5 33 10 16 0 4
# test_ll.insert(3, 0)
# test_ll.print_list()

# # 3 0 16 4 5 33 665 10 16 0 4
# test_ll.insert(665, 6)
# test_ll.print_list()

# # 3 0 16 4 5 33 665 10 16 0 4 999
# test_ll.insert(999, 999)
# test_ll.print_list()

# # 0 16 4 5 33 665 10 16 0 4 999
# test_ll.pop_front()
# test_ll.print_list()

# # 0 16 4 5 33 665 10 16 0 4
# test_ll.pop()
# test_ll.print_list()

# # 0 16 4 33 665 10 16 0 4
# test_ll.remove(3)
# test_ll.print_list()


class LinkedList:
    class Node:
        def __init__(self, val):
            self.val = val
            self.next = None

    def __init__(self, val=0):
        self.head = LinkedList.Node(val)
        self.tail = self.head
        self.length = 1

    def push_front(self, val):
        new_node = LinkedList.Node(val)
        new_node.next = self.head
        self.head = new_node
        self.length += 1

    def push(self, val):
        new_node = LinkedList.Node(val)
        self.tail.next = new_node
        self.tail = new_node
        self.length += 1

    def insert(self, pos, val):
        if pos == 0:
            return self.push_front(val)
        elif pos >= self.length:
            return self.push(val)

        new_node = LinkedList.Node(val)
        prev_node = self.get_node_at(pos - 1)
        current_node = prev_node.next
        new_node.next = current_node
        prev_node.next = new_node
        self.length += 1

    def pop_front(self):
        self.head = self.head.next
        self.length -= 1

    # Horrible
    def pop(self):
        prev_tail_node = self.get_node_at(self.length - 2)
        prev_tail_node.next = None
        self.tail = prev_tail_node
        self.length -= 1

    def remove(self, pos):
        if pos == 0:
            return self.pop_front()
        elif pos >= self.length:
            return self.pop()

        prev_node = self.get_node_at(pos - 1)
        drop_node = prev_node.next
        prev_node.next = drop_node.next
        self.length -= 1

    def reverse(self):
        if self.length == 1:
            return self

        first = self.head
        self.tail = self.head
        second = first.next
        while second:
            after_next = second.next
            second.next = first
            first = second
            second = after_next
        self.head.next = None
        self.head = first

    # Horrible
    def new_reverse(self):
        if self.length < 2:
            return self

        ll = LinkedList(self.tail.val)

        temp_node = self.head
        for i in range(self.length):
            ll.push_front(temp_node.val)
            temp_node = temp_node.next
        ll.pop()

        return ll

    def get_node_at(self, pos):
        temp_node = self.head
        for i in range(pos+1):
            if i == pos:
                return temp_node
            temp_node = temp_node.next
        return

    def print_nodes(self):
        temp_node = self.head
        for i in range(self.length):
            print(temp_node.val, end=' ')
            temp_node = temp_node.next
        print()


# 16 4 33 665 10 16 0
test_sll = LinkedList(665)
test_sll.push(10)
test_sll.push(16)
test_sll.push(0)
test_sll.push_front(33)
test_sll.push_front(4)
test_sll.push_front(16)
test_sll.print_nodes()
# 16 4 33 665 10
test_sll.pop()
test_sll.pop()
test_sll.print_nodes()
# 33 665 10
test_sll.pop_front()
test_sll.pop_front()
test_sll.print_nodes()
# 16 33 33 665 10 16
test_sll.push_front(33)
test_sll.push(16)
test_sll.push_front(16)
test_sll.print_nodes()
# 16 33 33 665
test_sll.pop()
test_sll.pop()
test_sll.print_nodes()
# 16 33 66 99 33 665
test_sll.insert(2, 66)
test_sll.insert(3, 99)
test_sll.print_nodes()
# 665 33 99 66 33 16
reversed_sll = test_sll.new_reverse()
reversed_sll.print_nodes()
# 665 33 99 66 33 16
test_sll.reverse()
test_sll.print_nodes()
