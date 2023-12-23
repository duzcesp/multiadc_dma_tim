#include "stm32f10x.h"                  
#include "stm32f10x_rcc.h"             
#include "stm32f10x_adc.h"              
#include "stm32f10x_dma.h"             
#include "stm32f10x_tim.h"             
#include "stm32f10x_gpio.h"


void gpio_fonks(void);
void adc_fonks(void);
void dma_fonks(void);
void timer_fonks(void);
void scaleadc(void);
void pwm_fonks(uint16_t);
void pwm_fonks_1(uint16_t pulse_1);
void delay(uint32_t);
static uint16_t deger_0;
static uint16_t deger_1;
static uint16_t deger_0_geri;
static uint16_t deger_1_sol;


static uint16_t adcvalue[4];


void gpio_fonks(void){
   
   GPIO_InitTypeDef gpio_ayar;
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
   
   gpio_ayar.GPIO_Mode=GPIO_Mode_AIN;
   gpio_ayar.GPIO_Pin=GPIO_Pin_0;
   gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
   GPIO_Init(GPIOA,&gpio_ayar);
   
   gpio_ayar.GPIO_Mode=GPIO_Mode_AIN;
   gpio_ayar.GPIO_Pin=GPIO_Pin_1;
   gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
   GPIO_Init(GPIOA,&gpio_ayar);
   
   gpio_ayar.GPIO_Mode=GPIO_Mode_AIN;
   gpio_ayar.GPIO_Pin=GPIO_Pin_2;
   gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
   GPIO_Init(GPIOA,&gpio_ayar);
   
   gpio_ayar.GPIO_Mode=GPIO_Mode_AIN;
   gpio_ayar.GPIO_Pin=GPIO_Pin_3;
   gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
   GPIO_Init(GPIOA,&gpio_ayar);
   
   gpio_ayar.GPIO_Mode=GPIO_Mode_AF_PP;
   gpio_ayar.GPIO_Pin=GPIO_Pin_6;
   gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
   GPIO_Init(GPIOA,&gpio_ayar);
   
    gpio_ayar.GPIO_Mode=GPIO_Mode_AF_PP;
    gpio_ayar.GPIO_Pin=GPIO_Pin_0;
    gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&gpio_ayar);
    
    gpio_ayar.GPIO_Mode=GPIO_Mode_Out_PP;
    gpio_ayar.GPIO_Pin=GPIO_Pin_1;
    gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&gpio_ayar);
    
    gpio_ayar.GPIO_Mode=GPIO_Mode_Out_PP;
    gpio_ayar.GPIO_Pin=GPIO_Pin_10;
    gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&gpio_ayar);
      
      gpio_ayar.GPIO_Mode=GPIO_Mode_Out_PP;
      gpio_ayar.GPIO_Pin=GPIO_Pin_13;
      gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
      GPIO_Init(GPIOB,&gpio_ayar);
      
      gpio_ayar.GPIO_Mode=GPIO_Mode_Out_PP;
      gpio_ayar.GPIO_Pin=GPIO_Pin_12;
      gpio_ayar.GPIO_Speed=GPIO_Speed_50MHz;
      GPIO_Init(GPIOB,&gpio_ayar);
    
}

void timer_fonks(void){
   TIM_TimeBaseInitTypeDef timer_ayar;
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
   
   timer_ayar.TIM_ClockDivision=TIM_CKD_DIV1;
   timer_ayar.TIM_CounterMode=TIM_CounterMode_Up;
   timer_ayar.TIM_Period=3999;
   timer_ayar.TIM_Prescaler=10;
   timer_ayar.TIM_RepetitionCounter=0;
   
   TIM_TimeBaseInit(TIM3,&timer_ayar);
   TIM_Cmd(TIM3,ENABLE);

}

void pwm_fonks_1(uint16_t pulse_1){
   
   TIM_OCInitTypeDef tim_pwm_ayar_1;
   
   tim_pwm_ayar_1.TIM_OCMode=TIM_OCMode_PWM1;
   tim_pwm_ayar_1.TIM_OutputState=TIM_OutputState_Enable;
   tim_pwm_ayar_1.TIM_OCPolarity=TIM_OCPolarity_High;
   tim_pwm_ayar_1.TIM_Pulse=pulse_1;
   
   TIM_OC3Init(TIM3,&tim_pwm_ayar_1);
   TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
   

}

void pwm_fonks(uint16_t pulse){
   
   TIM_OCInitTypeDef tim_pwm_ayar;
   
   tim_pwm_ayar.TIM_OCMode=TIM_OCMode_PWM1;
   tim_pwm_ayar.TIM_OutputState=TIM_OutputState_Enable;
   tim_pwm_ayar.TIM_OCPolarity=TIM_OCPolarity_High;
   tim_pwm_ayar.TIM_Pulse=pulse;
   
   TIM_OC1Init(TIM3,&tim_pwm_ayar);
   TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);

}


void adc_fonks(void){
   ADC_InitTypeDef adc_ayar;
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
   
   adc_ayar.ADC_ContinuousConvMode=ENABLE;
   adc_ayar.ADC_DataAlign=ADC_DataAlign_Right;
   adc_ayar.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
   adc_ayar.ADC_Mode=ADC_Mode_Independent;
   adc_ayar.ADC_NbrOfChannel=4;
   adc_ayar.ADC_ScanConvMode=ENABLE;
   
   ADC_Init(ADC1,&adc_ayar);
   ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);
   ADC_RegularChannelConfig(ADC1,ADC_Channel_1,2,ADC_SampleTime_55Cycles5);
   ADC_RegularChannelConfig(ADC1,ADC_Channel_2,3,ADC_SampleTime_55Cycles5);
   ADC_RegularChannelConfig(ADC1,ADC_Channel_3,4,ADC_SampleTime_55Cycles5);
   ADC_Cmd(ADC1,ENABLE);
   ADC_DMACmd(ADC1,ENABLE);
   ADC_SoftwareStartConvCmd(ADC1,ENABLE);

}

void dma_fonks(void){
   DMA_InitTypeDef dma_ayar;
   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
   
   DMA_Cmd(DMA1_Channel1,DISABLE);
   DMA_DeInit(DMA1_Channel1);
   
   dma_ayar.DMA_BufferSize=4;
   dma_ayar.DMA_DIR=DMA_DIR_PeripheralSRC;
   dma_ayar.DMA_M2M=DISABLE;
   dma_ayar.DMA_MemoryBaseAddr=(uint32_t) adcvalue;
   dma_ayar.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;
   dma_ayar.DMA_MemoryInc=DMA_MemoryInc_Enable;
   dma_ayar.DMA_Mode=DMA_Mode_Circular;
   dma_ayar.DMA_PeripheralBaseAddr=(uint32_t) & ADC1->DR;
   dma_ayar.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
   dma_ayar.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
   dma_ayar.DMA_Priority=DMA_Priority_High;
   
   DMA_Init(DMA1_Channel1,&dma_ayar);
   DMA_Cmd(DMA1_Channel1,ENABLE);
}

void delay(uint32_t time){
   
   while(time--);
}




int main(void){
   gpio_fonks();
   adc_fonks();
   dma_fonks();
   timer_fonks();
   
   
   while(1){
      deger_0=adcvalue[0];
      deger_1=adcvalue[1];
		 /*pwm_fonks((uint16_t)deger_0);*/
     /* pwm_fonks_1((uint16_t)deger_0);*/
		  
		  if(deger_0>3000 && deger_0<3250 && deger_1>3150 && deger_1<3350){ /*arac hareketsiz iken*/
				
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_12);
				GPIO_ResetBits(GPIOB,GPIO_Pin_13);
				pwm_fonks(0);
				pwm_fonks_1(0);
			
			}
			else if(deger_0>=3250 && deger_1>3150 && deger_1<3350){ /*arac ileri hareket ediyor iken*/
				
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_SetBits(GPIOB,GPIO_Pin_12);
				GPIO_ResetBits(GPIOB,GPIO_Pin_13);
				pwm_fonks((uint16_t)deger_0);
				pwm_fonks_1((uint16_t)deger_0);
				
			}
			else if(deger_0<3000 && deger_1>3150 && deger_1<3350){ /*arac geri iken*/
				deger_0_geri = 3130 - (uint16_t) deger_0;
				if(deger_0_geri>0){
					GPIO_ResetBits(GPIOB,GPIO_Pin_1);
					GPIO_SetBits(GPIOB,GPIO_Pin_10);
					GPIO_ResetBits(GPIOB,GPIO_Pin_12);
					GPIO_SetBits(GPIOB,GPIO_Pin_13);
					pwm_fonks((uint16_t)deger_0_geri);
					pwm_fonks_1((uint16_t)deger_0_geri);
				}
				}
			else if(deger_0>3250 && deger_1>3350){ /*arac saga doner sol motor ileri sag motor geri*/
				
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_10);
				GPIO_ResetBits(GPIOB,GPIO_Pin_12);
				GPIO_SetBits(GPIOB,GPIO_Pin_13);
				pwm_fonks((uint16_t)deger_0);
				pwm_fonks_1((uint16_t)deger_1);
			
			}
			else if(deger_0>3250 && deger_1<3150){ /* arac sola doner sag motor ileri sol motor geri*/
				
				deger_1_sol = 3100 - (uint16_t) deger_1 ;
				if(deger_1_sol>0){
					GPIO_ResetBits(GPIOB,GPIO_Pin_1);
					GPIO_SetBits(GPIOB,GPIO_Pin_10);
					GPIO_SetBits(GPIOB,GPIO_Pin_12);
					GPIO_ResetBits(GPIOB,GPIO_Pin_13);
					pwm_fonks((uint16_t)deger_0);
					pwm_fonks_1((uint16_t)deger_1_sol);
				}
				
			}
			
				
				
				
				
				
				
				
			}
			 
      
         
       
       
         
        
   
   

}


