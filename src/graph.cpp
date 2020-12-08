#include <inc/graph.hpp>

/* Functor to be used like unary predicate in edge_pair */
class edge_value
{
    private:
        string value;

    public:
        edge_value(string s) : value(s) { }
        bool operator () (pair<unsigned int, Edge> p) { return value == p.second.condition; }
};

Graph::Graph()
{
    this->node_qt = 0;
}

Graph::Graph(const Graph &g)
{
    this->node_qt = g.node_qt;
    this->graph = g.graph;
}

Graph::Graph(size_t node_qt)
{
    vector<list<pair<unsigned int, Edge>>> tmp_graph(node_qt, list<pair<unsigned int, Edge>>());
    this->node_qt = node_qt;
    this->graph = tmp_graph;
}


// Adds an edge with value "value" in the graph
int Graph::add_edge(unsigned int i_node, unsigned int j_node, Edge value)
{
    int ret = -1;
    if(i_node >= 0 && i_node < this->node_qt)
    {
        if(j_node >= 0 && j_node < this->node_qt)
        {
            this->graph[i_node].push_back(pair<unsigned int, Edge>(j_node, value));
            ret = 0;
        }
    }
    return ret;
}


/*
    Searches for a node with transition value "value".
    It uses the find_if and edge_value functor for it.
*/
pair<unsigned int, Edge> Graph::edge_pair(unsigned int i_node, string value)
{
    pair<unsigned int, Edge> j_node;
    list<pair<unsigned int, Edge>>::iterator it;
    list<pair<unsigned int, Edge>> tmp = this->graph[i_node];
    it = find_if(tmp.begin(), tmp.end(), edge_value(value));
    if(it != tmp.end())
    {
        j_node = (*it);
    }
    return j_node;
}


// Prints all nodes and their connections
void Graph::print_all_edges()
{
    for(int i = 0; i < this->node_qt; i++)
    {
        for(list<pair<unsigned int, Edge>>::iterator it = this->graph[i].begin(); it != this->graph[i].end(); it++)
        {
            cout << i << " -> " << (*it).first << ": " << (*it).second << endl;
        }
    }
}


// Returns the quantity of nodes in the graph
size_t Graph::nodes_qt()
{
    return this->node_qt;
}

Graph::~Graph()
{
    for(int i = 0; i < this->node_qt; i++)
    {
        this->graph[i].clear();
    }
    this->graph.clear();
    this->node_qt = 0;
}