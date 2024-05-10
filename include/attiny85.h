#ifndef EPHO_ATTINY85_H
#define EPHO_ATTINY85_H

#include <stdint.h>

#define MEM_OFFSET 0x20
#define MEM_DEREF_8(X) (*(volatile uint8_t *)(MEM_OFFSET + X))

#define ADCSRB MEM_DEREF_8(0x03)
#define BIN     7
#define ACME    6
#define IPR     5
#define ADTS2   2
#define ADTS1   1
#define ADTS0   0

#define ADCL   MEM_DEREF_8(0x04)

#define ADCH   MEM_DEREF_8(0x05)

#define ADCSRA MEM_DEREF_8(0x06)
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

#define ADMUX  MEM_DEREF_8(0x07)
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define REFS2   4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#define ACSR   MEM_DEREF_8(0x08)
#define ACD     7
#define ACBG    6
#define ACO     5
#define ACI     4
#define ACIE    3
#define ACIS1   1
#define ACIS0   0

#define USICR  MEM_DEREF_8(0x0D)
#define USISIE  7
#define USIOIE  6
#define USIWM1  5
#define USIWM0  4
#define USICS1  3
#define USICS0  2
#define USICLK  1
#define USITC   0

#define USISR  MEM_DEREF_8(0x0E)
#define USISIF  7
#define USIOIF  6
#define USIPF   5
#define USIDC   4
#define USICNT3 3
#define USICNT2 2
#define USICNT1 1
#define USICNT0 0

#define USIDR  MEM_DEREF_8(0x0F)

#define USIBR  MEM_DEREF_8(0x10)

#define GPIOR0 MEM_DEREF_8(0x11)

#define GPIOR1 MEM_DEREF_8(0x12)

#define GPIOR2 MEM_DEREF_8(0x13)

#define DIDR0  MEM_DEREF_8(0x14)
#define ADC0D   5
#define ADC2D   4
#define ADC3D   3
#define ADC1D   2
#define AIN1D   1
#define AIN0D   0

#define PCMSK  MEM_DEREF_8(0x15)
#define PCINT5  5
#define PCINT4  4
#define PCINT3  3
#define PCINT2  2
#define PCINT1  1
#define PCINT0  0

#define PINB   MEM_DEREF_8(0x16)
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB   MEM_DEREF_8(0x17)
#define DDB5    5
#define DDB4    4
#define DDB3    3
#define DDB2    2
#define DDB1    1
#define DDB0    0

#define PORTB  MEM_DEREF_8(0x18)
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define EECR   MEM_DEREF_8(0x1C)
#define EEPM1   5
#define EEPM0   4
#define EERIE   3
#define EEMPE   2
#define EEPE    1
#define EERE    0

#define EEDR   MEM_DEREF_8(0x1D)

#define EEARL  MEM_DEREF_8(0x1E)
#define EEAR7   7
#define EEAR6   6
#define EEAR5   5
#define EEAR4   4
#define EEAR3   3
#define EEAR2   2
#define EEAR1   1
#define EEAR0   0

#define EEARH  MEM_DEREF_8(0x1F)
#define EEAR8   0

#define PRR    MEM_DEREF_8(0x20)
#define PRTIM1  3
#define PRTIM0  2
#define PRUSI   1
#define PRADC   0

#define WDTCR  MEM_DEREF_8(0x21)
#define WDIF    7
#define WDIE    6
#define WDP3    5
#define WDCE    4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0

#define DWDR   MEM_DEREF_8(0x22)
#define DWDR7   7
#define DWDR6   6
#define DWDR5   5
#define DWDR4   4
#define DWDR3   3
#define DWDR2   2
#define DWDR1   1
#define DWDR0   0

#define DTPS1  MEM_DEREF_8(0x23)
#define DTPS11  1
#define DTPS10  0

#define DT1B   MEM_DEREF_8(0x24)
#define DT1BH3  7
#define DT1BH2  6
#define DT1BH1  5
#define DT1BH0  4
#define DT1BL3  3
#define DT1BL2  2
#define DT1BL1  1
#define DT1BL0  0

#define DT1A   MEM_DEREF_8(0x25)
#define DT1AH3  7
#define DT1AH2  6
#define DT1AH1  5
#define DT1AH0  4
#define DT1AL3  3
#define DT1AL2  2
#define DT1AL1  1
#define DT1AL0  0

#define CLKPR  MEM_DEREF_8(0x26)
#define CLKPCE  7
#define CLKPS3  3
#define CLKPS2  2
#define CLKPS1  1
#define CLKPS0  0

#define PLLCSR MEM_DEREF_8(0x27)
#define LSM     7
#define PCKE    2
#define PLLE    1
#define PLOCK   0

#define OCR0B  MEM_DEREF_8(0x28)

#define OCR0A  MEM_DEREF_8(0x29)

#define TCCR0A MEM_DEREF_8(0x2A)
#define COM0A1  7
#define COM0A0  6
#define COM0B1  5
#define COM0B0  4
#define WGM01   1
#define WGM00   0

#define OCR1B  MEM_DEREF_8(0x2B)

#define GTCCR  MEM_DEREF_8(0x2C)
#define TSM     7
#define PWM1B   6
#define COM1B1  5
#define COM1B0  4
#define FOC1B   3
#define FOC1A   2
#define PSR1    1
#define PSR0    0

#define OCR1C  MEM_DEREF_8(0x2D)

#define OCR1A  MEM_DEREF_8(0x2E)

#define TCNT1  MEM_DEREF_8(0x2F)

#define TCCR1  MEM_DEREF_8(0x30)
#define CTC1    7
#define PWM1A   6
#define COM1A1  5
#define COM1A0  4
#define CS13    3
#define CS12    2
#define CS11    1
#define CS10    0

#define OSCCAL MEM_DEREF_8(0x31)

#define TCNT0  MEM_DEREF_8(0x32)

#define TCCR0B MEM_DEREF_8(0x33)
#define FOC0A   7
#define FOC0B   6
#define WGM02   3
#define CS02    2
#define CS01    1
#define CS00    0

#define MCUSR  MEM_DEREF_8(0x34)
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0

#define MCUCR  MEM_DEREF_8(0x35)
#define BODS    7
#define PUD     6
#define SE      5
#define SM1     4
#define SM0     3
#define BODSE   2
#define ISC01   1
#define ISC00   0

#define SPMCSR MEM_DEREF_8(0x37)
#define RSIG    5
#define CTPB    4
#define RFLB    3
#define PGWRT   2
#define PGERS   1
#define SPMEN   0

#define TIFR   MEM_DEREF_8(0x38)
#define OCF1A   6
#define OCF1B   5
#define OCF0A   4
#define OCF0B   3
#define TOV1    2
#define TOV0    1

#define TIMSK  MEM_DEREF_8(0x39)
#define OCIE1A  6
#define OCIE1B  5
#define OCIE0A  4
#define OCIE0B  3
#define TOIE1   2
#define TOIE0   1

#define GIFR   MEM_DEREF_8(0x3A)
#define INTF0   6
#define PCIF    5

#define GIMSK  MEM_DEREF_8(0x3B)
#define INT0    6
#define PCIE    5

#define SPL    MEM_DEREF_8(0x3D)
#define SP7     7
#define SP6     6
#define SP5     5
#define SP4     4
#define SP3     3
#define SP2     2
#define SP1     1
#define SP0     0

#define SPH    MEM_DEREF_8(0x3E)
#define SP9     1
#define SP8     0

#define SREG   MEM_DEREF_8(0x3F)
#define I       7
#define T       6
#define H       5
#define S       4
#define V       3
#define N       2
#define Z       1
#define C       0

#define sei() __asm__ __volatile__ ( "sei" ::: "memory");
#define cli() __asm__ __volatile__ ( "cli" ::: "memory");

#define ISR(vector)            \
    void vector (void) __attribute__ ((signal)); \
    void vector (void)

#define _VECTOR(X) __vector_ ## X

#define RESET_vect        _VECTOR(0)
#define INT0_vect         _VECTOR(1)
#define PCINT0_vect       _VECTOR(2)
#define TIMER1_COMPA_vect _VECTOR(3)
#define TIMER1_OVF_vect   _VECTOR(4)
#define TIMER0_OVF_vect   _VECTOR(5)
#define EE_RDY_vect       _VECTOR(6)
#define ANA_COMP_vect     _VECTOR(7)
#define ADC_vect          _VECTOR(8)
#define TIMER1_COMPB_vect _VECTOR(9)
#define TIMER0_COMPA_vect _VECTOR(10)
#define TIMER0_COMPB_vect _VECTOR(11)
#define WDT_vect          _VECTOR(12)
#define USI_START_vect    _VECTOR(13)
#define USI_OVF_vect      _VECTOR(14)

#endif // EPHO_ATTINY85_H
