class ListNode:

	def __init__(self,val:int):
		self.val:int=val
		self.next:ListNode | None=None

class linkedliststack:
    
	def __init__(self):

		self._peek: ListNode | None=None
		self._size:int=0

	def size(self)->int:
		return self._size
	
	def is_empty(self)->bool:
		return self.size==0
	
	def push(self,val:int):

		node=ListNode(val)
		node.next=self._peek
		self._peek=node
		self._size+=1

	def pop(self)->int:
		num=self.peek()
		self._peek=self._peek.next
		self._size-=1
		return num
	
	def peek(self)->int:
		if self.is_empty():
			raise IndexError("stack is empty")
		
		return self._peek.val
	
	def to_list(self)->list[int]:
		arr=[]
		node=self._peek
		while node:
			arr.append(node.val)
			node=node.next

		arr.reverse()
		return arr
	

if __name__=="__main__":

	stack=linkedliststack()

	stack.push(1)
	stack.push(3)
	stack.push(2)
	stack.push(4)
	stack.push(5)
	stack.push(6)

	print("stack = ",stack.to_list())

	peek=stack.peek()
	print("peek = ",peek)

	pop=stack.pop()

	print("pop=",pop)
	print("stack =",stack.to_list())


	size=stack.size()
	print("size=",size)

	is_empty=stack.is_empty()
	print("check stack is empty?",is_empty)
	
