## push_swap

This project sorts data on a stack (with a second stack to help), with a limited set of instructions, using the lowest possible number of actions. To succeed we manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

I'm implementing the Radix Sort algorithm.

| operation | description |
| ------------ | ------------ |
| `sa` | swap a - swap the first 2 elements at the top of stack_a |
| `sb` | swap b - swap the first 2 elements at the top of stack_b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | push a - take the first element at the top of b and put it at the top of a |
| `pb` | push b - take the first element at the top of a and put it at the top of b |
| `ra` | rotate a - shift up all elements of stack_a by 1. The first element becomes the last one |
| `rb` | rotate b - shift up all elements of stack_b by 1. The first element becomes the last one |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate a - shift down all elements of stack_a by 1. The last element becomes the first one |
| `rrb` | reverse rotate b - shift down all elements of stack_b by 1. The last element becomes the first one |
| `rrr` | `rra` and `rrb` at the same time |

## checker download

* [push_swap checker for macOS](https://projects.intra.42.fr/uploads/document/document/5299/checker_Mac)
* [push_swap checker for linux](https://projects.intra.42.fr/uploads/document/document/5300/checker_linux)
