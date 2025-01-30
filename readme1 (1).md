# ESGI/C 
# ------- 
# Eval (structures, boucle)

# TODO:
Faire un tricount simplifié

# Détails: 
Le prog principal doit être de haut niveau et c'est un scénario qui met en oeuvre lors d'une virée à 3 en Montagne au Pakistan: 
- Paul (dépenses: 100, 450)
- Elsa (dépenses: 200, 100, 300, 400)
- Marc (dépenses: 300)
Le but étant bien sûr d'éditer pour chaque personne son bilan (en + et -) [les dépenses peuvent être en nombre variable]

<<< Mettre le focus sur les structures à implanter pour mener à bien ce projet, notamment il doit être possible de facilement rajouter un utilisateur. >>>

# Aide
- 1/ Quelles structures pourraient être utiles (il faudrait peut-être regrouper le nom, les dépenses, le total des dépenses, le restant, ...)

- 2/ souvent on adopte une archi MVC (bonus)
Commencer par la mise en place des données et structures.
Faire un système FLEXIBLE (je dois pouvoir facilement rajouter des personnes et dépenses).
Puis le modèle: que faut-il faire? (peut être déjà sommer les dépenses, calculer la moyenne, ...)

La vue (ici les printf) ça vient en dernier quand tout est calculé!

# Bonus: 
- Découper l'application en plusieurs composants: elle comporte au minimum 3 fichiers, le prog principal et le modèle sont des fichiers C, les 2 incluent un fichier (.h), qui contient les prototypes, les constantes, ...
Auquel cas, voici la nouvelle tâche:
Pour faire fonctionner dans vscode, vous pouvez prendre la tâche suivante:
		{
			"type": "shell",
			"label": "Run Multiple File Program",
			"command": "C:\\MinGW\\bin\\gcc.exe -g3 -Wall ${fileDirname}\\*.c -o ${fileDirname}\\out.exe;${fileDirname}\\.\\out.exe",
			"options": {
				"cwd":  "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],

			"detail": "compilateur : C:\\MinGW\\bin\\cpp.exe"
		}
- stocker dans un fichier binaire ces infos

# Résultats attendus:

Average: 616.000000
Name: Paul, Expenses: 100 450 , total Expenses: 550,  owes: 66.000000
Name: Elsa, Expenses: 200 100 300 400 , total Expenses: 1000,  receives: 384.000000
Name: Marc, Expenses: 300 , total Expenses: 300,  owes: 316.000000

# Consignes
me livrer une archive: NomPrénom.zip contenant le .C le readme par messagerie:
pdareys@myges.fr