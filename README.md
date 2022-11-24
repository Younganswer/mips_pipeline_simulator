# MIPS_PIPELINE_SIMULATOR
### It shows how the "MIPS 5-staged pipeline" works.
<br/><br/><br/>

## Summary
#### 대충 5-staged 파이프라인의 장점, 처리 과정에 대한 개념적 설명
<br/><br/><br/>

## Platform
* Code Type: &nbsp;ARM64
* Platform: &nbsp;&nbsp;macOS 12.6 (21G115)
<br/><br/><br/><br/>

## Requirement
#### Raylib has to be pre-installed before running program
<br/>

### Brew (in macOS)
	$ brew install raylib
<br/><br/><br/>

## Install
	$ make
<br/><br/><br/><br/>

## Usage
### Default
	$ make run [INPUT_FILE="test.s"]
* Default &nbsp;*INPUT_FILE*&nbsp; is "test.s"
* Rule "run" execute following two commands
	* `./assembler/spim/spim -file test.s -dump`
	* `./mips_pipeline_simulator text.asm data.asm`
* Using in manual is not recommended
<br/>

### For custom File
	$ make run [INPUT_FILE="your_mips_file.s"]
* &nbsp;*INPUT_FILE*&nbsp; has to be ".s" file
<br/>

### Make support following commands
* `make (all)` : compile program
* `make run` : run program (includes make all)
* `make clean` : remove all object files
* `make fclean` : remove all object files and executable file
* `make re` : recompile program
<br/><br/><br/>

## How to use
* This program is made for showing how the "MIPS 5-staged pipeline" works.
* Your assembly code will be converted to machine code and then executed.
* You can see the process of execution in the data path of the window.
<br/>

### Interaction
| keyboard | action               |
| -------- | -------------------- |
| `←`      | move camera to left  |
| `→`      | move camera to right |
| `↑`      | move camera to up    |
| `↓`      | move camera to down  |
| `i`      | zoom in              |
| `o`      | zoom out             |
| `ESC ⎋`  | exit program         |

| mouse                       | action                         |
| --------------------------- | ------------------------------ |
| `click "next_cycle" button` | Execute next cycle of pipeline |
| --------------------------- | ------------------------------ |

<br/><br/><br/>

## Result
#### 결과 이미지 스크린샷, 동영상
<br/><br/><br/>

## Contact
### younganswer@kookmin.ac.kr