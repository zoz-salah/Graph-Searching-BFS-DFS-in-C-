#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Vertex
{
public:
    char label;
    bool wasVisited;

    Vertex(char lab)
    {
        label = lab;
        wasVisited = false;
    }
};



class Graph
{
private:
    static const int MAX_VERTS = 20;
    Vertex* vertexList[MAX_VERTS];
    int adjMat[MAX_VERTS][MAX_VERTS];
    int nVerts;

public:

    Graph()
    {
        nVerts = 0;
        for(int i = 0; i < MAX_VERTS; i++)
            for(int j = 0; j < MAX_VERTS; j++)
                adjMat[i][j] = 0;
    }

    void addVertex(char lab)
    {
        vertexList[nVerts++] = new Vertex(lab);
    }

    void addEdge(int start, int end)
    {
        adjMat[start][end] = 1;
        adjMat[end][start] = 1;
    }

    void displayVertex(int v)
    {
        cout << vertexList[v]->label << " ";
    }

    int getAdjUnvisitedVertex(int v)
    {
        for(int j = 0; j < nVerts; j++)
            if(adjMat[v][j] == 1 && vertexList[j]->wasVisited == false)
                return j;
        return -1;
    }

    void dfs()
    {
        stack<int> s;
        vertexList[0]->wasVisited = true;
        displayVertex(0);
        s.push(0);

        while(!s.empty())
        {
            int v = getAdjUnvisitedVertex(s.top());
            if(v == -1)
                s.pop();
            else
            {
                vertexList[v]->wasVisited = true;
                displayVertex(v);
                s.push(v);
            }
        }

        for(int j = 0; j < nVerts; j++)
            vertexList[j]->wasVisited = false;
    }

    void bfs()
    {
        queue<int> q;
        vertexList[0]->wasVisited = true;
        displayVertex(0);
        q.push(0);

        while(!q.empty())
        {
            int v1 = q.front();
            q.pop();

            int v2;
            while((v2 = getAdjUnvisitedVertex(v1)) != -1)
            {
                vertexList[v2]->wasVisited = true;
                displayVertex(v2);
                q.push(v2);
            }
        }

        for(int j = 0; j < nVerts; j++)
            vertexList[j]->wasVisited = false;
    }
};

int main()
{
    Graph g;

    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addVertex('F');
    g.addVertex('G');
    g.addVertex('H');
    g.addVertex('I');

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.addEdge(3,7);
    g.addEdge(4,8);

    cout << "DFS: ";
    g.dfs();
    cout << endl;

    cout << "BFS: ";
    g.bfs();
    cout << endl;

    return 0;
}
