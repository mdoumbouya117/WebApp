<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title>Création de la table user </title>
		<link type="text/css" rel="stylesheet" href="styles/global.css">
	</head>

	<body>
<?php
// PDO : Connexion à la base de données 
$bddobject = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
// Requete de création de la table users
$req=$bddobject->prepare('CREATE TABLE IF NOT EXISTS users( 
	ID int(11) unsigned NOT NULL AUTO_INCREMENT,
	username varchar(255) NOT NULL, 
	email varchar(255) NOT NULL,
	password varchar(255) NOT NULL,
	signup_date INT(20) NOT NULL, 
	PRIMARY KEY (ID),
	UNIQUE KEY (username)
	)ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1
');
// execution de la requete
$req->execute();
// enregistrement de l'éventuelle erreur
$erreur=$req->errorCode();
// si il y a une erreur
if ($erreur !== '00000'){
	// affichage de l'erreur
	echo "problème lors de la création de la table users :".$req->errorCode();
// sinon
}else{
	// affichage du succès
	echo "La table users a été créée sans problème";
	echo'</br><a href="../../index.php">Retour à l\'accueil</a>';
}
?>

</body>