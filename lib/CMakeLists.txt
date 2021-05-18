set(DS18B20_HEADERS
        avr-ds18b20/include/ds18b20/ds18b20.h
        avr-ds18b20/include/ds18b20/onewire.h
        avr-ds18b20/include/ds18b20/romsearch.h)
set(DS18B20_SRCS
        avr-ds18b20/src/ds18b20.c
        avr-ds18b20/src/onewire.c
        avr-ds18b20/src/romsearch.c)


add_library(ds18b20-lib ${DS18B20_SRCS} ${DS18B20_HEADERS} )
target_include_directories(ds18b20-lib PUBLIC avr-ds18b20/include)
