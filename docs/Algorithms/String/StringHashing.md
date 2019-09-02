# String hashing
> String Hashing is a technique that allows us to efficiently check whether two strings are equal.

> The idea in string hashing is to compare hash values of strings instead of their individual characters.

## Time complexity



## Calculating hash values
> A Hash value of a string is a number that is calculated from the characters of the string.

> A usual way to implement string hashing is ==polynomial hashing==, which means that the hash value of a string $s$ of length $n$ is

$$
(s[0]A^{n-1} + s[1]A^{n-2} + \dotsm + s[n-1]A^0) \text{mod }B \\\\
\text{where } A \text{ and } B \text{ are pre-chosen constants}.
$$

## Preprocessing
> Using polynomial hashing, we can calculate the hashvalue of any substring of a string s in $\Omicron(1)$ time after an $\Omicron(n)$ time preprocessing.

> The idea is to construct an array $h$ contains the hash value of the prefix $s[0\dots k]$. The array values can be recursively calculated as follows:

$$
\begin{aligned}
h[0] &= s[0] \\\\
h[k] &= (h[k-1]A + s[k]) \text{mod } B
\end{aligned}
$$

> In addition, we construct array $p$ where $p[k]=A^k \text{mod } B$.

$$
\begin{aligned}
p[0] &= 1
p[k] &= (p[k-1]A) \text{mod } B
\end{aligned}
$$

> Constructing these arrays takes $\Omicron(n)$ time.

> After this, the hash value of any substring $s[a\dots b]$ can be calculated in $\Omicron(1)$ time using the formula

$$
(h[b] - h[a]p[b-a+1]) \text{mod } B
$$

> assuming that a > 0. If a = 0, the hash value is simply $h[b]$.

## Collisions and parameters
> An evident risk when comparing hash values is a collision, which means that two strings have different contents but equal hash values.

> collisions are always possible, because the number of different strings is larger than the nubmer of different hash values.

> However, the probability of a collision is small if the constants $A$ and $B$ are carefully chosen.

> A usual way is to choose random constants near $10^9$


## Implementation

```cpp
/**
 * File              : hashstring.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 02.09.2019
 * Last Modified Date: 02.09.2019
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s = "ALLEY";
ll A = 3;
ll B = 97;
ll h[1000];
ll p[1000];
void build(string s) {
    for (int k = 0; k < (int)s.size(); k++) {
        if (k == 0) {
            h[k] = s[0] % B;
            p[0] = 1;
        } else {
            h[k] = (h[k - 1] * A + s[k]) % B;
            p[k] = (p[k - 1] * A) % B;
        }
    }
}
ll get_hash_value(int a, int b) {
    if (a == 0) {
        return h[b];
    } else {
        return (h[b] - (h[a - 1] * p[b - a + 1])) % B;
    }
}
int main() {
    build(s);
    for (int i = 0; i <(int) s.size(); i++) {
        cout << h[i] << ' '; 
    }
    cout << endl;
    for (int i = 0; i <(int) s.size(); i++) {
        cout << p[i] << ' '; 
    }

    return 0;
}

```
