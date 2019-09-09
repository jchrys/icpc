# Static array queries
> We first focus on a situation the array is ==static==, i.e., the array values are never updated between the queries.

## Sum queries
> We can easily process sum queries on a static array by constructing a ==prefix sum array==.

> we can calculate any value of $sum_q(a, b)$ in $\Omicron(1)$ time as follows

$$
\text{sum}_q(a, b) = \text{sum}_q(0, b) - \text{sum}_q(0, a - 1)
$$

> By defining $\text{sum}_q(0, -1) = 0$, the above formula also holds when $a = 0$.


### Higher dimensions
> It is also possible to generalize this idea to higher dimensions.

> We can construct a two-dimensional prefix sum array that can be used to calculate the sum of any rectangular subarray in $\Omicron(1)$ time.

> Each sum in such a array corresponds to a subarray that begins at the upper-left corner of the array.


## Minimum queries
> Minimum queries are more difficult to process than sum queries.

> Still, there is a quite simple $Omicron(nlgn)$ time preprocessing method after which we can answer any minimum query in $Omicron(1)$ time. 

> Note that since minimum and maximum queries can be processed similarly, we can focus on minimum queries.

> ==The idea== is to precalculate all values of $\text{min}_q(a, b)$ where $b-a+1$(the length of the range) is a power of two.

> The number of precalculated value is $\Omicron(nlgn)$, because there are $\Omicron(lgn)$ range lengths that are powers of two.

> The values can be calculated efficiently using recursive formula

$$
\text{min}_q(a, b) = \text{min}(\text{min}_q(a, a + w -1), \text{min}_q(a + w, b) ) 
$$
> where $b - a + 1$ is apower of two and $w = (b - a + 1) / 2$.

> Calculating all those values takes $\Omicron(nlgn)$ time.


> After this, any value of $min_q(a, b)$ can be calculated in $\Omicron(1)$ time as a minimum of two precalculated values.

> Let $k$ be the largest power of two that does not exceed $ b - a + 1 $.

> We can calculate the value of $min_q(a, b)$ using the formula

$$
\text{min}_q(a, b) = \text{min}(\text{min}_q(a, a + k -1), \text{min}_q(b - k + 1, b))
$$

> In the above formula, the range $[a, b]$ is represented as the union of the ranges $[a, a + k -1 ]$ and $[b - k + 1, b]$, both of length $k$.


### Implementation
> naive implementation
```cpp
int arr[log(N) + 1][N];
//preprocess  
for (int k = 1; k <= log(N); k++) {
    int w = (1 << (k - 1));
    for (int i = 0; i < N - w + 1; i++) {
        arr[k][i] = min(arr[k - 1][i], arr[k-1][i + w]);
    }
}

// queries
int minq(int a, int b) {
    int w = b - a + 1;
    int k = 0;
    while ( (1 << (k + 1)) <= w ) k++;
    return min(arr[k][a], arr[k][b - (1 << k) + 1]);
}
```


> improved version

```cpp
/**
 * File              : 2357RMQimproved.cpp
 * Author            : JCHRYS <jchrys@me.com>
 * Date              : 09.09.2019
 * Last Modified Date: 09.09.2019
 * Last Modified By  : JCHRYS <jchrys@me.com>
 */

#include <bits/stdc++.h>
using namespace std;
int const MAXN = 100000;
int const MAXLOG = 17;
int log(int x) {
    int ans = -1;
    while(x) {
        ans++;
        x >>= 1;
    }
    return ans;
}
int mintable[MAXLOG][MAXN];
int maxtable[MAXLOG][MAXN];

int N, M;

void preprocess() {
    // building base
    for (int i = 0; i < N; i++) {
        cin >> mintable[0][i]; 
        maxtable[0][i] = mintable[0][i];
    }

    for (int j = 1; j <= log(N); j++) {
        for (int i = 0; i + (1 << (j - 1))< N; i++) {
            mintable[j][i] = min(mintable[j - 1][i], 
                                 mintable[j - 1][i + (1 << (j - 1))]);
            maxtable[j][i] = max(maxtable[j - 1][i], 
                                 maxtable[j - 1][i + (1 << (j - 1))]);
        }
    }

}

int minq(int a, int b) {
    int len = b - a + 1;
    int k = log(len);
    return min(mintable[k][a], mintable[k][b - (1 << k) + 1]);
}

int maxq(int a, int b) {
    int len = b - a + 1;
    int k = log(len);
    return max(maxtable[k][a], maxtable[k][b - (1 << k) + 1]);
}


int main() {
    cin >> N >> M;
    preprocess();
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        cout << minq(a, b) << ' ' << maxq(a, b) << '\n';
    }

    return 0;
}

```
