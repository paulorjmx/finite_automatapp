#ifndef EDGE_VALUE_HPP
    #define EDGE_VALUE_HPP
        #include <inc/turing_machine.hpp>

        using namespace TuringMachine;
        

        /*
            In a turing machine, an transition is made of 3 objects: an condition,
            an valid tape symbol to write to in the position which read/write heads points, and 
            a command to the read/write head (move to the left (L), to the right (R) or stays (S)).
            The purpose of this class is to describe an valid transition for TuringMachine class.
        */

        class EdgeValue
        {
            private:
                string condition, write_to;
                Command cmd;
            
            public:                
                EdgeValue(); // Empty constructor
                EdgeValue(string, string, Command); // Constructor with condition, symbol to write and the command for the head
                string get_condition(); // Returns the condition of the transition
                Command get_command(); // Returns the command of the transition
                string get_write_to(); // Returns the symbol to write 
                
                /* Overloading the output stream */
                friend ostream &operator<<(ostream &out, const EdgeValue &e)
                {
                    const string cmd_text[3] = { "L", "R", "S"};
                    out << e.condition << "; " << e.write_to << "; " << cmd_text[e.cmd];
                    return out;
                }
        };
#endif