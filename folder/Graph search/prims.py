
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
graph={'a':[('f',3),('b',2),('k',9)],'f':[('a',3),('d',2),('g',4)],'d':[('f',2),('e',1),('b',3)],'b':[('d',3),('a',2),('c',2)],'c':[('b',2),('k',5)],'k':[('c',5),('a',9),('i',3)],'e':[('d',1)],'i':[('k',3),('h',6),('j',3)],'j':[('h',4),('i',3)],'h':[('j',4),('g',2),('i',6)],'g':[('f',4),('h',2)]}
root='j'

#graph1={'a':[('c',1),('b',4),('d',3)],'c':[('a',1),('d',2)],'d':[('b',5),('c',2),('a',3)],'b':[('a',4),('d',5)]}

bucket,mst=balti(graph,root)
print('MST:',mst)
print('BUCKET: ',bucket)


    

    
