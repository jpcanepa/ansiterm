#ifndef ANSITERM_SGR_H_
#define ANSITERM_SGR_H_

#include <ansiterm/bits/ansiterm_control.hpp>

/*!\brief ANSI escape sequences for terminal control */
namespace ansi
{
namespace color
{

/*!\brief ANSI Color table */
enum ansi_color
{
    black   = 0,
    red     = 1,
    green   = 2,
    yellow  = 3,
    blue    = 4,
    magenta = 5,
    cyan    = 6,
    white   = 7,
    def     = 9 /*!< Implementation-defined default */
};

/*!\brief Target for color */
enum ansi_color_target
{
    foreground = 30,
    background = 40
};

/*!\brief Color manipulator */
struct color_manipulator
{
    struct reset {};

    explicit
    color_manipulator(ansi_color color, ansi_color_target target = foreground)
        : color_(color),
        target_(target)
    {

    }

    ansi_color_target target() const { return target_; }
    ansi_color color() const { return color_; }


private:
    ansi_color color_;
    ansi_color_target target_;
};

/*!\brief Insertion operator for a \c color_manipulator 
 * \param[in] s output stream to write to 
 * \param[in] c instance of \c color_manipulator to output 
 * \return the stream \c s */
inline 
std::ostream& operator<<(std::ostream& s, color_manipulator const& c)
{
    return s << csi << (c.target() + c.color()) << sgr;
}

/*!\brief Reset all graphic styles */
inline 
std::ostream& reset(std::ostream& s)
{
    return s << csi << sgr;
}

/*!\brief Helper shorthands for foreground colors */
namespace fg
{

/*!\brief Resets the foreground color to the default value */
inline 
std::ostream& reset(std::ostream& s)
{
    return s << color_manipulator(ansi::color::def);
}

/*!\brief Sets the foreground color to black */
inline 
std::ostream& black(std::ostream& s)
{
    return s << color::color_manipulator(color::black);
}

/*!\brief Sets the foreground color to red */
inline 
std::ostream& red(std::ostream& s)
{
    return s << color_manipulator(color::red);
}

/*!\brief Sets the foreground color to green */
inline 
std::ostream& green(std::ostream& s)
{
    return s << color::color_manipulator(color::green);
}

/*!\brief Sets the foreground color to yellow */
inline 
std::ostream& yellow(std::ostream& s)
{
    return s << color::color_manipulator(color::yellow);
}

/*!\brief Sets the foreground color to blue */
inline 
std::ostream& blue(std::ostream& s)
{
    return s << color::color_manipulator(color::blue);
}

/*!\brief Sets the foreground color to magenta */
inline 
std::ostream& magenta(std::ostream& s)
{
    return s << color::color_manipulator(color::magenta);
}

/*!\brief Sets the foreground color to cyan */
inline 
std::ostream& cyan(std::ostream& s)
{
    return s << color::color_manipulator(color::cyan);
}

/*!\brief Sets the foreground color to white */
inline 
std::ostream& white(std::ostream& s)
{
    return s << color::color_manipulator(color::white);
}

} /* namespace fg */

/*!\brief Helper shorthands for background colors */
namespace bg
{

/*!\brief Resets the background color to the default value */
inline 
std::ostream& reset(std::ostream& s)
{
    return s << color_manipulator(ansi::color::def, color::background);
}

/*!\brief Sets the background color to black */
inline 
std::ostream& black(std::ostream& s)
{
    return s << color::color_manipulator(color::black, color::background);
}

/*!\brief Sets the background color to red */
inline 
std::ostream& red(std::ostream& s)
{
    return s << color_manipulator(color::red, color::background);
}

/*!\brief Sets the background color to green */
inline 
std::ostream& green(std::ostream& s)
{
    return s << color::color_manipulator(color::green, color::background);
}

/*!\brief Sets the background color to yellow */
inline 
std::ostream& yellow(std::ostream& s)
{
    return s << color::color_manipulator(color::yellow, color::background);
}

/*!\brief Sets the background color to blue */
inline 
std::ostream& blue(std::ostream& s)
{
    return s << color::color_manipulator(color::blue, color::background);
}

/*!\brief Sets the background color to magenta */
inline 
std::ostream& magenta(std::ostream& s)
{
    return s << color::color_manipulator(color::magenta, color::background);
}

/*!\brief Sets the background color to cyan */
inline 
std::ostream& cyan(std::ostream& s)
{
    return s << color::color_manipulator(color::cyan, color::background);
}

/*!\brief Sets the background color to white */
inline 
std::ostream& white(std::ostream& s)
{
    return s << color::color_manipulator(color::white, color::background);
}

} /* namespace bg */
} /* namespace color */

namespace attribute
{

/*!\brief Modifiers. Those most widely supported, at least */
enum ansi_attribute
{
    resetall  = 0,
    bold      = 1,
    underline = 4,
    blink     = 5,

    nobold      = 22,
    nounderline = 24,
    noblink     = 25
};

struct attribute_manipulator
{
    explicit 
    attribute_manipulator(ansi_attribute attr)
        : attribute_(attr)
    {

    }

    ansi_attribute attribute() const { return attribute_; }

private:
    ansi_attribute attribute_;
};

inline
std::ostream& operator<<(std::ostream& s, attribute_manipulator const& am)
{
    return s << csi << am.attribute() << sgr;
}

namespace style
{

inline
std::ostream& reset(std::ostream& s)
{
    return s << attribute_manipulator(resetall);
}

inline
std::ostream& bold(std::ostream& s)
{
    return s << attribute_manipulator(attribute::bold);
}

inline
std::ostream& nobold(std::ostream& s)
{
    return s << attribute_manipulator(attribute::nobold);
}

inline
std::ostream& underline(std::ostream& s)
{
    return s << attribute_manipulator(attribute::underline);
}

inline
std::ostream& nounderline(std::ostream& s)
{
    return s << attribute_manipulator(attribute::nounderline);
}

inline
std::ostream& blink(std::ostream& s)
{
    return s << attribute_manipulator(attribute::blink);
}

inline
std::ostream& noblink(std::ostream& s)
{
    return s << attribute_manipulator(attribute::noblink);
}

} /* namespace style */
} /* namespace attribute */

} /* namespace ansi */

#endif
