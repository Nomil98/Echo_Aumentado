#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use RS232(BAUD=9600, XMIT= PIN_C6, RCV = PIN_C7, BITS = 8, PARITY = N, STOP=1, STREAM = PORT1)
#use fast_io(c)
char echo[50];
int puntero=0;
int flagRecibido=0;

#INT_RDA
void serial_isr(){
if (kbhit()){
    echo[puntero]=getch();
    puntero++;
    flagrecibido=1;
    }
}

void main(){
setup_oscillator(OSC_16MHZ);
 setup_adc_ports(NO_ANALOGS); 
set_tris_c(0xff);
enable_interrupts(int_rda);
enable_interrupts(GLOBAL);
printf("Ingresa un caracter y se mostrar� el caracter siguiente.");
while(1){

    if(flagRecibido==1){
        flagRecibido=0;
        printf("%c\n\r", echo[puntero-1]);
        
         printf("%c\n\r", echo[puntero-1]+1);
        }
    }
}

