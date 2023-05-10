#include <iostream>
#include <cstring>
using namespace std;
class node{
	int data;
	node * next;
	public:
		friend class SLL;
		friend class graph;
		node(int val, node* ptr=0)
		{
			data = val;
			next = ptr;
		}
		
};

class SLL{
	
	node* head;
	
	public: 
		SLL()
		{
			head = 0;
		}
		
		bool isempty()
		{
			return (head==0);
		}
		void addToHead(int val)
		{
			head = new node(val,head);
		}
		void add(int data)
		{
	        node* p = new node(data);
	        if (head == NULL) 
			{
	            head = p;
	        }
	        else {
	            node* ptr = head;
	            while (ptr->next != NULL) {
	                ptr = ptr->next;
	            }
	            ptr->next = p;
	        }
	    }
		
		node* getHead() 
		{
        	return head;
    	}
		void display()
		{
			if(!isempty()) 
			{
				
				node *ptr = head;
				while(ptr)
				{
					cout<<ptr->data<<" ";
					ptr=ptr->next;
				}
			}
		}
};
	
class graph
{
	SLL *arr; //adjacency list
    int n,m; // number of vertices and edges
    int * parent; // parent vertex in the DFS tree for each vertex
    
    public:
    	graph(int n)        //constructor
    	{
    		this->n=n;
    		arr= new SLL[n+1];
    		parent = new int [n+1];
    		
    		for(int i=1;i<=n;i++)
    		{
    			parent[i]=-1;           //initially each vertex has no parent for the tree
    		}
		}
		
		void addVertice(int n)   
		{
			int u;
			cout<<"Enter the vertices of the Graph: ";
			for (int i=1;i<=n;i++)
			{
				cin>>u;
				arr[i].add(u);
			}
		}
		void addEdge(int u, int v)       //adds edges to the adjacency list
		{
		    arr[u].add(v);
		    arr[v].add(u);
		}
		void displayList (int n)         //prints the adjacency list
		{
			for(int i=1;i<=n;i++)
	    	{
	    	cout<<"\nVertice "<<i <<": ";
	    	arr[i].display();
			}
		}
		
		void DFS(int u, bool visited[])     //only runs if vertex is not visited      
		{
	        visited[u] = true;             //sets vertex is visited
	        cout << u << " ";
	        node *ptr = arr[u].getHead();
	        while (ptr != NULL)             
			{
	            int v = ptr->data;       
	            if (!visited[v])
	            {
					parent[v]=u;
	                DFS(v, visited);     //runs recursively for all vertices u is connected to
				}     
	            ptr = ptr->next;
	        }
   		}
	    void DFS()                          
		{
	        bool *visited = new bool[n];          //array to check if vertex is visited
	        for (int i = 1; i <= n; i++)          
	            {
	            	visited[i] = false;           //initially no vertex visited
				}
	        for (int i = 1; i <= n; i++)          
	            {
	            	if (!visited[i])             //checks for each vertex             
	                DFS(i, visited);
				}
        }
        
        void parents()
        {
        	for(int i=1; i<=n;i++)
			{
				cout<<i<<"-> "<<parent[i]<<endl;	
			}	
		}
};

	

int main() 
{
    
    int n, m;
	cout<<"\n Enter the number of vertices: ";
	cin >> n;
	cout<<"\n Enter the number of edges: ";
	cin  >> m;
	graph g(n);
    cout<<"\nEnter the edges (u,v) in the graph: "<<endl;
    for (int i = 0; i < m; i++) 
	{
        int u, v;
        cout<<"Edge "<<i+1<<": ";
        cin >> u >> v;
        g.addEdge(u, v);
    }
	cout<<"\nThe Adjacency List is: ";
    g.displayList(n);
   
    cout<<"\n\nThe DSF of the graph is: ";
    g.DFS();
    cout<<"\n\nThe parents of the vertices are:"<<endl;
    g.parents();
		

    return 0;
}

    
