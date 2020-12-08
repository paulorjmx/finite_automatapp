/********************************************/
/*                                          */
/*                                          */
/*      Nome: Paulo Ricardo J. Miranda      */
/*      N USP: 10133456                     */
/*                                          */
/*                                          */
/********************************************/


#include <inc/graph.hpp>
#include <inc/turing_machine.hpp>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;
 
 
int main(int argc, char const *argv[])
{
    unsigned num_states = 0, num_terminals = 0, num_ext_symbols = 0, final_state = 0, num_transitions = 0, num_strings = 0, k, j;
    string tmp_terminals, tmp_extended, condition, write_to, command, tape;
    unordered_set<string> terminals_alph, extended_alph;
    Command cmd;

    /* Get the total number of states that machine will have */
    cin >> num_states;
    Graph g_transitions(num_states);

    /* Get the quantity of terminals symbols */
    cin >> num_terminals;
    for(size_t i = 0; i < num_terminals; i++)
    {
        cin >> tmp_terminals;
        terminals_alph.insert(tmp_terminals);
    }

     /* Get the quantity of extended symbols */
    cin >> num_ext_symbols;
    for(size_t i = 0; i < num_ext_symbols; i++)
    {
        cin >> tmp_extended;
        extended_alph.insert(tmp_extended);
    }

    /* Get the number of acceptance state */
    cin >> final_state;
    
    /* Get the number of transitions */
    cin >> num_transitions;

    /* Read and store all transitions in a Graph data structure */
    for(size_t i = 0; i < num_transitions; i++)
    {
        /* 
            The format of the input is: q x q' y D. Will form the following transition:
                (x; y; D)                 (a; *; R)
            q -------------> q'       0 -------------> 1
         */
        cin >> k;
        cin >> condition;
        cin >> j;
        cin >> write_to;
        cin >> command;
        // cout << k << " " << condition << " " << j << " " << write_to << " " << command << endl;
        if(command == "R")
        {
           g_transitions.add_edge(k, j, Edge(condition, write_to, Command::R));
        }
        else if(command == "L")
        {
            g_transitions.add_edge(k, j, Edge(condition, write_to, Command::L));
        }
        else 
        {
            g_transitions.add_edge(k, j, Edge(condition, write_to, Command::S));
        }
        
    }

    // g_transitions.print_all_edges();
    /* Get the number of string that will be tested */
    cin >> num_strings;
    cin >> tape;
    Machine turing_machine(final_state, terminals_alph, extended_alph, tape, g_transitions);
    
    if(turing_machine.run() < 0)
    {
        cout << "rejeita" << endl;
    }
    else 
    {
        cout << "aceita" << endl;
    }


    for(size_t i = 0; i < (num_strings - 1); i++)
    {
        cin >> tape;
        turing_machine.change_tape(tape);
        if(turing_machine.run() < 0)
        {
            cout << "rejeita" << endl;
        }
        else 
        {
            cout << "aceita" << endl;
        }

    }

    return 0;
}
 