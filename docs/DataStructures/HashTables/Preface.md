# Preface
> Many applications require a dynamic set that supports only the dictionary
operations.   
:fire: A *Hash Table* is an effective data structure for implementing dictionaries.  
A hash table typically uses an array of size proportional to the number of  keys actually stored.


##[Hash functions](#)
Instead of using the key as an array index directly, the array index is computed from the key

## Dealing with collisions
> Since a hash table uses array of size relatively small to the number of possible keys, there is a chance to *collisions* in which more than one key maps to the same array index

### 1. Chaining
> Resolve Collisions with linked list

### 2. Open Addressing
> Resolve Collisions  with iterative hashing

## Perfect Hashing
> perfect hashing can support searches in $O(1)\  wosrt-case$ time, when the set is static(!= dynamic)   
