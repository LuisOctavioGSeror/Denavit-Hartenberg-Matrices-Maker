# &emsp;&emsp;&emsp; Denavit-Hartenberg-Matrices-Maker
**&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;A simple C algorithm that calculate Denavit-Hartenberg Matrices**


## what is?
A simple C algorithm that calculate DH matrices based on the DH parameters input and recursively multiply the resulting matrices to generate the final matrice with all the information needed to know the position and other informations about the robotic arm.

## Requirements 
Absolutly nothing if you are a linux user
Some C IDE if you are a Windows user, and the math.h library

## How to run
 I never tested on windows... but if you are a linux user, after download the file just tipe in the terminal: gcc DH.c -o "exec_name" -lm
 where "exec_name" its the name you choose for you exec file, and -lm because of the math.h library 
