# Push Swap

## Overview
Push Swap is an algorithmic project that sorts a list of integers using two stacks (A and B) and a set of predefined operations. The goal is to sort the numbers in the fewest possible moves. A key part of the implementation involves handling arguments correctly, including cases where multiple numbers are passed as a single string.

## Features
- Efficiently sorts numbers using two stacks.
- Handles arguments passed as a single string or as multiple separate inputs.
- Implements stack operations such as `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

## Argument Handling
Since arguments may be passed as a single string (e.g., `"3 2 1"`) or as separate arguments (`3 2 1`), the program must:
1. **Split the input string** when necessary.
2. **Validate** that all inputs are valid integers.
3. **Handle duplicates and non-numeric values** gracefully.

### Example Input Handling
#### Multiple Arguments:
```
./push_swap 3 2 1
```
#### Single String Argument:
```
./push_swap "3 2 1"
```
Both cases should be handled identically by the program.

## Implementation Details
1. **Parsing Input:**
   - If arguments are passed as a single string, split them into separate values.
   - Convert the string values to integers while checking for errors.
   - Store them in stack A.

2. **Sorting Algorithm:**
   - For small lists (3-5 numbers), use a hardcoded optimal strategy.
   - For larger lists, implement an efficient sorting method (e.g., quicksort-based approach with median pivoting).

3. **Operations:**
   - Implement stack operations to manipulate A and B efficiently.
   - Ensure minimal moves for an optimal solution.

## Compilation
Compile using:
```
make
```
Run with:
```
./push_swap "3 5 2 1 4"
```
Or:
```
./push_swap 3 5 2 1 4
```

## Error Handling
- **Non-numeric input**: Prints `Error`.
- **Duplicate numbers**: Prints `Error`.
- **Out-of-range values**: Prints `Error`.

## Notes
- The `checker` program should be used to verify the correctness of the sorting sequence.
- The program should work within the defined rules and minimize the number of operations.

## Author
Developed by Huayun Ai as part of projects at 42 Berlin.

