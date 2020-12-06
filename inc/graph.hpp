#ifndef GRAPH_HPP
    #define GRAPH_HPP

        #include <iostream>
        #include <vector>
        #include <list>
        #include <utility>
        #include <algorithm>
        #include <iterator>

        using namespace std;

        /* The Command enum data type represents an command in a Turing Machine. */
        enum Command
        {
            L, R, S
        };

        /* 
            This struct represents an Edge in Graph class.
            It's serves to a transition in a Turing Machine and have members like
            condition, symbol that will be write into tape and the command of read/write head.
        */
        struct Edge
        {
            string condition, write_to;
            Command cmd;

            /* Default constructor */
            Edge()
            {
                this->condition = "";
                this->write_to = "";
            }

            /* Initializing constructor */
            Edge(string condition, string write_to, Command cmd)
            {
                this->condition = condition;
                this->write_to = write_to;
                this->cmd = cmd;
            }

            /* Overloading the output stream */
            friend ostream &operator<<(ostream &out, const Edge &e)
            {
                const string cmd_text[3] = { "L", "R", "S"};
                out << e.condition << "; " << e.write_to << "; " << cmd_text[e.cmd];
                return out;
            }
        };

        /*
            This class serves to represents the graph of an deterministic Turing Machine.
            It is implemented in a adjacency list way, in which their nodes is a pair.
        */

        class Graph
        {
            private:
                size_t node_qt;
                vector<list<pair<unsigned int, Edge>>> graph;
            
            public:
                Graph(); // Empty constructor
                Graph(size_t node_qt); // Construct a graph with pre-determined number of nodes "node_qt"
                Graph(const Graph &g); // Copy constructor
                int add_edge(unsigned int i_node, unsigned int j_node, Edge value); // Adds an edge in the graph
                pair<unsigned int, Edge> edge_pair(unsigned int i_node, string value); // Returns an node identification if finds an transition with condition "value"
                void print_all_edges();
                size_t nodes_qt();
                ~Graph();
        };
#endif