class mylist:
    
	def __init__(self):

		self._capacity: int=10
		self._arr: list[int]=[0]*self._capacity
		self._size:int=0
		self._extend_ratio: int = 2

	def size(self)->int:

		return self._size
	
	def capacity(self)->int:

		return self._capacity
	
	def get(self,index:int)->int:

		if index<0 or index>=self._size:
			raise IndexError("out of bound")
		
		return self._arr[index]
	

	def set(self,num:int,index:int):
		if index<0 or index>=self._size:
			raise IndexError("out of bound")
		
		self._arr[index]=num

	def add(self,num:int):

		if self.size()==self.capacity():
			self.extend_ratio()

		self._arr[self._size]=num
		self._size+=1


	def insert(self,num:int,index:int):
		if index<0 or index>=self._size:
			raise IndexError("out of bound")
		
		if self.size==self.capacity():
			self.extend_ratio()

		for j in range(self._size-1,index-1,-1):
			self._arr[j+1]=self._arr[j]

		self._arr[index]=num

		self._size+=1


	def remove(self,index:int)->int:
		if index<0 or index>=self._size:
			raise IndexError("out of bound")
		
		num=self._arr[index]

		for j in range(index,self._size-1):
			self._arr[j]=self._arr[j+1]

		self._size-=1

		return num
	

	def extend_capacity(self):

		self._arr=self._arr+[0]*self.capacity()*(self._extend_ratio-1)

		self._capacity=len(self._arr)


	def to_array(self)->list[int]:
		return self.arr[:self._size]
	

	

	
	

