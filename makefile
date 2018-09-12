# The top rule is executed by default
all: x
# # Other rules are invoked as necessary
# # Rule for creating the hello executable
x: project0.c
	gcc project0.c -o project0
