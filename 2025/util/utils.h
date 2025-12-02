#include <string>
#include <iostream>
#include <source_location>
#include <string_view>
#ifndef UTILS_H

#define UTILS_H

template<typename Type>
void assert_equal(Type result, Type expected, const std::source_location location = std::source_location::current())
{
    if (result != expected)
    {
        std::cout << "Result isn't correct, is " << result << " but should be " << expected 
        << '\n' << location.file_name() << '(' << location.line() << ':' << location.column() << ')' << "\n";
        exit(1);
    }
}

#endif