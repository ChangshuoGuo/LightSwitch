# LightSwitch

## V1.0
使用*Arduino UNO R3开发板*+*SG90舵机*+*VS1838B红外接收模块*

用红外遥控器发送指令，控制舵机转动特定角度，拨动开关实现遥控灯开关功能

## V1.1
增加蓝牙模块功能，可通过手机连接模块发送指令控制开关

优化红外接收部分代码

## ~~V2.0~~ （已废弃，最近了解到ESP32和物联网，感觉非常适合做这种智能家居，有时间研究一下）

（计划，疫情原因社区都封了，网上买的模块送不到，也去不了公司，不然也不会闲的整这些）

-增加语音控制功能，使用*HLK-50模块*

-将*Arduino Uno R3*开发板换为核心板或芯片，降低成本及体积，设计PCB，将所有模块集成到一块PCB上

-更改供电方式，使用*单节18650锂电池*+*TP4056充放电管理模块*替代目前的充电宝供电方法

## V3 （ESP32&IoT）

## Demo
仅实现了通过51单片机测试控制*SG90舵机*
