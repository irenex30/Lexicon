# Lexicon

Le but du projet est de créer un jeu permettant à un groupe de 2 à 4 joueurs de participer à une partie du jeu Lexicon, un jeu de lettres créé dans les années 1930. Inspiré des règles officielles du jeu, le logiciel gère l'ensemble du déroulement de la partie, depuis la distribution des cartes jusqu'à l'annonce du vainqueur. Les joueurs interagissent à tour de rôle en effectuant des actions telles que piocher des cartes, former des mots, modifier ou compléter des mots existants. L'objectif est de se débarrasser de toutes les cartes le plus rapidement possible. Le jeu inclut des mécanismes de vérification des mots, des pénalités en cas de mot invalide, et exclut les joueurs atteignant 100 points. Le logiciel affiche en temps réel la situation du jeu, y compris le joueur actif, la carte exposée, les cartes en main, et la liste des mots sur la table. Le tout est conçu pour offrir une expérience de jeu fluide et conforme aux règles du Lexicon.

Le projet est un programme qui a pour but de permettre de jouer une partie entière du jeu Lexicon. Celui-ci permet à 2 à 4 joueurs de jouer, en fonction du paramètre
fourni à l’exécution du programme. La partie est entièrement automatisée, hormis les
actions des joueurs, qui sont saisies lorsque le programme le demande. Les règles
du jeu Lexicon sont les suivantes : il doit y avoir minimum deux joueurs et maximum
quatre joueurs pour commencer une partie. Un paquet de 51 cartes est mélangé et
10 cartes sont distribuées à chaque joueur. Chaque carte est désignée par une lettre
et un nombre de points. Les cartes non distribuées forment le talon. La carte au
sommet du talon est retournée (face visible) pour former un nouveau paquet, celui
des cartes exposées. Une fois tout cela fait, les joueurs peuvent, à tour de rôle, jouer
différentes actions. Le coup dit 'T' permet de jeter sa carte dans celles exposées et
de prendre la carte au sommet du talon. Le coup 'E' permet d’échanger une de ses
cartes avec celle au sommet des cartes exposées. Le coup 'P' permet de placer un
mot, seulement si celui-ci est dans le dictionnaire français. Le coup 'R' permet de
remplacer un mot posé par un autre mot, en utilisant les lettres de ce mot et les
cartes du joueur, à condition que le nouveau mot soit de même taille et en langue
française. Le coup 'C' permet de composer un nouveau mot, à condition de ne pas
changer l’ordre des lettres du mot de base et que ce soit en langue française, en
utilisant les lettres que possède le joueur. Un tour s'arrête quand un joueur n’a plus
de cartes. Les autres joueurs collectent alors les points des cartes restantes en main.
Lorsqu'un joueur atteint 100 points, il est éliminé. Le gagnant est le dernier joueur
n'ayant pas atteint 100 points. L'automatisation du programme comprend : le
mélange des cartes, la distribution des cartes, la désignation du joueur devant jouer,
l’affichage du plateau de jeu, la vérification de la validité du coup joué par le joueur
(notamment l’orthographe des mots posés), l’élimination des joueurs, le comptage
des points, la fin de la partie et l'exécution des coups T, E, P, R et C, en fonction des
informations données par le joueur, si le coup est possible.
