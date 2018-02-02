CC		= g++
OBJS	=	main.o List.o building.o office.o entrance.o floor.o elevator.o
CXXFLAGS =	-O2 -g -Wall
LIBS =
TARGET =	exc3.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
