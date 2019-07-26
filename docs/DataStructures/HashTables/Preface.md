# Preface
> Many applications require a dynamic set that supports only the dictionary
operations.   
:fire: A *Hash Table* is an effective data structure for implementing dictionaries.  
A hash table typically uses an array of size proportional to the number of  keys actually stored.


##[Hash functions](#)
Instead of using the key as an array index directly, the array index is computed from the key

## Dealing with collisions
> Collision: two keys hash to the same slot.   
> Since a hash table uses array of size relatively small to the number of possible keys, there is a chance to *collisions* in which more than one key maps to the same array index


<table><tr><th></th><th colspan="2">Chaining</th><th colspan="2">OpenAddressing<br></th><th colspan="2">PerfectHashing<br></th></tr><tr><td>OPERATIONS<br></td><td>average</td><td>worst</td><td>average</td><td>worst</td><td>average<br></td><td>worst</td></tr><tr><td>INSERT</td><td>$O(1)$</td><td></td><td></td><td></td><td>-</td><td>-</td></tr><tr><td>SEARCH</td><td>$O(n/m)$</td><td>$O(n)$</td><td></td><td></td><td>$O(1)$</td><td>$O(1)$</td></tr><tr><td>DELETE</td><td>$O(1)$<br></td><td></td><td></td><td></td><td>-</td><td>-</td></tr></table>

### 1. Chaining
> In Chaining, we place all the elements that hash to the same slot in to the same linked llist

### 2. Open Addressing
> Resolve Collisions  with iterative hashing

## Perfect Hashing
> Perfect Hasing uses second level Hashtable that has no collision. 
> perfect hashing can support searches in $O(1)\  wosrt-case$ time, when the set is static(!= dynamic)   
