CC = gcc

eeprom_dump.out: src/eeprom_dump.c
	mkdir -p ./build
	${CC} -o build/$@ $^
clean:
	rm -rf build
	rm -f *.bin

