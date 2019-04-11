# Cutscene Manager
I am [Alex Morales Garcia](https://www.linkedin.com/in/alex-morales-garcia-aba47b173/), student of the [Bachelor’s Degree in Video Games by UPC at CITM](https://www.citm.upc.edu/ing/estudis/graus-videojocs/). This content is generated for the second year’s subject Project 2, under supervision of lecturer [Ricard Pillosu](https://es.linkedin.com/in/ricardpillosu).

## What is a cutscene?
 
 A cutscene is a scene in a videogame that may no be interactive, develops the storyline and is shown when a certain event occurs.
 
## When do we use it?
 
 **1. Intro**: The initial cutscene in games is the iniTial movie. It introduces the player to the universe, and shows which events lead to the actual situation of the world. There are four different ways to break down the information:
  - Plot: It gives to the player lots of details and information about how he/she get there and what is about to encounter. Example: Command & Conquer
  
[C&C: Gold Intro](https://www.youtube.com/watch?v=5c9xyryhCqY)
  - Back-story: The game explains a little story which tolds the player the motivation of the good and the bad guys. Example: Lego Star Wars: The Complete Saga, Myth
  
[Myth Intro](https://youtu.be/PySrgfe6pr4?t=30)
  - Action: It shows examples how the basic gameplay is going to be. Example: Mech Warrior 2
  
 [Mech Warrior 2 Intro](https://www.youtube.com/watch?v=-X3GD0UnBCk)
  - Mood: The most effective way to setting a stage is by establishing the mood for the game. It would grant the player attention. Example: Diablo, Kingdom Hearts.
  
[Kingdom Hearts Intro](https://www.youtube.com/watch?v=c9-hdtsy0fA)

  **2. In-between**: The purpose of this can be a reward or a way to advance the plot. The custscene as a reward gives the player times to rest from the previous level and prepare for the next one. Advancing the plot gives a clue of what is going to happen next. Usually this elements are combined. Examples: The Last of Us, Uncharted, Kingdom Hearts, Professor Layton, etc.
  
[Profesor Layton and the Lost Future Cutscenes](https://www.youtube.com/watch?v=Zh2ReGQY0ts)

**3. Final**: The final cutscene has to be the best of the game. The player has to feel that all the effort was worth it and that she/he has recieved the final reward. Adding a couple of alternate endings will make the game replayable. Example: Bioshock

In Bioshock, the player has different endings depending on the path chosen. There are two different endings, one good (where you save all the Little Sisters) and one bad (where you decide to harvest a couple or more Little Sisters). 

[Bioshock Ending Cinematic](https://www.youtube.com/watch?v=f3nBbo-uyZo)

## Cutscene Types

### Pre-rendered
The pre-rendered cutscene are animated and rendered beforehand.
- Advantages: More graphic quality, allows the developers render things that willl be impossible in-engine.

- Disadvantages: Occupy lots of memory. The difference between the pre-rendered and in-game graphics.

[Kingdom Hearts III Intro](https://www.youtube.com/watch?v=PwsRQSkQc_A)

### In Game Engine
A real time cutscene means that the system is using the games graphics engine to render it.

 - Advantages: The feedback with the player appeareance. If the engine is used for rendering the scenes, there is no need to integrate other team specialaced in the cutscenes animation and rendering.
 
 - Disadvantages: Lower quality, but nowadays the difference between the graphics quality is not as wide as in the past.

In the next two images there is a link to a in-engine cutscenes:

[<img src="https://github.com/AlexMG99/Cutscene-Manager-Research/blob/master/docs/web_images/pokemon_diamond.jpg?raw=true" width="400" height="240">](https://www.youtube.com/watch?v=b1TNUPLXLqA) [<img src="https://github.com/AlexMG99/Cutscene-Manager-Research/blob/master/docs/web_images/stardew_valley.png?raw=true)" width="400" height="240">](https://www.youtube.com/watch?v=qCjfhCwVfKk&list=PLmTuEQqx9PwUCaC6j19bOj3h0fodYRcoB&index=4)


### Interactive
Interactive cutscenes involves the player taking control of the player in certain moments. The player usually has to pressed a button or a sequence of buttons, when they appear on the screen, in order to succed or continue the action.

- Advantages: The cutscene doesn't stop the game flow, as the player has to be attentive of the screen and what is happening.
- Disadvantages: The player may be less focused on what the cutscene is explaining. Limits the gameplay and usually simplifies it to QTE (Quick Time Events).

[Spiderman 3 Interactive Cutscene](https://www.youtube.com/watch?v=5Js72d-LpEI)

### Live-action 
Live-action cutscenes involves real actors on a set or in front of a chroma screen.

## Cutscene in Engines
I focus mainly in two Engines, Unreal and Unity. In both, you have a time bar, where you can add elements and change it's characateristics and attributes through time. There are key-frames, which are points where you can change the properties of the object. The engine will make an interpolation with the two positions and will generate a smooth transition. The properties that can be changed are rotation, scale, position, state, etc.

For example, we have a camera which position is {0,0,0} in the first frame. We can go to the frame 300, and change its position to {0,0,40}. The engine will make an interpolation, and the position of the camera will change gradually from the satrt point to the end one.

- [Unity Cutscene](https://www.youtube.com/watch?v=Tg-ydfLEPak)
- [Unreal Cutscene](https://www.youtube.com/watch?v=7dVHhwGBCQQ)

## My Cutscene Manager
My solution is an In Engine (Real-Time) cutscene system using C++ and SDL, It needs acces to a XML file and the engine requires their own Entity, GUI and map system. This solution can be implemented in other similar engines.

 ### Cutscenes
The cutscene is composed by two main cores: elements and actions. The Cutscene Manager will have to save them, and will execute it in order. They are stored in a XML similar at this:

    <cutscene>
	    <elements>
		    <!-- Here will go all the elements used in the cutscene-->
		</elements>
		<actions>
			<!-- Here will go all the actions that will execute in the cutscene-->
		</action>
	</cutscene>
	
- **Creating an element**

There are four types of elements:
- Map
- Entity
- Image
- Text

The structure of the XML is the following:

    <cutscene>
	    <elements>
		    <element type="map" <!-- Here goes all the map information --> />
		    <element type="entity" <!-- Here goes all the entity information --> />
		    <element type="image" <!-- Here goes all the image information --> />
		    <element type="text" <!-- Here goes all the text information --> />
		</elements>
		<actions>
			<!-- Here will go all the actions that will execute in the cutscene-->
		</action>
	</cutscene>
	
All the elements have something in common:
- name: name that identifies the element.
- active: the element is activated or not.

#### Creating a map
The map module allow us to load and draw one map in the screen. It needs:
- path: the path for loading the xml.

Map XML example:

	<cutscene>
	    <elements>
		    <element type="map" name ="city" path="city.tmx"/>
		</elements>
		<actions>
			<!-- Here will go all the actions that will execute in the cutscene-->
		</actions>
	</cutscene>

#### Creating an entity
Entities are elements that can perform pre-programed actions inside the engine. entity system allows them to move. The attributes that needs to be passed are:
- pos_x: x position where the player begins.
- pos_y: y position where the player begins.

Entity XML example:

	<cutscene>
	    <elements>
		    <element type="entity" name="gold" pos_x="10" pos_y="340"/>
		</elements>
		<actions>
			<!-- Here will go all the actions that will execute in the cutscene-->
		</actions>
	</cutscene>

#### Creating an image
The images are static elements drawn at the screen, which follows the camera movement. You can use it as text boxes. The attributes used are:
- pos_x: x position on the screen.
- pos_y: y position on the screen.
- rect_x: x position of the image rect inside the spritesheet.
- rect_y: y position of the image rect inside the spritesheet.
- rect_w: width of the image rect.
- rect_h: height of the image rect.
- active: the element is seen in screen or not.

Image XML example:

	<cutscene>
	    <elements>
			 <element type="image" name ="dialog_image" pos_x="85" pos_y="265" rect_x="0" rect_y="0" rect_w="370" rect_h="103" active="false"/>
		</elements>
		<actions>
			<!-- Here will go all the actions that will execute in the cutscene-->
		</actions>
	</cutscene>

#### Creating a text
The text follows the camera movement.

Text need these attributes:
- pos_x: x position on the screen.
- pos_y: y position on the screen.
- txt: the text content
- active: the elements is seen in screen or not.
- size: size of the font.

Text XML example:

	<cutscene>
		<elements>
			<element type="text" name ="dialog" pos_x="100" pos_y="290" txt="Gold: Late, as always." active="false" size="27"/>
		</elements>
		<actions>
				<!-- Here will go all the actions that will execute in the cutscene-->
		</actions>
	</cutscene>

- **Creating an action**

The actions are changes in the elements properties during the cutscene. It includes camera and entity movement, and modifying properties from the text or image.
This manager has four different actions:

- MoveCamera
- MoveEntity
- ModifyText
- ModifyImage

All actions have common attributes:

-   start_time: start time in seconds.
-   duration_time: time that takes to finish the action.

The structure of the xml is:

	<cutscene>
	    <elements>
		     <!-- Here will go all the elements used in the cutscene-->
		</elements>
		<actions>
			<cutscene action="move_camera">
				<!-- Here will go the Move Camera attributes -->
			</cutscene>
			<cutscene action="move_entity" entity="">
				<!-- Here will go the Move Entity attributes -->
			</cutscene>
			<cutscene action="modify_image" name="">
				<!-- Here will go the Modify Image attributes -->
			</cutscene>
			<cutscene action="modify_text" name="">
				<!-- Here will go the Modify Text attributes -->
			</cutscene>
		</action>
	</cutscene>

#### Creating a MoveCamera
MoveCamera changes the camera position at certain speed. The attributes needed are:
- speed_x: x speed of the camera movement.
- speed_y; y speed of the camera movement.

Example of the move camera xml:

	<cutscene>
	    <elements>
		     <!-- Here will go all the elements used in the cutscene-->
		</elements>
		<actions>
			<cutscene action="move_camera">
				<time start="4000" duration="2000" speed_x="130" speed_y="0"/>
			</cutscene>
		</actions>
	</cutscene>

#### Creating a MoveEntity
MoveEntity changes the entity position. We need:
- entity: name of the entity that moves.
- speed_x: x speed of the player movement.
- speed_y; y speed of the player movement.

Example of the MoveEntity in xml:

	<cutscene>
	    <elements>
		     <!-- Here will go all the elements used in the cutscene-->
		</elements>
		<actions>
			<cutscene action="move_entity" entity="gold">
				<time start="4000" duration="2000" speed_x="0" speed_y="200"/>
			</cutscene>
		</actions>
	</cutscene>

#### Creating a ModifyImage
ModifyImage has two different functions:

 - Activate: the image is visible.
 - Deactivate: the image is not visible.

The attributes required are:
- name: name of the object that will affect this action.
- type: type of the action (activate or deactivate).

Example of the xml:

	<cutscene>
	    <elements>
		     <!-- Here will go all the elements used in the cutscene-->
		</elements>
		<actions>
			<cutscene action="modify_image" name="dialog_image">
		      <time start ="7500" duration="100" type="activate"/>
			</cutscene>
		</actions>
	</cutscene>

#### Creating a ModifyText
ModifyText has three different functions:

 - Activate: the text is visible.
 - Deactivate: the text is not visible.
 - Change: the text content changes

The attributes required are:
- name: name of the object that will affect this action.
- type: type of the action (activate, deactivate or change).
- text: new text

Example of the xml:

	<cutscene>
	    <elements>
		     <!-- Here will go all the elements used in the cutscene-->
		</elements>
		<actions>
			<cutscene action="modify_text" name="dialog">
		      <time start ="15600" duration="100" type="change" text="Gold: Finally, I thought you won't come."/>
			</cutscene>
		</actions>
	</cutscene>
	
	
## Exercises

You can download the exercises [here](https://github.com/AlexMG99/Cutscene-Manager-Research/releases/tag/V.1.1).

### TODO 1
Add 3 CutsceneEntity:

 1. Gold: His name is gold, and it has to be situated in x=10 and y=340.
 2. Silver: Her name is silver, and it has to be situated in x=670 and y=338.
 3. Ruby: His name is rival, and it has to be situated in x=670 and y=365.

Structure:

	<element type="" name="" pos_x="" pos_y=""/>
		
### TODO 2
Add a CutsceneImage, which will be used as a dialog. 
The name has to be dialog image. The position is {85,265} and the rect {0,0,370,103}. It has to be deactivated when starts.

	<element type="" name ="" pos_x="" pos_y="" rect_x="" rect_y="" rect_w="" rect_h="" active=""/>

### TODO 3
Create a MoveEntity action. You have to pass the name of the entity which will be affected by it.
The other parameters are the action type, start time = 0, duration = 4000, speed_x = 88, and speed y = 0. 

	<cutscene action="" entity="">
      <time start="" duration="" speed_x="" speed_y=""/>
    </cutscene>

### TODO 4
Create a new CutsceneEntity which will be load from the xml. Check the CutsceneEntity constructor for more information:

<img src="https://github.com/AlexMG99/Cutscene-Manager-Research/blob/master/docs/web_images/EntityMove.JPG?raw=true">

### TODO 5
Create a new CutsceneImage which will be load from the xml. Check the CutsceneImage constructor for more information:

<img src="https://github.com/AlexMG99/Cutscene-Manager-Research/blob/master/docs/web_images/EntityImage.JPG?raw=true">

### TODO 6
Create a new CutsceneMoveEntity that will be load from the xml. Check the CutsceneMoveEntity constructor for more information:
![CutsceneMoveEntity Constructor](https://github.com/AlexMG99/Cutscene-Manager-Research/blob/master/docs/web_images/MoveEntity.JPG?raw=true)

### TODO 7
Find the corresponding entity depending on the entity_name that has been passed. All the elements are in a map, which first value is a string and a second one is a CutsceneElement. There is a function in maps which is find(). You have to find it by the name and acces to the second element.

### TODO 8
Uncomment the code and check functionallity. The result has to be something like this:


[![Video of the final Cutscene](https://github.com/AlexMG99/Cutscene-Manager-Research/blob/master/docs/web_images/video_image.png?raw=true)](https://www.youtube.com/watch?v=WycmxD10BZA)

## Useful links
https://en.wikipedia.org/wiki/Cutscene
https://en.oxforddictionaries.com/definition/cutscene
https://www.gamasutra.com/view/feature/131410/better_game_design_through_.php
http://www.gamasutra.com/view/feature/131687/the_rules_of_the_game_cutting_cut_.php
https://www.quora.com/Why-dont-video-games-use-pre-rendered-videos-as-cut-scenes-instead-of-loading-everything-to-make-one
https://www.quora.com/Are-video-game-cutscenes-made-using-the-game-engine-or-video-making-software

