## Typedef

`typedef` is a reserved keyword used to create an additional name (alias) for another data type.
New identifier for an existing type.
Helps with readability and reduces typos.
Usual conventions it to using `_t` for type.
```cpp
#include <iostream>
#include <vector>

typedef std::vector<std::pair<std::string>, int>> pairlist_t;
```

It has actually been largely replaced with the `using` keyword (works better with *templates*).
```cpp
#include <iostream>
#include <vector>

using text_t = std::string;
using number_t = int;
```