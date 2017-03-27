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
As you can see in the follow picture we have the same attributes explained before in  the XML but also some other new ones that will help us to apply correctly all the buffs. j1Timer is who will help us to keep control to the time, j1Player will give us the info necesary to change the attributes needed to our target and finally last bool will help us to now if the buff is active or not we did it because we don't want that the same buff stack without control. To end this introduction we did a constructor inside of the struct to avoid implement a method to load the xml and load all more eficiently in the awake method of our buff module. 
![Buffs struct](http://subirimagen.me/uploads/20170326204221.PNG)

Next we will explain these methods and why we will use it. Keep in mind we are talking about a basic structure of buff debuff manager, and this format can be implemented in many ways to adapt you're code as you want. In our case we will be able to acces to the attributes of a class player and this attributes are the ones we aim to change using this module through our buffs. As we explained before all buff will be load in a stl list from the xml. but also we will need a method to keep an eye on those buffs that will be applied. The other one's like applybuff, searchbuff and chekapplied buffs will be explained with more detail in next step. 
![principal buff methods](http://subirimagen.me/uploads/20170326214453.PNG)



## Links to more documentation

## TODOs


## Explanation of any other improvements on the system



### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```
