# NXP LPSPI Zephyr Driver Module

## Usage

This is a west module. You can integrate it in your application by adding the project to your west manifest or by specifying it in your `EXTRA_ZEPHYR_MODULES`.

This module contains the old nxp lpspi driver from zephyr version v4.0.0 ([source](https://github.com/zephyrproject-rtos/zephyr/tree/v4.0.0/drivers/spi)) because later versions introduced a new but broken lpspi driver ([source](https://github.com/zephyrproject-rtos/zephyr/tree/v4.3.0-rc1/drivers/spi/spi_nxp_lpspi)) having issues with SCK and GPIO-CS timings. If later versions of the lpspi driver fix these issues, this module will become obsolete.

Enable the driver by specifying `compatible = "nxp,imx-lpspi";` for your spi bus in the device tree.

```c
&lpspi4 {
    // driver: zephyr 4.3.0-rc1
    // compatible = "nxp,lpspi";
    // driver: zephyr 4.0.0
    compatible = "nxp,imx-lpspi";

    status = "okay";

    transfer-delay = <50>; // ns

    pinctrl-0 = <&pinmux_lpspi4>;
    pinctrl-names = "default";
    
    cs-gpios = <&gpio1 24 GPIO_ACTIVE_LOW>; // Steering 1 (front-left)

    spi_dummy: nodevice@0{
        reg = <0>;
        compatible = "vnd,spi-device";
        spi-max-frequency = <100000>;
    };
};
```

## Example

A full working example for reading, writing ans transceiving values on a Teensy 4.1 can be found [here](samples/drivers/lpspi/).

## Writing Out-Of-Tree Drivers

Since this was kind of a pain to figure out, here are a few helpful links if you want to do this:

* https://interrupt.memfault.com/blog/building-drivers-on-zephyr
* https://blog.golioth.io/adding-an-out-of-tree-sensor-driver-to-zephyr/
* https://jonasotto.com/posts/zephyr_out_of_tree_driver/
