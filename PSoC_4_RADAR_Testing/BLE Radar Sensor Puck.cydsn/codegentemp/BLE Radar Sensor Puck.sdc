# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Alen\GitHub_Denzerek\PSoC-4-101\PSoC_4_RADAR_Testing\BLE Radar Sensor Puck.cydsn\BLE Radar Sensor Puck.cyprj
# Date: Fri, 03 Dec 2021 04:46:16 GMT
#set_units -time ns
create_clock -name {UART_SCBCLK(FFB)} -period 708.33333333333326 -waveform {0 354.166666666667} [list [get_pins {ClockBlock/ff_div_1}]]
create_clock -name {Clock(FFB)} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFClk} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 17 35} -nominal_period 708.33333333333326 [list]
create_generated_clock -name {Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 24001 48001} [list]


# Component constraints for C:\Alen\GitHub_Denzerek\PSoC-4-101\PSoC_4_RADAR_Testing\BLE Radar Sensor Puck.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Alen\GitHub_Denzerek\PSoC-4-101\PSoC_4_RADAR_Testing\BLE Radar Sensor Puck.cydsn\BLE Radar Sensor Puck.cyprj
# Date: Fri, 03 Dec 2021 04:46:13 GMT
