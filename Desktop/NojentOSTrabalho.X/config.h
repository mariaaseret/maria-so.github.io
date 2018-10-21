#ifndef CONFIG_H
#define	CONFIG_H

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <p18f4520.h>

#pragma config WDT = OFF                                                        // Desabilita Watch Dog Timer 
#pragma config OSC = HS                                                         // Oscilador de 4 MHz

#define ON      1
#define OFF     0

// Configura��es do NojentOS
#define MAX_TASKS           4                                                           // N�mero m�ximo de tarefas
#define RR_SCH              ON                                                         // Ativa escalonador Round Robin
#define PRIOR_SCH           OFF                                                          // Ativa escalonador Prioridade
#define MAX_STACK_LEVEL     31                                                      // N�veis da pilha de hardware
#define RR_QUANTUM          6    

#endif	/* CONFIG_H */

