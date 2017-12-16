# Pigeon

This program is a π generator using Jeremy Gibbons' Spigot Algorithm. See the Jeremy Gibbons' paper in directory paper.

## Requirement

* A C++ compiler support C++11.
* GMP (GNU Multiple Precision Arithmetic Library)

## Demo

For calculating exactly N digits after the decimal point:

```cpp
#include <iostream>
#include "pigeon.hh"
int main() {
  for (long pi: pigeon(1024))
    std::cout << pi << std::flush;
}
```

For calculating infinitely:

```cpp
#include <iostream>
#include "pigeon.hh"
int main() {
  for (long pi: pigeon())
    std::cout << pi << std::flush;
}
```

This is not infinite, to be honest. But I believe deeply that no one can successfully calculate 18446744073709551615 (on 64 bits machine) digits after decimal point before memory runs out, or time.
