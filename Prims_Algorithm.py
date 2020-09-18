"""
Created on Tue Dec 17 00:56:42 2019

BFS by Bucket Algorithm
"""
def baaltiWithTree(graph,root):
    bucket = []
    Q = []
    parent = {}
    BFSTree = {}  # we introduce a dictionary into the baalti algo to keep track of levels
    BFSTree[root] = 0   # Root is at Level 0
    parent[root] = ''
    bucket.append(root)
    Q.extend(graph[root])
    for v in graph[root]:
        BFSTree[v] = BFSTree[root] + 1  # Vertices adjacent to root are at Level 1
        parent[v] = root

    while len(Q) != 0:
        print(Q, bucket)
        adjacentVertex = Q.pop()  # without 0 in pop, this is a DFS, with 0, BFS
        if adjacentVertex not in bucket:
            bucket.append(adjacentVertex)
            Q.extend(graph[adjacentVertex])
            for v in graph[adjacentVertex]: # every bucket push gets the levels updated as well
                if v not in BFSTree.keys():
                    BFSTree[v] = BFSTree[adjacentVertex] + 1
                    parent[v] = adjacentVertex

    return bucket,BFSTree,parent


def baalti(graph,root):
    bucket = []
    Q = []
    bucket.append(root)   # initially push the root into the bucket
    Q.extend(graph[root]) # initially push the neighbors of root into our Q

    while len(Q) != 0:             # while Q isn't empty, keep looping
        print(Q, bucket)
        adjacentVertex = Q.pop(0)  # without 0 in pop, this is a DFS, with 0, BFS. But why?
        if adjacentVertex not in bucket:
            bucket.append(adjacentVertex)   # if the next vertex in Q not in bucket, push it in
            Q.extend(graph[adjacentVertex]) # and push its neighbors into the Q
    return bucket

       
#Example graph stored in a Python dictionary {key1:value1, key2:value2}
# so now if we access graph['c'], it will return the list of vertices ['k', 'b']   
graph = {'a': ['f','k','b'],'b': ['c','d','a'],'c':['k','b'],'d':['b','f', 'e'],
         'e':['d'],'f':['g','a','d'],'g':['f','h'],'h':['g','i'],'i':['j','k','h'],
         'j':['i'],'k':['i','a','c']}

root = 'a' 

# Directed graph representation
graph2 = {'a' : ['b','c'], 'b' : ['c'], 'd' : ['c'], 'e' : ['d', 'c'], 'f': ['e','a'], 'c': []}
root2 = 'f'

#print('Root:', root)

#myBucket = baalti(graph,root)
#print('Traversed Graph:', myBucket)

myBucket,DFSTree,parent = baaltiWithTree(graph,root)
print('Traversed Tree:', DFSTree)
print('Parents Info:', parent)

#print(graph[graph[root][1]])
#testList = [1,2,3,4,5,6]
#print(testList,testList.pop(0), testList)