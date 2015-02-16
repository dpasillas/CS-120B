################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../croutine.c \
../heap_1.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../tasks.c \
../timers.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
croutine.o \
heap_1.o \
list.o \
main.o \
port.o \
queue.o \
tasks.o \
timers.o

OBJS_AS_ARGS +=  \
croutine.o \
heap_1.o \
list.o \
main.o \
port.o \
queue.o \
tasks.o \
timers.o

C_DEPS +=  \
croutine.d \
heap_1.d \
list.d \
main.d \
port.d \
queue.d \
tasks.d \
timers.d

C_DEPS_AS_ARGS +=  \
croutine.d \
heap_1.d \
list.d \
main.d \
port.d \
queue.d \
tasks.d \
timers.d

OUTPUT_FILE_PATH +=[cslogin]_lab3_part1.elf

OUTPUT_FILE_PATH_AS_ARGS +=[cslogin]_lab3_part1.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler

















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -I"../../../../My Documents/Atmel Studio/include" -I"C:\Users\Dan\DOCUME~1\ATMELS~1\6.2\_CSLOG~1\_CSLOG~1\FREERT~1\FreeRTOS\Source" -I"C:\Users\Dan\DOCUME~1\ATMELS~1\6.2\_CSLOG~1\_CSLOG~1\FREERT~1\FreeRTOS\Source\include" -I"C:\Users\Dan\DOCUME~1\ATMELS~1\6.2\_CSLOG~1\_CSLOG~1\FREERT~1\FreeRTOS\Source\portable\GCC\ATMEGA~1"  -O3 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -Wundef -pedantic -mmcu=atmega32 -c -std=gnu99 -v -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="[cslogin]_lab3_part1.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "[cslogin]_lab3_part1.elf" "[cslogin]_lab3_part1.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "[cslogin]_lab3_part1.elf" "[cslogin]_lab3_part1.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "[cslogin]_lab3_part1.elf" > "[cslogin]_lab3_part1.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "[cslogin]_lab3_part1.elf" "[cslogin]_lab3_part1.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-size.exe" "[cslogin]_lab3_part1.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "[cslogin]_lab3_part1.elf" "[cslogin]_lab3_part1.a" "[cslogin]_lab3_part1.hex" "[cslogin]_lab3_part1.lss" "[cslogin]_lab3_part1.eep" "[cslogin]_lab3_part1.map" "[cslogin]_lab3_part1.srec" "[cslogin]_lab3_part1.usersignatures"
	