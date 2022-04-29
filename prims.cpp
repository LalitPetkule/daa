#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minimum_key(int k[], int mst[], int vertices)
{
    int minimum  = INT_MAX, min,i;
    for (i = 0; i < vertices; i++)
        if (mst[i] == 0 && k[i] < minimum)
            minimum = k[i], min = i;
    return min;
}

void prim(int n, int **adj)
{
	int vertices = n;
    int parent[vertices];
    int k[vertices];
    int mst[vertices];
    int i, count,edge,v; /*'v' is the vertex*/
    for (i = 0; i < vertices; i++)
    {
        k[i] = INT_MAX;
        mst[i] = 0;
    }
    k[0] = 0;
    parent[0] = -1;
    for (count = 0; count < vertices-1; count++)
    {

        edge = minimum_key(k, mst, vertices);
        mst[edge] = 1;
        for (v = 0; v < vertices; v++)
        {
            if (adj[edge][v] && mst[v] == 0 && adj[edge][v] <  k[v])
            {
                parent[v]  = edge, k[v] = adj[edge][v];
            }
        }
     }
     /*Print the constructed Minimum spanning tree*/
     int cost=0;
     cout<<"\n Edge \t  Weight\n";
     for (i = 1; i < vertices; i++)
    {
		cout<<" "<<parent[i]<<"<-->"<<i<<"    "<<adj[i][parent[i]]<< endl;
    	cost = cost + adj[i][parent[i]];
	}
	cout<<"Cost of Spanning Tree is : "<<cost;
}

int main()
{
	int n;
	cout<<"Enter total number of vertices:";
	cin>>n;
	int **adj = new int *[n];
	cout<<"Enter the weights for following vertices:\n";
	for(int i=0;i<n;i++)
	{
		adj[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				cout<<"Enter weight for edge between vertex "<<i+1<<" and "<<j+1<<" : ";
				cin>>adj[i][j];
			}
			else
			{
				adj[i][j]=0;
			}
		}
	}
	cout<<"\n ********************Printing The Matrix: ********************\n";
	for(int i =0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<adj[i][j]<<"\t";
		}
		cout<<endl;
	}


    prim(n, adj);

	return 0;
}

