# CS372_HW3 Prompt
Choose one topic from Modern C++ (C++11 and beyond) that you would like to know more about and experiment with it. This can take as little as 20-30 minutes, and can even be part of some other project. Turn in a link to a GitHub repository, and any explanatory comments necessary so I know what you did.

# Description
This is a simple program that demonstrates a state machine for a game with inventory features. 

# Build Specs
(see tasks.json under ./.vscode)
* LLVM clang 
* MinGW64 gdb
* VSCode C/C++ Extension Pack

# Modern C++ Features
* **Variadic Template**
  * `class Inventory` uses a recursion to "unpack" a number of item-quantity pairs for storing.
  * **\[MAIN TOPIC\]** > I was always intrigued by how these worked since I'd see `ARGS...` plenty of times in other people's code. My main focus was implementing this as a way to initialize several params without calling the function every single time.
* `unordered_map`
  * This is the primary container type used for the `Inventory class`.
* `auto`
  * This was the main way to declare/define variables such as the iterators used to look into the map
* Structured Binding
  * Used to retrieve the map's elements, specifically since a `struct` was used. For readability
* Strongly-Type Enum
  * For state machine
* Init Statement for `if`
  * Used for iterations through the map
