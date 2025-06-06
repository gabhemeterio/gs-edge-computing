#🛠️ Sistema de Monitoramento de Enchentes com Arduino – Edge Computing & IoT


#📌 Descrição do Problema
Em muitas cidades brasileiras, enchentes causadas por chuvas intensas alagam ruas e residências, especialmente em áreas de risco com pouca drenagem. Esses eventos resultam em prejuízos materiais, interrupções no tráfego e riscos à vida. É fundamental ter um sistema acessível e automatizado que possa alertar os moradores ou gestores locais antes que o alagamento se agrave.



#💡 Visão Geral da Solução
Este projeto consiste em um sistema físico de monitoramento baseado em Arduino, que utiliza sensores e atuadores para:

Monitorar o nível da água e a ocorrência de chuva.

Exibir os dados em um LCD com barra de progresso e status textual.

Sinalizar o estado do ambiente com LEDs de cor.

Ativar um alarme sonoro intermitente em caso de perigo.

Acionar um servo motor simulando a fechadura de uma comporta de drenagem.

Possui botões físicos para ativar emergência e resetar o sistema.



#🧰 Componentes Utilizados (no Tinkercad)

Arduino UNO R3

2 sensores de umidade (nível de água e chuva)

LCD 16x2 com módulo I2C

3 LEDs: verde, amarelo e vermelho

Buzzer

Servo motor SG90

Pushbutton (emergência)

Pushbutton (reset)

Resistores de 220Ω e 10kΩ

Protoboard e jumpers




#🖥️ Guia para Simular no Tinkercad
Acesse o projeto pelo link abaixo:
🔗 Clique aqui para abrir no Tinkercad

Faça login na sua conta do Tinkercad (ou crie uma gratuitamente).

Clique em “Start Simulation” no canto superior direito.

Interaja com os sensores (ajuste os sliders nos sensores de umidade) e pressione os botões para testar a emergência e o reset.




#🎬 Link para o Vídeo Demonstrativo
📺 Assistir no YouTube



#🧠 Funcionamento Resumido
Situação	LED	Servo	Buzzer	LCD
Normal	Verde	Aberto (0°)	Desligado	Exibe valores e barra
Alerta	Amarelo	45°	Desligado	Exibe valores e barra
Perigo	Vermelho	Fechado (90°)	Alarme intermitente	Status PERIGO no LCD



#📄 Código Fonte
O código está disponível no arquivo monitoramento_enchentes.ino. Ele está:

Organizado por seções claras: leitura de sensores, lógica de decisão, controle dos atuadores, exibição no LCD.

Comentado linha por linha para facilitar o entendimento.

Estruturado com boas práticas de indentação e nomes de variáveis autoexplicativos.

✨ Possibilidades de Expansão
Integração com Wi-Fi (ESP32) para envio de alertas via Telegram ou app.

Armazenamento de histórico em cartão SD.

Uso de sensores adicionais (temperatura, pressão).

