# Multiple Buff & Debuff Manager

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

### Buff module important methods

ApplyBuffs will be the method that will be use as a trigger in whatever place of our code and interest. In our case we programmed for some keys so these will trigger some especial buffs like an ability would do it in a MOBA game.
Going in more detail on this method: We recive two paremeters, one is the name of the buff, and the other one is a pointer to our player/target or whatever that we will change the values of their atributes. In our case it's a player. Once we have these two entries with the name we will iterate the list of buffs and take a pointer to the buff we want to apply. Now we have our beloved buff and the target the next step is to implement a way to apply the buff. 
Here is where all those attributes created on the XML file enters to the game. This part can be confusing so we are going to explain the best way we can. Now we need to make sure what kind of buff we have so we can apply the correct formula. First of all we need a switch so we now what kind of operation we want to use. Next is make sure what attribute we need to change. And now with these two steps we can apply the modification. 
But before end we have to make sure of the most important part, we want a system that handles multiples buff so this part of code cant stop here and waits to the duration of buff to finish. To resolve this problem we will use those usefull attributes told before on the Buffs struct. First we need to add our target on the buff set the buff active, then add this buff to the applied buff list and starts the timer. With this implementation and the method check applied buff we can follow the timer and make sure to erase the efect when it's needed. Remember to use the method compare for the std::strings. 

![ApplyBuffs](http://subirimagen.me/uploads/20170326221441.PNG)

### Final Step

As a final step we have to check our list of applied buff so we can remove the buff on time. For this we just need to use our timer duration and the method from j1Timer called ReadSec(). If we compare those two as we iterate the applied buff list we can undo the buff because now on the buff you have everything to make it happen. you need to have in mind that in case you did a operation like multiply here you have to apply it contraiwise.

## Links to more documentation

We hope you learned some way to improve or implement your basic buff/debuff manager, thank you for reading and also here we will let you this explanation as a excercise so you can do it by yourself and learn it.

Also here you can we let some documentation in case you need it:
 - 
 
 
## TODOs


## Explanation of any other improvements on the system





