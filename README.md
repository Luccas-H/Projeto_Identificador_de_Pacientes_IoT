# Projeto Hands-On: Sistema de Identificação de Pacientes com RFID

Este projeto faz parte das **atividades práticas** do curso **Maloca das iCoisas**. O sistema demonstra uma solução básica, mas eficaz, para a identificação de pacientes utilizando tecnologia RFID. O objetivo principal deste projeto é autorizar ou negar acesso com base nos dados de cartões RFID e exibir mensagens relevantes no LCD.

---

## **Visão Geral do Projeto**

### **Objetivo**
O objetivo deste projeto é demonstrar como a tecnologia RFID pode ser utilizada em aplicações na área da saúde para identificar e gerenciar informações de pacientes de forma segura e eficiente.

### **Funcionalidades**
- Lê cartões RFID usando um módulo PN532.
- Exibe "Acesso Autorizado" no LCD para cartões autorizados.
- Exibe "Acesso Negado" para cartões não autorizados ou passados rapidamente.
- Funcionalidade de reset para retornar ao estado "Esperando por cartao..." após cada operação.

---

## **Requisitos de Hardware**

- **Arduino Mega 2560** (ou equivalente)
- **Módulo RFID PN532**
- **LCD 16x2** (com um potenciômetro para ajuste de contraste)
- Fios jumper e uma protoboard

### **Conexões**

#### **Módulo PN532**
| Pino do PN532 | Pino do Arduino Mega |
|---------------|-----------------------|
| SDA           | 20                   |
| SCL           | 21                   |
| VCC           | 5V                   |
| GND           | GND                  |

#### **LCD 16x2**
| Pino do LCD | Pino do Arduino Mega |
|-------------|-----------------------|
| RS          | 7                    |
| EN          | 8                    |
| D4          | 9                    |
| D5          | 10                   |
| D6          | 11                   |
| D7          | 12                   |
| VCC         | 5V                   |
| GND         | GND                  |
| V0          | Potenciômetro        |

---

## **Requisitos de Software**

- **Arduino IDE** (versão mais recente)
- Bibliotecas Necessárias:
  - `LiquidCrystal` (pré-instalada no Arduino IDE)
  - `Adafruit_PN532` (instale via Gerenciador de Bibliotecas)

---

## **Instalação e Uso**

### **1. Clone este Repositório**
```bash
git clone https://github.com/Luccas-H/Projeto_Identificador_de_Pacientes_IoT.git
cd Projeto_Identificador_de_Pacientes_IoT
