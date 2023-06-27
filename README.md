# Hackathon-2
1. Description
   
Welcome to the captivating world of "Realm of Enigmas," an immersive text-based adventure game where you'll embark on a thrilling journey through a mysterious realm filled with secrets waiting to be unraveled. As a daring explorer, you'll find yourself immersed in a rich narrative that unfolds before you.

Your mission is to navigate through a series of captivating environments, each with its own unique challenges and enigmatic wonders. Engage with intriguing characters, uncover hidden clues, and make impactful choices that shape the outcome of your adventure.

Immerse yourself in a world of discovery as you explore the dark recesses of ancient caves, wander through enchanting forests with cascading waterfalls, dive into breathtaking underwater realms, and traverse the fabric of time through intricate tunnels.

Encounter mythical creatures, decipher cryptic symbols, and uncover long-forgotten artifacts that hold the key to unlocking the realm's deepest mysteries. Along your journey, you'll encounter allies and adversaries, each with their own motives and stories to share.

Embrace the immersive storytelling and let your imagination soar as you unravel the enigmas that permeate the "Realm of Enigmas." Your choices and actions will shape the course of your adventure, leading you closer to the truth that lies hidden within this captivating world.

Prepare to embark on a text-based adventure like no other, where the allure of the unknown beckons and the realm's secrets await your discovery. Are you ready to uncover the mysteries that lie within the "Realm of Enigmas"? The journey awaits!

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
