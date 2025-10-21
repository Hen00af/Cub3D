# 3D GAME with ray casting in C

this is a project thst is 3D game in C.

<p align="center">
  <img src="https://github.com/Hen00af/Cub3D/blob/main/doc/gifs/Screencast%20from%2010-22-2025%2008-03-55%20AM%20(1).gif" alt="Gameplay Demo" width="600">
</p>

## Skills 🔥
mathmatics (vector)
C
ray-casting
gaming

## How to play
#### 1️⃣ Build Dependencies
```sh
git clone https://github.com/42paris/minilibx-linux.git
cd minilibx-linux && make
cd ..
make
```

### 2️⃣ Run the Game
```sh
./cub3D maps/validmaps/{map_name}.cub
```

Now you can explore the map in 3D view using keyboard controls.
then you can play this game.

| Key           | Action                                 |
| ------------- | -------------------------------------- |
| W / A / S / D | Move forward / left / backward / right |
| ← / →         | Rotate view                            |
| ESC           | Exit the game                          |

## 🧩 What is Ray Casting?

Ray casting is a technique to simulate 3D perspective in a 2D world.
The world map is a 2D grid.
The player’s viewpoint casts rays in the direction they are facing.
Each ray travels until it hits a wall.
The distance to the wall determines the height of the vertical line drawn on screen — creating the illusion of depth.
This method allows 3D rendering without full 3D geometry, making it efficient and simple enough to implement in pure C.
Example visualization:
```
|Top-down map view (2D)          Screen view (3D)      |
|     P → → → → ▒▒▒▒▒▒▒▒▒▒        ███████████          |
|     ↑         ▒▒▒▒▒▒▒▒▒▒        ███████████          |
|     Walls     ▒▒▒▒▒▒▒▒▒▒        ███████████          |
|                                                      |
```
## structure
```
cub3D/
├── src/
│   ├── parse/        # Parse .cub map files
│   ├── game/         # Player logic, ray-casting, rendering
│   ├── utils/        # Math and helper functions
│   └── main.c
├── includes/
│   └── cub3d.h
|
├── maps/
│   └── validmaps/
└── Makefile

```
