// CONFIG
#pragma config FOSC = INTRCIO // Oscillator Selection bits (Internal clock)
#pragma config WDTE = OFF // Watchdog Timer Enable bit
#pragma config PWRTE = OFF // Power-Up Timer Enable bit
#pragma config MCLRE = OFF // GP3/MCLR pin function select
#pragma config BOREN = OFF // Brown-out Detect Enable bit
#pragma config CP = OFF // Code Protection bit
#pragma config CPD = OFF // Data Code Protection bit

// Define Internal clock frequency
#define _XTAL_FREQ 4000000