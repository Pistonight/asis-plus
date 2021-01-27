/*
 * Module that connects LUFA and ASIS
 */
#include <asis_joystick_adapter.h>
#include <asis_display_adapter.h>
#include <asis+_hw_adapter.h>

ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	HID_Task();
	USB_USBTask();
	TCNT1 = JA_TIMER;   // for 1 sec at 16 MHz
}

USB_JoystickReport_Input_t report;
void ja_setup(void){

	report.Button = BTN_NULL;
    report.HAT    = DPAD_C;
    report.LX     = STK_CTR;
    report.LY     = STK_CTR;
    report.RX     = STK_CTR;
    report.RY     = STK_CTR;
	report.VendorSpec = 0;
 // We need to disable watchdog if enabled by bootloader/fuses.
	MCUSR &= ~(1 << WDRF);
	wdt_disable();
	// We need to disable clock division before initializing the USB hardware.
	clock_prescale_set(clock_div_1);

  
	USB_Init();
	
	TCNT1 = JA_TIMER;   // for 1 sec at 16 MHz	

	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);  // Timer mode with 1024 prescler
	TIMSK1 = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)

  GlobalInterruptEnable();
  
}


void HID_Task(void){

	if (USB_DeviceState != DEVICE_STATE_Configured) return;
	
  // Clear the out endpoint because we don't need it
	Endpoint_SelectEndpoint(JOYSTICK_OUT_EPADDR);
	if (Endpoint_IsOUTReceived()) Endpoint_ClearOUT();
  // We'll then move on to the IN endpoint.
	Endpoint_SelectEndpoint(JOYSTICK_IN_EPADDR);
  if (Endpoint_IsINReady()) {
    // Write the report to the endpoint
    while(
      Endpoint_Write_Stream_LE(&report, 
                               sizeof(report), 
                               NULL) != ENDPOINT_RWSTREAM_NoError);
    //Regardless of a report was sent or not, clear the in endpoint
    Endpoint_ClearIN();

	}
}

void send_packet(asis_packet_t* packet){
	report.Button = packet->button;
    report.HAT    = packet->hat;
    report.LX     = packet->lx;
    report.LY     = packet->ly;
    report.RX     = packet->rx;
    report.RY     = packet->ry;
}
void EVENT_USB_Device_Connect(void) {
	ha_led_on();
	_delay_ms(1);
	ha_led_off();
}
void EVENT_USB_Device_Disconnect(void) {
	ha_led_on();
	_delay_ms(1);
	ha_led_off();
} 
void EVENT_USB_Device_ControlRequest(void) {
	ha_led_on();
	_delay_ms(1);
	ha_led_off();
}
void EVENT_USB_Device_ConfigurationChanged(void) {
  //Config joystick endpoints
	Endpoint_ConfigureEndpoint(JOYSTICK_OUT_EPADDR, EP_TYPE_INTERRUPT, JOYSTICK_EPSIZE, 1);
	Endpoint_ConfigureEndpoint(JOYSTICK_IN_EPADDR, EP_TYPE_INTERRUPT, JOYSTICK_EPSIZE, 1);
	ha_led_on();
	_delay_ms(1);
	ha_led_off();
}


