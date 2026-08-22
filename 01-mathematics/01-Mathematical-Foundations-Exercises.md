---
title: "Mathematical Foundations"
subtitle: "Worked solutions"
date: ""
lang: en
---

# Exercise 1 — Set Equality

Let $A=\{2k\mid k\in\mathbb{Z}\}$ and $B=\{n\in\mathbb{Z}\mid n\text{ is even}\}$. We want to prove that $A=B$. It is sufficient to prove both inclusions, $A\subseteq B$ and $B\subseteq A$.

## Proof that $A\subseteq B$

Let $x\in A$ be arbitrary. By the definition of $A$, there exists some $k\in\mathbb{Z}$ such that $x=2k$. An integer is even precisely when it has this form, so $x$ is even. Since $x\in\mathbb{Z}$, it follows that $x\in B$. As $x$ was arbitrary, $A\subseteq B$.

## Proof that $B\subseteq A$

Let $x\in B$ be arbitrary. By the definition of $B$, $x$ is an even integer, so there exists some $k\in\mathbb{Z}$ such that $x=2k$. Every integer of this form belongs to $A$; hence $x\in A$. As $x$ was arbitrary, $B\subseteq A$. The two inclusions together prove that

$$  
\boxed{A=B}.  
$$

$\square$

---

# Exercise 2 — Power Sets

Let $A=\{a,b,c\}$. The power set $\mathcal{P}(A)$ contains every subset of $A$, so

$$  
\mathcal{P}(A) =\{  
\varnothing,  
\{a\},  
\{b\},  
\{c\},  
\{a,b\},  
\{a,c\},  
\{b,c\},  
\{a,b,c\}  
\}.  
$$

There are eight listed subsets. Since $|A|=3$, we also have $2^{|A|}=2^3=8$. Therefore,

$$  
\boxed{|\mathcal{P}(A)|=2^{|A|}}.  
$$

The general reason for this formula is that, when constructing a subset, every element has exactly two possibilities: it is either included or excluded. Thus, if a set contains $n$ elements, the number of possible subsets is

$$  
\underbrace{2\cdot2\cdots2}_{n\text{ times}}=2^n.  
$$

---

# Exercise 3 — Cartesian Products

Let $A=\{0,1\}$ and $B=\{a,b,c\}$.

By definition,

$$  
A\times B=\{(x,y)\mid x\in A,\ y\in B\}.  
$$

Therefore,

$$  
A\times B=\{  
(0,a),  
(0,b),  
(0,c),  
(1,a),  
(1,b),  
(1,c)  
\}.  
$$

Similarly,

$$  
B\times A=\{(x,y)\mid x\in B,\ y\in A\},  
$$

so

$$  
B\times A=\{  
(a,0),  
(a,1),  
(b,0),  
(b,1),  
(c,0),  
(c,1)  
\}.  
$$

These sets are not equal: for example, $(0,a)\in A\times B$, but $(0,a)\notin B\times A$. Therefore,

$$  
\boxed{A\times B\neq B\times A}.  
$$
Although $|A\times B|=|B\times A|$, equal cardinality does not imply equality of sets.

---

# Exercise 4 — Logical Implication

We analyze each implication for arbitrary $n\in\mathbb{Z}$.

## Implication 1

Suppose $4\mid n$. By the definition of divisibility, there exists some $k\in\mathbb{Z}$ such that

$$  
n=4k=2(2k).  
$$

Since $2k\in\mathbb{Z}$, it follows that $2\mid n$. Therefore,

$$  
\boxed{4\mid n\implies2\mid n}  
$$

is true for every $n\in\mathbb{Z}$.

## Implication 2

The implication is false. Take $n=2$: we have $2\mid2$ because $2=2\cdot1$, but $4\nmid2$. Thus $n=2$ is a counterexample, and

$$  
\boxed{2\mid n\implies4\mid n}  
$$

is false in general.

## Implication 3

Suppose $6\mid n$. Then there exists some $k\in\mathbb{Z}$ such that

$$  
n=6k=3(2k).  
$$

Because $2k\in\mathbb{Z}$, this proves that $3\mid n$. Therefore,

$$  
\boxed{6\mid n\implies3\mid n}  
$$

is true for every $n\in\mathbb{Z}$.

---

# Exercise 5 — Contrapositive

The original implication is

$$  
3\mid n  
\implies  
n^2\equiv0\pmod3.  
$$

The contrapositive of $P\implies Q$ is $\neg Q\implies\neg P$. Here, $P$ is the statement $3\mid n$, and $Q$ is the statement $n^2\equiv0\pmod3$. Therefore, the contrapositive is

$$  
\boxed{  
n^2\not\equiv0\pmod3  
\implies  
3\nmid n  
}.  
$$

---

# Exercise 6 — Quantifier Negation

The original statement is

$$  
\forall x\in\mathbb{Z},  
\exists y\in\mathbb{Z},  
\quad  
y>x.  
$$

Negating the entire statement gives

$$  
\neg  
\left(  
\forall x\in\mathbb{Z},  
\exists y\in\mathbb{Z},  
\quad  
y>x  
\right).  
$$

Using

$$  
\neg(\forall x,P(x))  
\iff  
\exists x,\neg P(x),  
$$

we obtain

$$  
\exists x\in\mathbb{Z},  
\neg  
\left(  
\exists y\in\mathbb{Z},  
\quad  
y>x  
\right).  
$$

Next, using

$$  
\neg(\exists y,P(y))  
\iff  
\forall y,\neg P(y),  
$$

we obtain

$$  
\exists x\in\mathbb{Z},  
\forall y\in\mathbb{Z},  
\quad  
\neg(y>x).  
$$

Since

$$  
\neg(y>x)  
\iff  
y\leq x,  
$$

the negation is

$$  
\boxed{  
\exists x\in\mathbb{Z},  
\forall y\in\mathbb{Z},  
\quad  
y\leq x  
}.  
$$

---

# Exercise 7 — Quantifier Order

Consider first

$$  
\forall x\in\mathbb{R},  
\exists y\in\mathbb{R},  
\quad  
x+y=0.  
$$

Let $x\in\mathbb{R}$ be arbitrary and choose $y=-x$. Since $-x\in\mathbb{R}$,

$$  
x+y=x+(-x)=0.  
$$

Therefore,

$$  
\boxed{  
\forall x\in\mathbb{R},  
\exists y\in\mathbb{R},  
\quad  
x+y=0  
}  
$$

is true.

Now consider

$$  
\exists y\in\mathbb{R},  
\forall x\in\mathbb{R},  
\quad  
x+y=0.  
$$

This statement claims that a single real number $y$ satisfies $x+y=0$ for every $x\in\mathbb{R}$. Suppose such a $y$ exists. Taking $x=0$ gives $y=0$, while taking $x=1$ would then require $1+0=0$, which is false.

Therefore,

$$  
\boxed{  
\exists y\in\mathbb{R},  
\forall x\in\mathbb{R},  
\quad  
x+y=0  
}  
$$

is false.

The difference lies in the dependency of the quantified variables. In $\forall x\exists y$, the value of $y$ may depend on $x$; here, we choose $y=-x$. In $\exists y\forall x$, a single fixed value of $y$ must work for every possible $x$.

Thus, in general,

$$  
\forall x\exists y  
\not\equiv  
\exists y\forall x.  
$$

---

# Exercise 8 — Relations

Define a relation $R$ on $\mathbb{Z}$ by

$$  
aRb  
\iff  
a-b\text{ is even}.  
$$

We prove that $R$ is reflexive, symmetric, and transitive.

## Reflexivity

Let $a\in\mathbb{Z}$ be arbitrary. Since $a-a=0=2\cdot0$, the difference $a-a$ is even, so $aRa$. Thus $R$ is reflexive.

## Symmetry

Suppose $aRb$. Then $a-b$ is even, so there exists some $k\in\mathbb{Z}$ such that

$$  
a-b=2k.  
$$

Then

$$  
b-a=-(a-b)=-2k=2(-k).  
$$

Since $-k\in\mathbb{Z}$, the difference $b-a$ is even and hence $bRa$. Thus $R$ is symmetric.

## Transitivity

Suppose $aRb$ and $bRc$. Then there exist $k,l\in\mathbb{Z}$ such that

$$  
a-b=2k  
$$

and

$$  
b-c=2l.  
$$

Adding both equations,

$$  
(a-b)+(b-c)=2k+2l.  
$$

Hence,

$$  
a-c=2(k+l).  
$$

Since $k+l\in\mathbb{Z}$, the difference $a-c$ is even and hence $aRc$. Thus $R$ is transitive.

Since $R$ is reflexive, symmetric, and transitive,

$$  
\boxed{R\text{ is an equivalence relation}.}  
$$

## Equivalence Classes

The equivalence class of an integer $a$ is

$$  
[a]=\{x\in\mathbb{Z}\mid xRa\}.  
$$

By the definition of $R$,

$$  
[a]=\{x\in\mathbb{Z}\mid x-a\text{ is even}\}.  
$$

There are exactly two distinct equivalence classes.

The equivalence class of $0$ is

$$  
[0]=\{x\in\mathbb{Z}\mid x\text{ is even}\}.  
$$

Thus,

$$  
[0]=\{\ldots,-4,-2,0,2,4,\ldots\}.  
$$

Equivalently,

$$  
[0]=2\mathbb{Z}.  
$$

The equivalence class of $1$ is

$$  
[1]=\{x\in\mathbb{Z}\mid x-1\text{ is even}\}.  
$$

This is precisely the set of odd integers:

$$  
[1]=\{\ldots,-3,-1,1,3,5,\ldots\}.  
$$

Equivalently,

$$  
[1]=2\mathbb{Z}+1.  
$$

Since every integer is either even or odd, these are the only two distinct equivalence classes.

Therefore,

$$  
\boxed{  
\mathbb{Z}/R=\{[0],[1]\}  
}.  
$$

---

# Exercise 9 — Injectivity and Surjectivity

Consider the function $f:\mathbb{Z}\to\mathbb{Z}$ defined by $f(x)=3x+1$.

## Injectivity

Suppose $f(x_1)=f(x_2)$. Then

$$  
3x_1+1=3x_2+1.  
$$

Subtracting $1$ and dividing by $3$ gives $x_1=x_2$. Therefore,

$$  
\boxed{f\text{ is injective}.}  
$$

## Surjectivity

For $f$ to be surjective, every $y\in\mathbb{Z}$ would need a preimage $x\in\mathbb{Z}$ satisfying $3x+1=y$. Solving for $x$ gives

$$  
x=\frac{y-1}{3}.  
$$

This expression is not necessarily an integer. For example, when $y=0$ the only possible value is $x=-\frac{1}{3}\notin\mathbb{Z}$, so $0$ has no preimage under $f$.

Therefore,

$$  
\boxed{f\text{ is not surjective}.}  
$$

Its image is

$$  
\operatorname{Im}(f)=\{3k+1\mid k\in\mathbb{Z}\}.  
$$

Equivalently,

$$  
\operatorname{Im}(f)=\{n\in\mathbb{Z}\mid n\equiv1\pmod3\}.  
$$

Hence, $f$ is injective but not surjective, and therefore it is not bijective.

---

# Exercise 10 — Dependence on the Codomain

Consider the functions

$$  
f:\mathbb{R}\to\mathbb{R},\quad f(x)=x^2,
\qquad
g:\mathbb{R}\to[0,\infty),\quad g(x)=x^2.  
$$

## Function $f$

### Injectivity

The function $f$ is not injective because $f(1)=f(-1)=1$ while $1\neq-1$. Therefore,

$$  
\boxed{f\text{ is not injective}.}  
$$

### Surjectivity

For every $x\in\mathbb{R}$, we have $x^2\geq0$. Therefore, no negative real number belongs to the image of $f$; for example, there is no real solution to $x^2=-1$.

Conversely, let $y\in[0,\infty)$ be arbitrary and choose $x=\sqrt{y}$. Then $x\in\mathbb{R}$ and $f(x)=x^2=y$, so every nonnegative real number belongs to the image. Hence both inclusions hold, and

$$  
\operatorname{Im}(f)=[0,\infty)  
\neq  
\mathbb{R}.  
$$

Therefore,

$$  
\boxed{f\text{ is not surjective}.}  
$$

## Function $g$

### Injectivity

As before, $g(1)=g(-1)=1$ with $1\neq-1$. Therefore,

$$  
\boxed{g\text{ is not injective}.}  
$$

### Surjectivity

Let $y\in[0,\infty)$ be arbitrary. Since $y\geq0$, choose the real number $x=\sqrt{y}$. Then

$$  
g(x)=x^2=(\sqrt{y})^2=y.  
$$

Thus every element of the codomain has a preimage, and therefore

$$  
\boxed{g\text{ is surjective}.}  
$$

The two functions have the same formula $x\mapsto x^2$ but different codomains. For $f$, the image $[0,\infty)$ is a proper subset of the codomain $\mathbb{R}$, so $f$ is not surjective. For $g$, the same image is exactly the codomain, so $g$ is surjective. This demonstrates that surjectivity is a property of the entire function, including its domain and codomain, rather than only of its formula.

---

# Exercise 11 — Restricted Domains

Define $f:[0,\infty)\to[0,\infty)$ by $f(x)=x^2$. We prove that $f$ is both injective and surjective.

## Injectivity

Suppose $f(x_1)=f(x_2)$. Subtracting and factoring gives

$$  
(x_1-x_2)(x_1+x_2)=0.  
$$

Thus $x_1=x_2$ or $x_1=-x_2$. Because both values are nonnegative, the second equality can occur only when $x_1=x_2=0$. In every case $x_1=x_2$, and therefore

$$  
\boxed{f\text{ is injective}.}  
$$

## Surjectivity

Let $y\in[0,\infty)$ be arbitrary and choose $x=\sqrt{y}$. Since $y\geq0$, this choice belongs to the domain, and

$$  
f(x)=x^2=(\sqrt{y})^2=y.  
$$

Therefore,

$$  
\boxed{f\text{ is surjective}.}  
$$

Since $f$ is both injective and surjective,

$$  
\boxed{f\text{ is bijective}.}  
$$

To determine the inverse, solve $y=x^2$ for $x$. Because the domain is restricted to nonnegative values, $x=\sqrt{y}$. Hence,

$$  
\boxed{  
f^{-1}(x)=\sqrt{x}  
}.  
$$

Indeed, $f^{-1}(f(x))=\sqrt{x^2}=x$ and $f(f^{-1}(x))=(\sqrt{x})^2=x$ for every $x\in[0,\infty)$.

---

# Exercise 12 — Composition

Let

$$  
f:\mathbb{R}\to\mathbb{R},  
\qquad  
f(x)=2x+1,  
$$

and

$$  
g:\mathbb{R}\to\mathbb{R},  
\qquad  
g(x)=x^2.  
$$

By definition, $(g\circ f)(x)=g(f(x))$. Since $f(x)=2x+1$, we obtain

$$  
(g\circ f)(x)=g(2x+1)=(2x+1)^2.  
$$

Therefore,

$$  
\boxed{  
(g\circ f)(x)=4x^2+4x+1  
}.  
$$

Similarly, $(f\circ g)(x)=f(g(x))$. Since $g(x)=x^2$, we obtain

$$  
(f\circ g)(x)=f(x^2)=2x^2+1.  
$$

Therefore,

$$  
\boxed{  
(f\circ g)(x)=2x^2+1  
}.  
$$

These functions are not equal: evaluating at $x=1$ gives $(g\circ f)(1)=9$ while $(f\circ g)(1)=3$. Therefore,

$$  
\boxed{  
g\circ f\neq f\circ g  
}.  
$$

This illustrates that function composition is generally not commutative.

---

# Exercise 13 — Direct Proof

We prove that the sum of two odd integers is even.

## Proof

Let $a,b\in\mathbb{Z}$ be arbitrary odd integers.

By the definition of an odd integer, there exist $k,l\in\mathbb{Z}$ such that $a=2k+1$ and $b=2l+1$. Therefore,

$$  
a+b=2(k+l+1).  
$$

Since $k,l\in\mathbb{Z}$ and the integers are closed under addition, $k+l+1\in\mathbb{Z}$. Thus $a+b$ has the form $2m$ for an integer $m$.

By the definition of evenness,

$$  
\boxed{a+b\text{ is even}.}  
$$

$\square$

---

# Exercise 14 — Contraposition

We want to prove that, for every $n\in\mathbb{Z}$,

$$  
n^2\text{ odd}  
\implies  
n\text{ odd}.  
$$

We prove the contrapositive.

The contrapositive is

$$  
n\text{ not odd}  
\implies  
n^2\text{ not odd}.  
$$

Since every integer is either even or odd, this is equivalent to

$$  
n\text{ even}  
\implies  
n^2\text{ even}.  
$$

## Proof

Let $n\in\mathbb{Z}$ be even. By definition, there exists some $k\in\mathbb{Z}$ such that $n=2k$. Then

$$  
n^2=2(2k^2).  
$$

Since $2k^2\in\mathbb{Z}$, the square $n^2$ is even.

Thus,

$$  
n\text{ even}  
\implies  
n^2\text{ even}.  
$$

We have proved the contrapositive. Therefore,

$$  
\boxed{  
n^2\text{ odd}  
\implies  
n\text{ odd}  
}.  
$$

$\square$

---

# Exercise 15 — Correctness Implies Injectivity

Let $E:M\to C$ and $D:C\to M$ be functions satisfying $D(E(m))=m$ for every $m\in M$.

Equivalently,

$$  
D\circ E=\operatorname{id}_M.  
$$

We first prove that $E$ is injective.

## Injectivity of $E$

Let $m_1,m_2\in M$ and suppose $E(m_1)=E(m_2)$. Applying $D$ to both sides gives

$$  
D(E(m_1))=D(E(m_2)).  
$$

By the assumed correctness property, the left-hand side is $m_1$ and the right-hand side is $m_2$. Therefore $m_1=m_2$, and hence

$$  
E(m_1)=E(m_2)  
\implies  
m_1=m_2.  
$$

By definition,

$$  
\boxed{E\text{ is injective}.}  
$$

$\square$

## Is $D$ necessarily injective?

No. Consider $M=\{0\}$ and $C=\{a,b\}$. Define $E(0)=a$ and define $D:C\to M$ by $D(a)=D(b)=0$. Then

$$  
D(E(0))=D(a)=0.  
$$

Thus $D(E(m))=m$ for every $m\in M$. However, $a\neq b$ while $D(a)=D(b)=0$, so $D$ is not injective.

Hence,

$$  
\boxed{D\text{ is not necessarily injective}.}  
$$

The condition $D\circ E=\operatorname{id}_M$ does imply two general properties: $E$ is injective and $D$ is surjective.

To see why $D$ is surjective, let $m\in M$ be arbitrary. The element $E(m)\in C$ satisfies $D(E(m))=m$, so every element of $M$ has a preimage under $D$.

In general, however, the condition does not imply that $E$ is surjective or that $D$ is injective.
