#include <inc/turing_machine.hpp>

Machine::Machine(size_t num_states, unsigned int final_state, string tape, Graph g)
{
    this->num_states = num_states; // Total quantity of states
    this->final_state = final_state; // Acceptance state of the machine
    this->tape = "B" +tape+ "B"; // Tape that will be read and write by the head
    this->graph = g; // Graph that contains all transitions and states
    this->rw_head = 1; // Initial position of read/write head
    this->actual_state = 0; // Actual state of the machine
}