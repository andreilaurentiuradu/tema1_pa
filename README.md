// Radu Andrei-Laurentiu 322CC
1 Servere
Cerinta: Aflarea puterii maxime de calcul a sistemului

Functia f(x) = min(p[0] - |x - c[0]|, p[1] - |x - c[1]|, p[2] - |x - c[2]|, 
..., p[n-1] - |x - c[n-1]|) are urmatoarea forma( nu depinde de p si c, 
fiind asemanatoare cu un "munte")
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
Complexitate: O(N + N log(2 * 10^11)) (unde N este nr de servere
2 * 10 ^ 9 lungimea intervalului initial si 10 ^ 2 din epsilon)

2 Colorare
Cerinta: Aflarea numarului de posibilitati de colorare modulo 10^9 + 7

Daca secventa de piese incepe cu a H atunci punand cele 2 * a piese 
orizontale avem 2 * 3 ^ a posibilitati de colorare
Daca incepe cu a V atunci avem 3 * 2 ^ (a - 1).

Am initializat numarul de posibilitati de colorare in functie de primul 
tip pus.
In continuare avem 4 cazuri de analizat:
I. daca anterior am avut a H si urmeaza b H se inmulteste rezultatul 
cu 3 ^ b.
II. daca anterior am avut a H si urmeaza b V se inmulteste rezultatul 
cu 2 ^ (b - 1)
III. daca anterior am avut a V si urmeaza b H se inmulteste rezultatul
cu 2 * 3 ^ (b - 1)
IV. daca anterior am avut a V si urmeaza b V se inmulteste rezultatul
cu 2 ^ b

Observam ca formula contine doar valori de 2 si 3 asa ca in loc sa facem
inmultirile la fiecare pas vom numara cati de 2 si 3 avem.
La final vom calcula 2 ^ (nr de 2) * 3 ^ (nr de 3) % (10^9 + 7)
folosind ridicare la putere in timp logaritmic.

Complexitate: O(N) (unde N este nr de perechi)

3 Compresie
Cerinta: Determinarea sirului de lungime maxima obtinut prin aplicari
ale operatiei de inlocuire a elementelor din 2 vectori cu suma lor.

Parcurgem cu 2 indici i si j cei doi vectori.
Daca elementele din pozitiile i, respectiv j sunt egale incrementam
ambii indici. 
Altfel adaugam elementul mai mic la elementul urmator din vector si
incrementam indicele corespunzator vectorului.( ca si cum am "sterge"
elementele din vector si le-am inlocui cu suma lor)
Repetam algoritmul pana cand se termina unul din vectori.
Daca nr de elemente din vectori dupa "stergeri" este acelasi atunci
cel mai lung sir are dimensiunea exact nr de elemente ale vectorilor, 
altfel sirurile nu sunt egale si returnam -1

Complexitate: O(N + M)( unde N este nr de elemente din primul vector
si M nr de elemente din al doilea vector)

4 Criptat
Cerinta: Aflati parola de lungime maxima care are o litera dominanta
care se realizeaza alipind cuvintele primite.

Cream o "matrice de frecventa" in care pentru fiecare element
a[i][j] este nr de aparitii al literei 'a' + j in cuvantul cu indicele i.

Marcam intr-un vector caracteristic literele existente pentru a nu rula
functia de calcul a parolei de lungime maxima pentru litere care nu apar.

Calculam pentru fiecare litera existenta lungimea maxima a parolei avand
o anumita litera ca fiind dominanta si luam maximul dintre aceste valori. 

Pentru asta avem o abordare asemanatoare problemei "rucsacului", unde in 
loc de greutate si cost avem lungimea parolei si scorul ei.
DP[i] retine parola cu scorul cel mai mare de lungime i. Scorul pentru o anumita
litera reprezinta diferenta dintre numarul de aparitii ale literei in parola si
numarul de litere care nu sunt litera dominanta.

Complexitate: O(N + 26 * N * L)(unde N este nr de cuvinte si L este suma lungimilor)

5 Oferta
Cerinta: Calculati al k-lea pret posibil prin gruparea produselor

Cream cazurile de baza pentru preturile a 0, 1, respectiv 2 produse.
Cream pe baza lor urmatorul nivel, adica nivelul 3 (cu primele k preturi 
posibile a 3 produse), interclasand cei 3 vectori de pe nivele anterioare.
Repetam procesul mutand vectorii cu un nivel mai jos(ce aveam in vectorul cu 
preturile a 2 produse vom avea in vectorul cu preturile unui produs etc)
1 -> 0
2 -> 1
3 -> 2

Rezultatul este al k-lea element din ultimul vector creat, adica elementul de pe
pozitia k-1.

Complexitate: O(N  + N * 3 * K) unde N este numarul de produse si K este pretul cautat
