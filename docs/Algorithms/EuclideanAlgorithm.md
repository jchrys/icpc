title: Euclidean Algorithm
hero: Euclidean Algorithm
description: fast GCD algorithm, Euclidean Algorithm, Euclid's Algorithm
author: jchrys

# Euclidean Algorithm
> Euclidean algorithm, or Euclid's algorithm, is an efficient method for computing the GCD(greatest common divisor)

## Implementation
```cpp
int gcd(int a, int b) {
    if(!a) return b;
    return gcd(b % a, a);
}
```

## Proof 
> This proof consists of two parts.   
> - part 1: proves that Euclidean Algorithm gives us a common factor of two integers.   
> - part 2: proves that the common divisor that Euclidean Algorithm produces is the largest possible
### Part1
> Euclidean Algorithm gives us a common factor of two integers($a, b$).


$$
\begin{aligned}
a & = q_1b + r_1, &\text{where}(0<r<b)&  \\\\
b & = q_2r_1 + r_2, &\text{where}(0<r_2<r_1)& \\\\
r_1 & = q_3r_2 + r_3, &\text{where}(0<r_3<r_2)&\\\\
&\vdots \\\\
r_i & = q_{i+2}r_{i+1} + r_{i+2}, & \text{where}( 0 < r_{i+2} < r_{i+1})& \\\\
&\vdots \\\\
r_{k-2} & = q_{k}r_{k-1} + r_{k}\\\\
r_{k-1} & = q_{k+1}r_k \\\\
\end{aligned}
$$
From the last euqation, we know that $r_k|r_{k-1}$.
So, we know that we can express $r_{k-1} = cr_k$. where $c$ is an integer.
Now consider the previous equation.
$$
\begin{aligned}
r_{k-2} & = q_{k} r_{k-1} + r_{k} \\\\
        & = q_{k} cr_{k} + r_{k} \\\\
        & = r_{k} (q_{k}c + 1) \\\\
\end{aligned}
$$
Thus, we have that $r_{k} | r_{k-2}$.
In our equation previous to that one, we have
$$
r_{k-3} = q_{k-1} r_{k-2} + r_{k-1}
$$
From here, since $r_{k} | r_{k-1}$ and $r_{k}| r{k-2}$, using our rules of divisibility we have that $r_{k} | r_{k-3}$. 
As you can see, we can continue this process, considering each previous equation until we get to the last two, where we will find that $r_{k} | a$ and $r_{k} | b$.
Thus, we find that Euclids algorithm gives us a common factor of a and b.

### Part2
> The common divisor Euclidean Algorithm produces is the largest possible.

We will start by assuming that $a$ and $b$ have a common factor $d$, and then show that $d | r_{k}$.

consider an arbitrary common factor d of $a$ and $b$. If $d$ is a common factor, we can rewrite $a$ and $b$ as follows:

$$
a = d a^{\prime}, b = d b^{\prime}, \text{where } d, a, b \text{ are all positive integers }
$$

Now, consider the first euqation from Euclidean algorithm:

$$
\begin{aligned}
a & = q_{1} b + r_{1} \\\\
r_{1} & = a - q_{1}b \\\\
     & = da^{\prime} - q_{1} d b^{\prime} \\\\
     & = d(a^{\prime} - q_{1}b^{\prime})
\end{aligned}
$$

Thus, we have that $d|r_{1}$.
Now, consider the second equation, and repeat the steps we did on the first, this time solving for $r_{2}$

$$
\begin{aligned}
b      & = q_{2}r_{1} + r_{2} \\\\
r_{2}   & = b - q_{2}r_{1} \\\\
       & = d b^{\prime} - q_{2}dr_1^{\prime} \\\\
       & = d (b^{\prime} - q_{2} r_1^{\prime})
\end{aligned}
$$

As you can see, we can continue this process through each of the equations until we hit the second to last one, where we will have

$$
\begin{aligned}
r_{k-2}  & = q_{k}r_{k-1} + r_{k} \\\\
r_{k} & = q_{k}r_{k-1} - r_{k-2} \\\\
     & = q_{k}dr_{k-1}^{\prime} - d r_{k-2}^{\prime} \\\\
     & = d(q_{k}r_{k-1}^{\prime} - r_{k-2}^{\prime})
\end{aligned}
$$
Thus, $d| r_k$

But this says that any arbitrary common factor of $a$ and $b$ that we originally picked divides into $r_{k}$, the value that Euclidean algorithm produced.
Since we know that $r_{k}$ is a common factor to both $a$ and $b$, this shows that is must be the largest possible common factor, or $gcd(a, b)$   $\blacksquare$

## Extended Euclidean Algorithm
> Given integers $a$ and $b$, there is always an integral solution to the equation
$$
ax + by = gcd(a, b)
$$
> and we can find the values of $x$ and $y$.

### implementation
> not yet

### Proof
Consider writing down the steps of Euclidean Algorithm

$$
\begin{aligned}
a & = q_1b + r_1, &\text{where}(0<r<b)&  \\\\
b & = q_2r_1 + r_2, &\text{where}(0<r_2<r_1)& \\\\
r_1 & = q_3r_2 + r_3, &\text{where}(0<r_3<r_2)&\\\\
&\vdots \\\\
r_i & = q_{i+2}r_{i+1} + r_{i+2}, & \text{where}( 0 < r_{i+2} < r_{i+1})& \\\\
&\vdots \\\\
r_{k-2} & = q_{k}r_{k-1} + r_{k} & \text{where}(0 < r_k < r_{k-1}) \\\\
r_{k-1} & = q_{k+1}r_k \\\\
\end{aligned}
$$

Consider solving the second to last euqation for $r_k$. You get

$$
\begin{aligned}
r_{k-2} & = q_{k}r_{k-1} + r_{k} \\\\
r_{k}   & = r_{k-2} - q_{k}r_{k-1} \\\\
gcd(a, b) & = r_{k-2} - q_{k}r_{k-1} 
\end{aligned}
$$

Now, solve the previous equation for $r_{k-1}$

$$
\begin{aligned}
r_{k-3}   & = q_{k-1}r_{k-2} + r_{k-1} \\\\
r_{k-1}   & = r_{k-3} - q_{k-1}r_{k-2} \\\\
\end{aligned}
$$

and we substitute this value in to the previous derived equation

$$
\begin{aligned}
gcd(a, b) & = r_{k-2} - q_{k}r_{k-1} \\\\
          & = r_{k-2} - q_k(r_{k-3} - q_{k-1}r_{k-2}) \\\\
          & = r_{k-2}(1 - q_{k-1}) - q_kr_{k-3}
\end{aligned}
$$

Notice that now we have expressed $gcd(a, b)$ as a linear combination of $r_{k-2}$ and $r_{k-3}$. 
Next we can substitute for of $r_{k-2}$ in terms of $r_{k-3}$ and $r_{k-4}$, so that the $gcd(a, b)$ can be expressed as the linear combination of $r_{k-3}$ and $r_{k-4}$. 
Eventually, by continuing this process, $gcd(a, b)$ will be expressed as a linear combination of $a$ and $b$ as desired.

This process will be much easier to see with examples:

Find integers $x$ and $y$ such that

$$
135x + 50y = 5
$$

Use Euclidean Algorithm to compute $gcd(135, 50)$

$$
\begin{aligned}
135 & = 2 \sdot 50 + 35 \cdots\text{\textcircled 1}\\\\
50  & = 1 \sdot 35 + 15 \cdots\text{\textcircled 2}\\\\
35  & = 2 \sdot 15 + 5 \cdots\text{\textcircled 3}\\\\
15  & = 3 \sdot 5
\end{aligned}
$$

Now, let's use the Extended Euclidean algorithm to solve the problem

$ 5 = 35 - 2 \sdot 15  $ from equation 3

But, we have that

$ 15 = 50 - 35 $ from euqation $\text{\textcircled 2}$

Now we, substitute this value into the previously derived equation:
$$
\begin{aligned}
5 & = 35 - 2 \sdot 15 \\\\
5 & = 35 - 2 \sdot (50 - 35) \\\\
5 & = 3 \sdot 35 - 2 \sdot 50 
\end{aligned}
$$


Now, finally use the first equation to determine an expression for $35$ as a linear combination of $135$ and $50$
$$
35 = 135 - 2 \sdot 50 \text{ from equation}\text{\textcircled 1}
$$

Plug this into our last euqation:

$$
\begin{aligned}
5 & = 3 \sdot 35 - 2 \sdot 50  \\\\
5 & = 3 \sdot (135 - 2 \sdot 50) - 2 \sdot 50 \\\\
5 & = 3 \sdot 135 - 8 \sdot 50
\end{aligned}
$$

So, a set of solutions to the equation is $x=3, y = -8$


### This article is from 'COT3100Euclid01'

