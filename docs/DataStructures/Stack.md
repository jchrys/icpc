# Stack 
> Element deleted from the set is the one most recently inserted;  
> Stack implements *last-in, first out* or *LIFO* policy  
> You can use array to implement Stack

## supported operations
> The INSERT operation on a stack is often called PUSH,  
> and the DELETE operation, which does not take an argument,  
> is often called POP.

### 0. STEP0
maintain an array ${S}[{1,2,3, ..., n}]$


### 1. PUSH()

### 2. POP()

### 3. EMPTY()

$$
\begin{array}{cccc}
     0     &           1           &           2           &           3           \\\\
\hline
\text{COW} & \text{SE$\textbf{A}$} & \text{T$\textbf{A}$B} & \text{$\textbf{B}$AR} \\\\
\text{DOG} & \text{TE$\textbf{A}$} & \text{B$\textbf{A}$R} & \text{$\textbf{B}$IG} \\\\
\text{SEA} & \text{MO$\textbf{B}$} & \text{E$\textbf{A}$R} & \text{$\textbf{B}$OX} \\\\
\text{RUG} & \text{TA$\textbf{B}$} & \text{T$\textbf{A}$R} & \text{$\textbf{C}$OW} \\\\
\text{ROW} & \text{DO$\textbf{G}$} & \text{S$\textbf{E}$A} & \text{$\textbf{D}$IG} \\\\
\text{MOB} & \text{RU$\textbf{G}$} & \text{T$\textbf{E}$A} & \text{$\textbf{D}$OG} \\\\
\text{BOX} & \text{DI$\textbf{G}$} & \text{D$\textbf{I}$G} & \text{$\textbf{E}$AR} \\\\
\text{TAB} & \text{BI$\textbf{G}$} & \text{B$\textbf{I}$G} & \text{$\textbf{F}$OX} \\\\
\text{BAR} & \text{BA$\textbf{R}$} & \text{M$\textbf{O}$B} & \text{$\textbf{M}$OB} \\\\
\text{EAR} & \text{EA$\textbf{R}$} & \text{D$\textbf{O}$G} & \text{$\textbf{N}$OW} \\\\
\text{TAR} & \text{TA$\textbf{R}$} & \text{C$\textbf{O}$W} & \text{$\textbf{R}$OW} \\\\
\text{DIG} & \text{CO$\textbf{W}$} & \text{R$\textbf{O}$W} & \text{$\textbf{R}$UG} \\\\
\text{BIG} & \text{RO$\textbf{W}$} & \text{N$\textbf{O}$W} & \text{$\textbf{S}$EA} \\\\
\text{TEA} & \text{NO$\textbf{W}$} & \text{B$\textbf{O}$X} & \text{$\textbf{T}$AB} \\\\
\text{NOW} & \text{BO$\textbf{X}$} & \text{F$\textbf{O}$X} & \text{$\textbf{T}$AR} \\\\
\text{FOX} & \text{FO$\textbf{X}$} & \text{R$\textbf{U}$G} & \text{$\textbf{T}$EA} \\\\
\end{array}
$$
