# Stud

Comment utiliser le script  :

Sauvegardez le script dans un fichier 42tester_enhanced.sh

Rendez-le exécutable :     

    chmod +x 42tester_enhanced.sh

Placez-vous dans le dossier du projet à tester

Exécutez le script : ../42tester_enhanced.sh (ou le chemin approprié)

Choisissez le projet à tester dans le menu

Création d'un alias pour lancer votre script de test 42

Voici comment créer un alias pour votre script de test, ce qui vous permettra de l'exécuter facilement depuis n'importe quel répertoire.
Méthode 1 (temporaire - pour la session courante)

Ouvrez votre terminal et tapez :


    alias tester42='/chemin/vers/votre/42tester_enhanced.sh'

Méthode 2 (permanente)

Pour rendre l'alias permanent, ajoutez-le à votre fichier de configuration shell.
Pour bash (le shell le plus courant) :

Ouvrez votre fichier ~/.bashrc ou ~/.bash_aliases :



    vim ~/.bashrc

Ajoutez cette ligne à la fin du fichier :



    alias tester42='/chemin/vers/votre/42tester_enhanced.sh'

Sauvegardez (Ctrl+O) et quittez (Ctrl+X)

Appliquez les changements :


    source ~/.bashrc

Pour zsh :

Ouvrez votre fichier ~/.zshrc :



    vim ~/.zshrc

Ajoutez la même ligne :



    alias tester42='/chemin/vers/votre/42tester_enhanced.sh'

Sauvegardez et quittez

Appliquez les changements :



    source ~/.zshrc

Comment utiliser l'alias

Une fois configuré, vous pouvez simplement taper :


    tester42

depuis n'importe quel répertoire pour lancer votre script de test.
