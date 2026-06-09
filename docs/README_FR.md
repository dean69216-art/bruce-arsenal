?? [English](../README.md) | [Portugues](README_PT.md) | [Italiano](README_IT.md) | [Francais](README_FR.md) | [Russian](README_RU.md) | [Chinese](README_ZH.md) | [Polski](README_PL.md) | [Nederlands](README_NL.md) | [Turkce](README_TR.md) | [Deutsch](README_DE.md) | [Vietnamese](README_VN.md) | [Espanol](README_ES.md) | [Indonesia](README_ID.md) | [Arabic](README_AR.md)

<h1 align="center">?? Bruce Arsenal</h1>

<p align="center">
  <b>Firmware de securite offensive personnalise pour appareils ESP32</b><br>
  <i>72 outils - Un firmware - Appareils multiples</i>
</p>

---

## Qu'Est-Ce

Une version modifiee de Bruce Firmware avec un module Arsenal personnalise - 72 outils de securite offensive accessibles depuis un seul menu.

---

## Installation

1. Telechargez le .bin depuis les Releases
2. Flash via ESP Web Flasher (Chrome/Edge) ou OTA via Arsenal Dashboard

---

## Outils Arsenal (72)

### WiFi Arsenal (11)
Network Scanner, DHCP Starvation, Karma Attack, DNS Spoofer, Auto-Phish Portal, Cred Forward, Auth Flood, AP Clone Flood, SSL Strip Lite, DNS Tunnel, WPS PIN Attack

### BLE Arsenal (6)
BLE Tracker, BT Name Spammer, AirTag Spoofer, Audio Jammer, Notification Spoofer, BT Rickroll

### Intelligence (8)
Device Fingerprinter, OPSEC Monitor, OUI Lookup, Probe Log, Banner Grabber, SmartHome Scan, Channel Chart, People Counter

### Evasion (5)
MAC Rotator, Channel Hopper, Decoy Traffic, Identity Cloner, Time Randomizer

### Phishing (4)
Win Update Phish, WiFi Speed Phish, OAuth Phish, Device Found Phish

### Sub-GHz / RF (6)
NRF24 MouseJack, Doorbell Replay, Garage Brute Force, Keyfob Logger, Frequency Scanner, Flipper Import

### Detection (3)
Flipper Detector, Hacker Detector, RF Silence Enforcer

### Communications (5)
ESP-NOW Chat, ESP-NOW C2, Dead Drop Mesh, IR Data Transfer, Multi-Device Sync

### Utilitaires (2)
NFC Biz Card, Attack Stats

---

## Compatibilite des Cartes

### ESP32-S3 (Complet - 72 outils)
LilyGo T-Embed CC1101, T-Deck Pro, T-Deck, T-Display S3, T-HMI, T-LoRa Pager, T-Watch S3, M5Stack Cardputer, CoreS3, StickS3

### ESP32 (LITE - 31 outils)
M5Stack Core 4MB/16MB, CPlus 1.1, CYD (all variants), Elecrow, Marauder, Awok, WaveSentry, Phantom

### Limitations Connues
M5Stack CPlus2, M5Stack Core2 - Debordement DRAM (variables globales firmware core)

---

## Services en Arriere-Plan

- **OPSEC Dot** - Cercle colore sur la barre d'etat
- **Always-On Evasion** - Rotation MAC + saut de canaux + trafiege leurre
- **Auto-Dim** - Luminosite ecran diminue pendant les attaques

---

## Tableau de Bord a Distance

Arsenal > Dashboard. Connectez le telephone a ArsenalNet (mot de passe: arsenal32). Ouvrez 192.168.4.1.

---

## Credits

- [Bruce Firmware](https://github.com/pr3y/Bruce) by pr3y
- Arsenal module by quietdom

---

## Uniquement pour les tests de securite autorises et les fins educatives.