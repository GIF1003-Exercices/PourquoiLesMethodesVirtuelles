# Que sont les méthodes virtuelles

### Le but de la démo suivante, est de répondre à la question: qu'est-ce que ça change qu'une méthode soit déclarée virtuelle ou non?
Cette activité comporte 6 étapes, l'ordre des étapes à réaliser est décrit dans ce fichier.

## Étape 1: Cloner le dépôt git et inclure le projet dans votre IDE

Ce projet est prêt à être utilisé tel quel dans NetBeans 12.0

- Ouvrir NetBeans
- Menu Teams -> Git -> Clone
- Saisissez l'adresse du présent dépôt: https://github.com/pascalcharp/PourquoiLesMethodesVirtuelles.git
- Il n'est pas nécessaire de saisir de nom d'utilisateur ou de mot de passe: le dépôt est public
- Choisir la branche distante "main" (c'est la seule!)
- Il faut choisir ensuite à quelle destination le dépôt sera cloné
  EXEMPLE: Si je choisis le dossier parent: /Users/pascal et le nom de clone: machin, mon nouveau projet
  sera placé dans le dossier: /Users/pascal/machin
- Choisir ensuite "Finish" puis choisir "Oui" lorsque NetBeans offrira d'ouvrir le projet.
- Le projet est ouvert et utilisable immédiatement! 

Il s'agit d'un exécutable C++ standard.  Si vous n'utilisez pas NetBeans, vous pouvez simplement copier tous les fichiers .h et .cpp dans un nouveau projet 
de votre IDE préféré, il devrait compiler tel quel avec C++ 14.  Si vous utilisez CMake, un CMakeLists.txt est inclus.

## Étape 2: Analyse du projet

Le projet utilise trois classes, une classe de base Animal et deux classes dérivées: Chat et Chien. 

### Classe Animal

Cette classe renferme les comportements et données communes à toutes les instances d'animaux, quelle que soit leur espèce.  
Dans notre modèle très simple, notre classe de base a un seul attribut commun: un nom propre à l'individu, comme par-exemple "Fido", "Roger", ou "Minou".  Cet attribut est initialisé dans le constructeur.

Tout animal devrait produire certains comportements de base.  Encore là pour notre exemple nous voulons que tout animal 
produise un son, qui est caractéristique de son espèce: on s'attend à ce qu'un chien aboie, alors qu'un chat devrait miauler.

Notre classe de base Animal contient donc une méthode crier() qui ne fait pas grand chose, puisqu'on ne peut pas décrire 
le bruit d'un "Animal générique" si il ne fait pas partie d'une espèce donnée.

### Classes Chat et Chien

Les instances de ces classes représentent donc les animaux appartenant à l'une ou l'autre de ces espèces.  
Ils héritent donc de l'attribut "nom" ainsi que de la méthode publique permettant d'accéder au nom de l'animal.

Et puisqu'on veut que tous les animaux émettent un son, ces classes dérivées Chat et Chien implantent donc aussi une méthode crier() 
qui est appropriée à chacune de ces espèces: un chien émet un aboiement et un chat émet un miaulement.

### Questions et réflexion sur l'analyse des trois classes

Examinez la méthode crier() dans le fichier Animal.h à la ligne 16.  Observez qu'elle n'est PAS déclarée comme méthode virtuelle.  
Examinez maintenant sa définition dans Animal.cpp...  Cette méthode ne fait que retourner la chaîne "!!!" pour représenter 
qu'un animal n'appartenant à aucune espèce ne produit aucun son idientifiable.

Examinez maintenant les méthodes crier() correspondantes dans Chat.h ligne 16 et Chien.h ligne 15.  Leurs déclarations 
sont en tout point identiques à la déclaration correspondante dans Animal.h.
Examinez maintenant les définitions correspondantes dans Chien.cpp et Chat.cpp...  

En théorie, nous avons donc tous les comportements attendus dans nos trois classes.

## Étape 3 Analyse et essai du programme principal

### Première partie du programme principal: appel de la méthode crier() sur des objets déclarés statiquement

Analysez les lignes 12 à 19 du programme principal, on y déclare une instance de chaque classe, puis on appelle ensuite
les méthodes getNom() et crier() sur chacune de ces trois instances.  Quel sera l'affichage résultant?  Tentez de répondre
à la question par réflexion avant de construire et lancer l'exécutable.  Regardez les 5 premières lignes de l'affichage, 
le résultat correspond-il à votre réflexion?

### Deuxième partie du programme principal: appel de la méthode crier() sur des références à la classe de base

Analysez maintenant les lignes 23 à 31 du programme principal.  On y déclare trois références aux instances créées précédemment.
Regardez attentivement la déclaration de ces références, remarquez vous quelque chose de particulier?  De quel type sont
ces trois références?  Ce sont toutes trois des références à la CLASSE DE BASE.  Tentez de prévoir l'affichage résultant 
de l'exécution de ces lignes.  Lancez l'exécutable et regardez maintenant les lignes 6 à 10 de l'affichage...  Obtenez-vous le 
comportement attendu?  L'objet Chien a-t-il aboyé?  L'objet Chat a-t-il miaulé?  Quelle version de la méthode crier() a été
appelée?

### Troisième partie du programme principal: appel de la méthode crier() sur une instance non connue d'avance

Analysez la déclaration à la ligne 34: on y déclare un vecteur.  Que contient-il?  Quel est le type de ses éléments?
Est-ce que ce sont des objets, ou des pointeurs à des objets?  

Lancez maintenant l'exécutable à quelques reprises, en choisissant un numéro correspondant à l'animal choisi.  Observez
le résultat.  Est-ce le comportement attendu?  Quelle version de la méthode crier() a été appelée?

## Étape 4 Modification de la classe de base afin de virtualiser la méthode crier()

Modifiez maintenant la classe Animal.h en insérant le mot-clé "virtual" devant la déclaration de la méthode crier.  Lancez 
maintenant l'exécutable et répétez les trois étapes d'analyse faites plus haut.  L'affichage résultat est-il le même?  Le comportement
obtenu correspond-il maintenant à ce qui était attendu?  Quelles versions de la méthode crier() ont-elles été appelées?

## Étape 5 Récapitulation des méthodes virtuelles

Donc, dans quels cas est-il souhaitable de déclarer des méthodes virtuelles, c'est d'abord et avant tout une question de
sémantique:
1. Les classes dérivées ont des comportements communs
2. On veut accéder aux classes de manière générique

### Comportements communs
On a une classe de base, et on s'attend à ce que les classes dérivées présentent des comportements communs mais
pas nécessairement identiques: on s'attend par-exemple à ce que toutes les instances d'animaux produisent un cri, mais ce
n'est pas le même cri suivant l'espèce.

#### Autres exemples: 

Différentes catégories de personnages d'un jeu: "guerrier", "clerc" ou "brigand", doivent avoir des comportements communs
comme: "frapper", "esquiver" ou "lancer un sort",  mais le comportement ne sera pas identique pour chaque type de personnage, on s'attend à ce que 
"lancer un sort" soit plus spectaculaire pour un clerc que pour un guerrier.  Il y aura donc probablement une classe de base
"Personnage" contenant des méthode virtuelles comme "frapper", "esquiver", ou "lancer un sort" qui seront implantées différemment par les classes dérivées.

### Accès générique
Ensuite, on veut pouvoir accéder à ces différentes classes dérivées de manière générique: on veut par-exemple accéder aux 
instances d'animaux avec une référence ou un pointeur à Animal.  Si on accède à un objet déclaré statiquement, le compilateur
sait d'avance quel type d'objet est accédé, et il n'a pas besoin de méthodes virtuelles pour connaître la bonne version de 
la méthode crier() à appeler.  Par-contre, lorsqu'on accède à ces objets à l'aide de références à la classe de base, le 
compilateur ne peut pas prévoir le type d'Animal auquel on accède.  Si la méthode demandée n'est pas virtuelle, le compilateur se 
contente d'appeler la version de base, sans se poser de question. Si la méthode est virtuelle, le compilateur va générer du
code permettant de retarder le choix de la bonne version à appeler à l'exécution!  C'est là que se trouve la magie des méthodes
virtuelles.

Pourquoi voudrait-on accéder à nos instances de manière générique?  N'est-il pas plus simple d'utiliser des objets statiques?  
En réalité, c'est le traitement générique qui nous simplifie la vie! 

- Les programmes dont toutes les conditions d'exécution sont connues d'avance sont rares...  La grande 
majorité des logiciels doit: interagir avec un utilisateur, lire des données d'un fichier, ou encore accéder à un réseau pour lire
des messages. Par conséquent, on ne sait donc pas d'avance le type d'objet qui devra être manipulé!  Dans ces conditions les méthodes virtuelles
permettent de manipuler des catégories génériques d'objet sans qu'on sache a priori à quelle classe ils appartiennent.

- Si je veux implanter une nouvelle classe "Ornithorynque", je n'ai qu'à écrire un constructeur, puis à implanter une méthode
crier() qui produira le comportement attendu.  Cette nouvelle classe est donc implantée avec environ 6 lignes de C++!  En plus, si 
je veux utiliser cette classe dans mon programme principal, il sera facile de le faire puisque l'appel animalChoisi->crier() sera i
automatiquement résolu vers la nouvelle classe si le pointeur monAnimal pointe vers une instance de celle-ci!

## Étape 6 Réalisation d'une classe abstraite et d'une méthode virtuelle pure

Poursuivons notre réflexion sur les trois classes définies plus haut.  La classe Animal a-t-elle un sens?  Est-elle vraiment utile?
Y a-t-il une signification concrète à créer des instances d'un "animal générique" n'ayant aucune espèce?  Intuitivement la réponse
est non.  La classe Animal sert essentiellement de modèle pour construire des classes dérivées, qui elles ont un sens.
C'est un exemple parfait de classe abstraite.

Nous voudrions donc poursuivre notre démarche et empêcher un programmeur de créer des instances de cette classe.  Par-contre
nous voulons aussi que si un programmeur crée d'autres classes dérivées de Animal, ces classes soient obligées d'implanter une
méthode crier() afin que le comportement voulu soit présent.

### Modification de la classe Animal afin que la méthode crier() soit virtuelle pure

Nous allons de nouveau modifier le fichier Animal.h à la ligne 16 en ajoutant " = 0 " à la fin de la déclaration de la méthode
crier(). 
```c++
virtual std::string crier() const = 0 ; 
```
Tentez maintenant de lancer l'exécutable.  Que se passe-t-il, quel est cette catastrophe? Que faire???

### Explication des classes abstraites et des erreurs de compilation obtenues

Nous avons transformé la méthode crier() qui était une méthode virtuelle ordinaire, en méthode virtuelle pure.  Ceci est un 
changement important qui a deux conséquences:
1. La classe Animal est maintenant abstraite, et on ne peut plus créer d'instances de cette classe.  Regardez attentivement les
   messages d'erreur du compilateur.  Que se passe-t-il à la ligne 14?  Que faudra-t-il faire pour corriger le problème?
2. Toute classe dérivée de Animal va devoir absolument implanter la méthode crier().

### Correction des erreurs
Pour corriger les erreurs de compilation nous allons tout simplement mettre en commentaire les lignes 14, 17, 25 et 30 du 
programme principal, c'est-à-dire que nous ne créerons pas d'instances de la classe Animal.  Ensuite nous allons retire la
référence à monAnimal dans l'initialisation du vecteur à la ligne 34.  Lancez ensuite l'exécutable pour vérifier que le programme
a bien le comportement attendu.

## Récapitulation des classes abstraites et des méthodes virtuelles pures

### Classes abstraites

Les classes abstraites servent de modèle à d'autres classes.  Elles contiennent des méthodes virtuelles pures que leurs classes dérivées doivent absolument implanter.  En ce sens, une classe abstraite constitue un contrat ou un protocole imposé aux classes dérivées.

### Méthodes virtuelles pures

Une méthode virtuelle pure est déclarée avec la syntaxe suivante (ici les type int sont juste un exemple): 
```
virtual int CetteClasse::cetteMethode(int) = 0 ;
```
L'implantation de la méthode virtuelle pure est optionnelle dans la classe de base, mais elle est obligatoire dans toutes les classes dérivées.

### Différence entre virtuelle et virtuelle pure

Attention il y a des différences importantes entre les concepts de méthodes virtuelles et virtuelles pures!

- Une méthode virtuelle permet le polymorphisme: lors de l'exécution du programme, celui-ci choisira adéquatement la version
à exécuter selon le type d'objet qu'il manipule.  Si la méthode n'est pas implantée dans les classes dérivées, la version de base 
sera choisie.

- Une méthode virtuelle pure permet le polymorphisme et constitue une obligation: son implantation est obligatoire dans les 
classes dérivées, alors qu'elle est optionnelle dans la classe de base.
