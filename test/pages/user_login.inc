<h1>Zone utilisateur</h1>

<?php 
// Si il n'y a pas de session en cours on affiche le formulaire de login 
if(!isset($_SESSION['pseudo'])){ 
	if(isset($_GET['message'])){
		$message=$_GET['message'];
			$lesMessage=array(
				'Des champs n\'ont pas été remplis pour le login',
				'Les données ne correspondent pas avec la BDD',
				'Des champs n\'ont pas été remplis pour l\'inscription',
				'Attention, les mot de passe ne correspond pas',
				'utilisateur existe déja.',

				'');
			echo $lesMessage[$message];
			if (isset($_GET['id'])){
				echo '</br>ID de l\'utilisateur : '.$_GET['id'];
			}
	}
	
?>
<p>Pour vous connecter, indiquez votre pseudo et votre mot de passe.<br/>
Vous pouvez aussi cocher l'option "Me connecter automatiquement à mon
prochain passage." pour vous connecter automatiquement.<br/>
La connexion auto est basée sur les cookies. Ce sont de petits fichiers sur votre ordinateur
contenant votre ID que le MDP crypté.</p>
			
<form name="connexion" id="connexion" method="post" action="index.php?page=connexion">
	<fieldset><legend>Connexion</legend>
		<label for="connect" class="float">Pseudo ou Mail:</label> <input type="text" name="connect" id="connect" /><br/>
		<label for="mdp" class="float">Passe :</label> <input type="password" name="mdp" id="mdp"/><br/>
		<input type="hidden" name="type" id="validate" value="logIn"/>
		<input type="checkbox" name="cookie" id="cookie"/> <label for="cookie">Me connecter automatiquement à mon prochain passage.</label><br/>
		<div class="center"><input type="submit" value="Connexion" /></div>
	</fieldset>
</form>
<form name="inscription" id="inscription" method="post" action="index.php?page=connexion">
	<fieldset><legend>Inscription</legend>
		<label for="mail" class="float">Mail :</label> <input type="text" name="mail" id="mail" /><br/>
		<label for="pseudo" class="float">Pseudo :</label> <input type="text" name="pseudo" id="pseudo" /><br/>
		<label for="mdp" class="float">Mot de passe :</label> <input type="password" name="mdp" id="mdp"/><br/>
		<label for="mdpVerif" class="float">Vérifier MdP :</label> <input type="password" name="mdpVerif" id="mdpVerif"/><br/>
		<input type="hidden" name="type" id="validate" value="connect"/>
		<div class="center"><input type="submit" value="Inscription" /></div>
	</fieldset>
</form>


<?php 
}

else{
	echo "Vous êtes déja connecté </br>";
	
}
 ?>


