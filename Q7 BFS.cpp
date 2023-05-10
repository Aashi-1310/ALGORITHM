#include <iostream>
#include <queue>
#include <cstring>
#include <iomanip>

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
		}
	}
};
	
class graph
{
	
	int n, m; // number of vertices and edges
	bool * discovered; // discovered flag for each vertex
	int * layer; // layer number for each vertex
	int * parent; // parent vertex in the BFS tree for each vertex
    SLL	*arr; //adjacency list
    
	public:
		graph(int n, int m)   //constructor
		{
			this->n=n;
			this->m=m;
			arr=new SLL [n+1];
			discovered= new bool[n+1];
			layer= new int[n+1];
			parent = new int [n+1];
			
			for(int i=1;i<=n;i++)
		    {
		    	discovered[i]=false;    //initially no vertex is discovered
		    	layer[i]=-1;            //initially each vertex is not in any layer
		    	parent[i]=-1;           //initially each vertex has no parent
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
		
		void addEdge(int u, int v) //adds edges to the adjacency list
		{   
		    arr[u].add(v);
		    arr[v].add(u);
		}
		void displayList (int n)  //prints the adjacency list
		{
			for(int i=1;i<=n;i++)
	    	{
	    	cout<<"\nVertice "<<i <<": ";
	    	arr[i].display();
			}
			cout<<endl;
		}
		
		void bfs(int s)     //runs BFS on the graph starting from the vertice u              //O(m+n)
		{
        discovered[s] = true;                                                               //O(1)
        SLL L0;            //creating a linked list l0                                      //O(n)
        L0.add(s);
        int i = 0;         //layer counter=0
        graph T(n,m);       // Create a new graph to store the BFS tree
        while (!L0.isempty())                                                                //O(m+n)
		{
            SLL Li;
            cout << "Layer " << i << ": ";
            node* current = L0.getHead();
            while (current != NULL)    //
			{
                int u = current->data;
                node* U = arr
				[u].getHead();
                while (U != NULL) 
				{
                    int v = U->data;
                    if (!discovered[v]) 
					{
                        discovered[v] = true;
                        T.addEdge(u, v); // Add the edge to the BFS tree
                        Li.add(v);
                        parent[v]=u;     //Assigns parent to vertice
                    }
                    U = U->next;
                }
                cout << u << " ";
                current = current->next;
            }
            cout << endl;
            i++;
            L0 = Li;
        }
        cout<<"\nThe Adjacency List for BFS Tree is: ";
        for(int i=1;i<=n;i++)
	    	{
	    	cout<<"\nVertice "<<i <<": ";
	    	T.arr[i].display();
			cout<<endl;
	    	cout<<"Parent :"<<parent[i];
			}
    }
};
	

int main() {
    
    int n, m;
	cout<<"\n Enter the number of vertices: ";
	cin >> n;
	cout<<"\n Enter the number of edges: ";
	cin  >> m;
	graph g(n,m);
    cout<<"\nEnter the edges (u,v) in the graph: "<<endl;
    for (int i = 0; i < m; i++) 
	{
        int u, v;
        cout<<"Edge "<<i+1<<": ";
        cin >> u >> v;
        g.addEdge(u, v);
    }
	
    int s;
    cout<<"\nEnter the vertice to start BFS: ";
    cin >> s;
	g.bfs(s);
		

    return 0;}

