class pair:

    def __init__(self,key:int,val:str):
        self.key=key
        self.val=val


class arrayhashmap:

    def __init__(self):

        self.buckets:list[pair|None]=[None]*100

        
    def hash_func(self,key:int)->int:
        index=key%100
        return index
        
    def get(self,key:int)->str:
            
        index:int=self.hash_func(key)
        p :pair=self.buckets[index]
        if p is None:
            return None
        return p.val
        

    def put(self,key:int,val:str):

        p=pair(key,val)
        index:int=self.hash_func(key)
        self.buckets[index]=p

    def remove(self,key:int):
        index:int=self.hash_func(key)
        self.buckets[index]=None


    def entry_set(self)->list[pair]:
        
        results:list[pair]=[]

        for  p in self.buckets:
            if p is not None:
                results.append(p)

        return results
    
    def key_set(self)->list[int]:
        
        result=[]
        for p in self.buckets:
            if p is not None:
                result.append(p.key)

        return result
    
    def value_set(self)->list[str]:
        
        result=[]
        for p in self.buckets:
            if p is not None:
                result.append(p.val)

        return result
    
    def print(self):

        for p in self.buckets:
            if p is not None:
                print(p.key,"->",p.val)

    
if __name__=="__main__":

    hmap=arrayhashmap()

    hmap.put(12836, "小哈")
    hmap.put(15937, "小囉")
    hmap.put(16750, "小算")
    hmap.put(13276, "小法")
    hmap.put(10583, "小鴨")

    name=hmap.get(15937)

    hmap.remove(10583)

    for pair in hmap.entry_set():
        print(pair.key,"->",pair.val)

        
    