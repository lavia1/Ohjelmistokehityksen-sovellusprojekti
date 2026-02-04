# Ohjelmistokehityksen-sovellusprojekti
Liitteenä RestApi tiedosto, jossa CRUD-operaatiot sekä QtApp, jossa Qt applikaation tiedot. QtApp tiedostossa **carss** -tiedosto, jossa oikeat tiedot (muut tiedostot testiversioita.)

En saanut Delete cars -nappia toimimaan niin että se poistaisi auton Qt applikaatiossa. Backendissä pitäisi olla kaikki oikein, joten johtuu Qt applikaatiosta, mutten saanut selville, miksei se ala toimimaan, vaikka yritin.


### Car-taulun luomiseen kirjoitettu SQL-koodi:
CREATE TABLE car(<br/>
id_car INT primary key auto_increment,<br/>
branch VARCHAR(255),<br/>
model VARCHAR(255)<br/>
);
