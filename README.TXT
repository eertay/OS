Student ID: 260945126

OS used to develop the program: Mac
The OS Shell which has been built has been tested on mimi.cs.mcgill.ca

ErrorCode = 0 exits the program without any issues.
ErrorCode = -1 terminates the program due to an issue.

IMPORTANT NOTE: This code has been tested on mimi.cs.mcgill.ca as well as my own
computer, and works on vi files.

For non-vi files (e.g. the testfile.txt I have downloaded from MyCourses) code
does not work properly and doesn't output what it is supposed to when a file has
been fed directly to mysh (./mysh < testfile.txt). It does not recognise the
commands in that case, resulting in a series of "unknown comand"s. On the other
hand, when a $run testfile.txt command is run the code works with no problem.
However problem only occurs on non-vi files, and it has been consulted with
several TA's that our code will only be tested on vi files. The reason why it
doesn't work in that specific case is unclear to me as there seems to be no
anomaly I can detect in my code.
