# TP 13 : Templates et généricité

## la structure TP13
```
TP13/
│
├── Exercice1_ArrayDyn/
│   ├── ArrayDyn.hpp        
│   ├── Iterator.hpp        
│   └── main.cpp            
│
├── Exercice2_Matrice/
│   ├── Matrice.hpp        
│   └── main.cpp            
│
├── Exercice3_Stack/
│   ├── Stack.hpp           
│   └── main.cpp           
│
├── Exercice4_FoncteurTri/
│   ├── SortFunctor.hpp     
│   ├── main.cpp        
│             
│
└── README.md               

```


## Exercice 1 : Conteneur dynamique générique avec itérateur personnalisé


## Objectifs pédagogiques
- Manipuler les **templates de classes** en C++.
- Gérer la **mémoire dynamique** en toute sécurité.
- Implémenter un **conteneur générique** similaire à `std::vector`.

---

##  Spécifications techniques

### Classe `DynamicArray<T>`
Un conteneur générique permettant de stocker des éléments dans un tableau dynamique redimensionnable.

####  Attributs
- `T* data` : pointeur vers le tableau dynamique.
- `std::size_t capacity` : taille maximale actuelle du tableau.
- `std::size_t size` : nombre d’éléments stockés.

####  Méthodes principales
| Méthode | Description |
|----------|--------------|
| `DynamicArray()` | Constructeur par défaut (capacité initiale = 4). |
| `~DynamicArray()` | Libère la mémoire allouée. |
| `void push_back(const T&)` | Ajoute un élément à la fin du tableau. |
| `void pop_back()` | Supprime le dernier élément. |
| `T& operator[](std::size_t)` | Accède à un élément (non constant). |
| `const T& operator[](std::size_t) const` | Accède à un élément (constant). |
| `std::size_t getSize() const` | Retourne le nombre d’éléments. |
| `void reserve(std::size_t newCapacity)` | Augmente la capacité du tableau si nécessaire. |

---

## ⚙️ Fonctionnement interne
Lorsqu’un appel à `push_back()` dépasse la capacité actuelle,  
le tableau est **redimensionné automatiquement** (généralement doublé en taille),  
et les anciens éléments sont recopiés dans le nouveau tableau.

---

## Exemple de sortie attendue
```
Array int: 10 20 30
Array string: Bonjour C++ Monde
Array Point: (1,2) (3,4)
```
 ##  Exemple d’exécution (image)
 
Voici un exemple de l'exécution du programme (screenshot) : 

<img width="533" height="115" alt="image" src="https://github.com/user-attachments/assets/e5237811-f8fe-4464-ae7d-1ba7a7afd1a2" />



## Exercice 2 : Matrice générique + opérateurs arithmétiques


##  Objectifs pédagogiques
- Manipuler des **templates de classes avec plusieurs paramètres**.
- Implémenter des **opérateurs arithmétiques surchargés** pour des matrices.
- Appliquer les notions de **généricité** et de **surcharge d’opérateurs**.

---

##  Spécifications techniques

###  Classe `Matrice<T, N, M>`
Une classe template représentant une matrice statique de dimensions `N × M`.

####  Attributs
- `T data[N][M];` → tableau statique contenant les éléments de la matrice.

####  Constructeurs
| Constructeur | Description |
|---------------|-------------|
| `Matrice()` | Initialise tous les éléments à 0. |
| `Matrice(std::initializer_list<std::initializer_list<T>>)` | Initialise la matrice à partir d’une liste d’initialisation imbriquée. |

---

##  Opérateurs surchargés

| Opérateur | Prototype | Description |
|------------|------------|-------------|
| `operator+` | `Matrice<T, N, M> operator+(const Matrice<T, N, M>& other) const` | Addition élément par élément. |
| `operator-` | `Matrice<T, N, M> operator-(const Matrice<T, N, M>& other) const` | Soustraction élément par élément. |
| `operator*` | `template<std::size_t P> Matrice<T, N, P> operator*(const Matrice<T, M, P>& other) const` | Produit matriciel (multiplication). |
| `operator<<` | `friend std::ostream& operator<<(std::ostream&, const Matrice&)` | Affiche la matrice de manière lisible. |

---

 ##  Exemple d’exécution (image)
 
Voici un exemple de l'exécution du programme (screenshot) : 

<img width="371" height="585" alt="image" src="https://github.com/user-attachments/assets/6957ce61-0f27-4499-886f-28e0f747d9e0" />


## Exercice 3 : Pile générique sécurisée avec std::unique_ptr

## Objectifs pédagogiques
- Utiliser les **pointeurs intelligents (`std::unique_ptr`)** pour gérer la mémoire automatiquement.  
- Appliquer les **templates génériques** en C++.  
- Gérer les erreurs avec des **exceptions personnalisées**.  

---

##  Spécifications techniques

###  Classe `Stack<T>`
Une pile (LIFO) générique stockant les éléments dans un tableau dynamique géré automatiquement.

####  Attributs
| Nom | Type | Description |
|------|------|-------------|
| `std::unique_ptr<T[]> data` | Tableau dynamique géré automatiquement. |
| `std::size_t capacity` | Taille maximale de la pile. |
| `std::size_t top` | Indice du prochain emplacement libre. |

---

##  Constructeurs

| Constructeur | Description |
|---------------|-------------|
| `Stack(std::size_t cap = 10)` | Crée une pile avec une capacité par défaut. |
| `template<typename It> Stack(It begin, It end)` | Initialise la pile à partir d’une plage d’itérateurs. |

---

##  Méthodes principales

| Méthode | Prototype | Description |
|----------|------------|-------------|
| `void push(const T& value)` | Empile un nouvel élément. Lance une exception `StackOverflow` si la pile est pleine. |
| `void pop()` | Dépile le dernier élément. Lance une exception `StackUnderflow` si la pile est vide. |
| `T peek() const` | Retourne l’élément au sommet sans le retirer. |
| `bool empty() const` | Vérifie si la pile est vide. |
| `std::size_t size() const` | Retourne le nombre d’éléments stockés. |

---
 ##  Exemple d’exécution (image)
 
Voici un exemple de l'exécution du programme (screenshot) : 

<img width="766" height="394" alt="image" src="https://github.com/user-attachments/assets/b5a8801c-02f8-41d1-9799-6baf5ce97560" />



#  Exercice 4 : Foncteur générique de tri avec contraintes C++20 (Concepts)

##  Objectifs pédagogiques
- Maîtriser les **concepts C++20** pour restreindre les types dans les templates.  
- Créer des **foncteurs génériques** pour personnaliser la stratégie de tri.  
- Implémenter un **algorithme de tri paramétrable** (QuickSort).  
- Utiliser le tri sur différents types : `int`, `std::string`, et objets personnalisés (`Personne`).

---

 ## Sortie attendue
```
Int Asc: 1 2 3 5 8 
Int Desc: 8 5 3 2 1 
String Asc: Apple Banana Orange 
String Desc: Orange Banana Apple 
Personne Asc: Alice(20) Salma(21) John(25) 
Personne Desc: John(25) Salma(21) Alice(20) 

```
 ##  Exemple d’exécution (image)
 
Voici un exemple de l'exécution du programme (screenshot) : 

 <img width="771" height="245" alt="image" src="https://github.com/user-attachments/assets/58996ab4-d11c-49bf-af14-da43488153bb" />

#
