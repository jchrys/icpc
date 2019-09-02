# String Algorithms
> _Pattern matching problem_
> The pattern matching problem can be easily solved in $\Omicron(nm)$ time by a brute force algorithm that tests all positions where the pattern may occur in the string.

> However, in this chapter, we will se that there are more efficient algorithms that require only $\Omicron(n+m)$ time.


## Terminologies

- Alphabet: The set of characters that may appear in the string is called an alphabet.

- Substring: A substring is a sequence of consecutive characters in a string.

- Subsequence: A subsequence is a sequence of (not necessarily consecutive) characters in a string in their original order

- Prefix: A prefix is a substring that starts at the beginning of a string.

- Suffix: A suffix is a substring that ends at the end of a string.

- Rotation: A rotation can be generate by moving the characters of a string one by one from the beginning to the end(or vice versa)

- Period: A preiod is a prefix of a string such that the string can be constructed by repeating the period.

- Border: A border is a string that is both a prefix and a suffix of a string.

- Lexicographical order: todo
