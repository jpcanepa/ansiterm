#ifndef ANSITERM_CONTROL_H_
#define ANSITERM_CONTROL_H_

/*!\brief ANSI escape sequences for terminal control */
namespace ansi
{

/*!\brief ANSI Control Sequence Introducer/Initiator */
inline
std::ostream& csi(std::ostream& s)
{
    return s << "\033[";
}

/*!\brief Command parameter separator */
inline
std::ostream& sep(std::ostream& s)
{
    return s << ";";
}

/*!\brief Select Graphic Rendition */
inline 
std::ostream& sgr(std::ostream& s)
{
    return s << "m";
}

} /* namespace ansi */

#endif
