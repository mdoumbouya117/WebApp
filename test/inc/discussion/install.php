<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title>Le cours de développement web</title>
		<link type="text/css" rel="stylesheet" href="styles/global.css">
	</head>

	<body>
<?php
// PDO : Connexion à la base de données 
$bddobject = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
// Requete de création de la table
$req=$bddobject->prepare('CREATE TABLE IF NOT EXISTS discussion( 
	ID int(11) unsigned NOT NULL AUTO_INCREMENT,
	pseudo varchar(255) NOT NULL,
	message varchar(255) NOT NULL,
	time INT(20) NOT NULL, 
	PRIMARY KEY (ID),
	UNIQUE KEY (pseudo)
	)ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1
');
// execution de la requete
$req->execute();
// enregistrement de l'éventuelle erreur
$erreur=$req->errorCode();
// si l'erreur est différente de 0
if ($erreur !== 00000){
	echo "problème lors de la création de la table discussion :".$req->errorCode();
}else{
	echo "La table discussion a été créée sans problème";
	echo'</br><a href="../../index.php">Retour à l\'accueil</a>';
}

?>
</body>