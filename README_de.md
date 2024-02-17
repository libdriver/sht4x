[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT4X
[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht4x/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

SHT4X ist eine digitale Sensorplattform zur Messung der relativen Luftfeuchtigkeit und Temperatur in verschiedenen Genauigkeitsklassen. Seine I2C-Schnittstelle bietet mehrere vorkonfigurierte I2C-Adressen bei gleichzeitig extrem niedrigem Leistungsbudget (0,4 μW). Die leistungsgetrimmte Innenheizung kann in drei Heizstufen eingesetzt werden und ermöglicht so den Sensorbetrieb in anspruchsvollen Umgebungen. Das vierpolige Dual-Flat-No-Leads-Gehäuse eignet sich für die SMT-Verarbeitung (Surface Mount Technology) und umfasst optional eine patentierte PTFE-Membran auf dem Gehäuse oder eine abnehmbare Schutzabdeckung. Es sind sensorspezifische Kalibrierzertifikate gemäß ISO17025 erhältlich, die durch eine eindeutige Seriennummer identifizierbar sind.

LibDriver SHT4X ist der von LibDriver eingeführte Vollfunktionstreiber von SHT4X. Er bietet Funktionen zum Lesen von Temperatur und Luftfeuchtigkeit sowie zum Lesen von Seriennummern. LibDriver ist MISRA-kompatibel.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver SHT4X-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver SHT4X IIC.

/test enthält den Testcode des LibDriver SHT4X-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver SHT4X-Beispielcode.

/doc enthält das LibDriver SHT4X-Offlinedokument.

/Datenblatt enthält SHT4X-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige IIC-Schnittstellenvorlage und stellen Sie Ihren Plattform-IIC-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

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

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/sht4x/index.html](https://www.libdriver.com/docs/sht4x/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.