# Hackathon-2
1. Description
   
Realm of Enigmas is an immersive text-based adventure game that plunges you into a mysterious world filled with puzzles and secrets. As a daring adventurer, you find yourself trapped in a labyrinthine maze, each room brimming with enigmatic riddles and mind-bending challenges.

Your goal is to navigate through the maze, solving intricate puzzles and collecting valuable items that will aid you on your quest for freedom. Every room holds clues and hidden objects that must be deciphered and collected to unlock the next area.

Immerse yourself in a captivating narrative as you uncover the secrets of the maze and its cryptic inhabitants. Exercise your wit, logic, and intuition to overcome each challenge, using your collected items wisely to unlock doors, unveil hidden passages, and unravel the mysteries that await.

Will you prove yourself as a master puzzle solver and escape the Realm of Enigmas? Embark on this thrilling adventure and discover the secrets that lie within!

2. Features
   
Engaging Gameplay: Immerse yourself in a rich and immersive storyline, filled with intriguing characters, hidden clues, and challenging puzzles.
Exploration and Discovery: Traverse through beautifully crafted environments, each with its own unique atmosphere and enigmas waiting to be unraveled.
Mind-Bending Puzzles: Test your problem-solving skills with a variety of mind-bending puzzles, ranging from riddles and logic challenges to pattern recognition and hidden object quests.
Item Collection and Management: Gather a diverse array of items throughout your journey, each with its own special abilities and uses. Strategically manage your inventory to overcome obstacles and unlock new areas.

3. How to play
- Navigate through the game using text-based commands and choices presented to you (NORTH, SOUTH, EAST, WEST)
- Interact with the environment by examining objects, solving puzzles, and collecting items.
- Use your collected items strategically to overcome obstacles and unlock new areas.
- Pay attention to clues and hints provided throughout the game to progress and unravel the mysteries of the realm.
- EXAMINE, LOOK, TAKE, UNLOCK ... 

4. How object-oriented concepts were used in developing the game
   
Realm of Enigmas is developed using object-oriented concepts to enhance code organization, reusability, and maintainability. Classes such as Player, Location, Item, and Game are used to encapsulate related data and behavior, allowing for modular and structured code design. Polymorphism, and encapsulation principles are applied to model the game's entities and interactions, providing a flexible and extensible architecture.

6. Role of linked list
- Inventory Management: The linked list data structure can be used in the Player class to manage the player's inventory. Each item in the inventory can be represented as a node in the linked list, where each node contains a reference to the next item in the inventory. This allows for efficient insertion and traversal of the items in the inventory.
- Linked List of Items: The Item class can utilize a linked list to represent a collection of related items.
- Room Connections: The doubly linked list structure enables the Location class to establish connections between adjacent rooms. When creating the game map, each room's node can be connected to the previous and next rooms' nodes, creating a logical flow of room transitions.
- Flexibility in Navigation: The doubly linked list allows for flexibility in navigation. The player can move forward to the next room by following the next pointer, and they can also backtrack to the previous room by following the previous pointer. This allows for non-linear exploration of the game world, where the player can freely move between rooms they have visited.

6. Screenshot of the game
7. Link of game demo video
