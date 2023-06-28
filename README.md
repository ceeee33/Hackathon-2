# Hackathon-2
1. **Description**
Welcome to the mesmerising realm of "Realm of Enigmas," a captivating text-based adventure game that transports you to a world brimming with intrigue and secrets. Prepare yourself for a thrilling journey as you navigate through a series of immersive environments, each offering its own unique blend of challenges and enigmatic wonders.

Delve into the depths of ancient caves, where darkness conceals ancient riddles and hidden passages. Feel the mist on your face as you venture into a dark forest, with its enchanting waterfalls and whispers of forgotten secrets. Plunge into the depths of an underwater world, where vibrant marine life and hidden treasures await your discovery. Step into the realm of a time tunnel, where the boundaries of past, present, and future blur, presenting you with mind-bending conundrums. As you progress, exercise your wit, logic, and intuition to overcome the challenges that lie in your path.

Prepare to immerse yourself in the captivating world of "Realm of Enigmas" as you embark on a solitary adventure of exploration, discovery, and self-discovery. Are you ready to step into the unknown and unravel the enigmas that await? The journey awaits, adventurer.


2. **Features of the game**
- **Save and Load Progress**: A player can experience the convenience and continuity of the game by capturing his game data before quit the game. The game will preserve the name, score, inventory items, and current location of the player. When a player is ready to dive back into the adventure, he can load his progress to pick up where he left off, ensuring a reliable and uninterrupted gaming experience.
- **Unique Player Names**: Each player can have a distinct and exclusive name for this game. If a new player tries to set their name and it matches an existing player's name, they will be prompted to choose a different name. This ensures that every player has their own individual identity.
- Item Collection and Management: Gather a diverse array of items throughout the journey, each with its own special abilities and uses. Strategically manage the player's inventory to overcome obstacles and unlock new areas.
- **Immersive Descriptions**: A player can immerse themselves in vivid descriptions that paint a detailed picture of the realm's landscapes, characters, and objects. Engage his imagination as he visualises the scenes, bringing the game world to life in his mind.
- **An Interesting Theme & Visual Style**: When a player enters a new location, one of the items in that location will be shown to the player.  It can serve as a clue for the item able to be collected by a player. 
Validation: This game has a strong validation especially when a player wants to collect an item or unlock the next location. It will show an error message when the player input the wrong item.


3. **How to play the game**
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


4. **How object-oriented concepts were used in developing the game**
Realm of Enigmas is developed using object-oriented concepts to enhance code organisation, reusability, and maintainability. Classes such as Player, Location, Item, and Game are used to encapsulate related data and behaviour, allowing for modular and structured code design. Polymorphism, and encapsulation principles are applied to model the game's entities and interactions, providing a flexible and extensible architecture. 

There are 4 classes in our project. The class names are “Item.h”, “Player.h”, “Location.h” and “Main.h”. “Player.h” and “Location.h” composite to “Item.h” since both player and location contain items. “Player.h” requires “Item.h” to set inventory list while “Location.h” requires “Item.h” to set items that can be collected by the player. On the other hand“Game.h” composites to “Player.h” and “Location.h” because a game requires a player and locations to set up.

The relationship between each class is shown in the UML diagram below.:

5. **Role of linked list**
- **Linked List of Items**: The Item class can utilise a linked list to represent a collection of related items.
- **Inventory Management**: The singly linked list data structure can be used in the Player class to manage the player's inventory. Each item in the inventory can be represented as a node in the linked list, where each node contains details of the items and a reference to the next item in the inventory. This allows for efficient insertion and traversal of the items in the inventory. In addition, this linked list is used to store and load the details for each node when processing with file.
- **Item Left for Each Location**:  The singly linked list data structure can be used in the Player class to manage the items left in each location, where each item represents a node in the linked list. Append, remove and search item actions are performed for this linked list. Besides, linked lists are also used to store the information of each node in a file when the player quits the game.
- **Locations Connections**: The doubly linked list structure enables the Location class to establish connections between adjacent rooms. When creating the game map, each room's node can be connected to the previous and next rooms' nodes, creating a logical flow of room transitions. The player can move forward to the next room by following the next pointer, and they can also backtrack to the previous room by following the previous pointer. This allows for non-linear exploration of the game world, where the player can freely move between rooms they have visited.


6. **Screenshot of the game**


7. **Link of game demo video**

