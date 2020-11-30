#ifndef GRAPH_HPP
    #define GRAPH_HPP

        #include <iostream>
        #include <vector>
        #include <list>
        #include <utility>
        #include <algorithm>
        #include <iterator>
        #include <inc/edge_value.hpp>

        using namespace std;

        /*
            This class serves to represents the graph of an deterministic Turing Machine.
            It is implemented in a adjacency list way, in which their nodes is a pair.
        */

        class Graph
        {
            private:
                size_t node_qt;
                vector<list<pair<unsigned int, EdgeValue>>> graph;
            
            public:
                Graph(); // Empty constructor
                Graph(size_t node_qt); // Construct a graph with pre-determined number of nodes "node_qt"
                Graph(const Graph &g); // Copy constructor
                int add_edge(unsigned int i_node, unsigned int j_node, EdgeValue value); // Adds an edge in the graph
                vector<int> edge_pair(unsigned int i_node, string value); // Returns an node identification if finds an transition with condition "value"
                void print_all_edges();
                size_t nodes_qt();
                ~Graph();
        };
#endif