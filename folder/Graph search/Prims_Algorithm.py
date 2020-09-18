
def balti(graph,root):
    bucket=[]
    q=[]
    bucket.append(root)
    q.extend(graph[root])
    q=sorted(q, key=lambda index: index[1], reverse=True)
    mst=0

    # While queue not empty
    while len(q)!=0:
        adjacentvertex=q.pop()
        if adjacentvertex[0] not in bucket:
            bucket.append(adjacentvertex[0])
            q.extend(graph[adjacentvertex[0]])
            mst=mst+adjacentvertex[1]
        q=sorted(q, key=lambda index: index[1], reverse=True)

    return bucket,mst



# This graph is your favourite example
graph={'s':[('x',1),('y',1)],'x':[('s',1),('y',-1)],'y':[('s',1),('x',-1)]}
root='s'

#graph1={'a':[('c',1),('b',4),('d',3)],'c':[('a',1),('d',2)],'d':[('b',5),('c',2),('a',3)],'b':[('a',4),('d',5)]}

bucket,mst=balti(graph,root)
print('MST:',mst)
print('BUCKET: ',bucket)


    

    
