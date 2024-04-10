#include<iostream>
#include<climits>     
using namespace std;

// this function returns a minimum distance for the vertex which is not included in visited.
int minimumDist(int distFromNode[], bool visited[]) 
{
	int min=INT_MAX,index;
              
	for(int i=0;i<6;i++) 
	{
		if(visited[i]==false && distFromNode[i]<=min)      
		{
			min=distFromNode[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(int graph[6][6],int src) // setting the parameters
{
	int distFromNode[6]; // integer array to calculate minimum distance for each node.                            
	bool visited[6];// boolean array to mark visited or unvisited with 1 being visited and 0 being unvisited
	
	// set the nodes with infinity distance except for the initial node and mark them unvisited.  
	for(int i = 0; i<6; i++)
	{
		distFromNode[i] = INT_MAX;
		visited[i] = false;	
	}
	
	distFromNode[src] = 0;   // Setting source to source which is 0             
	
	for(int i = 0; i<6; i++)
	{
		int m=minimumDist(distFromNode,visited); // vertex not yet included.
		visited[m]=true;// m with minimum distance included in visited.
		for(int i = 0; i<6; i++)
		{
			// Updating the minimum distance for the particular node.
			if(!visited[i] && graph[m][i] && distFromNode[m]!=INT_MAX && distFromNode[m]+graph[m][i]<distFromNode[i])
				distFromNode[i]=distFromNode[m]+graph[m][i];
		}
	}
	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i = 0; i<6; i++)                      
	{ //Printing
		char str=65+i; // Ascii values for printing A,B,C..
		cout<<str<<"\t\t\t"<<distFromNode[i]<<endl;
	}
}

int main()
{
	int graph[6][6]={
		{0, 10, 20, 0, 0, 0},
		{10, 0, 0, 50, 10, 0},
		{20, 0, 0, 20, 33, 0},
		{0, 50, 20, 0, 20, 2},
		{0, 10, 33, 20, 0, 1},
		{0, 0, 0, 2, 1, 0}};
	Dijkstra(graph,0);
	return 0;	                        
}
