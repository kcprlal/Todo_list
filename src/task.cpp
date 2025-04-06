#include "task.hpp"
#include <sstream>

std::string Task::makeString() const{
    std::ostringstream oss;
    oss<<"["<< (done?"x":" ")<<"] "<<id<<". "<<context<<std::endl;
    return oss.str();
}