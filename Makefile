# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Target
TARGET = assistant

all: $(TARGET)

$(TARGET): src/core/$(TARGET).c
	sed -i '5 s/0/1/g' src/core/$(TARGET).c
	sed -i '6 s/0/1/g' src/core/$(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) src/core/$(TARGET).c

clean:
	$(RM) $(TARGET)

# Disable the voice output
no-voice:
	sed -i '5 s/1/0/g' src/core/$(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) src/core/$(TARGET).c

# Disable the development output
no-dev:
	sed -i '6 s/1/0/g' src/core/$(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) src/core/$(TARGET).c
