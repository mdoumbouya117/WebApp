<h1>Zone utilisateur</h1>

<?php 
// Si il y a une session en cours on affiche les infos de l'user:
if(isset($_SESSION['pseudo'])){ 
	// PDO : Connexion à la base de données 
	$bddobject = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
	// préparation de la requête paramétrée : recherche user
	$req=$bddobject->prepare('SELECT ID,username,password,email,signup_date FROM users WHERE ID = ?');
	// éxecution avec l'ID de l'utilisateur
	$req->execute(array($_SESSION['ID']));
	// on recupere la ligne du tableau (ID unique)
	$results=$req->fetch();
	// on affiche le résultat
	echo "Votre ID : ".$results['ID']. "</br>";
	echo "Votre nom : ".$results['username']. "</br>";
	echo "Votre MDP : ".$results['password']. "</br>";
	echo "Votre email : ".$results['email']. "</br>";
	echo "Votre date : ".$results['signup_date']. "</br>";
// Si il n'y a pas de session en cours, l'accès à la page est interdit.
}else{
	// renvoi vers l'accueil
	echo 'vous n\'êtes pas autorisé à accéder à cette page </br>'; 
	echo '<a href="/"> Retour vers l\'accueil</a>';
}

?>