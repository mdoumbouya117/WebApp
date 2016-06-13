<?php
// on enregistre les cookies dans des variables
include('../fonction.inc');
$connect=rec($_COOKIE['connect']);
$mdp_hash=rec($_COOKIE['pass_hash']);
// connexion à la BDD
$bddobject = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
// préparation de la requête paramétrée : recherche User
$req=$bddobject->prepare('SELECT ID,username, password, email, signup_date FROM users WHERE username = ? OR email = ?');
// execution avec les données du formulaire
$req->execute(array($connect,$connect));
// on prend la première ligne de résultat ( username est UNIQUE KEY)
$results=$req->fetch();
// on enregistre le MDP dans une variable :
$mdp_bdd=$results['password'];
// si le mot de passe est bon
if ($mdp_bdd == $mdp_hash){
	// On initialise les variables SESSION
	$_SESSION['ID']=$results['ID'];
	$_SESSION['pseudo']=$results['username'];
	var_dump($_SESSION);
	var_dump($_COOKIE);
	// header('Location: ../../index.php?page=accueil');		
}
// si le mot de passe n'est pas bon.	
else{
	// on efface les cookies et renvoi vers l'accueil
	setcookie('connect','');
	setcookie('pass_hash','');
	header('Location: ../../index.php?page=accueil');		
}

?>