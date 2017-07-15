CXX = g++					# compiler
CXXFLAGS = -g -std=c++11 -Wall -MMD	-pthread	# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

OBJECTS1 = Baccarat.o				# object files forming 1st executable
EXEC1 = Baccarat				# 1st executable name

OBJECTS2 = cards.o				# object files forming 2nd executable
OBJECTS3 = game.o
OBJECTS4 = player.o


OBJECTS = ${OBJECTS1} ${OBJECTS2} ${OBJECTS3} ${OBJECTS4}		# all object files
DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"
EXECS = ${EXEC1}			# all executables

########## Targets ##########

.PHONY : all clean				# not file names

all : ${EXECS}					# build all executables

${EXEC1} : ${OBJECTS1} ${OBJECTS2} ${OBJECTS3}  ${OBJECTS4}	# link step 1st executable
	${CXX} ${CXXFLAGS} $^ -o $@		# additional object files before $^

${OBJECTS} : ${MAKEFILE_NAME}			# OPTIONAL : changes to this file => recompile

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}

c :						# shortcut to 'clean'
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}