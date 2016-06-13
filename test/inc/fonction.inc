<?php
// -- Toutes les fonctions pour le site

// fonction de nettoyage des données
function rec($text){
	// remplace une chaine de caractère par une autre (ici retire les ")
	$text=str_replace('"','',$text);
	// retire les balises
	$text=strip_tags($text);
	// convertir les caractères spéciaux en HTML
	$text=htmlspecialchars($text);
	// retire les espaces en début et en fin de chaine
	$text=trim($text);
	// retire les / du texte
	$text = stripslashes($text);
	return $text;
}

// fonction rechercher dans un tableau
function chercher($index,$table){
	if (is_array($index)){
		foreach ($index as $i=>$val){
			$value[]=$table[$val];
		}	
		return $value;
	}else{
		$value=$table[$index];
		return $value;
	}
}

