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

![class diagram](https://github.com/ceeee33/Hackathon-2/assets/117928541/ec6838e7-2d87-45b9-bbfe-68347b8839f4)


5. **Role of linked list**
   - **Linked List of Items**: The Item class can utilise a linked list to represent a collection of related items.
   - **Inventory Management**: The singly linked list data structure can be used in the Player class to manage the player's inventory. Each item in the inventory can be represented as a node in the linked list, where each node contains details of the items and a reference to the next item in the inventory. This allows for efficient insertion and traversal of the items in the inventory. In addition, this linked list is used to store and load the details for each node when processing with file.
   - **Item Left for Each Location**:  The singly linked list data structure can be used in the Player class to manage the items left in each location, where each item represents a node in the linked list. Append, remove and search item actions are performed for this linked list. Besides, linked lists are also used to store the information of each node in a file when the player quits the game.
   - **Locations Connections**: The doubly linked list structure enables the Location class to establish connections between adjacent rooms. When creating the game map, each room's node can be connected to the previous and next rooms' nodes, creating a logical flow of room transitions. The player can move forward to the next room by following the next pointer, and they can also backtrack to the previous room by following the previous pointer. This allows for non-linear exploration of the game world, where the player can freely move between rooms they have visited.


6. **Screenshot of the game**
   ![Screenshot 2023-06-28 143225](https://github.com/ceeee33/Hackathon-2/assets/117928541/d12e9c56-50ce-481e-a28d-03ebbf346b59)
   Interface when player enter the game "Realm of Enigmas"
   Require player to set a nickname for the name. For this figure, the player sets his name as "abc".

   ![Screenshot 2023-06-28 143301](https://github.com/ceeee33/Hackathon-2/assets/117928541/9dff2131-822d-4332-8d2e-f799e8a6b794)
   The game has started.
   After the player enters the first location of the game. A description about the location is given to the player and the player is required to find the clues and hints based on the description given.
   For this figure, the action chosen by the player is examined. So, it will shows the description for the current location.

   
   ![Screenshot 2023-06-28 143323](https://github.com/ceeee33/Hackathon-2/assets/117928541/a7e07d9d-fccc-41b6-b187-bb4712860bab)
   The examine action is called out by the user to know about the current location and its description in case the player has forgetten which location he/she at.
   
   ![Screenshot 2023-06-28 143418](https://github.com/ceeee33/Hackathon-2/assets/117928541/654761d3-5c83-4030-8985-3fd387bd31f2)
   In this picture, the player has called out the show inventory action to check the items that he/she has collected previously. Then, the player called out collect items action to collect the item that they felt it is neccessary to unlock the location. After they collected the item, the program will shows their current score and the successful status of the collected items.
   
   ![Screenshot 2023-06-28 143448](https://github.com/ceeee33/Hackathon-2/assets/117928541/0ae8c0e9-07c2-4213-8f35-d843a3c73015)
   After that, the player collect another item then he called out show inventory items to check the items and description to know more about these items. 
   
   ![Screenshot 2023-06-28 143529](https://github.com/ceeee33/Hackathon-2/assets/117928541/ad32664d-c3a9-4d58-9fee-d05ba66190df)
   The player wished to perform move action, however, he failed to do so as he does not fulfilled the condition required.
   
   ![Screenshot 2023-06-28 143628](https://github.com/ceeee33/Hackathon-2/assets/117928541/5b0b0fc9-0332-41c4-831e-056f30203952)

   The player is using the items in his inventory to unlock the next location one by one. Fortunately, one of the items that he had collected is the key item. So, he is able to unlock the next location. This program will automatically move the player to the next room once the player successfully unlocked the next location.

   ![Screenshot 2023-06-28 143705](https://github.com/ceeee33/Hackathon-2/assets/117928541/f69e9f76-c7bb-44f2-9a6e-4881ad9d0338)

   So, the name and description for the next location had given once they entered this location

   ![Screenshot 2023-06-28 143859](https://github.com/ceeee33/Hackathon-2/assets/117928541/6b51c888-d3e3-4aad-bd3f-18f99d3cb9b7)

   The player is trying to collect the item that he feels is important.
   
   ![Screenshot 2023-06-28 143925](https://github.com/ceeee33/Hackathon-2/assets/117928541/13f4a026-bc0e-412b-ad01-e48d303d59c9)

   Then, the player uses one of the items that he collected in the second location to unlock the third location and the details of the next location is given.

   ![Screenshot 2023-06-28 144018](https://github.com/ceeee33/Hackathon-2/assets/117928541/5048b6da-67ef-48fd-b96c-248d254a14f2)

   The player is moving to the next room

   ![Screenshot 2023-06-28 144112](https://github.com/ceeee33/Hackathon-2/assets/117928541/cc1c23fc-93cc-49bb-a1bd-3f143717ae1b)

   Now, the player wants to perform a move action.

   ![Screenshot 2023-06-28 144138](https://github.com/ceeee33/Hackathon-2/assets/117928541/e04401f5-a014-435e-bb78-b07a12f3f393)

  The player chooses to move to the previous location and it works. 

   ![Screenshot 2023-06-28 144203](https://github.com/ceeee33/Hackathon-2/assets/117928541/a318a361-a5d8-4af0-815d-5c211699fbe7)

   The player then wishes to move to the next location. Since the next location, he had unlocked previously, thus he is able to move to the next location.
   
   ![Screenshot 2023-06-28 144318](https://github.com/ceeee33/Hackathon-2/assets/117928541/e68e030a-1e9e-4e6e-b42e-6ebcb671fa62)

   At this location, player choose to unlock the next location by using “Photo”. Since there is no this item in the player’s inventory list, the player cannot unlock the next location.
   
  
   ![Screenshot 2023-06-28 144415](https://github.com/ceeee33/Hackathon-2/assets/117928541/ff3d9e3b-6dbe-47c1-be59-8ba46615ff23)
    After that, the player is trying to collect this item again from this location and use it to unlock the next location.
   Congratulation! The last location is unlocked. No more locations to explore.

   ![Screenshot 2023-06-28 144509](https://github.com/ceeee33/Hackathon-2/assets/117928541/2ab6f55b-b20a-4dac-a5ed-81a4cb98acac)

   The player has won the game and the progress will be saved to a file based on the player's name. Although the player already unlocks all of the location, but locationshoose to collect more items that can increase his score.

   After the progress has been saved, it will lead the player to quit the game.
   
   ![Screenshot 2023-06-28 144929](https://github.com/ceeee33/Hackathon-2/assets/117928541/d3f43d28-1941-4cdc-bd34-65ba25b334a7)

   Right now, the same player runs the game. If the player is an existing player, when the player starts the game, after entering his name, a function called “loadProgress()” will try to find whether the file based on the player’s name exists or not. The “I found your file!” appear at the game interface shows that the game contains the data of the player. It will start to load the previous game data and set up the previous game situation for the player.
   
   ![Screenshot 2023-06-28 144948](https://github.com/ceeee33/Hackathon-2/assets/117928541/28a7a9af-bf2d-4b25-ba13-ef635cdf967d)

   Right now, the current location’s name and description will be shown at the game interface, representing the player’s previous last location. The player is trying to show his inventory. Luckily, the items collected by the player remain in the inventory list.
   
   
   ![Screenshot 2023-06-28 145005](https://github.com/ceeee33/Hackathon-2/assets/117928541/0749e084-f760-4e3d-a9b6-454cb6cb2899)

   The player chooses to quit the game. A line is executed to ask whether the player wants to quit the game or not. If the player chooses yes. The current data of the player and the condition for each location will be saved to the file. After the file is closed, the game will be quit.
   


8. **Link of game demo video**
   https://youtu.be/GdNT-DGYlwI
