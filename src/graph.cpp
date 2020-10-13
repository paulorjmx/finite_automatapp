#include <inc/graph.hpp>

/* Functor to be used like unary predicate in edge_pair */
class edge_value
{
    private:
        string value;
    public:
        edge_value(string s) : value(s) { }
        bool operator () (pair<unsigned int, string> p) { return value == p.second; }
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
    vector<list<pair<unsigned int, string>>> tmp_graph(node_qt, list<pair<unsigned int, string>>());
    this->node_qt = node_qt;
    this->graph = tmp_graph;
}

int Graph::add_edge(unsigned int i_node, unsigned int j_node, string value)
{
    int ret = -1;
    if(i_node >= 0 && i_node < this->node_qt)
    {
        if(j_node >= 0 && j_node < this->node_qt)
        {
            this->graph[i_node].push_back(pair<unsigned int, string>(j_node, value));
            ret = 0;
        }
    }
    return ret;
}

vector<int> Graph::edge_pair(unsigned int i_node, string value)
{
    vector<int> j_nodes;
    list<pair<unsigned int, string>>::iterator it;
    list<pair<unsigned int, string>> tmp = this->graph[i_node];
    it = find_if(tmp.begin(), tmp.end(), edge_value(value));
    while(it != tmp.end())
    {
        cout << "Transição: " << (*it).first << endl;
        j_nodes.push_back((*it).first);
        it++;
        it = find_if(it, tmp.end(), edge_value(value)); // Find transition in adjacent list
    }
    return j_nodes;
}

void Graph::print_all_edges()
{
    for(int i = 0; i < this->node_qt; i++)
    {
        for(list<pair<unsigned int, string>>::iterator it = this->graph[i].begin(); it != this->graph[i].end(); it++)
        {
            cout << i << " " << (*it).second << " " << (*it).first << endl;
        }
    }
}

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