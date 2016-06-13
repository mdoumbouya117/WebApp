<?php
$chaine= $salut. ", C’est PHP";
echo "<table border= \"3\"> <tr> <td width = \"100%\" > <h2>".$chaine."</h2>   </td> </tr></table>";


function testphp(){
$foo="variable locale";
echo "$foo dans le contexte global : ".$GLOBALS["foo"]."</br>";
echo "$foo dans le contexte courant : ".$foo."</br>";
}
?>