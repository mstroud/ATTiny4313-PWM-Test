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

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/asf/ \
../src/asf/common/ \
../src/asf/common/utils/ \
../src/asf/common/utils/interrupt/ \
../src/asf/common/utils/make/ \
../src/asf/mega/ \
../src/asf/mega/utils/ \
../src/asf/mega/utils/assembler/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/colorFade.c \
../src/main.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
src/colorFade.o \
src/main.o


OBJS_AS_ARGS +=  \
src/colorFade.o \
src/main.o


C_DEPS +=  \
src/colorFade.d \
src/main.d


C_DEPS_AS_ARGS +=  \
src/colorFade.d \
src/main.d


OUTPUT_FILE_PATH +=ATTiny4313\ PWM\ Test.elf

OUTPUT_FILE_PATH_AS_ARGS +="ATTiny4313 PWM Test.elf"

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR32/GNU C Compiler
src/colorFade.o: ../src/colorFade.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -DBOARD=STK600_MEGA  -I"../src" -I"../src/asf/common/applications/user_application/atmega32_stk600-mega" -I"../src/asf/common/boards" -I"../src/asf/common/utils" -I"../src/asf/mega/utils" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -g3 -Wall -c -Werror-implicit-function-declaration -Wmissing-prototypes -Wpointer-arith -Wstrict-prototypes -mrelax -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=attiny4313   -o"$@" "$<" 
	@echo Finished building: $<

src/main.o: ../src/main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -DBOARD=STK600_MEGA  -I"../src" -I"../src/asf/common/applications/user_application/atmega32_stk600-mega" -I"../src/asf/common/boards" -I"../src/asf/common/utils" -I"../src/asf/mega/utils" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -g3 -Wall -c -Werror-implicit-function-declaration -Wmissing-prototypes -Wpointer-arith -Wstrict-prototypes -mrelax -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=attiny4313   -o"$@" "$<" 
	@echo Finished building: $<


src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -DBOARD=STK600_MEGA  -I"../src" -I"../src/asf/common/applications/user_application/atmega32_stk600-mega" -I"../src/asf/common/boards" -I"../src/asf/common/utils" -I"../src/asf/mega/utils" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -g3 -Wall -c -Werror-implicit-function-declaration -Wmissing-prototypes -Wpointer-arith -Wstrict-prototypes -mrelax -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=attiny4313   -o"$@" "$<" 
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

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="ATTiny4313 PWM Test.map" -Wl,--start-group  -Wl,--end-group -Wl,--gc-sections -mrelax -Wl,-section-start=.fade_table=0xc00 -Wl,-section-start=.rcal_table=0xd00 -Wl,-section-start=.gcal_table=0xe00 -Wl,-section-start=.bcal_table=0xf00  -Wl,--relax  -mmcu=attiny4313  
	@echo Finished building target: $@
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "ATTiny4313 PWM Test.elf" "ATTiny4313 PWM Test.hex"
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "ATTiny4313 PWM Test.elf" "ATTiny4313 PWM Test.eep" || exit 0
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objdump.exe" -h -S "ATTiny4313 PWM Test.elf" > "ATTiny4313 PWM Test.lss"
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "ATTiny4313 PWM Test.elf" "ATTiny4313 PWM Test.srec"
	"C:\Program Files\Atmel\Atmel Studio 6.0\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-size.exe" "ATTiny4313 PWM Test.elf"
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "ATTiny4313 PWM Test.elf" "ATTiny4313 PWM Test.a" "ATTiny4313 PWM Test.hex" "ATTiny4313 PWM Test.lss" "ATTiny4313 PWM Test.eep" "ATTiny4313 PWM Test.map" "ATTiny4313 PWM Test.srec"
	