#include <iostream>

#include <ansiterm/ansiterm.hpp>

int main(int argc, char* argv[])
{
    using namespace ansi::color;

    std::cout << "-- Test foreground colors --\n";
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

    std::cout << "-- Test background colors --\n";
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

    std::cout << "-- Test color resets --\n";
    std::cout 
        << fg::red << bg::blue << "{FG red, BG blue}" 
        << fg::reset << "{BG blue}" 
        << bg::reset << "{Normal}"
        << "\n\n"
        ;

    using namespace ansi::attribute;
    std::cout << "-- Test styles --\n";
    std::cout 
        << style::bold      << "Bold" << style::reset << "\n"
        << style::underline << "Underline" << style::reset  << "\n"
        << style::blink     << "Blink (like it's web 0.1!)" << style::reset << "\n"
        << "\n"
        ;

    std::cout << "-- Test style resets --\n";
    std::cout 
        << style::bold << style::underline << fg::red << "{FG:red, bold, underlined}"
        << style::nobold << "{FG:red, underlined}"
        << fg::reset << "{Underlined}"
        << style::nounderline << "{Normal}"
        << "\n\n"
        ;
    return 0;
}
