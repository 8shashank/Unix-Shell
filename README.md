Building instructions

1.    Change the current working directory to the project (folder “CS-281-Project”)
2.    Run cmake by typing “cmake .”
3.    Build the executable by typing “make”
4.    Run the executable by typing “./mainClass”

Using the program

•  Run a foreground process through the shell:
o    Type the name of the program followed by arguments to be passed in
o    Example: 
        echo “hello”
        
•  Run a process in the background
o    Type the name is the program followed by its arguments; include a “&” sign in any part of the command
o    Example: 
        sleep & 5s
        This should suspend execution in the background for 5 seconds while still allowing users to run foreground processes. After 5 seconds, the console should print out a message showing if the process has exited successfully with its pid.

•  Run a background process with auto recovery mode
o    Type the name of the program followed by its arguments, then followed by “- -autorecovery”
o    Example: 
        echo & “hi” - -autorecovery
       This should print out “hi” repeatedly followed by the message “Child x exited successfully”, where x is the child pid of the process.
       
o    Note that the running process can be killed by using the kill command followed by the pid of the process, in which case the process will not auto recover again.

•  Query the status of previously launched process
o    Type “ps” in the shell
o    This should prints out a table showing information on all the previously launched processes, including the process name, its status, and its exit status

•    Change current working directory
o    Type “cd” followed by the subdirectory

•    Exit the shell
o    Type “exit”