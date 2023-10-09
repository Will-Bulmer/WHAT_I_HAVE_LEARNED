## Namespaces

Namespace provides a solution for preventing name conflicts in large projects. Each entity needs a unique name.
A namespace allows for identically named entities as long as the namespaces are different.

:: - The Scope Resolution Operator

```cpp
#include <iostream>

namespace first {
    int x = 1;
}
namespace second {
    int x = 2;
}

int main() {
    int x = 0;
    std::cout << first::x; // x = 1;
    
    using namespace first

    std::cout << x; // x = 1;
    return 0;
}
```

### Warning
A lot of people save on typing by using 
```cpp
using namespace std;
```
std namespace has hundreds of methods which could lead to a naming conflict.
```cpp
using std::cout;
using std::string;
```