class pair:

    def __init__(self,key:int,val:str):
        self.key=key
        self.val=val

class hashchaining:

    def __init__(self):

        self.size=0
        self.capacity=4
        self.load_thres=2.0/3.0 #負載因子，超過就擴充容量
        self.extend_ratio=2 #擴充兩倍
        self.buckets=[[] for _ in range(self.capacity)] #bucket array

    def hash_func(self,key:int)->int:
        return key%self.capacity
    
    def load_factor(self)->float:
        return self.size/self.capacity
    
    def get(self,key:int)->str|None:
        index=self.hash_func(key)
        bucket=self.buckets[index]
        
        for pair in bucket:
            if pair.key==key:
                return pair.val
            
        return None
    
    def put(self,key:int,val:str):
        
        if self.load_factor() > self.load_thres:
            self.extend()

        index=self.hash_func(key)
        bucket=self.buckets[index]

        for p in bucket:
            if p.key==key:
                p.val=val
                return
        
        p=pair(key,val)
        bucket.append(p)
        self.size+=1

    def remove(self,key:int):
        index=self.hash_func(key)
        bucket=self.buckets[index]

        for pair in bucket:
            if pair.key==key:
                bucket.remove(pair)
                self.size-=1
                break

    def extend(self):

        buckets=self.buckets
        self.capacity*=self.extend_ratio
        self.buckets=[[] for _ in range(self.capacity)]

        self.size=0

        for bucket in buckets:
            for pair in bucket:
                self.put(pair.key,pair.val)


    def print(self):

        for bucket in self.buckets:
            res=[]
            for pair in bucket:
                res.append(str(pair.key)+"->"+pair.val)
            print(res)

if __name__=="__main__":

    hashmap=hashchaining()

    hashmap.put(12836, "小哈")
    hashmap.put(15937, "小囉")
    hashmap.put(15938, "三金")
    hashmap.put(16750, "小算")
    hashmap.put(13276, "乙方")
    hashmap.put(10583, "乙包")
    hashmap.put(13676, "真善美")
    hashmap.put(85423, "火龍果")
    hashmap.put(66666, "好棒棒")


    name=hashmap.get(13276)

    hashmap.remove(12836)

    hashmap.print()

    
        
        