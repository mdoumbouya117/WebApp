<!-- CONTENU -->
<div id="content">
	<form id="contact" method="post" action="index.php?page=traitement_formulaire">
		<fieldset><legend>Vos coordonnées</legend>
			<p><label for="nom">Nom : </label><input type="text" id="nom" name="nom" /> Prénom : </label><input type="text" id="nom" name="prenom"/></p>
			<p><label for="nom"></p>
			<p><label for="pass">Password : </label><input type="password" id="pass" name="pass" /></p>
		</fieldset>
		
		<fieldset><legend>Vos infos</legend>
			<select id="age" name="age" type="list">
				<option value="1">- de 18 ans</option>
				<option value="2"> entre 18 et 60 ans</option>
				<option value="3"> + de 60 ans</option>
			</select>
			<br>
			<br>
			<label for="bd">Vous aimez ?</label><br>
			<input id="check1" name="bd[]" type="checkbox" value="1">Livre<br>
			<input id="check2" name="bd[]" type="checkbox" value="2" checked>BD<br>
			<input id="check3" name="bd[]" type="checkbox" value="3">Aucun<br>
			<input id="check4" name="bd[]" type="checkbox" value="4">Les deux<br>
			<br>
			<br>
			<label>Vous préférez quelle saison ?</label><br>
			<input type="radio" name="saison" id="radio" value="1">ETE<br>
			<input type="radio" name="saison" id="radio" value="2">AUTOMNE<br>
			<input type="radio" name="saison" id="radio" value="3">HIVER<br>
			<input type="radio" name="saison" id="radio" value="4">PRINTEMPS<br>
		</fieldset>	
				
		<fieldset><legend>Votre message :</legend>
			<p><label for="message">Message : </label><textarea id="message" name="message" cols="30" rows="8"></textarea></p>
		
		
		</fieldset>
 
		<div style="text-align:center;"><input type="submit" name="envoi" value="Envoyer le formulaire !" /></div>
</form>

	
</div>
		
				