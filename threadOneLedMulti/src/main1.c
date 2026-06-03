#include<zephyr/kernel.h>
#include<zephyr/sys/printk.h>
#include<zephyr/drivers/gpio.h>
#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led=
    GPIO_DT_SPEC_GET(LED0_NODE,gpios);
K_THREAD_STACK_DEFINE(led_stack,1024);
struct k_thread led_thread_data;
void led_thread(void *p1,void *p2, void *p3){
    while(1){
        gpio_pin_toggle_dt(&led);
        printk("LED Thread running\n");
        k_msleep(1000);
    }
}
int main(void){
    printk("main thread started\n");
    if(!gpio_is_ready_dt(&led)){
        printk("LED not ready\n");
        return 0;
    }
    gpio_pin_configure_dt(&led,GPIO_OUTPUT_INACTIVE);
    k_thread_create(
        &led_thread_data,
        led_stack,
        K_THREAD_STACK_SIZEOF(led_stack),
        led_thread,
        NULL,
        NULL,
        NULL,
        5,
        0,
        K_NO_WAIT
    );
    while(1){
        printk("Main Thread alive\n");
        k_msleep(1000);
    }
    return 0;
}