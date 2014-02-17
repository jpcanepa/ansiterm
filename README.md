## Rationale

Just that. For all your 

```C++
using namespace ansi::color;
std::cout << fg::red << "ERROR: something happened!" << fg::reset << "\n";
```

needs.

### Ok. Why?
This seems to be the main justification behind all code I submit to Github: _because of reasons_. 

In this case, I wanted to play with manipulators (that's kind of a WTF in and of itself), and
for some reason, adding color to the output in a C++-esque way seemed like a good fit.

### Doesn't libX do the same, only better/sexier/faster?
Most certainly. Don't really know. Don't really care. Read the previous point.

### License?
Want to say _MIT_, but I haven't included the notice in any files, only the LICENSE file. That's not
enough if I understand correctly, and I'll correct it if anyone ever cares enough to _use_ any of this 
nonsense.
