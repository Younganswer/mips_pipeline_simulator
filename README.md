# MIPS_PIPELINE_SIMULATOR
### It shows how the "MIPS 5-staged pipeline" works.
<br/><br/><br/>

## Summary
* This program is made for showing how the "MIPS 5-staged pipeline" works.
* Your assembly code will be converted to machine code and then executed.
* You can see the process of execution in the data path of the window.
<br/><br/><br/>

## Platform
* Code Type: &nbsp;ARM64
* Platform: &nbsp;&nbsp;macOS 12.6 (21G115)
<br/><br/><br/><br/>

## Requirement
### Raylib
[Link to raylib (Github)](https://github.com/raysan5/raylib)
* checkout following link to install raylib
* You can find a few ways to install raylib
#### OSX
https://github.com/raysan5/raylib/wiki/Working-on-macOS
#### Linux
https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux
<br/><br/><br/>

### Spim
[Link to spim (Sourceforge)](https://sourceforge.net/p/spimsimulator/code/HEAD/tree/)
* You need to install flex and bison before installing spim
#### OSX
	$ brew install flex bison
#### Linux
    $ sudo apt-get -y install flex bison
<br/><br/><br/>

## Install
	$ make (all) [SIZE_FACTOR=size_factor]
* *SIZE_FACTOR*: size factor of the window (default: 8.0)
	* Only 7, 8, and 9 are supported for &nbsp;*SIZE_FACTOR*
	* If you want to resize the simulator, you have to execute
		* `$ make re SIZE_FACTOR=other_value`
<br/><br/><br/><br/>

## How to run
### Default
	$ make run [INPUT_FILE="test.s"] [SIZE_FACTOR=size_factor]
* Default &nbsp;*INPUT_FILE*&nbsp; is "test.s"
* Rule "run" executes following two commands
	* `cd ./libs/assembler/spim; ./spim -file ../../../test.s -dump; cd ../../../;`
	* `./mips_pipeline_simulator ./libs/assembler/spim/text.asm ./libs/assembler/spim/data.asm`
* Using in manual is not recommended
<br/>

### For custom File
	$ make run [INPUT_FILE="your_assembly_file.s"]
* &nbsp;*INPUT_FILE*&nbsp; has to be ".s" file
<br/>

### Make support following commands
* `make (all)` : compile program
* `make run` : run program (includes make all)
* `make clean` : remove all object files
* `make fclean` : remove all object files and executable file
* `make re` : recompile program
<br/><br/><br/>

## Usage
### Keyboard Interaction
| Key                         | Action                            |
| --------------------------- | --------------------------------- |
| `←`                         | Move camera to left               |
| `→`                         | Move camera to right              |
| `↑`                         | Move camera to up                 |
| `↓`                         | Move camera to down               |
| `i/o`                       | Zoom in / Zoom out                |
| `r`                         | Reset camera                      |
| `d`                         | Open/Close User Data Segment Page |
| `[/] (in Data Segment Page)`| Move to prev/next page            |
| `ESC ⎋`                     | Exit program                      |

### Mouse Interaction
| Mouse                       | Action                         |
| --------------------------- | ------------------------------ |
| `Click "next_cycle" button` | Execute next cycle of pipeline |

<br/><br/><br/>

## Result
https://user-images.githubusercontent.com/55086725/208013442-c2919d94-6647-498c-b3a8-877e4b3be5f4.mp4

<br/><br/><br/>

## Description of source code
[In Markdown](./srcs/README.md)

[Link to Youtube]()
<br/><br/><br/>

## Contact
### younganswer@kookmin.ac.kr
### akdlwofyd@kookmin.ac.kr
