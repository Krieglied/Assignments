# **DIRTY OLD RAT**

Project members: Smith, Krieser, Graham

This project was a colloborative effort to build a Remote Access Terminal (RAT), that would have two components.  

The first, a server program, would accept an IP address to connect to, send a message to establish connection, and be able to send commands to/receive input from the client.

The second, the client, would have two components itself.  An overhead program would run, in our example a game, which to a user on the machine would make the application seem more legitimate.  The user would be able to interact with the overhead game without interfering with the underlying program.  The unerlying program would be the client itself, able to establish a listening socket, connect to a server, accept commands, process what to run based on those commands, and return an output.

At the this stage of the project (and at time of the demo), the server/client was able to connect, and the commands that were able to be run on the client were: dir, ipconfig /all, systeminfo, tasklist, and a custom provided by the server.  Issues that existed at the time of demo were: the client and server would desync after one command sent, so that the server would not get the appropriate result back until the next command was run; some commands that were planned had not been implemented (screenshot and transfer file had been proposed); traffic was not encrypted; the code was not encoded.
