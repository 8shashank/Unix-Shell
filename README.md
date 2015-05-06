#Building instructions

1. Change the current working directory to the project folder
2. Run cmake by typing “cmake .”
3. Build the executable by typing “make”
4. Run the executable by typing “./mainClass”

#Using the program

1. Run a foreground process through the shell:
  * Type the name of the program followed by arguments to be passed in
  * Example: 
    * echo “hello”
        
2. Run a process in the background
  * Type the name is the program followed by its arguments; include a “&” sign in any part of the command
  * Example: 
    * sleep & 5s
This should suspend execution in the background for 5 seconds while still allowing users to run foreground processes. After 5 seconds, the console should print out a message showing if the process has exited successfully with its pid.

3. Run a background process with auto recovery mode
  * Type the name of the program followed by its arguments, then followed by “- -autorecovery”
  * Example: 
    * echo & “hi” - -autorecovery
In auto recovery mode, the program restarts continuously unless killed by SIGINT or SIGSEGV.

4. Query the status of previously launched process
  * Type “ps” in the shell
This prints out a table showing information on all the previously launched processes, including the process name, its status, and its exit status.

5. Change current working directory
  * Type “cd” followed by the subdirectory

6. Exit the shell
  * Type “exit”
