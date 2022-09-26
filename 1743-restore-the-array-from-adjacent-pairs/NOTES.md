The first and last elements of the array are the nodes who have only 1 adjacent node.
So, first we traverse the adjacency list and find the starting point of array (here its -2 coz it has only 1 neighbour)
We push -2 to our answer vector (here ans).
From -2, we start a depth first search and keep on appending each node into ans till we have traversed all nodes.
We also maintain a map (here visited) to check which node to visit next. (We won't be visiting the nodes which are already traversed.)