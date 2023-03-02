# **Gestion intelligente de parkings dans un centre urbain**

Projet LIFPROJET - Gestion intelligente de parkings dans un centre urbain (SA4).

Réalisé par FERRER Raphaël (p1908300), BOULET Benjamin (p2006010), MUNOZ Matéo (p2002495).


# Démo vidéo
Voici une démonstration vidéo chapitré de cette application : https://youtu.be/JPF5OE7hKS0 .

# Installation
Les installations nécessaires pour lancer l'application (sous Linux uniquement) :
>sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev

>sudo apt-get install libgnuplot-iostream-dev

Sur les ordinateurs du batîment Nautibus, ces packages sont tous installés. Le projet y est donc directement compilable et exécutable.

# Objectif

L'objectif de cette application est de simuler la gestion d'un ou plusieurs parkings, en utilisant des intelligences artificielles (IA) pour négocier avec les véhicules (eux aussi dotés d'IA) le prix des places. Le but est que les véhicules puissent choisir la meilleure offre et que les parkings s'adaptent pour atteindre un rendement optimal. L'application permet également de paramétrer chaque simulation de manière détaillée et de visualiser clairement les données récoltées.
# Lancement des exécutables et utilisation

## Application
Pour lancer l'application, vous devez la compiler en utilisant la commande make dans le répertoire contenant le Makefile.
>make

Vous obtiendrez deux exécutables, bin/test et bin/app.

L'exécutable bin/test exécute tous les tests de régression. Pour le lancer, tappez bin/test dans la console (dans le répertoire de l'application).
>bin/test

Pour lancer l'application, tappez bin/app dans la console (toujours dans le répertoire de l'application).
>bin/app

Ensuite, vous accédez à un menu avec 3 choix possibles : Start, Exit, et un bouton pour les paramètres de la simulation. Pour lancer la simulation avec les paramètres par défaut, cliquez directement sur Start. 

Si vous voulez tester une configuration spécifique, paramétrez d'abord l'application en validant vos réglages avec OK, puis lancez-la avec Start. Pour plus de détails sur les paramètres modifiables, allez à la section "Paramètres modifiables de la simulation" de ce README.

Une fois dans l'application, vous pouvez utiliser les fonctionnalités suivantes :
### Quand la simulation n'est pas en pause
- Vous pouvez mettre la simulation en pause avec le bouton de pause (situé dans la barre de menu en bas de l'écran, c'est le bouton le plus à gauche).
- Vous pouvez accélérer la simulation (le temps passera alors 5 fois plus vite) avec le bouton situé à coté du bouton de pause. Notez que la vitesse de la simulation n'est pas réinitialisée si vous mettez celle-ci en pause. Notez également que l'accélération de la simulation ne modifie pas la vitesse des voitures.

### Quand la simulation est mise en pause
- Vous pouvez la relancer en cliquant à nouveau sur le bouton de pause.
- Vous pouvez cliquer sur n'importe quelle voiture pour afficher les informations de l'utilisateur de celle-ci, dont les suivantes :
    - ID de l'utilisateur.
    - Noms, prénoms, âges (chaque utilisateur est un mix d'informations tirées au hasard dans des banques de données de noms et de prénoms).
    - Temps de stationnement (en minutes).
    - Prix maximum que l'utilisateur est prêt à payer (en euros).
- Vous pouvez voir les informations de chaque parking en cliquant sur la petite fiche située en bas à droite de chacun. Les informations affichées sont l'ID du parking, le prix minimum accepté et le prix de départ pour ses négociations.
- Vous pouvez afficher le menu des graphiques en cliquant sur la flèche située en haut de l'écran, au milieu.
## Les graphiques
Vous avez la possibilité d'afficher 4 graphiques différents, en déroulant le menu des graphiques :
- L'évolution du profit de chaque parking au cours du temps.
- L'évolution des prix de départ de chaque parking au cours du temps.
- L'évolution du nombre de places occupées dans chaque parking au cours du temps.
- Le succès moyen au cours du temps (moyenne des succès de chaque parking).

Pour afficher le graphique voulu, vous n'avez qu'à cliquer sur son nom dans le menu déroulant.
Sur l'interface du graphique, vous avez la possibilité d'exporter ce dernier dans différents formats (en utilisant le bouton le plus à gauche de la barre d'outils).

***ATTENTION***, il est possible et normal de recevoir l'avertissement suivant à l'ouverture d'un graphique : 
>qt.qpa.plugin: Could not find the Qt platform plugin "wayland" in ""

La librairie utilisée pour générer les graphiques (gnuplot-iostream) cherche à utiliser un plugin qui n'est pas présent dans cette application (et pas nécessaire).

## Paramètres modifiables de la simulation
Vous pouvez modifier plusieurs paramètres avant de lancer la simulation depuis le menu, dont les suivants (dans l'ordre) :
- Les prix de départ des différents parkings (en euros).

    *Notez que le prix minimum n'est pas réglable car il est calculé en fonction du prix de départ.*
- La fréquence d'apparition des voitures (en secondes).
- Le prix maximum attribuable à un utilisateur (en euros).
- Le prix minimum attribuable à un utilisateur (en euros).
- Un bouton CLEAR, qui permet de supprimer le fichier "User.txt", qui contient toutes les données des utilisateurs.

    **Conseil :** si vous voulez modifier les prix utilisateurs, il vaut mieux utiliser le bouton CLEAR. En effet, cela permettra de regénérer les utilisateurs avec les nouvelles données choisies.

## Données récoltées
L'application récolte plusieurs types de données pour analyser la simulation, dont :
- Les données utilisées pour générer les graphiques (prix de départ des parkings, nombre de places occupées, profit et succès moyen). Elles sont stockées sous forme de fichier texte dans le répertoire "data" de l'application.
- Chaque parking stocke aussi les données dont il a besoin sur les utilisateurs de la simulation. Ces données sont stockées sous forme de fichier texte dans le répertoire "data" de l'application.
- Enfin, vous pouvez visualiser l'historique des conversations réalisées dans la simulation en cours ou des conversations de la simulation que vous venez de quitter. Toutes les données sont stockées sous forme de fichier texte, et sont nommées de la façon suivante :
    >Conversation U5P0_104.txt

    Le fichier désigne ici la conversation entre l'utilisateur d'ID 5 (U5) et le parking d'ID 0 (P0), et il fait partie du 104ème ensemble de conversations (104) entre une voiture et les 3 parkings.

# Documentation du code
Pour accéder à la documentation du code, vous devez exécuter, dans la console (dans le répertoire du projet), la commande suivante (remplacez "unNavigateur" par le nom du navigateur que vous utilisez) :
>unNavigateur doc/html/index.html

Par exemple, avec Firefox, la commande est la suivante :
>firefox doc/html/index.html

Vous avez accès au diagramme de classes du projet dans le répertoire "doc".
