#include <iostream>

#include <ansiterm/ansiterm.hpp>

int main(int argc, char* argv[])
{
    using namespace ansi::color;

    std::cout << "-- Test foreground --\n";
    std::cout
        << fg::black   << "Black" << fg::reset << "\n"
        << fg::red     << "Red" << fg::reset << "\n"
        << fg::green   << "Green" << fg::reset << "\n"
        << fg::yellow  << "Yellow" << fg::reset << "\n"
        << fg::blue    << "Blue" << fg::reset << "\n"
        << fg::magenta << "Magenta" << fg::reset << "\n"
        << fg::cyan    << "Cyan" << fg::reset << "\n"
        << fg::white   << "White" << fg::reset << "\n"
        << fg::reset   << "Default" << fg::reset << "\n"
        << "\n"
        ;

    std::cout << "-- Test background --\n";
    std::cout
        << bg::black   << "Black" << bg::reset << "\n"
        << bg::red     << "Red" << bg::reset << "\n"
        << bg::green   << "Green" << bg::reset << "\n"
        << bg::yellow  << "Yellow" << bg::reset << "\n"
        << bg::blue    << "Blue" << bg::reset << "\n"
        << bg::magenta << "Magenta" << bg::reset << "\n"
        << bg::cyan    << "Cyan" << bg::reset << "\n"
        << bg::white   << "White" << bg::reset << "\n"
        << bg::reset   << "Default" << bg::reset << "\n"
        << "\n"
        ;

    std::cout << "-- Test resets --\n";
    std::cout 
        << fg::red << bg::blue << "{FG red, BG blue}" 
        << fg::reset << "{BG blue}" 
        << bg::reset << "{Normal}"
        << "\n"
        ;


    return 0;
}
