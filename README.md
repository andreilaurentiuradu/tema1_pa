// Radu Andrei-Laurentiu 322CC
1111111111111111111111111111111111111111111111111111111111111111111111111111111
1 Servere

Functia f(x) = min(p[0] - |x - c[0]|, p[1] - |x - c[1]|, p[2] - |x - c[2]|, ..., p[n-1] - |x - c[n-1]|)
are urmatoarea forma( nu depinde de p si c)
   /\
  /  \
 /    \
/      \
Cautam binar maximul functiei incepand cu limitele -10^9 si 10^9,
calculand valorile functiei f in punctele x is x + epsilon, 
unde epsilon = 10^(-2).
Daca valoarea lui f in x este mai mare atunci suntem pe ramura
din dreapta si trebuie sa actualizam limita din dreapta, altfel
actualizam limita din stanga.
Complexitate: O(N log(2 * 10^9))
