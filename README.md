# Hackathon-2
1. Description
   
Welcome to the mesmerizing realm of "Realm of Enigmas," a captivating text-based adventure game that transports you to a world brimming with intrigue and secrets. Prepare yourself for a thrilling journey as you navigate through a series of immersive environments, each offering its own unique blend of challenges and enigmatic wonders.

Delve into the depths of ancient caves, where darkness conceals ancient riddles and hidden passages. Feel the mist on your face as you venture into a dark forest, with its enchanting waterfalls and whispers of forgotten secrets. Plunge into the depths of an underwater world, where vibrant marine life and hidden treasures await your discovery. Step into the realm of a time tunnel, where the boundaries of past, present, and future blur, presenting you with mind-bending conundrums.

In this enthralling adventure, you'll encounter mythical creatures, engage in thought-provoking conversations with enigmatic characters, and uncover ancient artifacts that hold the key to unraveling the mysteries that shroud the realm. Your journey will be guided by a captivating narrative, inviting you to delve deeper into the realm's rich lore and forge your own path through a series of choices and actions. As you progress, exercise your wit, logic, and intuition to overcome the challenges that lie in your path. 

Prepare to immerse yourself in the captivating world of "Realm of Enigmas" as you embark on a solitary adventure of exploration, discovery, and self-discovery. The fate of the realm rests in your hands, and only through your tenacity and astuteness will you unveil the secrets that lie within. Are you ready to step into the unknown and unravel the enigmas that await? The journey awaits, adventurer.

2. Features
   
- Engaging Gameplay: Immerse yourself in a rich and immersive storyline, filled with intriguing characters, hidden clues, and captivating challenges.
- Exploration and Discovery: Embark on a thrilling adventure as you traverse through meticulously crafted environments that are teeming with mysteries to unravel. Explore dark caves, traverse dense forests, dive into the depths of underwater worlds, and venture through time-bending tunnels. Each location offers unique atmospheres and hidden secrets waiting to be discovered.
- Immersive Descriptions: Immerse yourself in vivid descriptions that paint a detailed picture of the realm's landscapes, characters, and objects. Engage your imagination as you visualize the scenes, bringing the game world to life in your mind.
- Item Collection and Management: Gather a diverse array of items throughout your journey, each with its own special abilities and uses. Strategically manage your inventory to overcome obstacles and unlock new areas.

3. How to play
- Navigate through the game using text-based commands and choices presented to you 
- Interact with the environment by examining location and collecting items.
- Use your collected items strategically to overcome obstacles and unlock new areas.
- Pay attention to clues and hints provided throughout the game to progress and unravel the mysteries of the realm.
- EXAMINE, TAKE, UNLOCK ... 

4. How object-oriented concepts were used in developing the game
   
Realm of Enigmas is developed using object-oriented concepts to enhance code organization, reusability, and maintainability. Classes such as Player, Location, Item, and Game are used to encapsulate related data and behavior, allowing for modular and structured code design. Polymorphism, and encapsulation principles are applied to model the game's entities and interactions, providing a flexible and extensible architecture.

6. Role of linked list
- Inventory Management: The linked list data structure can be used in the Player class to manage the player's inventory. Each item in the inventory can be represented as a node in the linked list, where each node contains a reference to the next item in the inventory. This allows for efficient insertion and traversal of the items in the inventory.
- Linked List of Items: The Item class can utilize a linked list to represent a collection of related items.
- Room Connections: The doubly linked list structure enables the Location class to establish connections between adjacent rooms. When creating the game map, each room's node can be connected to the previous and next rooms' nodes, creating a logical flow of room transitions.
- Flexibility in Navigation: The doubly linked list allows for flexibility in navigation. The player can move forward to the next room by following the next pointer, and they can also backtrack to the previous room by following the previous pointer. This allows for non-linear exploration of the game world, where the player can freely move between rooms they have visited.

6. Screenshot of the game
7. Link of game demo video
