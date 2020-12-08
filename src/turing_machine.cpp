#include <inc/turing_machine.hpp>

Machine::Machine(unsigned int final_state, string tape, Graph g)
{
    this->num_states = g.nodes_qt(); // Total quantity of states
    this->final_state = final_state; // Acceptance state of the machine
    this->tape = "B" +tape+ "B"; // Tape that will be read and write by the head
    this->graph = g; // Graph that contains all transitions and states
    this->rw_head = 1; // Initial position of read/write head
    this->actual_state = 0; // Actual state of the machine
}

int Machine::run()
{
    int result = -1;
    pair<unsigned int, Edge> j_node;
    while(this->actual_state != this->final_state)
    {
        j_node = this->graph.edge_pair(this->actual_state, this->tape.substr(this->rw_head, 1));
        if(j_node.second.condition != "")
        {
            this->tape.replace(this->rw_head, 1, j_node.second.write_to);
            this->rw_head = this->rw_head + j_node.second.cmd;
            this->actual_state = j_node.first;
        }
        else 
        {
            break;
        }
        // cout << "Condition: " << j_node.second.condition << endl;
    }
    result = this->actual_state - this->final_state;
    return result;
}

void Machine::set_tape(string new_tape)
{
    this->tape = "B" +new_tape+ "B";
}

void Machine::print_tape()
{
    cout << this->tape << endl;
}