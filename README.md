# PimpMyKicker
The Place where we share our progress of pimping our kicker with NFC Readers, goal counter, statistics and more.

## What do we want to achive?

We would like to have statistics of all our kicker games in our Appdafuer Office. The data we want to collect is:

* Who is playing
* At which position is the player playing (attackers / defense) 
* Whats the end result of the game
* How long did the game take
* The order and time of the goals

## How are we building it?

* Installing NFC-Tag Reader at each corner of the Kicker Table which will read a rfid tag representing the player
* Each player has a small Lego-Figure with an Rfid-tag at the bottom representing the player
* Installing big red buttons at the wall near the kicker to count each goal
* Installing two big 100mm 7-segment displays at the wall to show the current score
* Everything is connected to an Arduino Mega which shoul sync the data to the cloud, e.g. Google Firebase

## What is the current state of the project?

* We are very early. We bought most of the necessary parts and are able to read NFC-Tags with the arduino
* We will post images in `images/`
* We will keep you update and work on the project about once a week

## How are we visualising the Data?

* Not sure yet, maybe with an Apple TV App or with Google Data Studio

## Why are we doing it?

We want to learn something about electronics and embedded programming.

## Can I contribute ideas?

Sure, just write us at info@appdafuer.com
