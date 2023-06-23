### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(sht4x REQUIRED)
```


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
./sht4x -i

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
./sht4x -p

sht4x: SCL connected to GPIO3(BCM).
sht4x: SDA connected to GPIO2(BCM).
```

```shell
./sht4x -t read --addr=0 --times=3

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
sht4x: serial number is 0x0E 0x5D 0x61 0x13.
sht4x: high precision without heater.
sht4x: temperature is 28.22C.
sht4x: humidity is 42.52%.
sht4x: temperature is 28.21C.
sht4x: humidity is 42.47%.
sht4x: temperature is 28.19C.
sht4x: humidity is 42.45%.
sht4x: medium precision without heater.
sht4x: temperature is 28.18C.
sht4x: humidity is 42.47%.
sht4x: temperature is 28.15C.
sht4x: humidity is 42.46%.
sht4x: temperature is 28.16C.
sht4x: humidity is 42.48%.
sht4x: lowest precision without heater.
sht4x: temperature is 28.15C.
sht4x: humidity is 42.48%.
sht4x: temperature is 28.11C.
sht4x: humidity is 42.54%.
sht4x: temperature is 28.07C.
sht4x: humidity is 42.59%.
sht4x: activate heater with 200mW for 1s, high precision.
sht4x: temperature is 70.12C.
sht4x: humidity is 19.43%.
sht4x: temperature is 70.93C.
sht4x: humidity is 13.48%.
sht4x: temperature is 71.08C.
sht4x: humidity is 12.87%.
sht4x: activate heater with 200mW for 0.1s, high precision.
sht4x: temperature is 49.78C.
sht4x: humidity is 27.33%.
sht4x: temperature is 49.73C.
sht4x: humidity is 30.61%.
sht4x: temperature is 49.63C.
sht4x: humidity is 32.22%.
sht4x: activate heater with 110mW for 1s, high precision.
sht4x: temperature is 56.35C.
sht4x: humidity is 24.45%.
sht4x: temperature is 56.91C.
sht4x: humidity is 20.24%.
sht4x: temperature is 57.13C.
sht4x: humidity is 19.40%.
sht4x: activate heater with 110mW for 0.1s, high precision.
sht4x: temperature is 42.86C.
sht4x: humidity is 29.51%.
sht4x: temperature is 42.84C.
sht4x: humidity is 32.52%.
sht4x: temperature is 42.73C.
sht4x: humidity is 33.99%.
sht4x: activate heater with 20mW for 1s, high precision.
sht4x: temperature is 35.45C.
sht4x: humidity is 38.48%.
sht4x: temperature is 35.45C.
sht4x: humidity is 36.97%.
sht4x: temperature is 35.43C.
sht4x: humidity is 36.04%.
sht4x: activate heater with 20mW for 0.1s, high precision.
sht4x: temperature is 32.07C.
sht4x: humidity is 37.68%.
sht4x: temperature is 32.02C.
sht4x: humidity is 38.70%.
sht4x: temperature is 31.94C.
sht4x: humidity is 39.25%.
sht4x: soft reset.
sht4x: finish read test.
```

```shell
./sht4x -e read --addr=0 --times=3

sht4x: 1/3.
sht4x: temperature is 28.08C.
sht4x: humidity is 42.56%.
sht4x: 2/3.
sht4x: temperature is 28.08C.
sht4x: humidity is 42.82%.
sht4x: 3/3.
sht4x: temperature is 28.08C.
sht4x: humidity is 43.21%.
```

```shell
./sht4x -e number --addr=0

sht4x: serial number is 0x0E 0x5D 0x61 0x13.
```

```shell
./sht4x -h

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

