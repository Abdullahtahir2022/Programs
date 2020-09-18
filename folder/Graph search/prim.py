import random

def Prims(graph):
    MST = 0
    bucket = []
    queue = []
    x,y = random.choice(list(graph.items())) 
    bucket.append(x)
    queue.extend(graph[x]) 
    print(bucket)
    print(queue)  
    return
    # print(bucket)    '''... Randomly choose vertex'''
    # print(queue)      '''... Show neighbour vertex'''
    # print("HAAN")
    while len(queue)!=0:
        # print("loop")
        queue.sort(key=lambda x:x[1])  # Sort the QUEUE and get minimum neighbour vertex
        # print(queue,bucket,MST)
        adjacentVertex = queue.pop(0)    # pop the vertex which is on INDEX[0]
        # print(adjacentVertex)
        if adjacentVertex[0] not in bucket:    # adjacentVertex[0] is the smallest neighbour vertex and it is not in the bucket
            MST+=adjacentVertex[1]
            bucket.append(adjacentVertex[0])
            queue.extend(graph[adjacentVertex[0]])

    return bucket, MST    



# main function
graph = {'a': [('f',3),('k',9),('b',2)],'b': [('c',2),('d',3),('a',2)],'c':[('k',5),('b',2)],'d':[('b',3),('f',2), ('e',1)],
         'e':[('d',1)],'f':[('g',4),('a',3),('d',2)],'g':[('f',4),('h',2)],'h':[('g',2),('i',6),('j',4)],'i':[('j',3),('k',3),('h',6)],
         'j':[('i',3),('h',4)],'k':[('i',3),('a',9),('c',5)]}

bucket, MST = Prims(graph)
print(bucket, MST)
