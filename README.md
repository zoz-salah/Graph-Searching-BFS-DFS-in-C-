# Graph DFS and BFS Implementation

A C++ implementation of Depth-First Search (DFS) and Breadth-First Search (BFS) algorithms for graph traversal.

## 📋 Description

This program demonstrates graph traversal using two fundamental algorithms:
- **Depth-First Search (DFS)** - Explores as far as possible along each branch before backtracking
- **Breadth-First Search (BFS)** - Explores all vertices at the present depth level before moving to vertices at the next depth level

The implementation uses an adjacency matrix representation of the graph and includes a custom Vertex class to store node information.

## 🏗️ Class Structure

### Vertex Class
- Stores vertex label (character)
- Tracks visited status during traversal

### Graph Class
- Manages vertices and edges using an adjacency matrix
- Provides methods for graph creation and traversal
- Supports up to 20 vertices (configurable)

## ✨ Features

- **Adjacency Matrix Representation** - Simple and intuitive graph storage
- **DFS Implementation** - Using stack data structure (LIFO)
- **BFS Implementation** - Using queue data structure (FIFO)
- **Automatic Reset** - Visited flags are reset after each traversal

## 🚀 Usage


### Sample Graph
The program creates a sample graph with 9 vertices (A-I) connected as follows:
- A connected to B and C
- B connected to D and E
- C connected to F and G
- D connected to H
- E connected to I

### Expected Output
```
DFS: A B D H E I C F G 
BFS: A B C D E F G H I
```

## 📝 Code Example

```cpp
// Create a graph
Graph g;

// Add vertices
g.addVertex('A');
g.addVertex('B');

// Add edges (0-based indexing)
g.addEdge(0, 1); // Connects A and B

// Perform traversals
g.dfs(); // Depth-First Search
g.bfs(); // Breadth-First Search
```



## 📊 Algorithm Complexity

- **Time Complexity**: O(V²) for adjacency matrix representation
- **Space Complexity**: O(V) for visited array and stack/queue

Where V is the number of vertices.

## 🎯 Key Methods

| Method | Description |
|--------|-------------|
| `addVertex(char lab)` | Adds a new vertex with given label |
| `addEdge(int start, int end)` | Creates an undirected edge between vertices |
| `dfs()` | Performs Depth-First Search traversal |
| `bfs()` | Performs Breadth-First Search traversal |
| `getAdjUnvisitedVertex(int v)` | Finds adjacent unvisited vertex |

