/*
 * Bit_Math.h
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_

#define set_bit(reg,bitno)   reg|=(1<<bitno)
#define clr_bit(reg,bitno)   reg&=~(1<<bitno)
#define tog_bit(reg,bitno)   reg^=(1<<bitno)
#define get_bit(reg,bitno)   ((reg>>bitno)&1)


#endif /* COMMON_BIT_MATH_H_ */
