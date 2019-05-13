# lem_in

## Goal of lem_in project

Your ant colony must move from one point to another. But how to make it the shortest path possible? This project introduces you to graphing algorithms: your program will have to intelligently select the precise paths and movements that these ants must take.

## How to Run this
To run without visualisation:
```
./lem-in-hex < maps/middle_map.txt
```
To run visualisation:
```
./lem-in-hex < maps/middle_map.txt | ./visu-hex
```
## What is a map?
```
5           // The number of ants
hello 3 1   // Room named (hello) with X-Y coordonates
3 4 5       
##start     // The command Start (next room will be the start-room)
1 1 3
##end       // The command End (next room will be the end-room)
2 5 3
#stone      // The comment Stone (stone is in the next room, ants can't pass through it)
stone 2 5
1-2         // The link between two rooms
1-stone
stone-3
3-2
```
## The output of lem-in-hex
```
L[ant_num]-[room_name]
L1-2 L2-14                 // First step : ants number 1 and 2 (L1, L2) moving to room 2 and 14, other at the start-room
L1-6 L3-2 L2-15 L4-14
L1-5 L3-6 L5-2 L2-13 L4-15 L6-14
L3-5 L5-6 L7-2 L2-5 L4-13 L6-15 L8-14
L5-5 L7-6 L9-2 L4-5 L6-13 L8-15 L10-14
L7-5 L9-6 L11-2 L6-5 L8-13 L10-15 L12-14
L9-5 L11-6 L13-2 L8-5 L10-13 L12-15 L14-14
L11-5 L13-6 L15-2 L10-5 L12-13 L14-15
L13-5 L15-6 L12-5 L14-13
L15-5 L14-5                // Last step: now everyone at the end-room (5)
```
<img width="150" align="middle" src="https://i.imgur.com/Jc4fCTLm.png">
## Prerequisites to rebiuld programs
```
You have to install graphics libraries as in <a href="http://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/index.php">this instructions</a> to ~/Library/Frameworks/

SDL2        
SDL2_image  
SDL2_ttf    
`
