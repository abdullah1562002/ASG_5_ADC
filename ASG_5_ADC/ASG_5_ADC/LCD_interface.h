/*
 * ILCD_interface.h
 *
 * Author: Abdullah Abdelgalel
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_init                (void);
void LCD_sendCmnd            (u8 Cmnd);
void LCD_sendChar            (u8 data);
void LCD_writeString         (u8* String);
void LCD_clear               (void);
void LCD_writeNumber         (u32 number);
void LCD_shift               (u8 shifttingDirection);
void LCD_goToSpecificPosition(u8 LineNumber, u8 Position);


#endif /* ILCD_INTERFACE_H_ */