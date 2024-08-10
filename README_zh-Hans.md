[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT4X

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht4x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHT4X是一个数字传感器平台，用于测量不同精度等级的相对湿度和温度。它的I2C接口提供了几个预配置的I2C地址，同时保持了超低的功率预算（0.4μW）。功率调整的内部加热器可以在三个加热级别下使用，从而使传感器能够在苛刻的环境中工作。四引脚双扁平引线封装适用于表面安装技术（SMT）处理，包括可选的封装上专利PTFE膜或可拆卸的保护盖。提供符合ISO17025的传感器特定校准证书，可通过唯一序列号进行识别。

LibDriver SHT4X是LibDriver推出的SHT4X全功能驱动程序，提供温湿度读取和序列号读取功能等功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver SHT4X的源文件。

/interface目录包含了LibDriver SHT4X与平台无关的IIC总线模板。

/test目录包含了LibDriver SHT4X驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver SHT4X编程范例。

/doc目录包含了LibDriver SHT4X离线文档。

/datasheet目录包含了SHT4X数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的IIC总线模板，完成指定平台的IIC总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

#### example basic

```C
#include "driver_sht4x_basic.h"

uint8_t res;
uint8_t num[4];
uint32_t i;
float temperature;
float humidity;

/* basic init */
res = sht4x_basic_init(SHT4X_ADDRESS_0);
if (res != 0)
{
    return 1;
}

...
    
/* loop */
for (i = 0; i < 3; i++)
{
    /* delay 1000ms */
    sht4x_interface_delay_ms(1000);

    /* read data */
    res = sht4x_basic_read((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        (void)sht4x_basic_deinit();

        return 1;
    }

    /* output */
    sht4x_interface_debug_print("sht4x: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)3);
    sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature);
    sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity);
}

...
    
/* get serial number */
res = sht4x_basic_get_serial_number(num);
if (res != 0)
{
    (void)sht4x_basic_deinit();

    return 1;
}

/* output */
sht4x_interface_debug_print("sht4x: serial number is 0x%02X 0x%02X 0x%02X 0x%02X.\n", num[0], num[1], num[2], num[3]);

...
    
/* basic deinit */
(void)sht4x_basic_deinit();

return 0;
```

### 文档

在线文档: [https://www.libdriver.com/docs/sht4x/index.html](https://www.libdriver.com/docs/sht4x/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。