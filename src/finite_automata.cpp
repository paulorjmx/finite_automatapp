#include <inc/finite_automata.hpp>

string get_next_symbol(unordered_set<string> alphabet, string &value); // Searchs for next terminal symbol in the string

FiniteAutomata::FiniteAutomata()
{
    this->num_states = 0;
}

FiniteAutomata::FiniteAutomata(unsigned int num_states, 
                               unordered_set<string> terminal_alphabet, 
                               unordered_set<unsigned int> initial_states, 
                               unordered_set<unsigned int> final_states)
{
    this->num_states = num_states;
    this->terminal_symbols = terminal_alphabet;
    this->initial_states = initial_states;
    this->final_states = final_states;
}

FiniteAutomata::FiniteAutomata(unsigned int num_states, 
                               unordered_set<string> terminal_alphabet, 
                               Graph transitions, 
                               unordered_set<unsigned int> initial_states, 
                               unordered_set<unsigned int> final_states)
{
    this->num_states = num_states;
    this->terminal_symbols = terminal_alphabet;
    this->transitions = transitions;
    this->initial_states = initial_states;
    this->final_states = final_states;
}

int FiniteAutomata::add_transition(unsigned int f_state, unsigned int s_state, string value)
{
    return this->transitions.add_edge(f_state, s_state, value);
}

int FiniteAutomata::add_final_state(unsigned int state)
{
    int status = -1;
    if(this->final_states.size() < this->num_states)
    {
        this->final_states.emplace(state);
        status = 0;
    }
    return status;
}

int FiniteAutomata::add_initial_state(unsigned int state)
{
    int status = -1;
    if(this->initial_states.size() < this->num_states)
    {
        this->initial_states.emplace(state);
        status = 0;
    }
    return status;
}

bool FiniteAutomata::check_string(string value)
{
    int i_node = -1;
    bool status = false;
    string bkp_value = value;
    unordered_set<unsigned int>::iterator initial_state;
    // cout << "Current symbols: " << endl;
    for(initial_state = this->initial_states.begin(); (initial_state != this->initial_states.end()) && (status != true); initial_state++)
    {
        i_node = (*initial_state);
        status = this->check_paths(i_node, value);
        value = bkp_value;
    }
    return status;
}

bool FiniteAutomata::check_paths(unsigned int i_node, string value)
{
    string current_symbol;
    vector<int> j_nodes;
    bool status = false;
    // cout << "string value: " << value << endl;
    if(value.compare("") != 0)
    {
        while((value.size()) > 0 && (status != true)) // While have symbols to process
        {
            /* Get the next symbol on string */
            current_symbol = get_next_symbol(this->terminal_symbols, value);
            // Finds the next states on the automata
            j_nodes = this->transitions.edge_pair(i_node, current_symbol);
            if(j_nodes.size() > 0)
            {
                if(j_nodes.size() > 1)
                {
                    for(vector<int>::iterator it = j_nodes.begin(); (it != j_nodes.end()) && (status != true); it++)
                    {
                        status = this->check_paths((*it), value);
                    }
                }
                else 
                {
                    i_node = j_nodes[0];
                }
            }
            else 
            {
                break;
            }
        }

        /* At the end, checks if the reached state is an final state */
        if(this->final_states.find(i_node) != this->final_states.end())
        {
            status = true;
        }
    }
    return status;
}

FiniteAutomata::~FiniteAutomata()
{
    this->num_states = 0;
    this->initial_states.clear();
    this->final_states.clear();
    this->terminal_symbols.clear();
}

string get_next_symbol(unordered_set<string> alphabet, string &value)
{
    size_t position, tmp_position;
    unordered_set<string>::iterator tmp_it = alphabet.begin(), it;
    string symbol;
    position = value.find(*tmp_it);
    symbol = *tmp_it;
    it = tmp_it;
    tmp_it++;
    while(tmp_it != alphabet.end())
    {
        tmp_position = value.find(*tmp_it);
        if(tmp_position < position)
        {
            position = tmp_position;
            symbol = *tmp_it;
            it = tmp_it;
        }
        tmp_it++;
    }
    value = value.substr((position + (*it).size()), value.size());
    return symbol;
}