OBJ = main.o field.o graphics.o
CFLAGS = -Wall
POSTFLAGS = -lSDL -lSDL_image -lSDL_ttf

all: bin

bin: $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o bin $(POSTFLAGS)

%.o : %.c
	g++ $(CFLAGS) -c $<

clean:
	rm bin $(OBJ)
