# Subset Sum Problem Solver

This program implements two approaches—Dynamic Programming and Brute Force—to solve the subset sum problem, where the goal is to find a subset of given numbers that adds up to or is as close as possible to a target sum.

## Features
- **Dynamic Programming Approach**:
  - Efficiently computes the closest subset sum.
  - Displays the subset of numbers that produce the result.

- **Brute Force Approach**:
  - Examines all possible subsets to find the exact or closest solution.
  - Ensures correctness by comparing all combinations.

## How It Works
1. **Input**:
   - A list of integers representing the available numbers.
   - A target sum as the last input.
2. **Output**:
   - The closest possible sum to the target.
   - The subset of numbers used to achieve that sum.
   - Validation of the solution.

## Example Usage

# Compile the code
g++ -o subsum AlgLab6.cpp

# Run the program
./subsum 14 8 11 5 14 18 4 15 11 79

Dynamic Programming:
The best possible sum is: 78
These are the values to add together:
1: 11
2: 15
3: 4
4: 18
5: 14
6: 5
7: 11

Brute Force:
The best possible sum is: 78
These are the values to add together:
1: 14
2: 8
3: 11
4: 5
5: 14
6: 15
7: 11
