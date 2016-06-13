<li><a href="index.php?page=accueil">Accueil</a></li>
<li><a href="index.php?page=contact">Contacte</a></li>
<li><a href="index.php?page=discussion">Discussion</a></li>
<?php if (isset($_SESSION['ID'])){ ?>
	<li><a href="index.php?page=user">Page utilisateurs</a></li>
<li><a href="index.php?page=user_logout">Déconnexion</a></li>
<?php }else{ ?>
	<li><a href="index.php?page=user_login">Connexion</a></li>
<?php }?>