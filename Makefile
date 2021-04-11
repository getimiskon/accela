# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Target
TARGET = assistant

all: $(TARGET)

$(TARGET): $(TARGET).c
	sed -i '5 s/0/1/g' $(TARGET).c
	sed -i '6 s/0/1/g' $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)

# Disable the voice output
no-voice:
	sed -i '5 s/1/0/g' $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

# Disable the development output
no-dev:
	sed -i '6 s/1/0/g' $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
