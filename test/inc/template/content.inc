<!-- CONTENU -->
<div id="content">

<?php
if (isset($_GET['page'])){
// INFO : user_logout se gère dans index.php
	switch ($_GET['page']){
		//PAGES :
		case "accueil":
			include('pages/accueil.inc');
		break;
		case "contact":
			include('pages/contact.inc');
		break;
		case "discussion":
			include('pages/discussion.inc');
		break;
		case "user":
			include('pages/user.inc'); 
		break;
		case "user_login":
			include('pages/user_login.inc'); 
		break;
		// INCLUDES :
		case "connexion":
			include('inc/user/connexion.php'); 
		break;
		case "user_logout":
			include('inc/user/deconnexion.php'); 
		break;
		// DEFAULT : Accueil
		default:
			include('pages/accueil.inc');
		break;
		
	}
}else{
	include('pages/accueil.inc');
}
?>

</div>
</section>