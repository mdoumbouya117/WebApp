<?php
// --------------------------
// Si l'utilisateur se LOG IN
// --------------------------
if ($_POST['type'] == "logIn"){
	// S'il manque des informations de LOGIN
	if (empty($_POST['mdp']) || empty($_POST['connect'])){
			$message=0;
			// renvoi vers le formulaire avec message d'erreur
			header('Location: index.php?page=user&message='.$message);
	}
	// s'il y a toutes les infos de LOGIN
	else{
		//  on nettoie les inputs
		include('inc/fonction.inc');
		$connect=rec($_POST['connect']);
		$mdp=rec($_POST['mdp']);
		// connexion à la BDD
		$bddobject = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
		// préparation de la requête paramétrée
		$req=$bddobject->prepare('SELECT ID,username, password, email, signup_date FROM users WHERE username = ? OR email = ?');
		// execution avec les données du formulaire
		$req->execute(array($connect,$connect));
		// on prend la première ligne de résultat ( username est UNIQUE KEY)
		$results=$req->fetch();
		// on enregistre le MDP dans une variable :
		$mdp_bdd=$results['password'];
		// on le crypt avec une clef '123456'
		$mdp_post=crypt('123456',$mdp);
		// si le mot de passe est bon
		if ($mdp_bdd == $mdp_post){
			// connexion réussie !
			echo 'Bonjour,<strong> '.$results['username'].'</strong>, votre email est : <strong>'.$results['email']."</strong></br>";
			echo 'Vous êtes maintenant connecté';
			// On initialise les variables SESSION
			$_SESSION['ID']=$results['ID'];
			$_SESSION['pseudo']=$results['username'];
			// si l'utilisateur souhaite une connexion automatique
			if(isset($_POST['cookie'])){
				// Enregistrement des cookies
				setcookie('connect',$connect, time() + 365*24*3600);
				setcookie('pass_hash',$mdp_post, time() + 365*24*3600);
				// prevenir l'utilisateur :
				echo "<p> Vous serez maintenant connecté automatiquement</p>";
			}
		}
		// si le mot de passe n'est pas bon.	
		else{
			$message=1;
			// renvoi vers la page formulaire avec message d'erreur
			header('Location: index.php?page=user&message='.$message);		
		}
	}
// --------------------------
// Si l'utilisateur SIGN IN
// --------------------------
}else if ($_POST['type'] == "connect"){
	// S'il manque des infos de SIGN IN
	if (empty($_POST['mail']) || empty($_POST['pseudo']) || empty($_POST['mdp']) || empty($_POST['mdpVerif'])){
		// Renvoi vers la page formulaire avec message d'erreur
		$message=2;
		header('Location: index.php?page=user&message='.$message);	
	}
	// s'il y a toutes les infos de SIGN IN
	else{
		// connexion à la BDD
		$bddobject = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
		// récupérer et nettoyer / crypter les données
		include('inc/fonction.inc');
		$pass=rec($_POST['mdp']);
		$passVerif=rec($_POST['mdpVerif']);
		$username=rec($_POST['pseudo']);
		$hashpass = crypt('123456',$pass);
		$email=rec($_POST['mail']);
		$signup_date=time();
		// Si les deux champs mot de passe ne correspondent pas :
		if($pass !== $passVerif){
			// renvoi vers la page formulaire avec message d'erreur
			$message=3;
			header('Location: index.php?page=user&message='.$message);
		} 
		// Si le formulaire de SIGN IN est bien complété
		else{
			// ---- On test si l'utilisateur existe :
			//Preparation d'une requete pour tester si username ou email existe
			$reqVerif=$bddobject->prepare('SELECT ID FROM users WHERE username= ? OR email = ?');
			// executer avec les données de l'utilisateur
			$reqVerif->execute(array($username,$email));
			// Le résultat de la requête est stockée dans une variable
			$results=$reqVerif->fetch();
			// Si la variable n'est pas vide ( email ou username existe deja)
			if (!empty($results)){
				// Renvoi vers la page formulaire avec message d'erreur
				$message=4;
				$id=$results['ID'];
				header('Location: index.php?page=user&message='.$message.'&id='.$id);
			}
			// Si la variable est vide ( tout OK, on crée l'user)
			else{
				// creation de l'utilisateur - preparation de la requete d'insertion paramétrée 
				$req=$bddobject->prepare('INSERT INTO users (username,password,email,signup_date) VALUE (?,?,?,?)');
				// envoi de la requete paramétrée
				$req->execute(array($username,$hashpass,$email,$signup_date));
				//  Affichage de la connexion réussie 
				echo "Votre compte a été créé et vous êtes connecté";
				// requete pour afficher les données de l'user créé (ID,...)
				// - preparation
				$req=$bddobject->prepare('SELECT ID FROM users WHERE email= ?');
				// - execution paramétrée
				$req->execute(array($email));
				$results=$req->fetch();
				// On initialise les variables SESSION
				$_SESSION['ID']=$results['ID'];
				$_SESSION['pseudo']=$username;
			}
		}
	}
}
?>