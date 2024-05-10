#ifndef EPHO_BITWISE_H
#define EPHO_BITWISE_H

#define READ_BIT(FROM, BIT) !!((FROM) & (1 << (BIT))) 
#define CLEAR_BIT(FROM, BIT)  ((FROM) &= ~(1 << (BIT))) 
#define SET_BIT(FROM, BIT) ((FROM) |= (1 << (BIT)))  
#define TOGGLE_BIT(FROM, BIT) ((FROM) ^= (1 << (BIT)))

#endif // EPHO_BITWISE_H
