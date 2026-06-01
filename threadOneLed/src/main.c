#include<zephyr/kernel.h>
#include<zephyr/sys/printk.h>
K_THREAD_STACK_DEFINE(led_stack,1024);
struct k_thread led_thread_data;
void led_thread(void *p1,void *p2, void *p3){
    while(1){
        printk("LED Thread running\n");
        k_msleep(1000);
    }
}
int main(void){
    printk("main thread started\n");
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