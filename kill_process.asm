;just practicing programming in assembly language (Ferdinand Silva)
            section     .data
SYS_KILL:   equ         62
SIGKILL:    equ         9

            global      kill_process
            section     .text

kill_process:
            mov         r15, rdi
            mov         rax, SYS_KILL
            mov         rdi, r15
            mov         rsi, SIGKILL
            syscall
            ret