/** 
 *
 * @brief  PWM example minimalist using nRF5x family from Nordic Semiconductor 
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "app_error.h"
#include "bsp.h"
#include "nrf_delay.h"
#include "app_pwm.h"

#define LED_PIN               			20    // PIN with PWM feature

APP_PWM_INSTANCE(PWM1,1);                   // Create the instance "PWM1" using TIMER1 (TIMER0 is reserved by SoftDevice)

static volatile bool ready_flag;            // A flag indicating PWM status.

void pwm_ready_callback(uint32_t pwm_id)    // PWM callback function
{
    ready_flag = true;
}

int main(void)
{
    ret_code_t err_code;

    /* 1-channel PWM, 200Hz, output on DK LED pins. */
		app_pwm_config_t pwm1_cfg = APP_PWM_DEFAULT_CONFIG_1CH(5000L,TP05_PIN); 


    /* Switch the polarity of the second channel. */
    //pwm1_cfg.pin_polarity[1] = APP_PWM_POLARITY_ACTIVE_HIGH;

    /* Initialize and enable PWM. */
    err_code = app_pwm_init(&PWM1,&pwm1_cfg,pwm_ready_callback);
    APP_ERROR_CHECK(err_code);
    app_pwm_enable(&PWM1);

    uint32_t value = 50;

		app_pwm_channel_duty_set(&PWM1, 0, value);	//set duty cycle on channel '0'

}
