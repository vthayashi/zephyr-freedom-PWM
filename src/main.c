#include <zephyr/kernel.h>             
#include <zephyr/device.h>             
#include <zephyr/drivers/gpio.h>       
#include <pwm_z42.h>              

// Define o valor do registrador MOD do TPM para configurar o período do PWM
#define TPM_MODULE 1000     
uint16_t duty_VERMELHO  = TPM_MODULE/9;     
uint16_t duty_VERDE  = TPM_MODULE/2;  

int main(void)
{
    pwm_tpm_Init(TPM2, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_128, EDGE_PWM);
    pwm_tpm_Ch_Init(TPM2, 0, TPM_PWM_H, GPIOB, 18);
    pwm_tpm_CnV(TPM2, 0, duty_VERMELHO);
    pwm_tpm_Ch_Init(TPM2, 1, TPM_PWM_H, GPIOB, 19);
    pwm_tpm_CnV(TPM2, 1, duty_VERDE);

    for (;;)
    {
    }

    return 0;
}
