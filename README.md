# 🌊 Sistema de Monitoramento de Enchentes com Arduino  
**Projeto de Edge Computing & IoT**

---

## 📌 Problema

Cidades brasileiras frequentemente sofrem com **alagamentos causados por chuvas intensas**, principalmente em áreas com infraestrutura deficiente de drenagem. Esses eventos causam:

- Danos a residências e veículos
- Interrupções no tráfego
- Riscos à vida humana

➡️ É necessário um **sistema acessível, automático e local**, capaz de **emitir alertas** e **agir preventivamente** para mitigar danos.

---

## 💡 Solução Proposta

Criamos um **sistema físico com Arduino** que monitora o ambiente em tempo real e **emite alertas locais** com sensores e atuadores.  
O sistema:

- 📏 Monitora **nível de água** e **chuva** com sensores de umidade
- 📟 Exibe informações em **LCD com barra de progresso**
- 🚨 Aciona **LEDs e alarme sonoro** conforme o nível de risco
- 🛑 Move um **servo motor** simulando a **fechadura de uma comporta**
- 🧠 Permite **ativação manual de emergência** e **reset do sistema**

---

## 🧰 Componentes Utilizados (Tinkercad)

| Componente              | Função                                         |
|-------------------------|-----------------------------------------------|
| Arduino Uno R3          | Microcontrolador principal                    |
| 2 sensores de umidade   | Medem nível da água e presença de chuva       |
| LCD 16x2 I2C            | Exibe dados e status                          |
| 3 LEDs (verde, amarelo, vermelho) | Indicadores visuais de risco         |
| Buzzer                  | Alarme sonoro intermitente no modo PERIGO     |
| Servo motor SG90        | Simula uma comporta automática                |
| 2 botões (emergência/reset) | Controle manual do sistema               |
| Protoboard + resistores | Conexão e proteção do circuito                |

---

## 🖥️ Simulação no Tinkercad

🔗 [Clique aqui para abrir o projeto no Tinkercad](https://www.tinkercad.com/things/SEU-LINK-AQUI](https://www.tinkercad.com/things/2Xl3MTinNeT-gs-edge-computing))

> ✅ Use os sliders dos sensores para simular chuva e alagamento  
> ✅ Pressione os botões para testar os modos "Emergência" e "Reset"

---

## 🎬 Vídeo Demonstrativo

📺 [Assista ao vídeo explicativo no YouTube](https://youtu.be/W6aEQC4Ioj0)

---

## ⚙️ Lógica de Funcionamento

| Estado   | LED        | Servo     | Buzzer           | Ação                              |
|----------|------------|-----------|------------------|-----------------------------------|
| NORMAL   | Verde      | 0°        | Desligado        | Sistema seguro, comporta aberta   |
| ALERTA   | Amarelo    | 45°       | Desligado        | Risco moderado, atenção necessária|
| PERIGO   | Vermelho   | 90°       | Alarme pulsando  | Emergência, comporta fechada      |

---

## 📂 Código Fonte

- Arquivo: [`gs-edge-computing.ino`](gs-edge-computing.ino)
- Estruturado com:
  - ✅ Comentários explicativos
  - ✅ Boa indentação
  - ✅ Variáveis com nomes intuitivos
  - ✅ Divisão clara por blocos (setup, sensores, lógica, exibição)

---

## 🚀 Como Testar Localmente

1. Acesse o link do projeto no Tinkercad
2. Clique em “**Start Simulation**”
3. Interaja com os sliders dos sensores e os botões
4. Observe os LEDs, buzzer, LCD e servo motor em ação

---

## ✨ Expansões Futuras

- ☁️ Integração com ESP32 + Wi-Fi para enviar alertas remotos
- 💾 Registro histórico com cartão SD
- 📱 Integração com app de celular

---

**Desenvolvido para fins educacionais - Projeto de IoT & Edge Computing 2025.**
