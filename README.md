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

### Brew (in MacOS)
	$ brew install raylib
<br/><br/><br/>

## Install
	$ make
<br/><br/><br/><br/>

## Usage
#### Default
	$ make run [INPUT_FILE=test.s]
* Default input file is "test.s"
* Rule "run" execute following two commands
	* `./assembler/spim/spim -file test.s -dump`
	* `./mips_pipeline_simulator test.asm data.asm`
* Using in manual is not recommended
<br/>

#### For custom File
	$ make run [INPUT_FILE="your_mips_file.s"]
<br/><br/><br/>

## Result
#### 결과 이미지 스크린샷, 동영상
<br/><br/><br/>

## Contact
### younganswer@kookmin.ac.kr