# PRACTICE ASSIGNMENT - 2
# DFS

graph = {
'0' : ['1','2'],
'1' : ['2', '3'],
'2' : ['3'],
'3' : ['4'],
'4' : ['0','1','5'],
'5' : []
}
visited = set()
def dfs(visited, graph, node): #function for DFS
    if node not in visited:
        print (node,end=" ")
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

print("Following is the Depth-First Search --> ",end=" ")
dfs(visited, graph, '2') # function call
print()

# BFS
visited =[] # List for visited nodes.
queue = [] #Initializing a queue
def bfs(visited, graph, node): #function for BFS
    visited.append(node)
    queue.append(node)
    while queue: # Creating loop to visit each node
        m = queue.pop(0)
        print (m,end=" ")
        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

print("Following is the Breadth-First Search -->",end=" ")
bfs(visited, graph, '1')
print() 
