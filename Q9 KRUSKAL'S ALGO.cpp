#include <iostream>
using namespace std;


class node
{
	int data;
	int weight;
	node * next;
	public:
		friend class SLL;
		friend class graph;
		node(int val,int w, node* ptr=0)
		{
			data = val;
			weight=w;
			next = ptr;
		}
		
};
struct Node
{
	int src;
	int dest;
	int weight;
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
			head = new node(val,-1,head);
		}
		void add(int data, int w)
		{
	        node* p = new node(data,w);
	        if (head == NULL) {
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
			cout<<endl;
		}
	}
};
class unionFind
{
	int n;
	int * parent;
	int * size;
	
	public:
		unionFind(int n)
		{
			this->n=n;
			parent=new int[n];
			size=new int [n];
			for(int i=1;i<=n;i++)
			{
				parent[i]=-1;
				size[i]=0;
			}	
		}
		
		void makeset(int val)
		{
			
			if(val<=n)
			{
				parent[val]=val;
				size[val]=0;
			}
			else cout<<"Invalid Input"<<endl;	
		}
		
		int Find(int x)
		{
			return parent[x];
		}
		void Union(int x, int y)
		{
			int px, py;
			px=Find(x);
			py=Find(y);
			
			if(px==py)
			{
				return;
			}
			else if (size[px]>=size[py])
			{
				for(int i=1;i<=n;i++)
				{
					if(parent[i]==py)
					{
						parent[i]=px;
						size[px]+=1;
					}
				}
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					if(parent[i]==px)
					{
						parent[i]=py;
						size[py]+=1;
					}
				}	
			}
		}
		
		void display(int rep)
		{
			for (int i=1;i<=n;i++)
			{
				if(Find(i)==rep)
					cout<<i<<" ";
			}
			cout<<endl;
		}
};

class graph
{
	SLL *arr; //adjacency list
    int n,m; // number of vertices and edges
    Node *edge;//stores the information about edges
    Node * mst;//to store the minimum spanning tree
    
    public:
    	
    	graph(int n,int m)        //constructor
    	{
    		this->n=n;
    		this->m=m;
    		arr= new SLL[n+1];
    		edge= new Node[m+1];
    		mst=new Node[n];
		}
		
		/*void addVertice(int n)   
		{
			int u;
			cout<<"Enter the vertices of the Graph: ";
			for (int i=1;i<=n;i++)
			{
				cin>>u;
				arr[i].add(u);
			}
		}*/
		void addEdge(int u, int v, int w)       //adds edges to the adjacency list
		{
		    arr[u].add(v,w);
		    arr[v].add(u,w);
		}
		void displayList (int n)         //prints the adjacency list
		{
			for(int i=1;i<=n;i++)
	    	{
	    	cout<<"\nVertice "<<i <<": ";
	    	arr[i].display();
			}
		}
		void store(int i,int s, int d, int w)  
		{
			edge[i].dest=d;
        	edge[i].src=s;
        	edge[i].weight=w;
		}
		void eDisplay()
		{
			for(int i=1;i<=m;i++)
		    {
		    	cout<<edge[i].src<<" -> "<<edge[i].dest<<" = "<<edge[i].weight<<endl;
			}
		}
		void inSort(Node a[],int n)  //sorts the edges according to their weights in decreasing order
		{
				Node temp;
				int j;
				
				for(int i=2; i<=n; i++)
				{
					temp = a[i];
					j = i-1;
					
					while(j >=0 && a[j].weight > temp.weight)
					{
						a[j+1] = a[j];
						j--;
					}
					
					a[j+1] = temp;
				}
				//eDisplay();
			}
		void kruskal()  //using Kruskals Algo to find the cost
		{
			int j=1;   //index counter for MST
			int cost=0; //stores the cost
			inSort(edge,m); // sort the array on the basis of weight in dec order
			unionFind u(n);
			for(int i=1;i<=n;i++)
			{
				u.makeset(i); // make set for all vertices
			}
			for(int i=1;i<=m;i++)
			{
				if(u.Find(edge[i].src) != u.Find(edge[i].dest))  //checks if edge is making any cycle
				{
					mst[j++]=edge[i];	                        //adding edge to MST
					u.Union (edge[i].src, edge[i].dest);        //Merging edges together so that they are counted
				}	
			}
			
			cout<<"\nThe Minimum Spanning Tree for the given graph is: "<<endl;  
			for(int i=1;i<n;i++)                        //to find cost
			{
				cost+=mst[i].weight;
				cout<<mst[i].src<<" -> "<<mst[i].dest<<" = "<<mst[i].weight<<endl;   //displaying MST
				
			}
			
			cout<<"\nTotal cost generated by minimum spanning tree: "<<cost;
		}

};


int main()
{
	int n, m,w;
	cout<<"\n Enter the number of vertices: ";
	cin >> n;
	cout<<"\n Enter the number of edges: ";
	cin  >> m;
	graph g(n,m);
    cout<<"\nEnter the edges (u,v) in the graph: "<<endl;
    for (int i = 1; i <= m; i++) 
	{
        int u, v;
        cout<<"Edge "<<i<<": ";
        cin >> u >> v;
        cout<<"Enter it's weight: ";
        cin>>w;
        g.addEdge(u, v,w);
        g.store(i,u,v,w);
    }
    cout<<endl;
    g.kruskal();
    
    
	
}
