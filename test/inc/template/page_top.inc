<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8" />
		<title>Développement web</title>
		<!-- Latest compiled and minified CSS -->
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">

		<!-- Optional theme -->
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css" integrity="sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r" crossorigin="anonymous">

		<!-- Latest compiled and minified JavaScript -->
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js" integrity="sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS" crossorigin="anonymous"></script>
		<link type="text/css" rel="stylesheet" href="styles/global.css">
	</head>

	<body>
		<header class="navbar">
		Bonjour
		</header>
	
		<!-- HEADER -->
		<div id="header-wrap">
			<div id="header">
				<div id="titre du site">Développement Web</div>
				<div id="slogan">Le web, c'est simple !!</div>
			</div>
			<div id="user">
				<?php 
				if (isset($_SESSION['pseudo'])){
					echo "Bonjour, ".$_SESSION['pseudo'];
echo " <a href=\"index.php?page=user_logout\"> déconnexion</a>";
				} else{
					echo " <a href=\"index.php?page=user_login\"> connexion</a>";
				}
				?>
			</div>
		</div>
		
		<!-- NAVIGATION -->
		<div id="nav">
			<ul>
				<?php include "inc/menus/menu_principal.inc";?>
			</ul>
		</div>
		