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
| 🟨 | ✔️ | 🇲 | 🔌 | 🛜 | **TL** | `_TZ3000_zbfya6h0` <br> `TS0002` | [Tuya common 2-gang](https://www.zigbee2mqtt.io/devices/TS0002_basic_2.html) |   | [`#032`](https://github.com/romasku/tuya-zigbee-switch/issues/32) | Needs pinout confirmation | 
| 🟧 | ✔️ | 🇸 | 🔌 | 🛜 | **TL** | `_TZ3000_ybjqjsuz` <br> `TS0004` | [4-gang switch (ybjqjsuz)](https://www.zigbee2mqtt.io/devices/TS0004_basic.html) |   |   | 4-gang variant — first 3 channels mirror TS0003-YBJ. Channel 4 (S=B7,R=B5) inferred from leftover 4-endpoint exploration in TeclaBañoNiños device_config_switch_0. Indicator 4 (I=A2) is a guess to be confirmed on first flash. | 

Data from [`device_db.yaml`](/device_db.yaml)
