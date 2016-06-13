<?php
// destruction de la session et destruction des variables de session
session_destroy();
$_SESSION = array();
// Suppression des cookies de connexion automatique
setcookie('connect', '');
setcookie('pass_hash', '');
// renvoi vers la page d'accueil
header('Location: index.php?page=accueil');	
?>