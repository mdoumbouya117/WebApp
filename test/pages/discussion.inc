<?php 
if (isset($_GET['message'])){
	$numMessage = $_GET['message'];
	$messages=array("Le champ message est vide","Le champ utilisateur est vide","Les champs sont vides");
	echo $messages[$numMessage];
}

?>

<h1>Bienvenue sur votre espace de discussion</h1>
<form action="inc/discussion/discussion_traitement.php" method="post">
        <p>
        <label for="pseudo">Pseudo</label> : <input type="text" name="pseudo" id="pseudo" /><br />
        <label for="message">Message</label> :  <input type="text" name="message" id="message" /><br />

        <input type="submit" value="Envoyer" />
    </p>
    </form>

<?php
// Connexion à la base de données
	$bddobject = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', '');
// Récupération des 10 derniers messages
$reponse = $bddobject->query('SELECT pseudo, message, time FROM discussion ORDER BY ID DESC LIMIT 0, 10');

// Affichage de chaque message (toutes les données sont protégées par htmlspecialchars)
while ($donnees = $reponse->fetch())
{
    echo '<p><strong>' . htmlspecialchars($donnees['pseudo']) . '</strong> : ' . htmlspecialchars($donnees['message']) .'</br>'.date('d/m/Y H:m:s',$donnees['time']). '</p>';
}

$reponse->closeCursor();

?>
