OBJ = main.o field.o graphics.o menu.o
CFLAGS = -Wall
LIBS = -lSDL -lSDL_image -lSDL_ttf

all: bin

bin: $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o bin $(LIBS)

%.o : %.c
	g++ $(CFLAGS) -c $<

clean:
	rm bin $(OBJ)
