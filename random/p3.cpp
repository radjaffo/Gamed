#include<vector>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

/************LINKED LIST**********************************************/
//Adjacency List Representation of the Graph
class Node{
    public:
    int data;
    Node* next;
    Node(int x):data(x){next = NULL;}
    void displayData(){
        cout<<data;
    }
};
class LinkList {
    public:
    Node* head;
    int length;

    LinkList(){
        head = NULL;
    }
    LinkList(int x){
        head= new Node(x);       
    }
    LinkList(int x, int y){
        head= new Node(x);   
        length = y;
    }
    void insert_at_head(int x){
        Node* new_node = new Node(x);       
        new_node->next=head->next;
        head->next=new_node;
    }//end insertFirst

    void remove_at_head(){
    }//end removeFirst

    void insert_at_tail(int x){
        //parse to get to the end element
        Node* parse = this->head;       
        while(parse->next != NULL){           
            parse=parse->next;//last node
        }
        Node* n;
        n->data = x;   
        n->next = NULL;
        parse->next = n;       
    }
    int countNodes(){//count the number of nodes
        int count=0;
        Node* curr = head;
        while(curr!=NULL){
            curr=curr->next;
            count++;
        }
        return count;
    }
};

class Graph{
public:
    int V;//number of vertices
    LinkList* vertex_array;//linked list implementation of vertex array for dynamic allocation

    Graph(int v){//create Graph of v vertices
         
    this->V = v;
     this->vertex_array = new LinkList[V];
 
    // Create an array of adjacency lists.  Size of array will be V
   // LinkList graph->vertex_array[V] = new LinkList();//declaration
    //allocate memory to each element of vertex_array
    int i;
    for (i = 0; i < V; ++i){
        //graph->vertex_array[i] = new LinkList();
       this->vertex_array[i].head = NULL;
    }
    }
    void addEdge(int src, int dest);
    void printGraph();
};

// A utility function that creates a graph of V vertices

// Adds an edge to an undirected graph
void Graph::addEdge(int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining.. for efficiency
    Node* newNode = new Node(dest);
    newNode->next = this->vertex_array[src].head;
    this->vertex_array[src].head = newNode;
 
    // Since graph is undirected, add an edge from dest to src also
    newNode = new Node(src);
    newNode->next = this->vertex_array[dest].head;
    this->vertex_array[dest].head = newNode;
}

// A utility function to print the adjacenncy list representation of graph
void Graph::printGraph()
{
    int v;
    for (v = 0; v < this->V; ++v)
    {
        Node* pCrawl = this->vertex_array[v].head;
       cout<<"\n Adjacency list of vertex "<<v<<"\n head";
        while (pCrawl)
        {
            cout<<"->"<<pCrawl->data;
            pCrawl = pCrawl->next;
        }
        cout<<"\n";
    }
}

int main(){
 // create the graph given in above fugure
    int V = 5;

    Graph* graph = new Graph(V);
    graph->addEdge(0, 1);
    graph->addEdge(0, 4);
    graph->addEdge(1, 2);
    graph->addEdge(1, 3);
    graph->addEdge(1, 4);
    graph->addEdge(2, 3);
    graph->addEdge(3, 4);
 
    // print the adjacency list representation of the above graph
    graph->printGraph();
 
    return 0;
}