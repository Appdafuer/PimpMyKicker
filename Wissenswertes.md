# Wissenswertes

Hier sammeln wir vorerst unser neu erlerntes Wissen über Elektronik.
 
## Pole

### Pluspol

Anlternative Bezeichnungen / Anzuschließen an:

* Anode
* `+`
* Rot
* LED Seite vom Dreieck
* LED Langes Bein

### Minuspol

* Kathode
* `-`
* GND
* LED Spitze vom Dreieck
* LED Kurzes Bein


## Transistoren

Wie wähle ich den richtigen Transistor aus? Folgende Antwort in einem [Forum](https://www.mikrocontroller.net/topic/157763) hilft viel weiter:


> Um am Anfang wenigstens ein Bisschen den Durchblick im Transistor-
> dschungel zu behalten, kannst du folgendermaßen vorgehen:
> 
> 1. Nomenklatur
> 
> Nach der amerikanischen Nomeklatur beginnen die Transistornamen meist
> mit 2N (z.B. 2N2222 oder 2N3055), nach der japanischen mit 2S (z.B.
> 2SC1815). Für den Anfang kann man sich auf europäischen Tranistsoren
> beschränken, da es diese in ausreichender Auswahl gibt und die Bezeich-
> nungen relativ gut den Transistortyp wiedergeben:
> 
> Der erste Buchstabe bezeichnet das Halbleitermaterial (A=Germanium,
> B=Silizium). Germaniumtransistoren werden heute nur noch selten
> verwendet.
> 
> Der zweite Buchstabe steht für den Einsatzzweck (C=Universal,
> D=hohe Leistung, F=Hochfrequenz, U=hohe Spannung).
> 
> So ist also ein ACxxx ein Germaniumuniversaltransistor und ein BDxxx
> ein Siliziumleistungstransistor.
> 
> 2. Auswahl
> 
> Wenn du dich für einen Grundtyp entschieden hast (für die LED ist ein
> BC-Typ das Richtige), gehst du auf die Webseite eines Elektronikhändlers
> (Reichelt, Kessler usw.), schlägst die Seite mit den BC-Transistoren
> auf. Da gibt es natürlich sehr viele davon, und du brauchst jetzt eine
> Suchreihenfolge. Als erstes Auswahlkriterium nimmst du den Preis, denn:
> 
> - Zuviel Geld hast wahrscheinlich nicht einmal du.
> - Billig ist meist das, was in großen Stückzahlen hergestellt wird. Was
>   für die Masse gut ist, ist (zumindest in diesem Fall) meist auch für
>   dich gut.
> - Was billig und damit in Massen verkauft wird, bekommst du auch bei
>   anderen Händlern und auch noch in 10 Jahren. Das ist wichtig, wenn
>   deine Schaltung irgendwann einmal in Serie gefertigt werden soll.
> 
> Gleich als nächstes überlegst du, ob du einen NPN- oder einen PNP-Typ
> brauchst. Das ergibt sich aus der Anordnung der Bauteile in deiner
> Schaltung. Hast du die Möglichkeit, die Schaltung wahlweise für einen
> NPN- oder einen PNP-Typ auszulegen, wählst du die Variante mit dem
> NPN-Typ. Um einfach eine LED über einen Mikrocontroller einzuschalten,
> ist i.Allg. ein NPN-Typ in Emitterschaltung richtig.
> 
> Ein weiteres wichtiges Kriterium ist die Befestigungstechnik: Wenn dir
> die SMD-Löterei etwas suspekt ist, lässt du die entsprechenden Modelle
> erst einmal alle außen vor. Ein typisches Nicht-SMD-Gehäuse für Univer-
> saltransistoren ist TO-92. Es gibt im Internet bebilderte Listen mit den
> einzelnen Gehäuseformen, ich finde nur gerade keine.
> 
> Wenn du jetzt also bei Reichelt die BC-Transistoren nach Preis aufstei-
> gend sortiert hast, siehst du erst einen Schwung SMD-Tranistoren. Dann
> kommen ein paar Transistoren im TO-92-Gehäuse, die sind aber PNP. Etwas
> weiter unten kommt der erste NPN-Transistor in TO-92, nämlich der
> BC547C. Netterweise stehen gleich ein paar Eckdaten dabei:
> 
>   45V  0,1A  0,5W
> 
> Die 45V sind die maximale Kollektor-Emitter-Spannung, in deinem Fall
> also die Spannung, die du maximal schalten kannst. Da die LED bei Weitem
> keine 45V braucht und deine Versorgungsspannung eher in der gegend von
> 5V liegt, bist du auf jeden Fall auf der sicheren Seite.
> 
> Deine LED wird typisch mit 20mA (max. 30mA) betrieben. Der BC547C kann
> 100mA, also ist auch hier noch Luft.
> 
> Zur maximalen Verlustleistung (0,5W): Wenn deine LED eingeschaltet ist,
> fließen bspw. 20mA. Ist der Transistor voll durchgesteuert (in Sätti-
> gung) beträgt die Kollektor-Emitter-Spannung bei diesem geringen Strom
> typischerweise zwischen 0,1V und 0,2V (Genaueres steht im Datenblatt).
> Am Transistor wird also maximal die Leistung 20mA·0,2V=4mW in Wärme
> umgesetzt. Bis zu 500mW dürfen es sein, also ebenfalls ok.
> 
> Nachdem du den Transistor in engere Auswahl gezogen hast, lohnt sich auf
> jeden Fall ein Blick ins Datenblatt. Aus den Tabellen und Diagrammen
> erfährst du bspw., wie hoch der Basisstrom sein muss, um den Kollektor-
> strom von mindestens 20mA bei ausreichend geringer CE-Spannung bereit-
> zustellen. Dort ist auch erklärt warum es einen BC547A, BC547B und
> BC547C gibt. Der letzte Buchstabe gibt nämlich die Stromverstärkungs-
> klasse an. Da eine hohe Stromverstärkung meist wünschenswert ist und in
> diesem Fall keinen Aufpreis kostet, ziehst du den BC547C den anderen
> beiden vor.
> 
> Da in deiner Anwendung HF-und Rauschverhalten keine Rolle spielen, bist
> du schon am Ziel angelangt.
> 
> Würde deine LED 100mA statt 20mA benötigen, wären die 100mA des BC457
> etwas knapp bemessen. Du blätterst also in der Reichelt-Liste weiter und
> stößt auf den BC337-40 mit 45V, 0,5A und 0,525W. Das ist genau das,
> wonach du suchst. Bei diesem Transistor sind die Stromverstärkungsklas-
> sen durch die Endungen -16, -25 und -40 gekennzeichnet. Es wäre ja auch
> zu einfach, wenn immer nur A, B und C verwendet würde ;-)
> 
> Bei Strömen ab etwa 500mA kommt man an die Grenze der Leistungsfähigkeit
> der BC-Typen. Dann geht es weiter mit BD. Der BD135 geht bspw. schon bis
> 1,5A. Das Problem bei solchen größeren Transistoren: Die Stromverstär-
> kung ist nicht besonders hoch, so dass irgendwann der Mikrocontroller
> nicht mehr den benötigten Basisstrom liefern kann. Dann muss dem großen
> Transistor ein kleiner vorangeschaltet werden, um den erhöhten Basis-
> strom bereitszustellen. Man kann diese Kombination von zwei Transistoren
> auch fertig als Darlington-Transistor kaufen, von denen ebenfalls einige
> in der BD-Reihe zu finden sind (z.B. BD647). Ein Transistortyp der sich
> sehr gut zum Schalten höherer Ströme eignet, ist der Mosfet, auf den ich
> jetzt aber nicht näher eingehen möchte, sonst bin ich morgen noch mit
> Schreiben beschäftigt ;-)
> 
> Wie schon oben angedeutet: Wenn die 30-80V die die meisten BC- und
> BD-Transistoren abkönnen, nicht ausreichen, suchst du weiter bei BU.
> Steigst du in die HF-Technik ein, sind BF-Transistoren eher das
> Richtige, wobei bei HF-Anwendungen die Auswahl der Transistoren nicht
> mehr das Schwierigste ist ;-)
> 
> 3. Und wie geht's weiter?
> 
> Man könnte natürlich noch viel mehr zu diesem Thema schreiben. Ich hoffe
> aber, dass das Geschriebene dir wenigstens grob zeigt, wie man bei nicht
> allzu speziellem Anforderungen relativ schnell zu einem gewünschten
> Transistortyp kommt, der nicht nur die technischen Anforderungen
> erfüllt, sondern auch leicht beschaffbar ist.
> 
> Werden die Anforderungen spezieller, helfen oft die Selektionstabellen
> auf den Webseiten der einschlägigen Hersteller weiter. Auch Händler wie
> Farnell haben teilweise ganz gute Auswahlwerkzeuge.
> 
> Wenn du dich intensiv mit Elektronik beschäftigst, wirst du wahrschein-
> lich noch viele Schaltungen von Leuten zu Gesicht bekommen, die viel-
> leicht schon etwas weiter fortgeschritten sind. Dabei wirst du immer
> wieder auf bestimmte Standardtypen von Transistoren (und auch anderen
> Bauteilen wie Operationsverstärker u.ä.) stoßen und sehen, welche Bau-
> teile "man" üblicherweise für bestimmte Anwendungen einsetzt. Mit der
> Zeit setzt sich dann eine Auswahl von bspw. 10 oder 20 verschiedenen
> Transistoren und 5 bis 10 verschiedenen OpAmps im Kopf fest, von denen
> man die wesentlichen Parameter auswendig kennt, so dass man ohne aufwen-
> dige Suche eine schnelle Auswahl treffen kann.
