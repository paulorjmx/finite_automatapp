#include <inc/finite_automata.hpp>
#include <inc/graph.hpp>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;
 
 
 int main(int argc, char const *argv[])
 {

    string cadeia = "aaa";
    unordered_set<string> terminal_symbols;
    unordered_set<unsigned int> initial_states, final_states;
    Graph transitions(3);
    transitions.add_edge(0, 1, "a");
    transitions.add_edge(0, 1, "b");
    transitions.add_edge(1, 1, "a");
    transitions.add_edge(1, 2, "b");
    transitions.add_edge(2, 0, "a");
    transitions.add_edge(2, 2, "b");
    //  transitions.print_all_edges();
    // unsigned int j_node = transitions.edge_pair(0, "a");
    // cout << "0 a " << j_node << endl;
    initial_states.emplace(0);
    final_states.emplace(2);
    terminal_symbols.emplace("a");
    terminal_symbols.emplace("b");
    terminal_symbols.emplace("c");
    FiniteAutomata afd(3, terminal_symbols, transitions, initial_states, final_states);
    if(afd.check_string(cadeia) == true)
    {
        cout << "aceita" << endl;
    }
    else 
    {
        cout << "rejeita" << endl;
    }
    return 0;
 }
 