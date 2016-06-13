<?php 
$nom="";$prenom="";
$pass="";$bd="";
$age="";$saison="";
$message="";

include('inc/misc/var_traitement_form_contact.inc');
include('inc/fonction.inc');


// Traitement des champs text
if (isset($_POST['nom'])){ $nom=rec($_POST['nom']);}
if (isset($_POST['prenom'])){$prenom=rec($_POST['prenom']);}
if(isset($_POST['message'])){$message=rec($_POST['message']);}

// Traitement des champs pass
if(isset($_POST['pass'])){$pass=rec($_POST['pass']);}

// Traitement des choix de sélection
if(isset($_POST['saison'])){$saison=chercher($_POST['saison'],$lesSaisons);}
if(isset($_POST['bd'])){$bd=chercher($_POST['bd'],$lesBD);}
if(isset($_POST['age'])){$age=chercher($_POST['age'],$lesAges);}


?>

<!-- CONTENU -->
<div id="content">
<?php
echo "Bonjour, <strong>".$prenom." ".$nom."</strong></br></br>";
echo "ton mot de passe est : <strong>".$pass."</strong></br>"; 
echo "Tu as <strong>".$age."</strong> ans.<br>";
echo "Tu aimes les BD ?</br>";
foreach ($bd as $result){echo "<strong>".$result."</strong></br>";}
echo "ta saison préféré est : <strong>".$saison."</strong>. </br></br>";
echo "ton message sur notre site : <strong>".$message."</strong>";

 ?>
	
</div>
		
				