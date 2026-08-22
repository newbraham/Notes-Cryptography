---
title: "Mathematical Foundations"
subtitle: "The language of sets, logic, functions, and proofs for cryptography"
date: ""
lang: en
---

Cryptography is formulated in a mathematical language. Cryptographic algorithms operate on precisely defined sets, security properties are expressed using logical statements and quantifiers, and the correctness or security of a construction is established through mathematical proofs.

Before introducing number theory, modular arithmetic, algebraic structures, probability, lattices, or computational problems, we therefore establish the notation and foundational concepts that will be used throughout this text.

The purpose of this chapter is not to develop axiomatic set theory or formal logic from first principles. Instead, we introduce the mathematical language required to state definitions and prove results rigorously.

---

# 1. Sets

Informally, a **set** is a collection of distinct mathematical objects. These objects are called the **elements** of the set.

If an object $x$ is an element of a set $A$, we write $x\in A$; otherwise, we write $x\notin A$. For example, if $A=\{1,2,3,4\}$, then $2\in A$ while $5\notin A$.

Two sets are equal precisely when they contain the same elements.

More formally,

$$  
A=B  
\iff  
\forall x,\; (x\in A\iff x\in B).  
$$

Thus, the order in which elements are written is irrelevant, and repeated elements have no effect:

$$  
\{1,2,3\}=\{3,1,2\},
\qquad
\{1,1,2,3\}=\{1,2,3\}.  
$$

---

## 1.1 Set-builder notation

A set may be specified by listing its elements explicitly, as in $A=\{2,4,6,8\}$. When an explicit enumeration is inconvenient or impossible, we may instead specify a property that characterizes its elements.

For example,

$$  
A=\{x\in\mathbb{N}\mid 2\leq x\leq 8 \text{ and } x\text{ is even}\}.  
$$

In general, the expression

$$  
\{x\in S\mid P(x)\}  
$$

denotes the set of all elements $x$ of $S$ for which the predicate $P(x)$ is true. The symbol $\mid$ is read as _such that_; a colon is also frequently used, with the identical meaning: $\{x\in S:P(x)\}$.

---

## 1.2 Standard number sets

Several sets of numbers will occur repeatedly.

The set of natural numbers will be taken to include zero:

 $$  
\mathbb{N} = \{0,1,2,3,\ldots\}.  
$$

The set of integers is

 $$  
\mathbb{Z} = \{\ldots,-3,-2,-1,0,1,2,3,\ldots\}.  
$$

The set of rational numbers is

 $$  
\mathbb{Q} = \left\lbrace  
\frac{a}{b}  
\;\middle|\;  
a,b\in\mathbb{Z},\ b\neq0  
\right\rbrace.  
$$

The set of real numbers is denoted by

$$  
\mathbb{R}.  
$$

These sets satisfy

$$  
\mathbb{N}  
\subseteq  
\mathbb{Z}  
\subseteq  
\mathbb{Q}  
\subseteq  
\mathbb{R}.  
$$

We will later introduce sets such as $\mathbb{Z}_n$. Their meaning will be defined carefully when congruence classes and modular arithmetic are developed.

---

# 2. Subsets

Let $A$ and $B$ be sets.

We say that $A$ is a **subset** of $B$, written

$$  
A\subseteq B,  
$$

if every element of $A$ is also an element of $B$.

Formally,

$$  
A\subseteq B  
\iff  
\forall x\; (x\in A\implies x\in B).  
$$

For example,

$$  
\{1,2\}\subseteq\{1,2,3\}.  
$$

Every set is a subset of itself:

$$  
A\subseteq A.  
$$

Two sets are equal if and only if each is a subset of the other:

$$  
A=B  
\iff  
(A\subseteq B)\land(B\subseteq A).  
$$

This observation is frequently useful when proving that two sets are equal.

A **proper subset** is sometimes denoted by

$$  
A\subsetneq B,  
$$

meaning

$$  
A\subseteq B  
\quad\text{and}\quad  
A\neq B.  
$$

---

## 2.1 The empty set

The **empty set**, denoted by

$$  
\varnothing,  
$$

is the unique set containing no elements.

Thus,

$$  
\forall x,\quad x\notin\varnothing.  
$$

For every set $A$

$$  
\varnothing\subseteq A.  
$$

To see why, recall that

$$  
\varnothing\subseteq A  
$$

means

$$  
\forall x,\quad  
x\in\varnothing\implies x\in A.  
$$

Since there exists no $x$ satisfying $x\in\varnothing$, the implication cannot be violated. Such a statement is said to hold **vacuously**.

---

# 3. Operations on Sets

Let $A$ and $B$ be sets.

Their **union** is

$$  
A\cup B = \{x\mid x\in A\lor x\in B\}.  
$$

Their **intersection** is

 $$  
A\cap B = \{x\mid x\in A\land x\in B\}.  
$$

Their **difference** is

 $$  
A\setminus B = \{x\mid x\in A\land x\notin B\}.  
$$

For example, if

$$  
A=\{1,2,3\}  
$$

and

$$  
B=\{3,4,5\},  
$$

then

$$  
A\cup B=\{1,2,3,4,5\},  
$$

$$  
A\cap B=\{3\},  
$$

and

$$  
A\setminus B=\{1,2\}.  
$$

Notice that set difference is not symmetric in general:

$$  
A\setminus B  
\neq  
B\setminus A.  
$$

---

## 3.1 Power sets

The **power set** of a set $A$, denoted by

$$  
\mathcal{P}(A),  
$$

is the set of all subsets of $A$:

 $$  
\mathcal{P}(A)=\{B\mid B\subseteq A\}.  
$$

For example, if

$$  
A=\{1,2\},  
$$

then

 $$  
\mathcal{P}(A)=\{  
\varnothing,  
\{1\},  
\{2\},  
\{1,2\}  
\}.  
$$

If $A$ is finite and

$$  
|A|=n,  
$$

then

$$  
|\mathcal{P}(A)|=2^n.  
$$

This follows because, for each element of $A$, a subset has exactly two possibilities: either that element is included or it is not.

---

# 4. Cardinality

For a finite set $A$, its **cardinality**, denoted by $|A|$, is the number of elements contained in $A$.

For example,

$$  
|\{2,4,6,8\}|=4.  
$$

If

$$  
A=\{0,1\}^n,  
$$

where $\{0,1\}^n$ denotes the set of all binary strings of length $n$, then

$$  
|A|=2^n.  
$$

This notation will occur constantly in cryptography.

For instance,

$$  
\{0,1\}^{128}  
$$

contains exactly

$$  
2^{128}  
$$

binary strings.

Hence, if a cryptographic key is defined to be an arbitrary $128$-bit string, its key space $\mathcal{K}$ satisfies

$$  
|\mathcal{K}|=2^{128}.  
$$

It is important to distinguish the **length of a representation** from the cardinality of the set of possible representations. A key of length $n$ bits admits $2^n$ possible bit strings.

---

# 5. Ordered Pairs and Cartesian Products

An **ordered pair**

$$  
(a,b)  
$$

is an object containing two components in a specified order.

In general,

$$  
(a,b)\neq(b,a)  
$$

unless $a=b$.

Equality of ordered pairs is defined componentwise:

$$  
(a,b)=(c,d)  
\iff  
a=c\land b=d.  
$$

Let $A$ and $B$ be sets. Their **Cartesian product** is

 $$  
A\times B = \{(a,b)\mid a\in A\land b\in B\}.  
$$

For example, if

$$  
A=\{1,2\}  
$$

and

$$  
B=\{x,y\},  
$$

then

 $$  
A\times B = \{(1,x),(1,y),(2,x),(2,y)\}.  
$$

If $A$ and $B$ are finite, then

 $$  
|A\times B|=|A||B|.  
$$

More generally, for sets $A_1,\ldots,A_n$, we write

$$  
A_1\times\cdots\times A_n  
$$

for the set of ordered $n$-tuples

$$  
(a_1,\ldots,a_n)  
$$

such that

$$  
a_i\in A_i  
$$

for every $i$.

When all factors are the same set $A$, we often write

 $$  
A^n=\underbrace{A\times\cdots\times A}_{n\text{ times}}.  
$$

Thus,

$$  
\{0,1\}^n  
$$

is precisely the set of binary strings of length $n$.

---

# 6. Propositions and Logical Connectives

A **proposition** is a declarative statement having a definite truth value: either true or false.

For example,

> $7$ is prime

is a true proposition, while

> $8$ is prime

is false.

An expression such as

$$  
x>5  
$$

is not itself a proposition unless the value of $x$ has been fixed or $x$ has been quantified. It is more appropriately viewed as a **predicate**, whose truth value depends on $x$.

We will denote propositions by symbols such as

$$  
P,\quad Q,\quad R.  
$$

---

## 6.1 Negation

The **negation** of $P$ is denoted by

$$  
\neg P.  
$$

It has the opposite truth value from $P$.

If $P$ is true, then $\neg P$ is false; if $P$ is false, then $\neg P$ is true.

---

## 6.2 Conjunction

The **conjunction**

$$  
P\land Q  
$$

is true precisely when both $P$ and $Q$ are true.

It is read as

> $P$ and $Q$.

---

## 6.3 Disjunction

The **disjunction**

$$  
P\lor Q  
$$

is true when at least one of $P$ or $Q$ is true.

Unless explicitly stated otherwise, mathematical _or_ is inclusive. Thus $P\lor Q$ is also true when both $P$ and $Q$ are true.

---

# 7. Implication

The implication

$$  
P\implies Q  
$$

is read as

> if $P$, then $Q$.

It is false only in the case where $P$ is true and $Q$ is false.

Its truth table is

|$P$|$Q$|$P\implies Q$|
|---|---|---|
|true|true|true|
|true|false|false|
|false|true|true|
|false|false|true|

The behavior of implication when $P$ is false is important. A statement of the form

$$  
P\implies Q  
$$

does not assert that $P$ is true. It asserts only that whenever $P$ holds, $Q$ must also hold.

For example,

$$  
n\text{ is divisible by }4  
\implies  
n\text{ is even}  
$$

is true for every integer $n$.

---

## 7.1 Converse, inverse, and contrapositive

Given

$$  
P\implies Q,  
$$

its **converse** is

$$  
Q\implies P,  
$$

its **inverse** is

$$  
\neg P\implies\neg Q,  
$$

and its **contrapositive** is

$$  
\neg Q\implies\neg P.  
$$

An implication is logically equivalent to its contrapositive:

$$  
(P\implies Q)  
\iff  
(\neg Q\implies\neg P).  
$$

In general, however,

$$  
P\implies Q  
$$

does not imply

$$  
Q\implies P.  
$$

For example,

$$  
4\mid n  
\implies  
2\mid n,  
$$

but the converse is false: $2\mid6$, while $4\nmid6$.

---

# 8. Logical Equivalence

Two propositions $P$ and $Q$ are **logically equivalent** if they have the same truth value under every possible assignment of truth values.

We write

$$  
P\iff Q.  
$$

Equivalently,

$$  
P\iff Q  
$$

holds precisely when both

$$  
P\implies Q  
$$

and

$$  
Q\implies P  
$$

hold.

For instance, for an integer $n$,

$$  
n\text{ is even}  
\iff  
\exists k\in\mathbb{Z}\text{ such that }n=2k.  
$$

In this case the right-hand side is not merely a property of even integers; it is their definition.

---

# 9. Quantifiers

Let $P(x)$ be a predicate defined for elements $x$ of some set $S$.

The **universal quantifier**

$$  
\forall  
$$

means _for every_.

Thus,

$$  
\forall x\in S,\;P(x)  
$$

states that $P(x)$ is true for every element $x$ of $S$.

The **existential quantifier**

$$  
\exists  
$$

means _there exists_.

Thus,

$$  
\exists x\in S,\;P(x)  
$$

states that at least one element $x$ of $S$ satisfies $P(x)$.

The **unique existential quantifier**

$$  
\exists!  
$$

states that exactly one such element exists.

Thus,

$$  
\exists!x\in S,\;P(x)  
$$

means that there exists an $x\in S$ satisfying $P(x)$ and that any two elements satisfying $P$ must be equal.

More explicitly,

$$  
\exists!x\in S,\;P(x)  
$$

means

$$  
\exists x\in S  
\left(  
P(x)  
\land  
\forall y\in S,\; (P(y)\implies y=x)  
\right).  
$$

---

## 9.1 Negating quantified statements

Quantifiers interact with negation according to the rules

$$  
\neg(\forall x\in S,\;P(x))  
\iff  
\exists x\in S,\;\neg P(x),  
$$

and

$$  
\neg(\exists x\in S,\;P(x))  
\iff  
\forall x\in S,\;\neg P(x).  
$$

In words:

> It is not true that every element satisfies $P$

is equivalent to

> There exists an element that does not satisfy $P$.

Similarly,

> There does not exist an element satisfying $P$

is equivalent to

> Every element fails to satisfy $P$.

These transformations will be essential when constructing proofs and when interpreting cryptographic security definitions.

---

## 9.2 Order of quantifiers

Quantifiers generally cannot be exchanged freely.

Consider

$$  
\forall x\in\mathbb{Z},  
\exists y\in\mathbb{Z}  
\text{ such that }  
y>x.  
$$

This statement is true. For each $x$, we may choose

$$  
y=x+1.  
$$

Now consider

$$  
\exists y\in\mathbb{Z},  
\forall x\in\mathbb{Z},  
\quad  
y>x.  
$$

This statement is false. It claims the existence of a single integer greater than every integer.

Thus,

$$  
\forall x\exists y  
$$

and

$$  
\exists y\forall x  
$$

express fundamentally different assertions.

In cryptography, the order of quantifiers is often part of the substance of a security definition rather than merely a matter of notation.

---

# 10. Relations

Let $A$ and $B$ be sets.

A **binary relation from $A$ to $B$** is a subset

$$  
R\subseteq A\times B.  
$$

If

$$  
(a,b)\in R,  
$$

we may write

$$  
aRb.  
$$

A binary relation **on** $A$ is a relation

$$  
R\subseteq A\times A.  
$$

For example, equality defines a relation on $\mathbb{Z}$:

$$  
R =\{(a,b)\in\mathbb{Z}^2\mid a=b\}.  
$$

Likewise, the ordinary order relation satisfies

$$  
<\;\subseteq\;\mathbb{Z}\times\mathbb{Z}.  
$$

---

# 11. Properties of Relations

Let $R$ be a relation on a set $A$.

The relation $R$ is **reflexive** if

$$  
\forall a\in A,\quad aRa.  
$$

It is **symmetric** if

$$  
\forall a,b\in A,\quad  
aRb\implies bRa.  
$$

It is **antisymmetric** if

$$  
\forall a,b\in A,\quad  
(aRb\land bRa)\implies a=b.  
$$

It is **transitive** if

$$  
\forall a,b,c\in A,\quad  
(aRb\land bRc)\implies aRc.  
$$

Symmetry and antisymmetry are different properties and should not be confused.

For example, equality is both symmetric and antisymmetric. The usual relation $\leq$ on $\mathbb{Z}$ is antisymmetric but not symmetric.

---

# 12. Equivalence Relations

A relation $R$ on $A$ is an **equivalence relation** if it is

1. reflexive;
    
2. symmetric;
    
3. transitive.
    

If $R$ is an equivalence relation and $a\in A$, the **equivalence class** of $a$ is

$$  
[a] = \{x\in A\mid xRa\}.  
$$

Equivalence classes satisfy an important property: any two equivalence classes are either identical or disjoint.

More precisely, if $R$ is an equivalence relation, then for all $a,b\in A$,

$$  
[a]=[b]  
$$

or

$$  
[a]\cap[b]=\varnothing.  
$$

Consequently, equivalence relations partition a set into disjoint equivalence classes.

This construction will be fundamental when defining integers modulo $n$. The relation

$$  
a\equiv b\pmod n  
$$

will be shown to be an equivalence relation on $\mathbb{Z}$, and $\mathbb{Z}_n$ will arise from the corresponding equivalence classes.

---

# 13. Functions

Let $A$ and $B$ be sets.

A **function**

$$  
f:A\to B  
$$

assigns to every element $a\in A$ exactly one element $b\in B$.

More formally, a function $f:A\to B$ may be regarded as a relation

$$  
f\subseteq A\times B  
$$

such that

$$  
\forall a\in A,\;  
\exists!b\in B  
\text{ such that }  
(a,b)\in f.  
$$

We write

$$  
f(a)=b  
$$

instead of

$$  
(a,b)\in f.  
$$

The set $A$ is the **domain** of $f$, and $B$ is its **codomain**.

The codomain is part of the specification of a function. Consequently, the functions

$$  
f:\mathbb{R}\to\mathbb{R},  
\qquad  
f(x)=x^2  
$$

and

$$  
g:\mathbb{R}\to[0,\infty),  
\qquad  
g(x)=x^2  
$$

have the same rule but are formally different functions because they have different codomains.

---

# 14. Image and Preimage

Let

$$  
f:A\to B.  
$$

If $S\subseteq A$, the **image** of $S$ under $f$ is

$$  
f(S) = \{f(x)\mid x\in S\}.  
$$

The image of the entire domain is

$$  
f(A)= \{f(x)\mid x\in A\},  
$$

also denoted

$$  
\operatorname{Im}(f).  
$$

Thus,

$$  
\operatorname{Im}(f)\subseteq B.  
$$

If $T\subseteq B$, the **preimage** of $T$ is

$$  
f^{-1}(T) = \{x\in A\mid f(x)\in T\}.  
$$

This notation does **not** require $f$ to possess an inverse function.

For example, if

$$  
f:\mathbb{R}\to\mathbb{R},  
\qquad  
f(x)=x^2,  
$$

then

$$  
f^{-1}(\{4\})=\{-2,2\},  
$$

even though $f$ is not invertible as a function $\mathbb{R}\to\mathbb{R}$.

This distinction between a preimage and an inverse function is important.

---

# 15. Injective, Surjective, and Bijective Functions

A function

$$  
f:A\to B  
$$

is **injective** if

$$  
\forall x_1,x_2\in A,  
\quad  
f(x_1)=f(x_2)  
\implies  
x_1=x_2.  
$$

Equivalently,

$$  
x_1\neq x_2  
\implies  
f(x_1)\neq f(x_2).  
$$

A function is **surjective** if every element of its codomain is attained:

$$  
\forall y\in B,  
\exists x\in A  
\text{ such that }  
f(x)=y.  
$$

Equivalently,

$$  
\operatorname{Im}(f)=B.  
$$

A function is **bijective** if it is both injective and surjective.

Equivalently,

$$  
\forall y\in B,  
\exists!x\in A  
\text{ such that }  
f(x)=y.  
$$

---

## 15.1 Dependence on the domain and codomain

These properties are determined by the complete specification of a function, not by its formula alone. Injectivity depends on the rule and the domain: restricting the domain may turn a non-injective rule into an injective function. Surjectivity also depends on the codomain, because every element declared to belong to the codomain must be attained.

Consider

$$  
f:\mathbb{Z}\to\mathbb{Z},  
\qquad  
f(x)=2x.  
$$

This function is injective because

$$  
2x_1=2x_2  
\implies  
x_1=x_2.  
$$

It is not surjective because no odd integer belongs to its image.

However, consider

$$  
g:\mathbb{Z}\to2\mathbb{Z},  
\qquad  
g(x)=2x,  
$$

where

$$  
2\mathbb{Z}= \{2k\mid k\in\mathbb{Z}\}.  
$$

Now $g$ is both injective and surjective, and therefore bijective.

---

# 16. Function Composition

Let

$$  
f:A\to B  
$$

and

$$  
g:B\to C.  
$$

Their **composition** is the function

$$  
g\circ f:A\to C  
$$

defined by

$$  
(g\circ f)(x) = g(f(x)).  
$$

Function composition is associative. If

$$  
f:A\to B,  
\qquad  
g:B\to C,  
\qquad  
h:C\to D,  
$$

then

$$  
h\circ(g\circ f)=(h\circ g)\circ f.  
$$

Thus, we may write

$$  
h\circ g\circ f  
$$

without ambiguity.

Composition is generally not commutative:

$$  
g\circ f  
$$

and

$$  
f\circ g  
$$

may be different functions or one of them may not even be well-defined.

---

# 17. Identity and Inverse Functions

For every set $A$, the **identity function** is

$$  
\operatorname{id}_A:A\to A  
$$

defined by

$$  
\operatorname{id}_A(x)=x.  
$$

For every function

$$  
f:A\to B,  
$$

we have

$$  
f\circ\operatorname{id}_A=f  
$$

and

$$  
\operatorname{id}_B\circ f=f.  
$$

A function

$$  
f:A\to B  
$$

is **invertible** if there exists a function

$$  
g:B\to A  
$$

such that

$$  
g\circ f=\operatorname{id}_A  
$$

and

$$  
f\circ g=\operatorname{id}_B.  
$$

Such a function $g$ is unique and is denoted by

$$  
f^{-1}.  
$$

A fundamental theorem states that

$$  
f\text{ is invertible}  
\iff  
f\text{ is bijective}.  
$$

Therefore,

$$  
f^{-1}  
$$

exists as a function precisely when $f$ is bijective.

---

# 18. Indexed Families and Sequences

It is often convenient to describe collections of mathematical objects indexed by another set.

An **indexed family**

$$  
(a_i)_{i\in I}  
$$

assigns an object $a_i$ to each index $i\in I$.

A finite sequence may therefore be written as

$$  
(a_1,a_2,\ldots,a_n).  
$$

A sequence of length $n$ over a set $A$ is equivalently an element of

$$  
A^n.  
$$

For example, a binary string

$$  
x=x_1x_2\cdots x_n  
$$

with

$$  
x_i\in\{0,1\}  
$$

may be regarded as an element of

$$  
\{0,1\}^n.  
$$

We denote its length by

$$  
|x|=n.  
$$

When working with bit strings, the notation $|x|$ therefore refers to the **length of the string**, whereas for a finite set $A$, the notation $|A|$ refers to **cardinality**. The intended meaning will always be clear from context.

The set of all finite binary strings is denoted by

$$  
\{0,1\}^*=\bigcup_{n=0}^{\infty}\{0,1\}^n.  
$$

This set plays an important role in the formal description of algorithms.

---

# 19. Mathematical Definitions and Results

Mathematical writing distinguishes between several types of statements.

A **definition** introduces the precise meaning of a mathematical term. Definitions are not proved; they establish terminology.

In theorem-style mathematical writing, a **proposition** is a result stated for the purpose of proving it. The proof establishes that this particular proposition is true. This usage is compatible with the logical definition given earlier, according to which a proposition is any declarative statement with a definite truth value and may therefore be either true or false.

A **lemma** is a proposition introduced primarily as an intermediate result used to prove another result.

A **theorem** is a proposition considered sufficiently important to receive particular emphasis.

A **corollary** is a result that follows relatively directly from a previously established theorem or proposition.

The distinction among proposition, lemma, and theorem is organizational rather than logical. Each represents a mathematical statement requiring justification.

---

# 20. Proofs

A **proof** is a finite argument showing that a proposition follows logically from accepted definitions, axioms, hypotheses, and previously established results.

A proof is not merely a collection of examples. Verifying that a proposition holds for many particular inputs does not prove a universally quantified statement.

For instance, observing that

$$  
2^2,\;4^2,\;6^2,\;8^2  
$$

are even does not prove

$$  
\forall n\in\mathbb{Z},  
\quad  
n\text{ even}\implies n^2\text{ even}.  
$$

A valid proof must address an arbitrary element satisfying the hypotheses.

---

# 21. Direct Proof

Suppose we wish to prove

$$  
P\implies Q.  
$$

A **direct proof** assumes $P$ and derives $Q$ through valid logical steps.

### Proposition

If $a$ and $b$ are even integers, then $a+b$ is even.

### Proof

Assume that $a,b\in\mathbb{Z}$ are even.

By the definition of an even integer, there exist $k,l\in\mathbb{Z}$ such that

$$  
a=2k  
$$

and

$$  
b=2l.  
$$

Therefore,

$$  
a+b=2k+2l=2(k+l).  
$$

Since $\mathbb{Z}$ is closed under addition,

$$  
k+l\in\mathbb{Z}.  
$$

Hence there exists an integer $m=k+l$ such that

$$  
a+b=2m.  
$$

By the definition of evenness, $a+b$ is even. $\square$

---

# 22. Proof by Contraposition

To prove

$$  
P\implies Q,  
$$

it is sufficient to prove the logically equivalent statement

$$  
\neg Q\implies\neg P.  
$$

### Proposition

For every $n\in\mathbb{Z}$,

$$  
n^2\text{ even}  
\implies  
n\text{ even}.  
$$

### Proof

We prove the contrapositive.

Assume that $n$ is not even. Since every integer is either even or odd, $n$ is odd. Hence there exists $k\in\mathbb{Z}$ such that

$$  
n=2k+1.  
$$

Then

$$  
n^2=(2k+1)^2=4k^2+4k+1=2(2k^2+2k)+1.  
$$


Because

$$  
2k^2+2k\in\mathbb{Z},  
$$

$n^2$ is odd and therefore not even.

Thus,

$$  
n\text{ not even}  
\implies  
n^2\text{ not even}.  
$$

This is the contrapositive of the original statement, so the original statement follows. $\square$

---

# 23. Proof by Contradiction

To prove a proposition $P$ by contradiction, we assume

$$  
\neg P  
$$

and derive a contradiction.

Symbolically, the argument has the form

$$  
\neg P  
\implies  
\bot,  
$$

where $\bot$ denotes a contradiction.

From this we conclude

$$  
P.  
$$

A contradiction may consist, for example, of deriving both $Q$ and $\neg Q$, or deriving an equation known to be impossible.

Proof by contradiction will appear frequently in number theory and algebra.

---

# 24. Proof by Cases

Suppose the possibilities under consideration can be partitioned into cases

$$  
C_1,\ldots,C_n  
$$

such that

$$  
C_1\lor C_2\lor\cdots\lor C_n  
$$

always holds.

If one proves

$$  
C_i\implies P  
$$

for every $i$, then $P$ follows.

For integers, a common partition is

$$  
n\text{ is even}  
\lor  
n\text{ is odd}.  
$$

Thus, a proposition about arbitrary integers may sometimes be proved separately in the even and odd cases.

---

# 25. Mathematical Induction

Let $P(n)$ be a proposition defined for integers

$$  
n\geq n_0.  
$$

The **principle of mathematical induction** states that if

$$  
P(n_0)  
$$

is true and

$$  
\forall k\geq n_0,  
\quad  
P(k)\implies P(k+1),  
$$

then

$$  
\forall n\geq n_0,  
\quad  
P(n)  
$$

is true.

A proof by induction therefore consists of two parts.

### Base case

Prove

$$  
P(n_0).  
$$

### Inductive step

Let $k\geq n_0$ be arbitrary and assume

$$  
P(k).  
$$

This assumption is the **induction hypothesis**.

Then prove

$$  
P(k+1).  
$$

The logical content of induction is therefore not merely that one example implies another. The inductive step must establish

$$  
P(k)\implies P(k+1)  
$$

for an arbitrary $k$ in the specified range.

---

# 26. Necessary and Sufficient Conditions

If

$$  
P\implies Q,  
$$

then $P$ is said to be **sufficient** for $Q$, and $Q$ is said to be **necessary** for $P$.

For example,

$$  
4\mid n  
\implies  
2\mid n.  
$$

Thus, divisibility by $4$ is sufficient for divisibility by $2$, while divisibility by $2$ is necessary for divisibility by $4$.

If

$$  
P\iff Q,  
$$

then $P$ is necessary and sufficient for $Q$, and vice versa.

The phrase

> $P$ if and only if $Q$

therefore means precisely

$$  
(P\implies Q)\land(Q\implies P).  
$$

---

# 27. A First Cryptographic Formalization

The concepts developed above already allow us to express basic cryptographic objects mathematically.

Let $\mathcal{K}$ denote a key space, $\mathcal{M}$ a message space, and $\mathcal{C}$ a ciphertext space.

In the simplest deterministic symmetric setting, encryption may be modeled as a function

$$  
E:\mathcal{K}\times\mathcal{M}\to\mathcal{C},  
$$

and decryption as

$$  
D:\mathcal{K}\times\mathcal{C}\to\mathcal{M}.  
$$

For a fixed key $k\in\mathcal{K}$, define

$$  
E_k:\mathcal{M}\to\mathcal{C}  
$$

by

$$  
E_k(m)=E(k,m),  
$$

and similarly

$$  
D_k:\mathcal{C}\to\mathcal{M}  
$$

by

$$  
D_k(c)=D(k,c).  
$$

A natural correctness requirement is

$$  
\forall k\in\mathcal{K},  
\forall m\in\mathcal{M},  
\quad  
D_k(E_k(m))=m.  
$$

Equivalently,

$$  
D_k\circ E_k=\operatorname{id}_{\mathcal{M}}  
$$

for every $k\in\mathcal{K}$.

This immediately implies that $E_k$ must be injective. Indeed, suppose

$$  
E_k(m_1)=E_k(m_2).  
$$

Applying $D_k$ to both sides gives

$$  
D_k(E_k(m_1))=D_k(E_k(m_2)),  
$$

and therefore, by correctness,

$$  
m_1=m_2.  
$$

Thus,

$$  
E_k(m_1)=E_k(m_2)  
\implies  
m_1=m_2.  
$$

Hence $E_k$ is injective.

If, in addition,

$$  
|\mathcal{M}|=|\mathcal{C}|<\infty,  
$$

then injectivity implies surjectivity, so $E_k$ is bijective.

This small example illustrates an important theme: once a cryptographic construction is stated precisely using sets and functions, mathematical consequences can be derived from its definition.

### Randomized encryption

Many modern encryption algorithms are randomized rather than deterministic. In that case, it is more accurate to introduce a randomness space $\mathcal{R}$ and model encryption as

$$  
E:  
\mathcal{K}\times\mathcal{M}\times\mathcal{R}  
\to  
\mathcal{C}.  
$$

A ciphertext is then determined by a key $k$, a message $m$, and randomness $r$:

$$  
c=E(k,m;r).  
$$

Correctness becomes

$$  
\forall k\in\mathcal{K},  
\forall m\in\mathcal{M},  
\forall r\in\mathcal{R},  
\quad  
D(k,E(k,m;r))=m,  
$$

assuming every $r\in\mathcal{R}$ represents valid encryption randomness.

More sophisticated formalizations will later distinguish symmetric encryption, public-key encryption, probabilistic algorithms, negligible error probabilities, and security experiments. For now, the purpose is only to illustrate how sets, functions, and quantifiers provide the language needed to state cryptographic properties precisely.

---

# 28. Why These Foundations Matter

Much of modern cryptography consists of statements about mathematical objects and efficient algorithms operating on them. The fundamental objects may include bit strings, integers, vectors, matrices, polynomials, elements of finite fields, group elements, or points in lattices.

A cryptographic definition may contain expressions such as

$$  
f:A\to B,  
$$

$$  
x\leftarrow S,  
$$

$$  
\forall x\in S,  
$$

or

$$  
\Pr[\mathcal{A}(x)=1].  
$$

Later, we will encounter substantially more sophisticated statements involving computational complexity and probability. A typical security claim will quantify over adversarial algorithms and compare probabilities as a function of a security parameter.

Understanding those definitions requires more than computational ability. It requires being able to determine exactly:

- what sets the variables belong to;
    
- which quantities are universally or existentially quantified;
    
- what the domain and codomain of each function are;
    
- when two mathematical objects are equal;
    
- whether an implication has been proved in both directions;
    
- whether a function is injective, surjective, or invertible;
    
- which assumptions are being used in a proof.
    

The concepts developed in this chapter therefore form the logical and notational foundation for everything that follows.

---

# 29. Exercises

## Exercise 1 — Set Equality

Let

$$  
A = \{2k\mid k\in\mathbb{Z}\}  
$$

and

$$  
B=\{n\in\mathbb{Z}\mid n\text{ is even}\}.  
$$

Prove that

$$  
A=B.  
$$

Your proof should establish both

$$  
A\subseteq B  
$$

and

$$  
B\subseteq A.  
$$

---

## Exercise 2 — Power Sets

Let

$$  
A=\{a,b,c\}.  
$$

Determine $\mathcal{P}(A)$ and verify that

$$  
|\mathcal{P}(A)|=2^{|A|}.  
$$

---

## Exercise 3 — Cartesian Products

Let

$$  
A=\{0,1\}  
$$

and

$$  
B=\{a,b,c\}.  
$$

List the elements of $A\times B$ and $B\times A$.

Determine whether

$$  
A\times B=B\times A.  
$$

---

## Exercise 4 — Logical Implication

For each of the following, determine whether the implication is true for all $n\in\mathbb{Z}$:

$$  
4\mid n\implies2\mid n,  
$$

$$  
2\mid n\implies4\mid n,  
$$

$$  
6\mid n\implies3\mid n.  
$$

If an implication is false, provide a counterexample.

---

## Exercise 5 — Contrapositives

Write the contrapositive of

$$  
3\mid n  
\implies  
n^2\equiv0\pmod3.  
$$

Do not attempt to prove the statement yet.

---

## Exercise 6 — Quantifier Negation

Negate the statement

$$  
\forall x\in\mathbb{Z},  
\exists y\in\mathbb{Z},  
\quad  
y>x.  
$$

Your answer should contain no negation outside the quantifiers.

---

## Exercise 7 — Quantifier Order

Determine the truth value of each statement:

$$  
\forall x\in\mathbb{R},  
\exists y\in\mathbb{R},  
\quad  
x+y=0,  
$$

and

$$  
\exists y\in\mathbb{R},  
\forall x\in\mathbb{R},  
\quad  
x+y=0.  
$$

Explain why changing the order of the quantifiers changes the statement.

---

## Exercise 8 — Relations

Define a relation $R$ on $\mathbb{Z}$ by

$$  
aRb  
\iff  
a-b\text{ is even}.  
$$

Prove that $R$ is reflexive, symmetric, and transitive.

Conclude that $R$ is an equivalence relation.

Determine all distinct equivalence classes.

---

## Exercise 9 — Injectivity and Surjectivity

Consider

$$  
f:\mathbb{Z}\to\mathbb{Z},  
\qquad  
f(x)=3x+1.  
$$

Determine whether $f$ is injective and whether it is surjective.

Prove both claims.

---

## Exercise 10 — Dependence on the Codomain

Consider

$$  
f:\mathbb{R}\to\mathbb{R},  
\qquad  
f(x)=x^2,  
$$

and

$$  
g:\mathbb{R}\to[0,\infty),  
\qquad  
g(x)=x^2.  
$$

Determine whether each function is injective and surjective.

Explain why the two functions have different surjectivity properties despite having the same formula.

---

## Exercise 11 — Restricted Domains

Define

$$  
f:[0,\infty)\to[0,\infty)  
$$

by

$$  
f(x)=x^2.  
$$

Prove that $f$ is bijective and determine its inverse.

---

## Exercise 12 — Composition

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

Compute

$$  
g\circ f  
$$

and

$$  
f\circ g.  
$$

Determine whether

$$  
g\circ f=f\circ g.  
$$

---

## Exercise 13 — Direct Proof

Prove that the sum of two odd integers is even.

Your proof should explicitly invoke the definition of an odd integer.

---

## Exercise 14 — Contraposition

Prove that for every $n\in\mathbb{Z}$,

$$  
n^2\text{ odd}  
\implies  
n\text{ odd}.  
$$

Use contraposition.

---

## Exercise 15 — Correctness Implies Injectivity

Let

$$  
E:M\to C  
$$

and

$$  
D:C\to M  
$$

be functions satisfying

$$  
D(E(m))=m  
$$

for every $m\in M$.

Prove that $E$ is injective.

Is $D$ necessarily injective? Justify your answer.

---

# 30. Summary

This chapter established the basic mathematical language that will be assumed throughout the remainder of the text.

We introduced sets and their fundamental operations, including subsets, power sets, cardinality, and Cartesian products. We then developed the logical language of propositions, negation, conjunction, disjunction, implication, equivalence, and quantification.

Relations were defined formally as subsets of Cartesian products, leading to reflexive, symmetric, antisymmetric, and transitive relations and, in particular, equivalence relations and equivalence classes.

Functions were treated as special relations satisfying existence and uniqueness conditions. We distinguished domains, codomains, images, and preimages and introduced injective, surjective, and bijective functions, composition, identity functions, and inverse functions.

Finally, we introduced several fundamental proof techniques and demonstrated how the language developed in this chapter can already be used to formulate elementary cryptographic correctness conditions.

We are now prepared to study the arithmetic structure of the integers. The next step is **divisibility**, which will lead naturally to greatest common divisors, the Euclidean algorithm, Bézout's identity, prime numbers, congruences, and modular arithmetic.
