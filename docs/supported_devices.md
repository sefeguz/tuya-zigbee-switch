# Supported devices

Support new devices: [contribute/porting.md](/docs/contribute/porting.md)  

### Quick-picks
- **modules:** AVATTO, Aubess, iHseno
- **switches:** Moes 1-3gang (any design)

### Careful with
- generic 1-gang modules - might not support OTA conversion
- BSEED switches - too many variants (can't know which you'll receive)

### Legend

| Symbol | Meaning  |                    |                     |                |                |           |          |
| :----: | -------- | ------------------ | ------------------- | -------------- | -------------- | --------- | -------- |
|   🚧️   | Status   | 🟩️ Fully supported | 🟨️ Mostly supported | 🟧️ In progress | 🟥️ Unsupported |           |          |
|   📦️   | Build    | ✔️ Available       | ❌️ Unavailable      |                |                |           |          |
|   💡️   | Category | 🇲️ Module          | 🇸️ Switch           | 🇴️ Outlet      | 🇵 Plug        | 🇷️ Remote | 🇧️ Board | 
|   ⚡️   | Power    | 🔌️ Mains           | 🔋️ Battery          | 🔱️ USB         |                |           |          |
|   📲️   | Install  | 🛜️ Wireless        | ➿️ By wire          | ❓️ Unknown     |                |           |          |
|   🏭️   | MCU      | `TL` Telink        | `SL` Silicon Labs   | `NXP` NXP      |                |           |          |
|   🅰   | Variant  | 🅰                  | 🅱                  | 🅲             | 🅳              | 🅴        | 🅵        |

<!-------------------------------------------------------------------
  `supported.md` is generated. 
  
  Do not edit it directly! Instead, edit:
  - `device_db.yaml`             - add or edit devices
  - `supported_devices.md.jinja` - update the template
  - `make_supported_devices.py`  - update generation script

  Generate with: `make tools/update_supported_devices`
-------------------------------------------------------------------->

> [!IMPORTANT]  
> Identify your device by **Zigbee Manufacturer** and linked threads/stores!  
> *Z2M pages are sometimes generic.*

### Device list

| 🚧 | 📦 | 💡 | ⚡️ | 📲 |  🏭  | Zb&nbsp;Manufacturer <br> Zb&nbsp;Model | Name <br> Z2M&nbsp;page&nbsp;🔗 | Store | Threads | Status |
| -- | -- | -- | -- | -- | :--: | :-------------------------------------- | :------------------------------ | ----: | ------: | :----- |
| 🟧 | ✔️ | 🇸 | 🔌 | 🛜 | **TL** | `_TZ3000_ybjqjsuz` <br> `TS0003` | [3-gang switch (ybjqjsuz)](https://www.zigbee2mqtt.io/devices/TS0003_switch_module_2.html) |   |   | Pin mapping from firmware dump analysis | 
| 🟧 | ✔️ | 🇸 | 🔌 | 🛜 | **TL** | `_TZ3210_ybjqjsuz` <br> `TS0003` | [3-gang switch (ybjqjsuz TZ3210 variant)](https://www.zigbee2mqtt.io/devices/TS0003_switch_module_2.html) |   |   | Same hardware as MODULE_YBJQJSUZ_TS0003 (_TZ3000_ybjqjsuz) but stock module is from _TZ3210_* family which uses image_type=2050 instead of 54179. Same config_str / pinout. | 
| 🟨 | ✔️ | 🇲 | 🔌 | 🛜 | **TL** | `_TZ3000_zbfya6h0` <br> `TS0002` | [Tuya common 2-gang](https://www.zigbee2mqtt.io/devices/TS0002_basic_2.html) |   | [`#032`](https://github.com/romasku/tuya-zigbee-switch/issues/32) | Needs pinout confirmation | 
| 🟨 | ✔️ | 🇸 | 🔌 | 🛜 | **TL** | `_TZ3210_mrigi9ij` <br> `TS0002` | [2-gang switch (Milfra _TZ3210_mrigi9ij)](https://www.zigbee2mqtt.io/devices/TS0002_basic_2.html) |   |   | 2-gang Milfra on Tuya ZTU module (same 6-button PCB as MODULE_03VS3KS5_TS0004 and MODULE_YBJQJSUZ_TS0003). Stock _TZ3210_ family uses image_type 2050. config_str baked identical to the deployed jazmin/mateo 2-gang teclas (reports ybjqjsuz/TS0002-YBJ, uses TS0002_basic_2 converter). Pinout ch1 S=B6 R=B4 I=A1i, ch2 S=D3 R=D2 I=D4i. | 
| 🟨 | ✔️ | 🇸 | 🔌 | 🛜 | **TL** | `_TZ3000_gsqxcwqr` <br> `TS0001` | [1-gang switch (Milfra _TZ3000_gsqxcwqr)](https://www.zigbee2mqtt.io/devices/TS0001_basic_1.html) |   |   | 1-gang Milfra on Tuya ZTU module (shares 6-button PCB with MODULE_YBJQJSUZ_TS0003 3-gang). Pinout VERIFIED physically on hardware 2026-05-29 - single button is the middle channel (C0, also master), relay B4, indicator C4. Note relay is B4 (not the 3-gang ch2 relay D2 nor 4-gang C3). config_str S=C0 R=B4 I=C4i. | 
| 🟧 | ✔️ | 🇸 | 🔌 | 🛜 | **TL** | `_TZ3210_03vs3ks5` <br> `TS0004` | [4-gang switch (Milfra _TZ3210_03vs3ks5)](https://www.zigbee2mqtt.io/devices/TS0004.html) |   |   | 4-gang Milfra variant on Tuya ZTU module — shares 6-button-capable PCB with TUYA_COMMON_TS0002 (2-gang uses B4/B5, this 4-gang uses D3/D7/C0/B6). Pin map traced physically by sefeguz from PCB silkscreen "N02B/04B CTRL V0.2". | 

Data from [`device_db.yaml`](/device_db.yaml)
