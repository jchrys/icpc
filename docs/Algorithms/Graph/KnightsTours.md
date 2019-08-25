# Knight's tours
> A knight's tour is sequence of moves of a knight on an $n \times n$ chess board following the rules of chess such that the knight visits each square exactly once.

> A knight's tour is *closed* if the knight finally returns to the starting square and otherwise it is called *open* tour.

> A knight's tour corresponds to a Hamiltonian path in a graph whose nodes represent the suqare of the board, and two nodes are connected with an edge if a knight can move between the squares according to the rules of chess.

> A natural way to construct a knight's tour is to use backtracking. The search can be made more fficient by using _heuristics_ that attempt to guide the knight so that a complete tour will be found quickly

!!!note "Polynomial algorithms"
    There are also polynomial algorithms for finding knight's tours,
    but they are more complicated.
    
## Warnsdorf's rule
> Warnsdorf's rule is a simple and effective heruistic for finding a knight's tour.
> Using the rule, _it is possible to efficiently construct a tour even on a large board_.

> The idea is to always move the knight so that it ends up in a square where the number of possible moves is as small as possible.

## Related Topic
[Hamiltonian Paths]

## Related Problems
1. [나이트 투어](https://www.acmicpc.net/problem/1331) :star::star:
2. [나이트 투어](https://www.acmicpc.net/problem/2025) :star::star::star:

