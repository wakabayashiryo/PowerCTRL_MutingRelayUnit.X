# Power cotrol and Muting relay unit for amplifier

- # pin define of PIC12F675   

    |No.|Name|content|   
    |:-:|:--:|:-----|   
    |1  |VDD |Connect Power supply voltage of 5V|
    |2  |GP5 |relay1 |
    |3  |GP4 |relay2 |
    |4  |MCLR|pull up to use resister|
    |5  |GP2 |connet input terminal of SSR(Solid Sate Relay)|
    |6  |GP1 |LED built in swtch which using on GP0|
    |7  |GP0 |alternate switch which was pull ups|
    |8  |Vss |Connet to GND|
    
- # Circuit

- # Configuration of 12F675   
    
    - Clock:Internal RC clock (4Mhz)   
    - GP0 is input mode 
    - interrupt timing ever 1ms=1kHz


