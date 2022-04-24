# Number Theory
### 1.1 INTRODUCTION
For two assertions $A$ and $B$, the following statements are logically equivalent.

1. $A$ implies $B$.
2. If $A$ is true, then $B$ is true.
3. In order that $A$ be true it is necessary that $B$ be true.
4. $B$ is a necessary condition for $A$.
5. $A$ is a sufficient condition of $B$

If $A$ implies $B$ and $B$ implies $A$, then one can say that $B$ is necessary and sufficient condition for $A$ to hold.


### 1.2 DIVISIBILITY

#### Definition 1.1
An Integer $b$ is divisible by an integer $a$, not zero, if there is an integer $x$ such that $b = ax$ and we write $a|b$. In case $b$ is not divisible by $a$, we write $a \not|  b$.

#### Definition 1.2
The integer $a$ is a common divisor of $b$ and $c$ in case $a|b$ and $a|c$.
Since there is only a finite number of divisors of any nonzero integer, there is only a finite number of common divisors of $b$ and $c$, except in the case $b = c = 0$.
If at least one of $b$ and $c$ is not 0, the greatest among their common divisors is called the greatest common divisor of $b$ and $c$ and is denoted by $(b, c)$.
Similarly, we denote the greatest common divisor $g$ of the integer $b_1, b_2, \dotsm , b_n$, not all zero, by $(b_1, b_2, \dotsm, b_n)$.

#### Definition 1.3
We say that $a$ and $b$ are relatively prime in case $(a, b) = 1$, and that $a_1, a_2, \dotsm, a_n$ are relatively prime in case $(a_1, a_2, \dotsm, a_n) = 1$.
We say that $a_1, a_2, \dotsm, a_n$ are relatively prime in pairs in case $(a_i, a_j) = 1$ for all $i = 1, 2, \dotsm, n$ and $j = 1, 2, \dotsm, n$ with $i \not = j$.

The fact that $(a, b) = 1$ is sometimes expressed by saying that $a$ and $b$ are coprime, or by saying that $a$ is prime to $b$.

#### Definition 1.4
The integers $a_1, a_2, \dotsm, a_n$, all different from zero, have a common multiple $b$ if $a_i|b$ for $i = 1, 2, \dotsm, n$.
(Note that common multiples do exist; for example the product $a_1 a_2 \dotsm a_n$ is one)
The least of the positive common multiples is called the least common multiple, and it is denoted by $[a_1, a_2, \dotsm, a_n]$.


#### Theorem 1.1
1. $a|b \text{ implies } a|bc \text{ for any integer } c$  
2. $a|b \text{ and } b|c \text{ imply  } a|c$
3. $a|b \text{ and } a|c \text{ imply } a|(bx+cy) \text{ for any integers } x \text{ and } y$
4. $a|b \text{ and } b|a \text{ imply } a = \pm b$
5. $a|b, a > 0, b > 0 \text{ imply } a \leqslant b$
6. $\text{if } m \ne 0, a|b \text{ implies and is implied by } ma|mb$

#### Theorem 1.2
The Division algorithm. Given any integers $a$ and $b$, with $a > 0$, there exists unique integers $q$ and $r$ such that $b = qa + r$, $0 \leqslant r \le a$. If $a \nmid b$, then $r$ satisfies the stronger inequalities $0 < r < a$.

#### Theorem 1.3
If $g$ is the greatest common divisor of $b$ and $c$, then there exist integers $x_0$ and $y_0$ such that $g = (b, c) = bx_0 + cy_0$.

Another way to state this very fundamental result is that the g.c.d. of two integers $b$ and $c$ is expressible as a linear combination of $b$ and $c$ with integral multipliers $x_0$ and $y_0$.

#### Theorem 1.4 
The greatest common divisor $g$ of $b$ and $c$ can be characterized in the following two ways  
1. It is the least positive value of $bx + cy$ where $x$ and $y$ range over all integers.  
2. It is the positive common divisor of $b$ and $c$ that is divisible by every common divisor.

#### Theorem 1.5
Given any integers $b_1, b_2, \cdots, b_n$ not all zero, with greatest common divisor $g$, there exist integers $x_1, x_2, \cdots, x_n$ such that
$$
g = (b_1, b_2, \cdots, b_n) = \sum_{j=1}^{n} b_j x_j.
$$
Further more, $g$ is the least positive value of the linear form $\textstyle\sum_{j=1}^{n}b_j y_j$ where the $y_j$ range over all integers; also $g$ is the positive common divisor of $b_1, b_2, \cdots, b_n$ that is divisible by every common divisor.

#### Theorem 1.6
For any positive integer $m$, $(ma, mb) = m(a, b)$.

#### Theorem 1.7
If $d|a$ and $d|b$ and $d > 0$, then
$$
(\frac a d, \frac b d) = \frac 1 d(a, b)
$$
If $(a, b) = g$, then 
$$
(\frac a g, \frac b g) = 1
$$

#### Theorem 1.8
If $(a, m) = (b, m) = 1$, then $(ab, m) = 1$.

#### Theorem 1.9
For any integer $x$, $(a, b) = (b, a) = (a, -b) = (a, b+ax)$.

#### Theorem 1.10
If $c|ab$ and $(b, c) = 1$, then $c|a$.

#### Theorem 1.11
The Euclidean algorithm. Given integers $b$ and $c > 0$, we make a repeated application of the division algorithm, Theorem 1.2, to obtain a series of equations
$$
\begin{aligned}
b &= c q_1 + r,     &0 < r_1 < c&, \\\\
c &= r_1 q_2 + r_2,  &0 < r_2 < r_1&,\\\\
r_1 &= r_2 q_3 + r_3,  &0 < r_3 < r_2&,\\\\
&\cdots, &\cdots &, \\\\
r_{j - 2} &= r_{j - 1} q_{j} + r_{j},  &0 < r_{j} < r_{j - 1}&,\\\\
r_{j - 1} &= r_{j} q_{j + 1}.\\\\
\end{aligned}
$$
The greatest common divisor $(b, c)$ of $b$ and $c$ is $r_j$, the last non zero remainder in the division process. Values of $x_0$ and $y_0$ in $(b, c) = bx_0 + cy_0$ can be obtained by writing each $r_i$ as a linear combination of $b$ and $c$.

#### Theorem 1.12
If $b$ is any common multiple of $a_1, a_2, \dotsm, a_n$, then $[a_1, a_2, \dotsm, a_n]|b$. 
This is the same as saying that if $h$ denotes $[a_1, a_2, \dotsm, a_n]$, then $0, ±h, ±2h, ±3h, \dotsm$ comprise all the common multiples of $a_1, a_2, \dotsm, a_n$.

#### Theorem 1.13
If $m > 0$, $[ma, mb] = m[a, b]$. Also $[a, b] \cdot (a, b) = |ab|$.

#### Problem 1.2.9
Show that if $ac|bc$ then $a|b$.

>Solution
>
Let $ c \not = 0$, above assertion in turn is a direct consequences of Theorem1.1 part 6 obtained by replacing $m$ in that theorem by $c$.

#### Problem 1.2.12
Given that $(a, 4) = 2$ and $(b, 4) = 2$, prove that $(a + b, 4) = 4$.

>Solution
>
Since $(a, 4) = 2$ , $2|a$, so $a = 2m$ for $m \in \Z$.
But we also know $4 \not | a$, so $2 \not | m$, and so $m = 2n + 1$ for $n \in \Z$.
This gives $a = 4n + 2$, and similarly $b = 4k + 2$ for some $k \in \Z$.
So we now have that
$$
a + b = (4n + 2) + (4k + 2) = 4n + 4k + 4 = 4(n + k + 1)
$$
So $4 | (a + b)$, which shows that $(a + b, 4) = 4$.


