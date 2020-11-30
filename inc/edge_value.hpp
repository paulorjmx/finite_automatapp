#ifndef EDGE_VALUE_HPP
    #define EDGE_VALUE_HPP
        #include <inc/turing_machine.hpp>

        using namespace TuringMachine;

        class EdgeValue
        {
            private:
                string condition, write_to;
                Command cmd;
            
            public:                
                EdgeValue();
                EdgeValue(string, string, Command);
                string get_condition();
                Command get_command();
                string get_write_to();
                friend ostream &operator<<(ostream &out, const EdgeValue &e)
                {
                    const string cmd_text[3] = { "L", "R", "S"};
                    out << e.condition << "; " << e.write_to << "; " << cmd_text[e.cmd];
                    return out;
                }
        };
#endif