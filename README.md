# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals

## minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.

- This project is to create two executables: a server and a client.
- Client, will send message (a string) to the server using UNIX signals.
- Server, must correctly receive message using SIGUSR1 and SIGUSR2 signals (mandatory part) then send feedback to client(bonus part).

Don't print out the message character by charecter.

## Usage
1. Clone the repository.
2. Run `make` to compile the source files.
3. Run `./server` to start the server.
3. Run `./client` `Server PID` `"text to be send"`.
