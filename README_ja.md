[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT4X

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht4x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHT4X は、さまざまな精度クラスで相対湿度と温度を測定するためのデジタル センサー プラットフォームです。 その I2C インターフェイスは、超低電力バジェット (0.4 μW) を維持しながら、いくつかの事前設定された I2C アドレスを提供します。 電力調整された内部ヒーターは 3 つの加熱レベルで使用できるため、要求の厳しい環境でもセンサーを動作させることができます。 4 ピン デュアル フラットノリード パッケージは、表面実装技術 (SMT) 処理に適しており、オプションのオンパッケージ特許取得済み PTFE メンブレンまたは取り外し可能な保護カバーで構成されています。 ISO17025 に準拠したセンサー固有の校正証明書は、固有のシリアル番号によって識別可能です。

LibDriver SHT4X は、LibDriver によって起動される SHT4X のフル機能ドライバです。温度と湿度の読み取り、シリアル番号の読み取り機能を提供します。 LibDriver は MISRA に準拠しています。

### 目次

  - [説明](#説明)
  - [インストール](#インストール)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [ドキュメント](#ドキュメント)
  - [貢献](#貢献)
  - [著作権](#著作権)
  - [連絡して](#連絡して)

### 説明

/ srcディレクトリには、LibDriver SHT4Xのソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver SHT4X用のプラットフォームに依存しないIICバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver SHT4Xドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver SHT4Xプログラミング例が含まれています。

/ docディレクトリには、LibDriver SHT4Xオフラインドキュメントが含まれています。

/ datasheetディレクトリには、SHT4Xデータシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないIICバステンプレートを参照して、指定したプラットフォームのIICバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

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

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/sht4x/index.html](https://www.libdriver.com/docs/sht4x/index.html)。

オフラインドキュメント: /doc/html/index.html。

### 貢献

CONTRIBUTING.mdを参照してください。

### 著作権

著作権（c）2015-今 LibDriver 全著作権所有

MITライセンス（MIT）

このソフトウェアおよび関連するドキュメントファイル（「ソフトウェア」）のコピーを取得した人は、無制限の使用、複製、変更、組み込み、公開、配布、サブライセンスを含む、ソフトウェアを処分する権利を制限なく付与されます。ソフトウェアのライセンスおよび/またはコピーの販売、および上記のようにソフトウェアが配布された人の権利のサブライセンスは、次の条件に従うものとします。

上記の著作権表示およびこの許可通知は、このソフトウェアのすべてのコピーまたは実体に含まれるものとします。

このソフトウェアは「現状有姿」で提供され、商品性、特定目的への適合性、および非侵害の保証を含むがこれらに限定されない、明示または黙示を問わず、いかなる種類の保証もありません。 いかなる場合も、作者または著作権所有者は、契約、不法行為、またはその他の方法で、本ソフトウェアおよび本ソフトウェアの使用またはその他の廃棄に起因または関連して、請求、損害、またはその他の責任を負わないものとします。

### 連絡して

お問い合わせくださいlishifenging@outlook.com。