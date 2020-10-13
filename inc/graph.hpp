#ifndef GRAPH_HPP
    #define GRAPH_HPP

        #include <iostream>
        #include <vector>
        #include <list>
        #include <utility>
        #include <algorithm>
        #include <iterator>
        #include <string>

        using namespace std;

        class Graph
        {
            private:
                size_t node_qt;
                vector<list<pair<unsigned int, string>>> graph;
            
            public:
                Graph();
                Graph(size_t node_qt);
                Graph(const Graph &g);
                int add_edge(unsigned int i_node, unsigned int j_node, string value);
                int edge_pair(unsigned int i_node, string value);
                void print_all_edges();
                size_t nodes_qt();
                ~Graph();
        };
#endif