# Hackathon-2
1. **Description**
   
   Welcome to the mesmerising realm of "Realm of Enigmas," a captivating text-based adventure game that transports you to a world brimming with intrigue and secrets. Prepare yourself for a thrilling journey as you navigate through a series of immersive environments, each offering its own unique blend of challenges and enigmatic wonders.
   
   Delve into the depths of ancient caves, where darkness conceals ancient riddles and hidden passages. Feel the mist on your face as you venture into a dark forest, with its enchanting waterfalls and whispers of forgotten secrets. Plunge into the depths of an underwater world, where vibrant marine life and hidden treasures await your discovery. Step into the realm of a time tunnel, where the boundaries of past, present, and future blur, presenting you with mind-bending conundrums. As you progress, exercise your wit, logic, and intuition to overcome the challenges that lie in your path.
   
   Prepare to immerse yourself in the captivating world of "Realm of Enigmas" as you embark on a solitary adventure of exploration, discovery, and self-discovery. Are you ready to step into the unknown and unravel the enigmas that await? The journey awaits, adventurer.


3. **Features of the game**
   - **Save and Load Progress**: A player can experience the convenience and continuity of the game by capturing his game data before quit the game. The game will preserve the name, score, inventory items, and current location of the player. When a player is ready to dive back into the adventure, he can load his progress to pick up where he left off, ensuring a reliable and uninterrupted gaming experience.
   - **Unique Player Names**: Each player can have a distinct and exclusive name for this game. If a new player tries to set their name and it matches an existing player's name, they will be prompted to choose a different name. This ensures that every player has their own individual identity.
   - Item Collection and Management: Gather a diverse array of items throughout the journey, each with its own special abilities and uses. Strategically manage the player's inventory to overcome obstacles and unlock new areas.
   - **Immersive Descriptions**: A player can immerse themselves in vivid descriptions that paint a detailed picture of the realm's landscapes, characters, and objects. Engage his imagination as he visualises the scenes, bringing the game world to life in his mind.
   - **An Interesting Theme & Visual Style**: When a player enters a new location, one of the items in that location will be shown to the player.  It can serve as a clue for the item able to be collected by a player. 
   Validation: This game has a strong validation especially when a player wants to collect an item or unlock the next location. It will show an error message when the player input the wrong item.


4. **How to play the game**
   - This game requires a player to navigate through the game using text-based commands and choices.
   - Before the game starts, a brief storyline will be given to the player.
   - Then, the player will be located at the first location. A description for this location will be provided.
   - Next, a player needs to key in a valid number in the menu given to perform action. (The menu will be shown after every action is done.)
   - Action can be done by a player:
      - Examine: Show the description of the current location.
      - Show Inventory: Show the item(s) collected by the player.
      - Collect Item: Collect the item specified by the player.
      - Move: A player can choose to move to the next location, previous location or remain at current location.
      - Unlock the Next Location: Player must use the right item to unlock the next location.
      - Quit: Player can choose to quit the game as he wishes. The current progress of the user will be saved automatically.
   - A player needs to interact with the environment by examining location and collecting items.
   - Beware when collecting items, some items may cause the player to lose his score.
   - It is required for a player to pay attention to clues and hints provided throughout the game to progress and unravel the mysteries of the realm.
   - A player must wisely use collected items strategically to unlock new areas.
   - If the last location is unlocked, tha player has won the game and overcome the challenges successfully!


5. **How object-oriented concepts were used in developing the game**
   
   Realm of Enigmas is developed using object-oriented concepts to enhance code organisation, reusability, and maintainability. Classes such as Player, Location, Item, and Game are used to encapsulate related data and behaviour, allowing for modular and structured code design. Polymorphism, and encapsulation principles are applied to model the game's entities and interactions, providing a flexible and extensible architecture. 
   
   There are 4 classes in our project. The class names are “Item.h”, “Player.h”, “Location.h” and “Main.h”. “Player.h” and “Location.h” composite to “Item.h” since both player and location contain items. “Player.h” requires “Item.h” to set inventory list while “Location.h” requires “Item.h” to set items that can be collected by the player. On the other hand“Game.h” composites to “Player.h” and “Location.h” because a game requires a player and locations to set up.

The relationship between each class is shown in the UML diagram below.:

![class diagram](https://github.com/ceeee33/Hackathon-2/assets/118290498/0e34ade2-1fcf-4741-96d2-37280e97368e)


5. **Role of linked list**
   - **Linked List of Items**: The Item class can utilise a linked list to represent a collection of related items.
   - **Inventory Management**: The singly linked list data structure can be used in the Player class to manage the player's inventory. Each item in the inventory can be represented as a node in the linked list, where each node contains details of the items and a reference to the next item in the inventory. This allows for efficient insertion and traversal of the items in the inventory. In addition, this linked list is used to store and load the details for each node when processing with file.
   - **Item Left for Each Location**:  The singly linked list data structure can be used in the Player class to manage the items left in each location, where each item represents a node in the linked list. Append, remove and search item actions are performed for this linked list. Besides, linked lists are also used to store the information of each node in a file when the player quits the game.
   - **Locations Connections**: The doubly linked list structure enables the Location class to establish connections between adjacent rooms. When creating the game map, each room's node can be connected to the previous and next rooms' nodes, creating a logical flow of room transitions. The player can move forward to the next room by following the next pointer, and they can also backtrack to the previous room by following the previous pointer. This allows for non-linear exploration of the game world, where the player can freely move between rooms they have visited.


6. **Screenshot of the game**
   ![Screenshot 2023-06-28 143225](https://github.com/ceeee33/Hackathon-2/assets/117928541/6d4ebf6c-66cb-415e-8d21-ea1c54f39ae1)
   Interface when player enter the game "Realm of Enigmas"
   Require player to set a nickname for the name. For this figure, the player sets his name as "abc".

   ![Screenshot 2023-06-28 143301](https://github.com/ceeee33/Hackathon-2/assets/117928541/74225afb-3616-4938-a95d-182262294dba)
   The game has started.
   After the player enters the first location of the game. A description about the location is given to the player and the player is required to find the clues and hints based on the description given.
   For this figure, the action chosen by the player is examined. So, it will show up the description for the current location.

   
   ![Screenshot 2023-06-28 143323](https://github.com/ceeee33/Hackathon-2/assets/117928541/6e45b801-2230-4a5a-8d0f-6b9d77a04c8c)
   The examine action is called out by the user to know about the current location and its description in case the player has forgetten which location he/she at.
   
   ![Screenshot 2023-06-28 143418](https://github.com/ceeee33/Hackathon-2/assets/117928541/4873e7e3-427a-47bf-ac52-d416ef12351b)
   In this picture, the player has called out the show inventory action to check the items that he/she has collected previously. Then, the player called out collect items action to collect the item that they felt it is neccessary to unlock the location. After they collceted the item, the program will shows their current score and the successful status of the collected items.
   
   ![Screenshot 2023-06-28 143448](https://github.com/ceeee33/Hackathon-2/assets/117928541/a1aa49ab-a8dc-4300-add3-b82803b7c01d)
   After that, the player collect another item then he called out show inventory items to check the items and description to know more about these items. 
   
   ![Screenshot 2023-06-28 143529](https://github.com/ceeee33/Hackathon-2/assets/117928541/ffd5e10c-6bfc-4e13-a423-be0b51473e14)
   The player wished to perform move action, however, he failed to do so as he does not fulfilled the condition required.
   
   ![Screenshot 2023-06-28 143628](https://github.com/ceeee33/Hackathon-2/assets/117928541/25a0d8dd-9ee5-4ad5-912b-76d39276d54d)
   The player is using the items in his inventory one by one to unlock the next location. Fortunately, one of the items that he had collected is the key item. So, he is able to unlock the next location. This program will automatically move the player to the next room once the player successfully unlocked the next location.

   ![Screenshot 2023-06-28 143705](https://github.com/ceeee33/Hackathon-2/assets/117928541/8fa24305-50b3-492b-8364-b470f581704b)
   So, the name and description for the next location had given once they entered this location

   ![Screenshot 2023-06-28 143859](https://github.com/ceeee33/Hackathon-2/assets/117928541/39e0e08d-434b-4814-b5d0-ae10758eb639)
   The player is trying to collect the item that he feels is important.
   
   ![Screenshot 2023-06-28 143925](https://github.com/ceeee33/Hackathon-2/assets/117928541/47791575-063e-4c15-a29c-2d9b96f2ff40)
   Then, the player uses one of the items that he collected in the second location to unlock the third location and the details of the next location is given.

   ![Screenshot 2023-06-28 144018](https://github.com/ceeee33/Hackathon-2/assets/117928541/b65e1248-1664-4094-ae1c-1a393ea933c4)
   The player is performing the same actions

   ![Screenshot 2023-06-28 144112](https://github.com/ceeee33/Hackathon-2/assets/117928541/c25e1d5f-28b4-4cb0-8e89-7b740bef94f2)
   ![Screenshot 2023-06-28 144138](https://github.com/ceeee33/Hackathon-2/assets/117928541/44e30065-9803-4cdd-9834-d33beb091d2d)
   ![Screenshot 2023-06-28 144203](https://github.com/ceeee33/Hackathon-2/assets/117928541/ada5b417-910f-4cb5-ba7d-3b1042254357)
   ![Screenshot 2023-06-28 144318](https://github.com/ceeee33/Hackathon-2/assets/117928541/68097d9a-dc9e-4b3f-90a7-1bf4cf77525c)
   ![Screenshot 2023-06-28 144318](https://github.com/ceeee33/Hackathon-2/assets/117928541/aa055d09-696d-4739-ae43-b1b1a4beffad)
   At this location, player choose to unlock the next location by using “Photo”. Since there is no this item in the player’s inventory list, the player cannot unlock the next location.
   ![Screenshot 2023-06-28 144415](https://github.com/ceeee33/Hackathon-2/assets/117928541/167cc8b1-419e-4b81-abcf-7383d9956bac)
   After that, the player is trying to collect this item again from this location and use it to unlock the next location.
   ![Screenshot 2023-06-28 144509](https://github.com/ceeee33/Hackathon-2/assets/117928541/361460a8-2a7b-4e9e-905e-7fdcb9be9a37)
   Congratulation! The last location is unlocked. No more location to explore.
The player has won the game and the progress will be save to file. Although the player already unlock all of the location, but he can choose to collect more items that can increase his score.

   After the progress has been saved, it will lead player to quit the game.
   ![Screenshot 2023-06-28 144929](https://github.com/ceeee33/Hackathon-2/assets/117928541/e2895452-cf71-4316-aa6c-15a172e5773a)
   Right now, the same player runs the game.If the player is an existing player, when the player start the game, after entering his name, a function call “loadProgress()” will try to find whether the file based on the player’s name exist or not.. The “I found your file!” appear at game interface shows that the game contains the data of the player. It will starts to load the previous game data and set up the previously game situation to the player.
   ![Screenshot 2023-06-28 144948](https://github.com/ceeee33/Hackathon-2/assets/117928541/b1d3c3c5-4728-44df-8b5b-fec8d39bdebb)
   Right now, the current location’s name and description will be shown at the game interface, representing the player’s previous last location. The player is trying to show his inventory. Luckily, the items collected by the player still remain in the inventory list.
   ![Screenshot 2023-06-28 145005](https://github.com/ceeee33/Hackathon-2/assets/117928541/7847c49d-fddc-4bc7-b6df-c2ae1f653c3b)
   The player chooses to quit the game. A line is executed to ask whether the player wants to quit the game or not. If the player chooses yes. The current data of the player and the condition for each location will be saved to the file. After the file is closed, the game will be quit.
   


8. **Link of game demo video**

