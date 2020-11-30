#include <inc/edge_value.hpp>

EdgeValue::EdgeValue()
{
    this->condition = "";
    this->write_to = "";
}

EdgeValue::EdgeValue(string condition, string write_to, Command cmd)
{
    this->condition = condition;
    this->write_to = write_to;
    this->cmd = cmd;
}

string EdgeValue::get_condition()
{
    return this->condition;
}

Command EdgeValue::get_command()
{
    return this->cmd;
}

string EdgeValue::get_write_to()
{
    return this->write_to;
}
