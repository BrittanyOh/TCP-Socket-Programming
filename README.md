# TCP-Socket-Programming
## CSCI 452/553: Network and Web Programming
## TCP Socket Programming Project

<br> • All development must be done with Github. Specifically, there must be at least one commit
for every five (or fewer) lines of code (excluding empty lines and lines with only comment).
With each commit, the log must explain the purpose of the added/changed code. The Github
repo must remain private before the deadline and public after the deadline.

<br> • Submit a single plain text file named repo.txt at
http://hucs.dynu.net/lij/courses/submit_hw.html
The text file should include only the URL of your Github repo.

## Grading
<br> • All or significant portion of the points will be deducted at the discretion of the instructor if any
of the above requirements are not met. Plagiarism will always lead to zero credit for this
assignment and potentially for the whole course. No credits will be given if the repo is
modified after the deadline. Other than that, the points will be given based on the correctness.

### In this project, you will develop two network programs in the C/C++ one for client and one for
server. You may base your program on the echo examples,
The client program reads input from user and performs the following actions repeatedly until
directed to exit:

<br> • If the user enters 's', it will ask user to enter a string. It then sends "CAP\nxxx\n" to the server
(where "xxx" is the string entered by the user, which could input any character except "\n"),
and receives a message from the server and display the message on the screen.

<br> • If the user enters 'f', it will ask user to enter a string. It then sends "FILE\nxxx\n" to the server
(where "xxx" is the string entered by the user), and receives data from the server and saves
the data to a file named "xxx" in the directory where the client program is in.

<br> • If the user enters 'q', it will exit.

<br> • If the user enters anything else, it will ignore.
The server program performs the following actions:

<br> • If "CAP\nxxx\n" is received from the client, it capitalizes the received string and sends
"###\nCCC" back to the client, where "###" is the number of characters in the capitalized
string and "CCC" is the capitalized string. If a character has no upper case, such as a comma, 
the character is sent back as it is.

<br> • If "FILE\nxxx\n" is received from the client, it reads the content from the file named "xxx"
from the directory where the server program is in and sends "###\nDDD" back to the client,
where "###" is the number of bytes of the file and "DDD" is the content of the file. Note that
the file may contain binary data such as images. If no file of the name "xxx" exists, it sends
"###\nNOT FOUND" back to the client, where "###" is the number of characters in the string
of "NOT FOUND".

<br> ***(For graduate students only) The server must support multiple connections with the client
simultaneously.
The client should be invoked by the following command:
<client> <server IP> <server port>
Where <client> is the name of the client executable file name, <server IP> is the IP address
of the server, <server port> is the TCP port of the server.
The server should be invoked by the following command:
<server> <port>
Where <server> is the name of the server executable file name, <port> is the port the server
listens to. ***
