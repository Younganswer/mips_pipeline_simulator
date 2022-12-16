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
CheckCollisionPointRec(Vector2 pointer, Rectangle rec)
IsMouseButtonPressed(int button)
IsMouseButtonReleased(int button)
```
<br/>

#### Camera
* `camera.hpp`: Camera header
* `camera.cpp`: Camera
```
IsKeyDown(int key)
IsKeyPressed(int key)
BeginMode2D(Camera2D camera)
EndMode2D(void)
=> Sources between BeginMode2D and EndMode2D, don't follow camera
```

#### Render
**Rendering all of the contents of Mips-pipeline-simulator**
* `render.hpp`: Render header
* `render.cpp`: Render
	* `render_camera.cpp`: Render camera
	* `render_content.cpp`: Render whole content
	* `render_data.cpp`: Render register, user data segment
	* `render_stages.cpp`: Render stages
	* `render_pipeline.cpp`: Render pipeline
	* `render_units.cpp`: Render hazard unit, forwarding unit, control unit, jump unit
```
DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color)
DrawRectangleLinesEx(Rectangle rec, int lineThick, Color color)
DrawRectangle(int posX, int posY, int width, int height, Color color)
DrawCircle(int posX, int posY, int radius, Color color)
```

#### Shape
**Frequently used shapes**
* `shape.hpp`: Shape header
* `shape.cpp`: Shape
	* `draw_arrow.cpp`: Draw arrow
	* `draw_circle_lines_ex.cpp`: Draw circle lines
	* `draw_circle_sector_ex.cpp`: Draw circle sector
	* `draw_trapazoid.cpp`: Draw trapazoid
```
draw_left_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
draw_right_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
draw_up_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
draw_down_arrow(float startPosX, float startPosY, float endPosX, float endPosY, Color color);
draw_circle_lines_ex(float centerX, float centerY, float radius, float thick, Color color);
draw_circle_sector_lines_ex(float centerX, float centerY, float radius, float startAngle, float endAngle, int segments, float thick, Color color);
draw_trapezoid(float posX, float posY, float size);

```

<br/><br/><br/>

## Background

### Sources are in follwing directory.
* `srcs/info`
* `srcs/instruction`
* `srcs/pipelines`
* `srcs/stages`
* `srcs/forward`
* `srcs/hazard`
* `srcs/update`

#### Info
* `info.hpp`: Info header
* `info.cpp`: Includes all values for operating this program
  * Instructions
  * Hazard Unit
  * Forward Unit
  * IF/ID pipeline
  * ID/EX pipeline
  * EX/MEM pipeline
  * MEM/WB pipeline
  * Register values
  * Data segment values
#### Instruction
* `instruction.hpp`: Instruction header
* `instruction.cpp`: Get instruction and split by field
  * opcode
  * rd
  * rs
  * rt
  * function
  * shift amount
  * immediate

* `pipelines.hpp`: Pipelines header
* `pipelines.cpp`: Pipelines
  * IF/ID pipeline
  * ID/EX pipeline
  * EX/MEM pipeline
  * MEM/WB pipeline

* `stages.hpp`: Stages header
* `stages.cpp`: Stages
  * IF stage
  * ID stage
  * EX stage
  * MEM stage
  * WB stage

* `forward.hpp`: Forwarding unit header
* `forward.cpp`: Forwarding unit
  * Forward A
  * Forward B
  * Forward C
  * Forward D

* `hazard.hpp`: Hazard unit header
* `hazard.cpp`: Hazard unit
  * IF flush
  * lw hazard
  * branch hazard

* `update.cpp`: Update stages
  * Update WB stage
    * check control signal
    * send data to decode stage if needed
  * Update MEM stage
    * check control signal
    * get memory data from data segment if MemRead is true
    * write data segment if MemWrite is true 
  * Update EX stage
    * check control signal
    * get data 1 from ID/EX pipeline and forwarding unit
    * get data 2 from ID/EX pipeline and forwarding unit
    * operate data 1 and data 2 with ALU control
  * Update ID stage
    * get instruction from IFID Pipeline
    * get data from execute stage and memory stage if hazard is detected
    * set control signal
    * detect lw hazard and branch hazard
  * Update IF stage
    * get instruction from instruction memory