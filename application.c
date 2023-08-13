/* 
 * File:   application.c
 * Author: Abdallah Saad
 * Created on November 28, 2020, 8:43 PM
 */

#include "application.h"




uint8 value_11 , value_12 , value_21 , value_22 ; 
uint8  number1 , number2 ,operater  , equal_operator;  
uint16 result ; 
uint8 int_str[20];

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
 
    
    ret = lcd_8bit_send_string_pos(&lcd_1 ,1,7,"WELCOME") ;  
    ret = lcd_8bit_send_string_pos(&lcd_1 ,2,4,"IN MY 2 DIGIT") ;
    ret = lcd_8bit_send_string_pos(&lcd_1 ,3,6,"CALCULATOR") ;  
    __delay_ms(1000) ; 
    ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR);

    while(1){
        ret = keypad_get_value_blocking(&keypad1 , &value_11 ) ; 
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,1,value_11) ;
        ret = keypad_get_value_blocking(&keypad1 , &value_12 ) ; 
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,2,value_12) ;
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,3,' ') ; 
        ret = keypad_get_value_blocking(&keypad1 , &operater ) ;
        
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,4,operater) ;
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,5,' ') ; 
        
        ret = keypad_get_value_blocking(&keypad1 , &value_21 ) ; 
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,6,value_21) ;
        ret = keypad_get_value_blocking(&keypad1 , &value_22 ) ; 
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,7,value_22) ;
        
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,8,' ') ; 
        ret = keypad_get_value_blocking(&keypad1 , &equal_operator ) ; 
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,9,'=') ; 
        ret = lcd_8bit_send_char_data_pos(&lcd_1 ,2,10,' ') ; 
        
        number1 = (value_11 -'0')*10 + (value_12 - '0') ; 
        number2 = (value_21 -'0')*10 + (value_22 - '0') ; 
        
        if(operater =='+'){
            result = number1 + number2 ; 
            
        }
        else if(operater =='-'){
            result = number1 - number2 ; 
        }
        else if(operater =='*'){
            result = number1 * number2 ; 
        }
        else if(operater =='/'){
            result = number1 / number2 ; 
        }
        
        sprintf(int_str, "%d", result);
        ret = lcd_8bit_send_string_pos(&lcd_1 ,2,11,int_str) ; 
        
        ret = keypad_get_value_blocking(&keypad1 , &operater ) ; 
 
        if(operater =='#'){
            ret = lcd_8bit_send_command( &lcd_1 , _LCD_CLEAR); 
        }
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize() ; 
    
}




