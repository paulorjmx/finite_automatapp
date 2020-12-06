#ifndef TURING_MACHINE_HPP
    #define TURING_MACHINE_HPP

        #include <iostream>
        #include <unordered_set>
        #include <algorithm>
        #include <string>
        #include <inc/graph.hpp>

        using namespace std;
        
        class Machine 
        {
            private:
                size_t num_states;
                unsigned int actual_state, rw_head, final_state;
                string tape;
                unordered_set<string> tape_sym, alph_sym;
                Graph graph;
            
            public:
                // Machine();
                Machine(size_t num_states, unsigned int final_state, string tape, Graph g);
                bool check_string(string st);

        };
#endif