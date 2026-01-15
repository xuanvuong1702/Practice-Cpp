
#include <iostream>
#include <functional>
#include <vector>
#include "sample.hpp"
#include <string>
#include "common/utils.hpp"

int main() {

    print_sample();

    std::string s = "sample header";
    
    mcpp::print_section(s);

}