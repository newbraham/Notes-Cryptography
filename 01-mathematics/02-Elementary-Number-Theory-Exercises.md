---
title: "Elementary Number Theory"
subtitle: "Worked solutions"
date: ""
lang: en
---

These solutions accompany the exercises in [Elementary Number Theory](02-Elementary-Number-Theory.md). The calculations retain the hypotheses used in each argument, particularly when cancellation, modular inverses, or exponent reduction is involved.

# Exercise 1 — Quotients and Remainders

For each pair, we seek integers $q$ and $r$ satisfying $a=bq+r$ and $0\leq r<b$.

For $(a,b)=(137,12)$, we have

$$
137=12\cdot11+5.
$$

Thus $q=11$ and $r=5$.

For the negative dividend, the remainder must still be nonnegative. We have

$$
-137=12(-12)+7.
$$

Thus $q=-12$ and $r=7$. The alternative expression $-137=12(-11)-5$ does not satisfy the required remainder condition.

Finally,

$$
2026=37\cdot54+28,
$$

so $q=54$ and $r=28$. Therefore the three answers are

$$
\boxed{(q,r)=(11,5),\quad(-12,7),\quad(54,28)}.
$$

---

# Exercise 2 — Divisibility and Linear Combinations

Suppose $a\mid b$ and $a\mid c$. By definition, there exist integers $s$ and $t$ such that $b=as$ and $c=at$. For arbitrary $x,y\in\mathbb{Z}$,

$$
bx+cy=(as)x+(at)y=a(sx+ty).
$$

Since $sx+ty\in\mathbb{Z}$, the definition of divisibility gives

$$
\boxed{a\mid(bx+cy)}.
$$

Now suppose an integer $d$ divides both $35$ and $64$. The result just proved implies that $d$ divides every integer linear combination of these numbers. In particular,

$$
11\cdot35-6\cdot64=385-384=1,
$$

so $d\mid1$. The only positive divisor of $1$ is $1$. Consequently, no integer greater than $1$ divides both $35$ and $64$, and

$$
\boxed{\gcd(35,64)=1}.
$$

---

# Exercise 3 — The Euclidean Algorithm

Applying the division algorithm repeatedly gives

$$
\begin{aligned}
12345&=6789\cdot1+5556,\\
6789&=5556\cdot1+1233,\\
5556&=1233\cdot4+624,\\
1233&=624\cdot1+609,\\
624&=609\cdot1+15,\\
609&=15\cdot40+9,\\
15&=9\cdot1+6,\\
9&=6\cdot1+3,\\
6&=3\cdot2+0.
\end{aligned}
$$

The last nonzero remainder is $3$. Therefore,

$$
\boxed{\gcd(12345,6789)=3}.
$$

---

# Exercise 4 — Bézout Coefficients

We substitute backward through the divisions from Exercise 3. Starting with the last nonzero remainder,

$$
\begin{aligned}
3
&=9-6\\
&=9-(15-9)\\
&=2\cdot9-15\\
&=2(609-40\cdot15)-15\\
&=2\cdot609-81\cdot15\\
&=2\cdot609-81(624-609)\\
&=83\cdot609-81\cdot624\\
&=83(1233-624)-81\cdot624\\
&=83\cdot1233-164\cdot624\\
&=83\cdot1233-164(5556-4\cdot1233)\\
&=739\cdot1233-164\cdot5556\\
&=739(6789-5556)-164\cdot5556\\
&=739\cdot6789-903\cdot5556\\
&=739\cdot6789-903(12345-6789)\\
&=-903\cdot12345+1642\cdot6789.
\end{aligned}
$$

Thus one pair of Bézout coefficients is

$$
\boxed{x=-903,\qquad y=1642}.
$$

Direct substitution verifies the result:

$$
12345(-903)+6789(1642)
=-11147535+11147538
=3.
$$

This agrees with $\gcd(12345,6789)=3$.

---

# Exercise 5 — Euclid's Lemma

We prove the statement by induction on the number $k$ of factors.

## Base case

For $k=1$, the hypothesis is $p\mid a_1$, which is already the desired conclusion.

## Inductive step

Assume the result holds for a product of $k$ integers. Consider integers $a_1,\ldots,a_k,a_{k+1}$ satisfying

$$
p\mid a_1a_2\cdots a_ka_{k+1}.
$$

Apply Euclid's lemma to the two integers $a_1a_2\cdots a_k$ and $a_{k+1}$. It follows that

$$
p\mid a_1a_2\cdots a_k
\quad\text{or}\quad
p\mid a_{k+1}.
$$

In the second case the conclusion holds immediately. In the first case, the induction hypothesis implies $p\mid a_i$ for some $i\in\{1,\ldots,k\}$. Thus in either case $p$ divides at least one of the $k+1$ factors.

By induction,

$$
\boxed{
p\mid a_1a_2\cdots a_k
\implies
\exists i\in\{1,\ldots,k\}\text{ such that }p\mid a_i
}.
$$

$\square$

---

# Exercise 6 — Congruence and Remainders

Let the division algorithm give

$$
a=nq+r,
\qquad
b=nq'+r',
\qquad
0\leq r,r'<n.
$$

Suppose first that $a\equiv b\pmod n$. Then $n\mid(a-b)$. Since

$$
a-b=n(q-q')+(r-r'),
$$

it follows that $n\mid(r-r')$. However, $-(n-1)\leq r-r'\leq n-1$, and the only multiple of $n$ in this interval is $0$. Hence $r=r'$, so $a$ and $b$ have the same remainder.

Conversely, suppose $r=r'$. Then

$$
a-b=n(q-q'),
$$

so $n\mid(a-b)$. By definition, $a\equiv b\pmod n$. Therefore,

$$
\boxed{
a\equiv b\pmod n
\iff
a\text{ and }b\text{ have the same remainder modulo }n
}.
$$

$\square$

---

# Exercise 7 — Modular Arithmetic

First reduce the inputs modulo $17$:

$$
38\equiv4\pmod{17},
\qquad
49\equiv-2\pmod{17}.
$$

For the sum,

$$
38+49\equiv4+(-2)\equiv2\pmod{17}.
$$

For the product,

$$
38\cdot49\equiv4(-2)\equiv-8\equiv9\pmod{17}.
$$

For the power,

$$
38^4\equiv4^4=256=17\cdot15+1\equiv1\pmod{17}.
$$

The requested canonical representatives are therefore

$$
\boxed{2,\qquad9,\qquad1}.
$$

---

# Exercise 8 — Modular Inverses

An inverse of $a$ modulo $n$ exists if and only if $\gcd(a,n)=1$.

## The inverse of $17$ modulo $3120$

The Euclidean algorithm gives

$$
\begin{aligned}
3120&=17\cdot183+9,\\
17&=9\cdot1+8,\\
9&=8\cdot1+1.
\end{aligned}
$$

Substituting backward,

$$
\begin{aligned}
1
&=9-8\\
&=9-(17-9)\\
&=2\cdot9-17\\
&=2(3120-17\cdot183)-17\\
&=2\cdot3120-367\cdot17.
\end{aligned}
$$

Thus $-367$ is an inverse of $17$ modulo $3120$. Its canonical representative is $3120-367=2753$, so

$$
\boxed{17^{-1}\equiv2753\pmod{3120}}.
$$

Indeed, $17\cdot2753=15\cdot3120+1$.

## The inverse of $18$ modulo $3120$

Since $\gcd(18,3120)=6\neq1$, the invertibility criterion gives

$$
\boxed{18^{-1}\pmod{3120}\text{ does not exist}}.
$$

## The inverse of $35$ modulo $64$

The Euclidean algorithm and backward substitution give

$$
\begin{aligned}
64&=35+29,\\
35&=29+6,\\
29&=4\cdot6+5,\\
6&=5+1,
\end{aligned}
$$

and hence

$$
\begin{aligned}
1
&=6-5\\
&=6-(29-4\cdot6)\\
&=5\cdot6-29\\
&=5(35-29)-29\\
&=5\cdot35-6(64-35)\\
&=11\cdot35-6\cdot64.
\end{aligned}
$$

Therefore,

$$
\boxed{35^{-1}\equiv11\pmod{64}}.
$$

---

# Exercise 9 — Linear Congruences

## The congruence $9x\equiv12\pmod{15}$

We have $\gcd(9,15)=3$, and $3\mid12$, so the congruence has exactly three solutions modulo $15$. Dividing the equation and modulus by $3$ gives

$$
3x\equiv4\pmod5.
$$

The inverse of $3$ modulo $5$ is $2$, so

$$
x\equiv8\equiv3\pmod5.
$$

The three lifts modulo $15$ are

$$
\boxed{x\equiv3,8,13\pmod{15}}.
$$

## The congruence $14x\equiv5\pmod{21}$

Here $\gcd(14,21)=7$, but $7\nmid5$. The solvability criterion therefore implies that

$$
\boxed{14x\equiv5\pmod{21}\text{ has no solution}}.
$$

Directly, a solution would give $14x-5=21k$ for some $k\in\mathbb{Z}$, or $5=7(2x-3k)$, which would imply $7\mid5$, a contradiction.

---

# Exercise 10 — Units and the Totient Function

An element $[a]_{20}$ is a unit precisely when $\gcd(a,20)=1$. Testing the canonical representatives gives

$$
\mathbb{Z}_{20}^*
=\{[1]_{20},[3]_{20},[7]_{20},[9]_{20},[11]_{20},[13]_{20},[17]_{20},[19]_{20}\}.
$$

There are eight elements, so

$$
\boxed{\varphi(20)=8}.
$$

Since $20=2^2\cdot5$ and $4$ and $5$ are coprime, multiplicativity and the prime-power formula give

$$
\varphi(20)=\varphi(2^2)\varphi(5)
=(4-2)(5-1)=2\cdot4=8.
$$

We may also count directly in $\{1,\ldots,20\}$. There are $10$ multiples of $2$ and $4$ multiples of $5$. The $2$ multiples of $10$ appear in both groups, so inclusion-exclusion gives

$$
10+4-2=12
$$

integers that are not coprime to $20$. The remaining $20-12=8$ integers are coprime to $20$, confirming the result.

---

# Exercise 11 — Cancellation

The congruence $ac\equiv bc\pmod n$ means

$$
n\mid c(a-b).
$$

Since $\gcd(c,n)=1$, Bézout's identity provides integers $u,v$ such that

$$
cu+nv=1.
$$

Multiplying by $a-b$ gives

$$
a-b=cu(a-b)+nv(a-b).
$$

The first term on the right is divisible by $n$ because $n\mid c(a-b)$, and the second is visibly divisible by $n$. Hence $n\mid(a-b)$, which proves

$$
\boxed{a\equiv b\pmod n}.
$$

The coprimality hypothesis is necessary. For example, take $a=1$, $b=4$, $c=2$, and $n=6$. Then

$$
ac=2\equiv8=bc\pmod6,
$$

but $1\not\equiv4\pmod6$. Here $\gcd(2,6)=2\neq1$.

---

# Exercise 12 — Euler's Theorem

Since $\gcd(7,20)=1$, Euler's theorem applies. We have $\varphi(20)=8$, so

$$
7^8\equiv1\pmod{20}.
$$

Because $222=8\cdot27+6$,

$$
7^{222}\equiv7^6\pmod{20}.
$$

Now $7^2=49\equiv9\pmod{20}$ and $7^4\equiv9^2=81\equiv1\pmod{20}$. Therefore,

$$
7^6=7^4\cdot7^2\equiv1\cdot9\equiv9\pmod{20},
$$

and the answer is

$$
\boxed{7^{222}\equiv9\pmod{20}}.
$$

Checking $\gcd(7,20)=1$ before reducing the exponent is essential because Euler's theorem does not assert $a^{\varphi(n)}\equiv1\pmod n$ for nonunits $a$.

---

# Exercise 13 — Fast Modular Exponentiation

The binary decomposition of the exponent is

$$
117=64+32+16+4+1.
$$

Starting with $5$ and repeatedly squaring modulo $19$ gives

$$
\begin{aligned}
5^1&\equiv5\pmod{19},\\
5^2&\equiv25\equiv6\pmod{19},\\
5^4&\equiv6^2\equiv36\equiv17\pmod{19},\\
5^8&\equiv17^2\equiv289\equiv4\pmod{19},\\
5^{16}&\equiv4^2\equiv16\pmod{19},\\
5^{32}&\equiv16^2\equiv256\equiv9\pmod{19},\\
5^{64}&\equiv9^2\equiv81\equiv5\pmod{19}.
\end{aligned}
$$

Using the powers selected by the binary expansion,

$$
\begin{aligned}
5^{117}
&=5^{64}5^{32}5^{16}5^4 5\\
&\equiv5\cdot9\cdot16\cdot17\cdot5\\
&\equiv1\pmod{19}.
\end{aligned}
$$

Therefore,

$$
\boxed{5^{117}\equiv1\pmod{19}}.
$$

---

# Exercise 14 — The Chinese Remainder Theorem

We first combine the congruences modulo $3$ and $5$. The integers congruent to $3$ modulo $5$ begin

$$
3,8,13,18,\ldots,
$$

and $8\equiv2\pmod3$. Thus

$$
x\equiv8\pmod{15}.
$$

Write $x=8+15k$. The remaining congruence requires

$$
8+15k\equiv2\pmod7.
$$

Since $8\equiv1\pmod7$ and $15\equiv1\pmod7$, this becomes

$$
1+k\equiv2\pmod7,
$$

so $k\equiv1\pmod7$. Taking $k=1$ gives $x=23$. Because $3$, $5$, and $7$ are pairwise coprime, the Chinese remainder theorem guarantees uniqueness modulo $3\cdot5\cdot7=105$. Hence

$$
\boxed{x\equiv23\pmod{105}}.
$$

Verification gives

$$
23\equiv2\pmod3,
\qquad
23\equiv3\pmod5,
\qquad
23\equiv2\pmod7.
$$

---

# Exercise 15 — Toy RSA

With $p=11$ and $q=17$, we obtain

$$
n=pq=187
$$

and

$$
\varphi(n)=(p-1)(q-1)=10\cdot16=160.
$$

Since $\gcd(7,160)=1$, the exponent $e=7$ is invertible modulo $160$. In fact,

$$
7\cdot23=161\equiv1\pmod{160},
$$

so

$$
\boxed{d=23}.
$$

## Encryption

Repeated squaring modulo $187$ gives

$$
8^2\equiv64\pmod{187},
\qquad
8^4\equiv64^2\equiv169\pmod{187}.
$$

Since $7=4+2+1$,

$$
8^7\equiv169\cdot64\cdot8\equiv134\pmod{187}.
$$

Thus the ciphertext representative is

$$
\boxed{c=134}.
$$

## Decryption

We compute powers of $134$ modulo $187$:

$$
\begin{aligned}
134^2&\equiv4\pmod{187},\\
134^4&\equiv16\pmod{187},\\
134^8&\equiv69\pmod{187},\\
134^{16}&\equiv86\pmod{187}.
\end{aligned}
$$

Because $23=16+4+2+1$, decryption yields

$$
\begin{aligned}
134^{23}
&=134^{16}134^4 134^2 134\\
&\equiv86\cdot16\cdot4\cdot134\\
&\equiv8\pmod{187}.
\end{aligned}
$$

Thus decryption recovers the original representative $m=8$.

---

# Exercise 16 — Degenerate Linear Congruences

For $0x\equiv0\pmod7$, every integer $x$ is a solution. There are exactly seven solution classes:

$$
\boxed{[0]_7,[1]_7,[2]_7,[3]_7,[4]_7,[5]_7,[6]_7}.
$$

Here $d=\gcd(0,7)=7$, and $d\mid0$, so the count agrees with the general criterion.

For $0x\equiv3\pmod7$, the left side is always congruent to zero, whereas $7\nmid3$. There are no solutions, again in agreement with $d=\gcd(0,7)=7$.

Finally, $14x\equiv21\pmod7$ reduces to $0\equiv0\pmod7$ for every integer $x$. Since $\gcd(14,7)=7$ divides $21$, all seven residue classes are solutions.

In each case, the coefficient of $x$ is divisible by the modulus. It is enough to check whether the right-hand side is also divisible by the modulus. No inversion, and in particular no inverse modulo $1$, is needed.

---

# Exercise 17 — RSA for a Nonunit Message

Since $\gcd(5,55)=5$, the message $m=5$ is not a unit modulo $55$. Euler's theorem therefore does not justify reducing powers of $5$ modulo $\varphi(55)=40$.

Encryption nevertheless gives

$$
c\equiv5^3=125\equiv15\pmod{55}.
$$

For decryption, first work modulo $5$. Since $15\equiv0\pmod5$ and $27>0$, we have $15^{27}\equiv0\pmod5$.

Modulo $11$, we have $15\equiv4$ and $\gcd(4,11)=1$. Fermat's little theorem permits reduction of the exponent modulo $10$, so

$$
\begin{aligned}
15^{27}&\equiv4^7\pmod{11},\\
4^2&\equiv5\pmod{11},\\
4^4&\equiv3\pmod{11},\\
4^7&=4^4\cdot4^2\cdot4
\equiv3\cdot5\cdot4
\equiv5\pmod{11}.
\end{aligned}
$$

The recovered representative must consequently satisfy

$$
m'\equiv0\pmod5,
\qquad
m'\equiv5\pmod{11}.
$$

The integer $5$ satisfies both congruences. By the Chinese remainder theorem it is the unique solution in $\{0,\ldots,54\}$, so

$$
\boxed{15^{27}\equiv5\pmod{55}}.
$$

The correctness proof treats the prime divisor $5$ through the case where the message is zero modulo that prime. It treats the prime divisor $11$ through Fermat's little theorem. These two cases explain why RSA arithmetic recovers this message even though it is not a unit modulo the composite modulus.
