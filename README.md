# 42Madrid - minitalk
The purpose of this project is to code a small data exchange program using UNIX signals. The client receives a string which is sent to the server and displayed on the standar output. The bonus part supports UNICODE characters and displays a message on the client once the server finish printing the string sent.

![LINUX](https://img.shields.io/badge/Linux-a?style=for-the-badge&logo=linux&color=grey)
![C](https://img.shields.io/badge/C-a?style=for-the-badge&logo=C&color=grey)
![Makefile](https://img.shields.io/badge/Makefile-a?style=for-the-badge&logo=monster&logoColor=orange&color=grey)

You can see the subject [**HERE**](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/minitalk_subject_en.pdf)

## Installing and running the project:

1- Clone this repository
	
	git clone https://github.com/MGuardia10/42cursus_minitalk.git
2- Navigate to the new directory and run `make`
	
	cd 42cursus_minitalk
   	make
    make bonus
3- `make clean` to remove the object files and work on a cleaner directory

	make clean
4- Run server and copy its PID to the client alongside the string you want to send.

	./server
	./client <SERVER_PID> <STRING_TO_PASS>
or

    ./server_bonus
    ./client_bonus <SERVER_PID> <STRING_TO_PASS>

## Compiling the Program
The minitalk program comes with a Makefile that includes the following rules:

- `all`: compiles the programs
- `re`: recompiles the programs
- `bonus`: compiles bonus files for the bonus features.
- `clean`: removes all object files
- `fclean`: removes all object files and client/server programs

## Resources:  
- [https://www.youtube.com/watch?v=83M5-NPDeWs](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- https://man7.org/linux/man-pages/man2/sigaction.2.html
- https://man7.org/linux/man-pages/man2/kill.2.html
- https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
- https://emojidb.org/terminal-emojis

## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/norm_en.pdf), the school's coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.
