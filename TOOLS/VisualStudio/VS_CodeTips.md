## Productivity Tips For VSCode

### Useful Shortcuts

- `Ctrl+p` : Command Palette 
  - `@` : Find Objects
  - `{#}` : Find Dependencies
  - `#CAP` : First Letter in CamelCase of long class name

- `Ctrl+G` : Go To Line

- `Shift+<>` : Highlight Characters
- `Ctrl+<>` : Word by Word
- `Ctrl+D` : Find Match
- `Ctrl+D (Twice)` : Edit multiline

- `Ctrl+X`: If cursor is on a line, cut entire line

- `Alt+^`: Move Line of code up

- `Ctrl+L` : Highlight line by line
- `Ctrl+/` : Toggle Comments on code.

- `Ctrl+`` : Toggle Terminal
- `Ctrl+K` : Clear Terminal

## Compiler VS Interpretator
**Compiler**: Translate source code into machine code. Produces an exectuable file (.exe, .out) to run multiple times without recompilation.
**Interpreter**: Translates source code into machine code on-the-fly. Non standalone executable file.

## Test Driven Development
1. Failing Test
2. Test Passed (Minimal Code)
3. Refactor

**Code Kata**: Exercise in programming which helps programmers hone their skills through practice and repetition.

### Test Driven C++ - Phil Nash
**Failing Test**: Doesn't have to be assertion tests. Can be non-compiling due to missing functions.
**Test Passed**: Quick dirtiest code that makes it pass.
**Note**: Remember separation of concerns, loosely coupled. Fast, deterministic.

Tests hard to write or pass indicate code smells.

#### DEMO: Snakes and Ladders Kata

```c++
struct Portal {
    enum class Type { Snake, Ladder};
    Type type;
    uint32_t target;
};

std::map<uint32_t, Portal> portals = {
    {2, { Portal::Type::Ladder, 38} },
    {4, { Portal::Type::Ladder, 14} },
    {8, { Portal::Type::Ladder, 31} },
    {21, { Portal::Type::Ladder, 42} },
    {28, { Portal::Type::Ladder, 84} },
    {36, { Portal::Type::Ladder, 44} },
    {47, { Portal::Type::Snake, 26} },
    {49, { Portal::Type::Snake, 11} },
    {51, { Portal::Type::Ladder, 67} },
    {56, { Portal::Type::Snake, 53} },
    {62, { Portal::Type::Snake, 18} },
    {64, { Portal::Type::Snake, 60} },
    {71, { Portal::Type::Ladder, 91} },
    {80, { Portal::Type::Ladder, 100} },
    {87, { Portal::Type::Snake, 24} },
    {93, { Portal::Type::Snake, 73} },
    {95, { Portal::Type::Snake, 75} },
    {98, { Portal::Type::Snake, 78} },
}

```


