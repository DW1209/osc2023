#include "mem.h"
#include "cpio.h"
#include "muart.h"
#include "shell.h"
#include "reboot.h"
#include "mailbox.h"

void ls(void) {
    cpio_list();
}

void cat(void) {
    cpio_concatenate();
}

void info(void) {
    get_board_revision();
    get_arm_memory();
}

void usage(void) {
    mini_uart_puts("ls:      list the filenames in initramfs file\r\n");
    mini_uart_puts("cat:     print the contents in initramfs\r\n");
    mini_uart_puts("help:    print this help memu\r\n");
    mini_uart_puts("info:    print hardware's information\r\n");
    mini_uart_puts("hello:   print Hello World!\r\n");
    mini_uart_puts("alloc:   test for the simple_alloc function\r\n");
    mini_uart_puts("reboot:  reboot the device\r\n");
    mini_uart_puts("execute: run user program from initramfs\r\n");
}

void alloc(void) {
    char *str = (char*) simple_alloc(8);

    for (int i = 0; i < 8; i++) {
        if (i != 7) {
            str[i] = 'A' + i;
        } else {
            str[i] = '\0';
        }
    }

    mini_uart_puts(str);
    mini_uart_puts("\r\n");
}

void hello(void) {
    mini_uart_puts("Hello World!\r\n");
}

void reboot(void) {
    mini_uart_puts("rebooting...\r\n");
    reset(100);
}

void execute(void) {
    cpio_execute();
}

void message(char *s) {
    mini_uart_puts(s);
    mini_uart_puts(" command not found\r\n");
}