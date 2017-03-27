# Multiple Buff & Debuff 

## Introduction 

We are a couple of student who will present you a research about how to handle a multiple buff & debuff manager in c++. During the next lines we will pass throught all the concepts and minimum requeriments to be able to implement this code. We will use XML files, STL list as a container and some UI elements to get a better visual aspect.

If you're here we understand that you know already what is a buff or a debuff but in any case we will explain it so you can have a clear vision on them. Buff or Debuff it's a modification to an attribute of any kind to a unit. In most of the games are usually to our main character but we also can apply to the enemies. We can see it as an ability, potion or any type of expression that game designer's and programmers decide to implement. 

In our case we are implementing a basic structure of a multiple buff debuff manager. The type of buff/debuff we are doing are applicable during a certain amount of time and the same buff can't stack.

### XML handle
In case you need some help in XML format we are using pugi xml and here you can find a link to a quick start into pugi: [xml pugi page](http://pugixml.org/docs/quickstart.html)

As you can see in the picture this is the way we organize our XML file to handle the buffs and debuffs the way we want. The most important part of this are the operator, timer_duration, attibute_to_change and the value. This four attributes of the XML file give us the information necessary to apply the buff or debuff to whatever attribute we want to change. 
![XML Picture](http://subirimagen.me/uploads/20170326202502.PNG)

### Buff & Debuff Module

As second step to implement our buff and debuff manager we need somewhere to manage all the data, variations or changes that will happen. So we will implement our module class where you will be able to do and undo what you want to your buffs. In our case we implemented a struct named buffs a list of buffs and applied buffs to keep an eye on them everytime we submit some changes to the player.

### Struct Buffs
As you can see in the follow picture we have the same attributes explained before in  the XML but also some other attributes that will help us to apply correctly all the buffs. 
![Buffs struct](http://subirimagen.me/uploads/20170326204221.PNG)

#### World of Warcraft ([official website](https://worldofwarcraft.com/es-es/))
Priests in World of Warcraft provide many, including resurrection. Most spellcasters have at least one buff spell.
Even Warriors and Rogues have some buff effects, although those are largely self-targeting abilities.
Druids are also notable for having no less than 3 types of Regeneration buffs. A normal one, one with an instant effect at the beginning, and one with an instant effect when it expires.

#### Warcraft III ([official website](http://eu.blizzard.com/es-es/games/war3/))
Many unit types in Warcraft III, especially the unique hero units, have buffs and auras that aid their subordinates in battle.

#### Diablo II ([official website](http://eu.blizzard.com/es-es/games/d2/))
Paladins in Diablo II were a lackluster fighter class at high levels, but were valued for their auras and healing abilities. This was later changed, while paladin auras were still beneficial to their parties, paladins are able to be extremely effective in melee (zealots and smiters, which is one of the best builds for killing the hardest bosses) and as casters (hammerdins, a very popular build for rushing, power leveling, and farming) in their own right.

#### Minecraft ([official website](https://minecraft.net/es-es/))
Minecraft has several status buffs that are obtained from potions and using beacons. The stronger the buff, the more potent it is and they can be used on friends and foes alike:</br>
. _Regeneration_: Restores health over time.</br>
. _Speed Boost_: Walk and run faster. </br>
. _Strength_: Damage output is boosted. </br>
. _Resistance_: Increased defense. </br>
. _Fire Resistance_: Immunity to fire and lava. </br>
. _Night Vision_: All dark areas are lit up, though they are not actually filled with light, thus monsters can still spawn. </br>
. _Water Breathing_: Super Not-Drowning Skills plus improved vision underwater.</br>
. _Invisibility_: Exactly What It Says on the Tin, except for items carried and armor pieces worn.</br>
. _Haste_: Mine blocks faster.</br>
. _Health Boost_: Temporarily increases your maximum health.</br>


## Introduction to the problem

## Description in detail for the selected approach

aqui tot 

## Links to more documentation

## TODOs

## Optional Homework for practicing

no cal oi ? 

## Explanation of any other improvements on the system

millores
clasificacio buff debuff amb la etiqueta del tipus 

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```
