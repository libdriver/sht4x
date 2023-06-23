### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. SHT4X

#### 3.1 Command Instruction

1. Show sht4x chip and driver information.

   ```shell
   sht4x (-i | --information)
   ```

2. Show sht4x help.

   ```shell
   sht4x (-h | --help)
   ```

3. Show sht4x pin connections of the current board.

   ```shell
   sht4x (-p | --port)
   ```

4. Run sht4x read test, num is test times.

   ```shell
   sht4x (-t read | --test=read) [--addr=<0 | 1 | 2>] [--times=<num>]
   ```

5. Run sht4x read function, num is read times.

   ```shell
   sht4x (-e read | --example=read) [--addr=<0 | 1 | 2>] [--times=<num>]
   ```

7. Run sht4x number function.

   ```shell
   sht4x (-e number | --example=number) [--addr=<0 | 1 | 2>]
   ```

#### 3.2 Command Example

```shell
sht4x -i

sht4x: chip is Sensirion SHT4X.
sht4x: manufacturer is Sensirion.
sht4x: interface is IIC.
sht4x: driver version is 1.0.
sht4x: min supply voltage is 1.1V.
sht4x: max supply voltage is 3.6V.
sht4x: max current is 100.00mA.
sht4x: max temperature is 125.0C.
sht4x: min temperature is -40.0C.
```

```shell
sht4x -p

sht4x: SCL connected to GPIOB PIN8.
sht4x: SDA connected to GPIOB PIN9.
```

```shell
sht4x -t read --addr=0 --times=3

sht4x: chip is Sensirion SHT4X.
sht4x: manufacturer is Sensirion.
sht4x: interface is IIC.
sht4x: driver version is 1.0.
sht4x: min supply voltage is 1.1V.
sht4x: max supply voltage is 3.6V.
sht4x: max current is 100.00mA.
sht4x: max temperature is 125.0C.
sht4x: min temperature is -40.0C.
sht4x: start read test.
sht4x: serial number is 0x0E 0xE4 0x51 0xA9.
sht4x: high precision without heater.
sht4x: temperature is 28.87C.
sht4x: humidity is 53.92%.
sht4x: temperature is 28.86C.
sht4x: humidity is 53.91%.
sht4x: temperature is 28.86C.
sht4x: humidity is 53.86%.
sht4x: medium precision without heater.
sht4x: temperature is 28.86C.
sht4x: humidity is 53.94%.
sht4x: temperature is 28.86C.
sht4x: humidity is 54.20%.
sht4x: temperature is 28.88C.
sht4x: humidity is 54.40%.
sht4x: lowest precision without heater.
sht4x: temperature is 28.89C.
sht4x: humidity is 54.47%.
sht4x: temperature is 28.89C.
sht4x: humidity is 54.42%.
sht4x: temperature is 28.89C.
sht4x: humidity is 54.37%.
sht4x: activate heater with 200mW for 1s, high precision.
sht4x: temperature is 68.08C.
sht4x: humidity is 35.95%.
sht4x: temperature is 69.33C.
sht4x: humidity is 27.56%.
sht4x: temperature is 69.84C.
sht4x: humidity is 25.98%.
sht4x: activate heater with 200mW for 0.1s, high precision.
sht4x: temperature is 51.44C.
sht4x: humidity is 37.19%.
sht4x: temperature is 51.35C.
sht4x: humidity is 40.94%.
sht4x: temperature is 51.24C.
sht4x: humidity is 42.98%.
sht4x: activate heater with 110mW for 1s, high precision.
sht4x: temperature is 55.65C.
sht4x: humidity is 38.04%.
sht4x: temperature is 56.24C.
sht4x: humidity is 33.44%.
sht4x: temperature is 56.49C.
sht4x: humidity is 32.22%.
sht4x: activate heater with 110mW for 0.1s, high precision.
sht4x: temperature is 44.24C.
sht4x: humidity is 39.60%.
sht4x: temperature is 44.14C.
sht4x: humidity is 42.82%.
sht4x: temperature is 44.00C.
sht4x: humidity is 44.54%.
sht4x: activate heater with 20mW for 1s, high precision.
sht4x: temperature is 35.94C.
sht4x: humidity is 47.11%.
sht4x: temperature is 35.96C.
sht4x: humidity is 46.89%.
sht4x: temperature is 35.93C.
sht4x: humidity is 46.84%.
sht4x: activate heater with 20mW for 0.1s, high precision.
sht4x: temperature is 33.05C.
sht4x: humidity is 48.63%.
sht4x: temperature is 33.01C.
sht4x: humidity is 49.81%.
sht4x: temperature is 32.98C.
sht4x: humidity is 50.32%.
sht4x: soft reset.
sht4x: finish read test.
```

```shell
sht4x -e read --addr=0 --times=3

sht4x: 1/3.
sht4x: temperature is 28.96C.
sht4x: humidity is 54.28%.
sht4x: 2/3.
sht4x: temperature is 28.94C.
sht4x: humidity is 54.20%.
sht4x: 3/3.
sht4x: temperature is 28.94C.
sht4x: humidity is 54.36%.
```

```shell
sht4x -e number --addr=0

sht4x: serial number is 0x0E 0xE4 0x51 0xA9.
```

```shell
sht4x -h

Usage:
  sht4x (-i | --information)
  sht4x (-h | --help)
  sht4x (-p | --port)
  sht4x (-t read | --test=read) [--addr=<0 | 1 | 2>] [--times=<num>]
  sht4x (-e read | --example=read) [--addr=<0 | 1 | 2>] [--times=<num>]
  sht4x (-e number | --example=number) [--addr=<0 | 1 | 2>]

Options:
      --addr=<0 | 1 | 2>
                        Set the addr.([default: 0])
  -e <read | number>, --example=<read | number>
                        Run the driver example.
  -h, --help            Show the help.
  -i, --information     Show the chip information.
  -p, --port            Display the pin connections of the current board.
  -t <read>, --test=<read>
                        Run the driver test.
      --times=<num>     Set the running times.([default: 3])
```

