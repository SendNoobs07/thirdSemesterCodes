#include <iostream>
#include<algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskals(Edge *input, int n, int E)
{
    // sorting the edges that were given by the user based on weights
    sort(input, input + E, compare); // sorting using library function cause, why not

    Edge *output = new Edge[n - 1]; // creation a new array of Edges to display the output

    int *parent = new int[n]; // making a pointer array called parent to store iterations
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int counter = 0; // keeps track of number of edges added to mst
    int i = 0;       // keeps track of iterations including the edges that were skipped due to kruskal's algorithm

    while (counter != n - 1) // as a MST contains n-1 number of edges where n is number of vertices
    {
        Edge currEdge = input[i];

        // checking if currEdge is okay to add to MST or not
        int sourceParent = findParent(currEdge.source, parent);
        int destParent = findParent(currEdge.dest, parent);

        if (sourceParent != destParent)
        {
            output[counter] = currEdge;
            counter++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
	cout<<"Final output: "<<endl;
    for (int i = 0; i < n - 1; i++) // printing the final output
    {
        if (output[i].source < output[i].dest)
        {
            cout << output[i].source << "  " << output[i].dest << "  " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << "  " << output[i].source << "  " << output[i].weight << endl;
        }
    }
}

int main()
{
    int n, E;
    cout << "Enter number of vertices and edges : ";
    cin >> n >> E;
    Edge *input = new Edge[E];

    cout<<"Enter data of edges (source  destination  weight, in that order): ";
    // taking user input of all edges
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, n, E);
}