#include "mbed.h"
DigitalOut red(PA_9);
DigitalOut blue(PA_8);
DigitalOut green(PB_10);
PwmOut speaker(PB_8);

//used to communicate to the PC and to use the keyboard as input
Serial pc(USBTX, USBRX); 

void readInput(char input);
void showMenu();
void checkInput(char);
void OffAllLeds(void);
void OffSpeaker(void);
void playHappyBirthday();
void playTwinkleTwinkeLittleStars();
void playNote(int freq);
void redLedOn();
void blueLedOn();
void greenLedOn();
void cycleLeds();

volatile float tone = 0.5f; //volume
volatile float freq_scale = 1.0f;
volatile float frequency = 440.0f;


/* note   frequency     
 * c(do)            261 Hz              
 * d(re)           294 Hz              
 * e(mi)            329 Hz              
 * f(fa)            349 Hz              
 * g(so)            392 Hz           
 * a(la)            440 Hz             
 * b(ti)            493 Hz             
 * C(do)            523 Hz          
*/


int main() {
    
    
    char input = 'Z';
        showMenu();
    
    do {
        input = pc.getc();  //Get user input    
        checkInput(input);
        readInput(input);                                    
       } while(input != 'q');
}

void readInput(char input)
{   
    switch(input)
    {
                case '1': redLedOn();
                          break;
            
                case '2': blueLedOn();
                          break;     
            
                case '3': greenLedOn();
                          break;   
            
                case '4': cycleLeds();    
                          break;  
             
                case '5': playTwinkleTwinkeLittleStars();             
                          break;
            
                case '6': playHappyBirthday();
                          break;
            
                case 'a': frequency = 261; 
                          playNote(frequency);
                          break;
            
                case 's': frequency = 293;
                          playNote(frequency);
                          break;
                                                     
                case 'd': frequency = 329;
                          playNote(frequency);
                          break;
                                                     
                case 'f': frequency = 349;
                          playNote(frequency);
                          break;  
                                                     
                case 'g': frequency = 391;
                          playNote(frequency);
                          break; 
                                                     
                case 'h': frequency = 440;
                          playNote(frequency);
                          break;
                                                     
                case 'j': frequency = 493;
                          playNote(frequency);
                          break;  
                                                    
                case 'k': frequency = 526;
                          playNote(frequency);
                          break;

                default:  OffAllLeds();
                          OffSpeaker();
													break;        
    }
}

//turns on the red LED
void redLedOn()
{
    red = 1;
    blue = 0;
    green = 0;
}

//turns on the blue LED
void blueLedOn()
{
    blue = 1;
    red = 0;
    green = 0;
}

//turns on the green LED
void greenLedOn()
{
    green = 1;
    blue = 0;
    red = 0;
}

//cycle through the RGB leds for 5 iterations
void cycleLeds()
{
    for(int i = 0; i < 5; i++)
    {
    red = 1;
  green = 0;
  blue = 0;
    wait(0.5);
    red = 0;
    green = 1;
    blue = 0;
    wait(0.5);
    red = 0;
    green = 0;
    blue = 1;
    wait(0.5);
    }
    OffAllLeds();
}

//turn off all LEDs by default
void OffAllLeds()
{
    red = 0;
    blue = 0;
    green = 0;
}

//turn off speaker by default
void OffSpeaker()
{
    frequency = 0.0f;
    speaker = 0.0f;   
}

//plays a note based on the frequency
void playNote(int freq)
{
    speaker.period(1.0f/(freq_scale*freq));
        speaker = tone;  
    wait(0.5);
        speaker = 0.0;
                                         
}

//shows the menu on the terminal
void showMenu()
{
    pc.printf("For do press A\r\n");
    pc.printf("For re press S\r\n");
    pc.printf("For mi press D\r\n");
    pc.printf("For fa press F\r\n");
    pc.printf("For so press G\r\n");
    pc.printf("For la press H\r\n");
    pc.printf("For ti press J\r\n");
    pc.printf("For do press K\r\n");
    pc.printf("For red LED press 1\r\n");
    pc.printf("For blue LED press 2\r\n");
    pc.printf("For green LED press 3\r\n");
    pc.printf("For cycle of LEDs press 4\r\n");
    pc.printf("For Twinkle Twinkle Little Star press 5\r\n");
    pc.printf("For Happy Birthday press 6\r\n");
    pc.printf("Press q to quit\r\n\n");
}

//checks for the input and prints out corresponding output
void checkInput(char input)
{
    
        if(input == 'a')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now playing Do\r\n\n");
        }
    else if(input == 's')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now playing Re\r\n\n");
        }       
        else if(input == 'd')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now playing Mi\r\n\n");
        }
        else if(input == 'f')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now playing Fa\r\n\n");
        }
        else if(input == 'g')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now playing Sol\r\n\n");
        }
        else if(input == 'h')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now playing La\r\n\n");
        }
        else if(input == 'j')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now playing Ti\r\n\n");
        }
        else if(input == 'k')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now playing Do\r\n\n");
        }
        else if(input == '1')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Red LED is on\r\n\n");
        }
        else if(input == '2')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Blue LED is on\r\n\n");
        }
        else if(input == '3')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Green LED is on\r\n\n");
        }
        else if(input == '4')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Cycling through the LEDs\r\n\n");
        }
        else if(input == '5')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now Playing Twinkle Twinkle Little Stars\r\n\n");
        }
        else if(input == '6')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Now Playing Happy Birthday\r\n\n");
        }
        else if(input == 'q')
        {
            pc.printf("Pressed: %c\r\n", input);
            pc.printf("Thank you for using the program!\r\n\n");
        }
}

//plays the song Twinkle Twinkle Little Stars while cycling LEDs
void playTwinkleTwinkeLittleStars()
{ 
        playNote(261);
        blueLedOn();
        wait(0.1);
        playNote(261);
        redLedOn();
        wait(0.1);
        playNote(392);
        greenLedOn();
        wait(0.1);
        playNote(392);
        redLedOn();
        wait(0.1);
        playNote(440);
        blueLedOn();
        wait(0.1);
        playNote(440);
        greenLedOn();
        wait(0.1);
        playNote(392);
        blueLedOn();
        wait(1.0);
        playNote(349);
        greenLedOn();
        wait(0.1);
        playNote(349);
        redLedOn();
        wait(0.1);
        playNote(329);
        blueLedOn();
        wait(0.1);
        playNote(329);
        greenLedOn();
        wait(0.1);
        playNote(294);
        redLedOn();
        wait(0.1);
        playNote(294);
        blueLedOn();
        wait(0.1);
        playNote(261);
        redLedOn();
        wait(1.0);
        playNote(392);
        greenLedOn();
        wait(0.1);
        playNote(392);
        blueLedOn();
        wait(0.1);
        playNote(349);
        redLedOn();
        wait(0.1);
        playNote(349);
        greenLedOn();
        wait(0.1);
        playNote(329);
        blueLedOn();
        wait(0.1);
        playNote(329);
        redLedOn();
        wait(0.1);
        playNote(294);
        greenLedOn();
        wait(1.0);
        playNote(392);
        redLedOn();
        wait(0.1);
        playNote(392);
        blueLedOn();
        wait(0.1);
        playNote(349);
        greenLedOn();
        wait(0.1);
        playNote(349);
        blueLedOn();
        wait(0.1);
        playNote(329);
        greenLedOn();
        wait(0.1);
        playNote(329);
        redLedOn();
        wait(0.1);
        playNote(294);
        blueLedOn();
        wait(1.0);
        playNote(261);
        redLedOn();
        wait(0.1);
        playNote(261);
        greenLedOn();
        wait(0.1);
        playNote(392);
        blueLedOn();
        wait(0.1);
        playNote(392);
        greenLedOn();
        wait(0.1);
        playNote(440);
        redLedOn();
        wait(0.1);
        playNote(440);
        greenLedOn();
        wait(0.1);
        playNote(392);
        blueLedOn();
        wait(1.0);
        playNote(349);
        redLedOn();
        wait(0.1);
        playNote(349);
        blueLedOn();
        wait(0.1);
        playNote(329);
        greenLedOn();
        wait(0.1);
        playNote(329);
        redLedOn();
        wait(0.1);
        playNote(294);
        blueLedOn();
        wait(0.1);
        playNote(294);
        greenLedOn();
        wait(0.1);
        playNote(261);
        OffAllLeds();
        wait(0.1);
}

//plays the song Happy Birthday while cycling LEDs
void playHappyBirthday()
{
    playNote(262);
    redLedOn();
    wait(0.1);
    playNote(262);
    blueLedOn();
    wait(0.1);
    playNote(294);
    greenLedOn();
    wait(0.1);
    playNote(262);
    redLedOn();
    wait(0.1);
    playNote(349);
    blueLedOn();
    wait(0.1);
    playNote(330);
    greenLedOn();
    wait(0.1);
    playNote(262);
    redLedOn();
    wait(0.1);
    playNote(262);
    blueLedOn();
    wait(0.1);
    playNote(294);
    greenLedOn();
    wait(0.1);
    playNote(262);
    redLedOn();
    wait(0.1);
    playNote(392);
    blueLedOn();
    wait(0.1);
    playNote(349);
    greenLedOn();
    wait(0.1);
    playNote(262);
    redLedOn();
    wait(0.1);
    playNote(262);
    blueLedOn();
    wait(0.1);
    playNote(523);
    greenLedOn();
    wait(0.1);
    playNote(440);
    redLedOn();
    wait(0.1);
    playNote(349);
    blueLedOn();
    wait(0.1);
    playNote(330);
    greenLedOn();
    wait(0.1);
    playNote(294);
    redLedOn();
    wait(0.1);
    playNote(466);
    blueLedOn();
    wait(0.1);
    playNote(466);
    greenLedOn();
    wait(0.1);
    playNote(440);
    redLedOn();
    wait(0.1);
    playNote(349);
    blueLedOn();
    wait(0.1);
    playNote(392);
    greenLedOn();
    wait(0.1);
    playNote(349);
    OffAllLeds();
    wait(0.1);
}