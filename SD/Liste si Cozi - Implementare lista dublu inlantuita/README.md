# Problema 1  
Implementarea unei liste dublu inlantuite.  
Sa se implementeze o lista dublu inlantuita cu functionalitatile descris in continuare.  
Se cere utilizarea unei structuri Node care are trei campuri:  
1. un camp pentru informatie -> int
2. si doua campuri de tip pointer la Node pentru legaturile catre elementele precedent si urmator

Se cere utilizarea unei structuri List care are ca mebri:
1. doua variable de tip Node* reprezentand primul respectiv ultimul element din lista
2. o variabila de tip int reprezentand numarul de elemente din lista si functiile:  
a. push_front(key) - adauga cheia key in capul listei (.2p)    
b. push_back(key) - adauga cheia key la finalul listei (.2p)   
c. pop_front() - sterge primul element din lista (.2p)  
d. pop_back() - sterge ultimul element din lista (.2p)  
e. find(key) - cauta o cheie key lista - returneaza pointer la nodul cu cheia key sau NULL (.2p)  
f. erase(Node* node) - sterge un element Node din lista (FARA cautare).   
Node-ul trimis ca parametru a fost in prealabil gasit cu find sau identificat prin parcurgerea listei (.2p)  
g. remove(key) - sterge toate aparitiile cheii key (CU cautare) (.2p)   
h. insert(Node* node, int val) - insereaza un element cu cheia val inainte de nodul indicat de Node. (.5p)  
i. empty() - verifica daca lista e vida (.2p)  
j. clear() - goleste lista. (.2p)  
k. print() - afiseaza elementele listei (.2p)  
l. size() - returneaza numarul de elemente din lista.  

De asemenea, sa se implementeze urmatoarele functii, care nu fac parte din structura:
1. palindrom (List L) - verifica daca lista este palindrom (.5p)
2. compare (List L1, List L2) - returneaza 1 daca L1 si L2 sunt identice si 0 altfel (.2p) 
    
 In functia main realizati un meniu cu ajutorul unei instructiuni switch, 
 prin care se ofera optiuni corespunzatoare fiecarei functionalitati,  
 precum si o optiune de EXIT.  
 Intr-o instruciune while, se citesc si se executa optiuni pana la alegerea optiunea EXIT.  
 **ATENTIE:** Nici o functie nu trebuie sa dea eroare de exectuie, daca se apeleaza pe o lista vida.  
