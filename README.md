# GS-Edge-Computing-2o.semestre
# Inclusão Produtiva – Monitoramento IoT com ESP32 + Node-RED + MQTT

👨‍💻 Integrantes

João Pedro Sassarrão – RM562499

Juan Pablo Molina – RM564445

📌 Descrição do Problema

O projeto aborda o tema Inclusão Produtiva, propondo uma solução IoT para monitoramento ambiental que auxilia pequenos produtores, trabalhadores ou cooperativas.
O objetivo é utilizar sensores de temperatura, umidade e luminosidade para monitorar o ambiente e emitir alertas automáticos, melhorando a produtividade e segurança.

🚀 Descrição da Solução

A solução utiliza um ESP32 com sensores DHT22 e LDR, enviando dados via MQTT (test.mosquitto.org).
O Node-RED recebe as informações, exibe no dashboard e aplica lógica automática e manual de alerta através de botões.

📡 Arquitetura da Solução
ESP32 → MQTT → Node-RED → Dashboard

🛠️ Como Rodar o Projeto (Passo a Passo)
🔹 Rodando o Wokwi

Abra o link do projeto:
👉 https://wokwi.com/projects/448184917268399105

Clique em Play.

O ESP32 começará a enviar dados automaticamente.

🔹 Rodando o Node-RED

Instale o Node-RED

Instale o Dashboard:

npm install node-red-dashboard


Inicie o Node-RED:

node-red


Importe o arquivo node-red-flow.json

Clique em Deploy

Abra o dashboard:
http://localhost:1880/ui

🔗 Links Importantes

🔹 Wokwi: https://wokwi.com/projects/448184917268399105

🔹 Vídeo Explicativo: https://www.youtube.com/watch?v=d2y8AibDyDw

📡 Explicação Técnica – MQTT

O projeto utiliza o protocolo MQTT para comunicação entre ESP32 e Node-RED.

📥 ESP32 → Node-RED

Topic: inclusao/device/data

Payload:

{
  "temp": 0,
  "umidade": 0,
  "luminosidade": 0
}

📤 Node-RED → ESP32

Topic: inclusao/device/cmd

Payloads aceitos:

ALERTA

🧩 Códigos Fonte Comentados

📌 Código do ESP32 (sketch.ino)
[sketch.ino](./sketch.ino)

📌 Fluxo do Node-RED (node-red-flow.json)
[node-red-flow.json](./node-red-flow.json)

✔️ Conclusão

O projeto demonstra como IoT pode auxiliar iniciativas de Inclusão Produtiva, usando sensores, comunicação MQTT e interface Node-RED para oferecer monitoramento inteligente e acessível.
