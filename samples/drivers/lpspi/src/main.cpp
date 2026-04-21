#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>

int main(){
    printk("LPSPI sample application\n");

    const spi_dt_spec spi_dummy = SPI_DT_SPEC_GET(DT_NODELABEL(spi_dummy), SPI_WORD_SET(8));

    if (!spi_is_ready_dt(&spi_dummy)) {
		printk("spi_dummy: device not ready.\n");
		return 0;
	}

    while (true) {        
        uint8_t write_content = 0x2A;
        struct spi_buf write_buf = {.buf = &write_content, .len = 1};
        struct spi_buf_set write_bufs = {.buffers = &write_buf, .count = 1};

        uint8_t read_content;
        struct spi_buf read_buf = {.buf = &read_content, .len = 1};
        struct spi_buf_set read_bufs = {.buffers = &read_buf, .count = 1};

        spi_write_dt(&spi_dummy, &write_bufs);
        printk("spi_dummy: written: %x\n", write_content);

        spi_read_dt(&spi_dummy, &read_bufs);
        printk("spi_dummy: read: %x\n", read_content);

        spi_transceive_dt(&spi_dummy, &write_bufs, &read_bufs);
        printk("spi_dummy: transceived: %x (written) | %x (read)\n", write_content, read_content);
    }
}
