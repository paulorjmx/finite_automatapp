#ifndef FINITE_AUTOMATA_HPP
    #define FINITE_AUTOMATA_HPP

        #include <inc/graph.hpp>
        #include <unordered_set>
        #include <string>
        #include <algorithm>

        using namespace std;

        class FiniteAutomata
        {
            private:
                unordered_set<string> terminal_symbols; /* Set of terminal symbols */
                unordered_set<unsigned int> initial_states, final_states; /* Set that contains initial states and final states of the automata, respectively */
                size_t num_states; /* Cardinality of set of states */
                Graph transitions; /* Graph that contains the transitions of the finite automata */
                bool check_paths(unsigned int i_node, string value); /* Function to check an path from a node i_node */
            
            public:
                /* Empty constructor */
                FiniteAutomata(); 
                /* Constructs an automata with particular config */
                FiniteAutomata(unsigned int num_states, unordered_set<string> terminal_alphabet, unordered_set<unsigned int> initial_states, unordered_set<unsigned int> final_states);
                /* Constructs and automata with pre-defined full configurations */
                FiniteAutomata(unordered_set<string> terminal_alphabet, Graph transitions, unordered_set<unsigned int> initial_states, unordered_set<unsigned int> final_states);
                /* Add transition from f_state to s_state with in finite automata */
                int add_transition(unsigned int f_state, unsigned int s_state, string value);
                /* Add an initial state in initial states set */
                int add_initial_state(unsigned int state);
                /* Add  an final state in initial states set */
                int add_final_state(unsigned int state);
                /* Checks if the strings is accepted by the automata */
                bool check_string(string value);
                ~FiniteAutomata();
        };
    
#endif