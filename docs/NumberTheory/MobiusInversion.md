# Mobius Inversion
> Mobius Function

$$
\mu(n) = \begin{cases}
    -1 &\text{if } n \text{ is a square-free positive integer with an \textcolor{blue}{even} number of prime factors.} \\\\
     1 &\text{if } n \text{ is a square-free positive integer with an \textcolor{blue}{odd} number of prime factors.}  \\\\
     0 &\text{if } n \text{ has a squared prime factor.} 
\end{cases}
$$

## Properties
> Mobius function is multiplicative.  

 $\mu(ab) = \mu(a)\mu(b) \text{ whenever } a \text{ and  } b \text{ are coprime.}$

> The sum of the Mobius function over all positive divisors of $n$ (including $n$ itself and $1$) is zero except when $n=1$:  

$$
\sum_{\mathclap{d|n}}\mu(d) = \begin{cases}
    1 &\text{if }n = 1 \\\\
    0 &\text{if }n \gt 1
\end{cases}
$$
The equality above leads to the important Mobius inversion formula and is the main reason why $\mu$ is of relevance in theory of multiplicative and arithmetic functions.

## Mobius Inversion Formula
The classic version states that if $g$ and $f$ are arithmetic functions satisfying
$$
g(n) = \sum_{d|n}f(d) \text{ for every integer } n \ge 1 \\\\
$$
then
$$
f(n) = \sum_{d|n}\mu(d)g(\frac n d) \text{ for every integer } n \ge 1 \\\\ 
$$
where $\mu$ is the Mobius function and the sums extend over all positive divisors $d$ of $n$ (indicated by $d|n$ in the above formulae). in effect, the original $f(n)$ can be determined given $g(n)$ by using inversion formula. The two sequences are said to be **Mobius transforms** of each other.

## Series relations


## Generalizations
A related inversion formula more useful in combinatorics is as follows: Suppose $F(x)$ and $G(x)$ are complex-valued functions defined on the interval $[1, \infin)$ such that
$$
G(x) = \sum_{1 \le n \le x}F(\frac x n) \text{ for all } x \ge 1
$$
then
$$
F(x) = \sum_{1 \le n \le x}\mu(n)G(\frac x n) \text{ for all } x \ge 1
$$

## Related problems

### Find out the number of co-prime pairs of integer $(x, y)$ in range $[1, n]$

$$
\begin{aligned}
&\text{let } F(N) = \sum_{i=1}^N\sum_{j=1}^N[gcd(i, j) = 1] \\\\
&\text{Consider that } [n = 1] = \sum_{d|n}\mu(d)  \\\\
&\text{set } n = gcd(i, j) \text{ then,  }\\\\
&[gcd(i, j) = 1] = \sum_{d|gcd(i, j)}\mu(d) \\\\
\end{aligned}
$$

$$
\begin{aligned}
f(N) &= \sum_{i=1}^N\sum_{j=1}^N\sum_{d|gcd(i, j)}\mu(d) \\\\
&= \sum_{i=1}^N\sum_{j=1}^N\sum_{d=1}^N\mu(d)[d|gcd(i, j)] \\\\
&= \sum_{i=1}^N\sum_{j=1}^N\sum_{d=1}^N\mu(d)[d | i][d | j] \\\\
&= \sum_{d=1}^N\sum_{i=1}^N\sum_{j=1}^N\mu(d)[d | i][d | j] \\\\
&= \sum_{d=1}^N\mu(d)\sum_{i=1}^N[d | i]\sum_{j=1}^N[d | j] \\\\
&= \sum_{d=1}^N\mu(d){\lfloor \frac N d \rfloor}^2
\end{aligned}
$$

### Find out the sum of $gcd(x, y)$ for every pair of integer $(x, y)$ in range $[1, N]$

$$
\begin{aligned}
f(N) &= \sum_{i=1}^N\sum_{j=1}^Ngcd(i, j) \\\\
&= \sum_{d=1}^N d \sum_{i=1}^N \sum_{j=1}^N [gcd(i, j) = d] \\\\
\text{replace } i = ad, j = bd \\\\
&= \sum_{d=1}^N d \sum_{ad=1}^N \sum_{bd=1}^N [gcd(ad, bd) = d] \\\\
&= \sum_{d=1}^N d \sum_{ad=1}^N \sum_{bd=1}^N [gcd(a, b) = 1] \\\\
&= \sum_{d=1}^N d \sum_{a=1}^{\lfloor {N \over d} \rfloor} \sum_{b=1}^{\lfloor {N \over d} \rfloor} [gcd(a, b) = 1] \\\\
\text{replace } a= i, b= j \\\\
&= \sum_{d=1}^N d \sum_{i=1}^{\lfloor {N \over d} \rfloor} \sum_{j=1}^{\lfloor {N \over d} \rfloor} [gcd(a, b) = 1] \\\\
\text{since } \sum_{i=1}^N \sum_{i=1}^N [gcd(i, j) = 1] &= \sum_{d=1}^N \mu(d) {\lfloor{N \over d} \rfloor}^2 \text{ by previous problem }\\\\
&= \sum_{d=1}^N d \sum_{k = 1}^{\lfloor {N \over d} \rfloor} \mu(k) {\lfloor {N \over dk} \rfloor}^2 \\\\
\end{aligned}
$$

### Links
1. Mocha and Stars(2200) [:link:](https://codeforces.com/contest/1559/problem/E)
