#include "cpio.h"
#include "muart.h"
#include "utils.h"
#include "shell.h"
#include "timer.h"
#include "exception.h"
#include "devicetree.h"

int main(void) {
    mini_uart_init();

    devicetree_get_address();
    fdt_traverse(initramfs_callback);
    
    enable_interrupt();
    mini_uart_puts("\r\nBasic Shell\r\n");

    while (1) {
        char buffer[BUFSIZE];
        mini_uart_puts("# ");
        mini_uart_gets(buffer, BUFSIZE);
        
        if (strcmp(buffer, "\0") == 0) {
            mini_uart_puts("\r\n");
        } else if (strcmp(buffer, "ls") == 0) {
            ls();
        } else if (strcmp(buffer, "cat") == 0) {
            cat();
        } else if (strcmp(buffer, "help") == 0) {
            usage();
        } else if (strcmp(buffer, "info") == 0) {
            info();
        } else if (strcmp(buffer, "hello") == 0) {
            hello();
        } else if (strcmp(buffer, "alloc") == 0) {
            alloc();
        } else if (strcmp(buffer, "async") == 0) {              // EL1
            async();
        } else if (strcmp(buffer, "reboot") == 0) {
            reboot();
        } else if (strcmp(buffer, "execute") == 0) {            // EL0
            execute();
        } else if (strcmp(buffer, "boottime") == 0) {           // EL0
            boottime();
        } else if (strncmp(buffer, "settimeout", 10) == 0) {    // EL1
            settimeout(buffer);
        } else {
            message();
        }
    }

    return 0;
}