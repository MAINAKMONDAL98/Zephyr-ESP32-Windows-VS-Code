#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

int main(void)
{
    int a = 10, b = 20;

    printk("ESP32 Zephyr Started\r\n");
    printk("Sum = %d\r\n", a + b);

    while (1) {
        printk("Running...\r\n");
        k_msleep(1000);
    }
}