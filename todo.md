# Basics
- [x] Single PWM
- [x] Quad PWM

# Comms
- [ ] RC via CRSF
    - [x] USART2 to DMA with idle line detection
        - [x] Callback called at correct moments 
        - [x] Fix DMA, some issues with specifically MCU of H7?
        - [ ] Re-enable DCACHE
    - [ ] Frame decoding
        - [ ] Link statistics
        - [ ] RC channels
        - [ ] Device ping
        - [ ] Device info
        - [ ] Parameter settings entry
        - [ ] Parameter read
        - [ ] Parameter write
        - [ ] Command
    - [ ] Reliable startup
    - [ ] Reattempt connections when there's issues
    - [ ] CRC check
- [ ] MAVLink connection Laptop <-> STM
- [ ] RC via MAVLink
- [ ] GPS to laptop
    - [ ] Via UART
    - [ ] Via MAVLink 

# Automatic Control
- [ ] Heading PID output to MAVLink
- [ ] PID 
- [ ] Limit rate of change
- [ ] LPF filters 
- [ ] Speed PID output to MAVLink
- [ ] PID 
- [ ] Limit rate of change
- [ ] LPF filters
- [ ] Hand heading over to uC
- [ ] Hand speed over to uC
