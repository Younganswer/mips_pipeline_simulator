## Description of source code

## GUI(Raylib)
### Graphic User Interface is implemented by Raylib.
### Sources are in following directory.
* `srcs/button`
* `srcs/camera`
* `srcs/render`
* `srcs/shape`
<br/>

#### Button
* `button.hpp`: Button class header
* `button.cpp`: Button class
* button texture is in `assets` directory
```
GetMousePosition(void)
=> Get mouse position

CheckCollisionPointRec(Vector2 pointer, Rectangle rec)
=> Check collision between mouse and button

IsMouseButtonPressed(int button)
=> Check mouse button is pressed

IsMouseButtonReleased(int button)
=> Check mouse button is released
```
<br/>

#### Camera
* `camera.hpp`: Camera class header
* `camera.cpp`: Camera class

<br/><br/><br/>

## Background