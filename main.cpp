#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) : data(new_data), next(nullptr) {}
};

class List {
public:
    Node* head;
    List() : head(nullptr) {}
    
    void push(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
    
    bool exists(int data) {
        Node* temp = head;
        while (temp) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    void print() {
        Node* temp = head;
        while (temp) {
            cout << " => " << temp->data;
            temp = temp->next;
        }
        cout << " ]" << endl;
    }
};

class Graph {
private:
    int num_vertices;
    List* graph;
    
public:
    Graph(int num_vertices) : num_vertices(num_vertices) {
        graph = new List[num_vertices];
    }
    
    ~Graph() {
        delete[] graph;
    }
    
    void add_edge(int starting_vertex, int ending_vertex) {
        if (starting_vertex < num_vertices && ending_vertex < num_vertices) {
            if (graph[starting_vertex].exists(ending_vertex)) {  // Fixed missing closing parenthesis
                cout << "[!] Uma aresta para esses vertices" << " (" << starting_vertex << ", " << ending_vertex << ")" << " ja existe" << endl;
                return;
            }
            
            graph[starting_vertex].push(ending_vertex);
            graph[ending_vertex].push(starting_vertex);
        } else {
            cout << "[!] Impossivel adicionar em um vertice inexistente. Maior vertice possivel: " << num_vertices + 1 << endl;
            return;
        }
    }
    
    void add_vertex() {
        List* new_graph = new List[num_vertices + 1];
        
        for (int i = 0; i < num_vertices; i++) {
            new_graph[i] = graph[i];
        }
        
        delete[] graph;
        graph = new_graph;
        num_vertices++;
    }
    
    void show() {
        for (int i = 0; i < num_vertices; ++i) {
            cout << "Vertice " << i << " [";
            graph[i].print();
        }
    }
};

int main() {
    Graph g(3);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(0, 2);
    g.add_edge(1, 0);
    g.add_edge(3, 1);

    cout << "Grafo inicial:" << endl;
    g.show();

    cout << "Adicionando um novo vértice..." << endl;
    g.add_vertex();
    g.add_edge(3, 1);

    cout << "Grafo atualizado:" << endl;
    g.show();

    return 0;
}
