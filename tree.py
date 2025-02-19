class node:

    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None

    
def printorder(node:node):

    if node is None:
        return
    

    printorder(node.left)
    print(node.val,end=' ')
    printorder(node.right)


if __name__=="__main__":
    root=node(1)
    root.left = node(2)
    root.right = node(3)
    root.left.left = node(4)
    root.left.right = node(5)
    root.right.right = node(6)

    printorder(root)
