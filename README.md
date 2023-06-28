# Hackathon-2
1. Description
   
Welcome to the mesmerizing realm of "Realm of Enigmas," a captivating text-based adventure game that transports you to a world brimming with intrigue and secrets. Prepare yourself for a thrilling journey as you navigate through a series of immersive environments, each offering its own unique blend of challenges and enigmatic wonders.

Delve into the depths of ancient caves, where darkness conceals ancient riddles and hidden passages. Feel the mist on your face as you venture into a dark forest, with its enchanting waterfalls and whispers of forgotten secrets. Plunge into the depths of an underwater world, where vibrant marine life and hidden treasures await your discovery. Step into the realm of a time tunnel, where the boundaries of past, present, and future blur, presenting you with mind-bending conundrums. As you progress, exercise your wit, logic, and intuition to overcome the challenges that lie in your path. 

Prepare to immerse yourself in the captivating world of "Realm of Enigmas" as you embark on a solitary adventure of exploration, discovery, and self-discovery. Are you ready to step into the unknown and unravel the enigmas that await? The journey awaits, adventurer.

2. Features
- Save and Load Progress: A player can experience the convenience and continuity of the game by capturing his game data before quit the game. The game will preserve the name, score, inventory items, and current location of the player. When a player is ready to dive back into the adventure, he can load his progress to pick up where he left off, ensuring a reliable and uninterrupted gaming experience.
- Unique Player Names: Each player can have a distinct and exclusive name for this game. If a new player tries to set their name and it matches an existing player's name, they will be prompted to choose a different name. This ensures that every player has their own individual identity. 
- Item Collection and Management: Gather a diverse array of items throughout the journey, each with its own special abilities and uses. Strategically manage player's inventory to overcome obstacles and unlock new areas.
- Exploration and Discovery: Embark on a thrilling adventure as the player traverse through meticulously crafted environments that are teeming with mysteries to unravel. Explore dark caves, traverse dense forests, dive into the depths of underwater worlds, and venture through time-bending tunnels. Each location offers unique atmospheres and hidden secrets waiting to be discovered.
- Immersive Descriptions: A player can immersed themselves in vivid descriptions that paint a detailed picture of the realm's landscapes, characters, and objects. Engage his imagination as he visualize the scenes, bringing the game world to life in his mind.

3. How to play
- Before the game start, a brief storyline will be given to player.
- Navigate through the game using text-based commands and choices.
- Interact with the environment by examining location and collecting items.
- Use collected items strategically to unlock new areas.
- Pay attention to clues and hints provided throughout the game to progress and unravel the mysteries of the realm.
- Key in a valid number in the menu given to perform action.
- Action can be done by a player:
   - Examine: Show the description of the current location.
   - Show Inventory: Show the item(s) collected by the player.
   - Collect Item: Collect the item specified by the player.
   - Move: Player can choose to move to next location, previous location or remain at current location.
   - Unlock the Next Location: Player must use the right item to unlock the next location.
   - Quit: Player can choose to quit the game as he wishes. The current progress of user will be saved automatically.
- If the last location is unlocked, tha player has won the game and overcome the challenges sucessfully!

4. How object-oriented concepts were used in developing the game
   
Realm of Enigmas is developed using object-oriented concepts to enhance code organization, reusability, and maintainability. Classes such as Player, Location, Item, and Game are used to encapsulate related data and behavior, allowing for modular and structured code design. Polymorphism, and encapsulation principles are applied to model the game's entities and interactions, providing a flexible and extensible architecture.

6. Role of linked list
- Inventory Management: The linked list data structure can be used in the Player class to manage the player's inventory. Each item in the inventory can be represented as a node in the linked list, where each node contains a reference to the next item in the inventory. This allows for efficient insertion and traversal of the items in the inventory.
- Linked List of Items: The Item class can utilize a linked list to represent a collection of related items.
- Room Connections: The doubly linked list structure enables the Location class to establish connections between adjacent rooms. When creating the game map, each room's node can be connected to the previous and next rooms' nodes, creating a logical flow of room transitions.
- Flexibility in Navigation: The doubly linked list allows for flexibility in navigation. The player can move forward to the next room by following the next pointer, and they can also backtrack to the previous room by following the previous pointer. This allows for non-linear exploration of the game world, where the player can freely move between rooms they have visited.

6. Screenshot of the game
7. Link of game demo video
