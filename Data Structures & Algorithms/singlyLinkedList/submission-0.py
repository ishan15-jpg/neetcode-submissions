class Node: 
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.length = 0
        self.head = None
        self.tail = None
    
    def get(self, index: int) -> int:
        if index >= self.length : return -1
        temp, i = self.head, 0
        while i < index:
            temp = temp.next
            i += 1
        return temp.val

    def insertHead(self, val: int) -> None:
        if not self.head : 
            self.head = self.tail = Node(val) 
            self.length += 1
            return
        temp = self.head
        self.head = Node(val)
        self.head.next = temp
        self.length += 1

    def insertTail(self, val: int) -> None:
        if not self.tail :
            self.head = self.tail = Node(val)
            self.length += 1
            return
        temp = self.tail
        self.tail = Node(val)
        temp.next = self.tail
        self.length += 1

    def remove(self, index: int) -> bool:
        if index >= self.length : return False
        if index == 0 : 
            temp = self.head
            self.head = self.head.next
            temp.next = None
            self.length -= 1
            return True
        prev,curr,i = None, self.head, 0
        while i < index :
            prev,curr = curr,curr.next
            i += 1
        prev.next = curr.next
        curr.next = None
        if index == self.length - 1 :
            self.tail = prev
        self.length -= 1
        return True
        
    def getValues(self) -> List[int]:
        if not self.head : return []
        temp, values = self.head, []
        while temp :
            values.append(temp.val)
            temp = temp.next
        return values
