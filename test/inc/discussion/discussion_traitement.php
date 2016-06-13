<?php
// ---- Vérification des input
// si le champs PSEUDO est vide
if (empty($_POST['pseudo'])){
	$message=0;
}
// si le champ MESSAGE est vide
if (empty($_POST['message'])){
	$message=1;
}
// si les champs MESSAGE et PSEUDO sont vides
if (empty($_POST['message']) && empty($_POST['pseudo']) ){
	$message=2;
}
// si il n'y a pas de champ vide (var message non définie)
if (!isset($message)){
	// on enregistre le timestamp dans une variable
	$time=time();
	// PDO : Connexion à la base de données 
	$bddobject = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
	// Insertion du message à l'aide d'une requête préparée
	$req = $bddobject->prepare('INSERT INTO discussion (pseudo, message, time) VALUES(?, ?, ?)');
	// execution de la requete paramétrée
	$req->execute(array($_POST['pseudo'], $_POST['message'],$time));
	// Redirection du visiteur vers la page de discussions
	header('Location: ../../index.php?page=discussion');
}
// S'il y a des champs vide (var message définie)
else{
	// Renvoi vers la page de connexion avec un message d'erreur
	header('Location: ../../index.php?page=discussion&message='.$message);
}
?>