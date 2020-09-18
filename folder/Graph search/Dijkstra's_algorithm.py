parent={}
level={}

def balti(graph,root):
    bucket=[]
    q=[]
    level[root]=0
    parent[root] = ''
    bucket.append(root)

    #loop for sorting tuple in desending order on distance basis and append that in stack
    #stack will pick that edge having minimum distance
    sorted_list = sorted(weight[root], key=lambda item: item[1], reverse=True)
    for j in sorted_list:
        q.extend(j[0])
    #loop for computing shortest path
    for v in graph[root]:
        for i in weight[root]:
            if i[0]==v:
                w=i[1]
                break
        level[v]=level[root]+w
        parent[v]=root
        


    while len(q)!=0:
        adjacentvertex=q.pop()
        if adjacentvertex not in bucket:
            bucket.append(adjacentvertex)
            sorted_list = sorted(weight[adjacentvertex], key=lambda item: item[1], reverse=True)
            for j in sorted_list:
                q.extend(j[0])
            #loop for computing shortest path
            for v in graph[adjacentvertex]:    
                for i in weight[adjacentvertex]:
                    if i[0]==v:
                        w=i[1]
                        break
            #if condition to check whether pre computed distance from sourse is greater or less
                if v not in level.keys():
                    level[v]=level[adjacentvertex]+w
                    parent[v] = adjacentvertex
                else:
                    if level[v]>level[adjacentvertex]+w:
                        level[v]=level[adjacentvertex]+w
                        parent[v] = adjacentvertex

    return bucket


weight={'s':[('a',3),('c',2),('f',6)],'a':[('b',6),('d',1)],'c':[('a',2),('d',3)],'f':[('e',2)],'b':[('e',1)],'d':[('e',4)],'e':[]}
graph={'s':['a','c','f'],'a':['b','d'],'c':['a','d'],'f':['e'],'b':['e'],'d':['e'],'e':[]}
root='s'




mybucket=balti(graph,root)
print('BUCKET: ',mybucket)
print('PARENT: ',parent)
print('SHORTEST PATH: ', level)

    

    
