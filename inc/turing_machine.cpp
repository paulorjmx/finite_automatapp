#ifndef TURING_MACHINE_HPP
    #define TURING_MACHINE_HPP

        #include <iostream>
        #include <unordered_set>
        #include <algorithm>
        #include <string>
        #include <inc/transition.hpp>

        using namespace std;

        namespace TuringMachine
        {
            enum Command
            {
                L, R, S
            };

            class Machine 
            {
                private:
                    size_t num_states;
                    unsigned int actual_state, rw_head;
                    string tape;
                    unordered_set<string> tape_sym, alph_sym;
                
                public:
                    Machine();
            };

            class Transition
            {

            };
        }
#endif