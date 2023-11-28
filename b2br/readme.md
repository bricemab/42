# Born To Be Root
## Avant de rendre le projet
- Clonner la VM
- Récupérer la signature de la VM
- Mettre dans un fichier signature.txt et push sur le git du projet

#### Vérifie bien que la signature est la bonne en relançant la commande sur la VM
si c'est bon, touche plus la VM comme ça pas de problème

## Questions pendant l'évaluation
#### Fonctionnement des machines virtuelles ?
C'est un environnement qui est sur notre machine physique. ELle exécute son propre OS et elle a les mêmes équipements que la machine physique. Il peut y en avoir plusieurs sur le même PC physique
#### Différences basiques entre Debian et Rocky
Debian est reconnu pour sa stabilité, sa sécurité et a une big commu alors que Rockyest plutot pour les environnements d'entreprise
#### Différence entre apt et aptitude
`apt` est un outil de gestion de package comme `aptitude`. La grosse différence est que `aptitude` est connu pour résoudre beaucoup plus facilement ces problème de dépendances
#### A quoi sert un firewall (UFW)?
il permet de sécurisé sa machine et ainsi controller le trafic entrante et sortant 
#### A quoi sert le SSH?
ça sert a créer un canal sécurisé pour communiquer en ligne de commande avec une machine (VM)

### TODO pendant l'évaluation
#### Créer un utilisateur
	useradd xxx
#### Créer un groupe nommé `evaluating`
	groupadd evaluating
#### Ajouter le user au groupe
	usermod -a -G evaluating xxx
#### C'est quoi les avantages de la politique de mot de passe
Augmenter la sécurité sur la VM
#### Changer le hostname de la machine
	hostnamectl set-hostname xxx
	reboot
#### Comment afficher les partitions
	lsblk
#### C'est quoi l'interet des partitions LVM
C'est des partitions qui sont plus maléable donc plus chill a modifier si y a besoin
#### Comment assigner le user au groupe SUDO
	usermod -a -G sudo xxx
	sudovi -> rajouter la ligne qui manque
#### C'est quoi l'interet de SUDO?
ça permet d'avoir des utilisateurs qui ont des privilèges semblable à `sudo` mais sans leur donner l'accès à cette utilisateur
#### Comment lister les règles du UFW
	ufw status
#### Comment ajouter une règle du UFW
	ufw allow 8080
#### Comment supprimer une règles du UFW
```bash
ufw status numbered
```
Retenir le numéro de la règle
```bash
ufw delete 1
```
#### Comment voir si SSH est lancé sur le bon port?
	systemctl status ssh
ça sera écrit qql part dans la réponse de cette commande que c'est sur le port 4242
#### Comment se connecter en SSH depuis sa machine physique?
	ssh lgaume@localhost -p 4242 # doit marcher avec ton password
	ssh root@localhost -p 4242 # ne doit pas marcher car on a config qu'on a pas le droit de se connecter en direct avec root
#### C'est quoi un `cron`?
C'est un programme qui permet d'exécuter des taches à une dates données
#### Comment faire exéctuer le script toutes les 10mins
	crontab -e
	remplacer */10 * * * * par * * * * *