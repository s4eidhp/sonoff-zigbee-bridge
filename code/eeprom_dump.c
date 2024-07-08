#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>

#include <linux/i2c-dev.h>


#define READ_SIZE       (128)
#define NB_PAGES        (512)

void dump_to_file(const char *output_file_path,
                  const uint8_t *buffer, const int buffer_length)
{
        int output_file = open(output_file_path, O_RDWR|O_APPEND|O_CREAT);
        if (output_file < 0) {
                printf("Failed opening output file %s\n", output_file_path);
                return;
        }

        write(output_file, buffer, buffer_length);
}

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("usage: ./eeprom_dump <i2c device> <output file>\n");
        return -1;
    }

    /* got these values from i2cdetect */
    const char *i2c_device = argv[1];
    const int device_address = 0x50;

    /* open the i2c device file */
    int file = open(i2c_device, O_RDWR);
    if (file < 0) {
            printf("Failed opening %s\n", i2c_device);
            return 1;
    }

    if (ioctl(file, I2C_SLAVE, device_address) < 0) {
            printf("Failed addressing device at %02X\n", device_address);
            close(file);
            return 1;
    }

    int i = 0;
    for (i = 0; i < NB_PAGES; i++) {
            char buf[READ_SIZE] = {0};

            if (read(file, buf, READ_SIZE) != READ_SIZE) {
                    printf("Failed reading\n");
                    close(file);
                    return 1;
            }

            dump_to_file(argv[2], buf, READ_SIZE);
    }

    close(file);
    return 0;
}