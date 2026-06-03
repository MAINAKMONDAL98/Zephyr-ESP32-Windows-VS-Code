#include<zephyr/kernel.h>
#include<zephyr/sys/printk.h>
//First
K_THREAD_STACK_DEFINE(led_stack,1024);

struct k_thread led_thread_data;

void thread_led(void *p1,void *p2,void *p3){
    while(1){
        printk(" 1 thread\n");
        k_msleep(1000);
    }
    
}

//Second
K_THREAD_STACK_DEFINE(led_stack2,1024);

struct k_thread led_thread_data2;

void thread_led2(void *p1,void *p2,void *p3){
    while(1){
        printk(" 2 thread\n");
        k_msleep(1000);
    }
    
}

//Third
K_THREAD_STACK_DEFINE(led_stack3,1024);

struct k_thread led_thread_data3;

void thread_led3(void *p1,void *p2,void *p3){
    while(1){
        printk(" 3 thread\n");
        k_msleep(1000);
    }
    
}

int main(){
    printk("Main thread\n");
    //First
    k_thread_create(
        &led_thread_data,
        led_stack,
        K_THREAD_STACK_SIZEOF(led_stack),
        thread_led,
        NULL,
        NULL,
        NULL,
        5,
        0,
        K_NO_WAIT
    );
    //Second
    k_thread_create(
        &led_thread_data2,
        led_stack2,
        K_THREAD_STACK_SIZEOF(led_stack2),
        thread_led2,
        NULL,
        NULL,
        NULL,
        5,
        0,
        K_NO_WAIT
    );
    //Third
    k_thread_create(
        &led_thread_data3,
        led_stack3,
        K_THREAD_STACK_SIZEOF(led_stack3),
        thread_led3,
        NULL,
        NULL,
        NULL,
        5,
        0,
        K_NO_WAIT
    );
    while(1){
        printk(" Main loop\n");
        k_msleep(1000);
    }
    return 0;
}