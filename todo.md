# Basics
- [x] Single PWM
- [x] Quad PWM

# Comms
- [ ] RC via CRSF
    - [x] USART2 to DMA with idle line detection
    - [ ] Fix DMA, some issues with specifically MCU of H7?
    - [ ] Decode channel message
    - [ ] Decode other peripherals
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
